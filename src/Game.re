[%raw {|require('./styles/reset.css')|}]
open Shared;
open Logic;

type action =
| SelectedGamePiece(gamePiece)
| SlideGamePiece(gamePiece)
| ResetGame;

let initialState: state = {
  checkerBoard: Logic.buildBoard(),
  gameState: Playing(Red),
};

let gameOuter = Css.[
  border(px(4), solid, hex("236253")),
  width(px(400))
];

type jumpMove = {
  captures: list((int, int)),
  landingX: int,
  landingY: int,
};

type remaining = {
  moves: list(jumpMove),
  jumps: list((int, int)),
  selX: int,
  selY: int
};

[@react.component]
let make = _ => {
  let (state: Shared.state, dispatch) = React.useReducer(
    (state, action) =>
    switch (action) {
      | SelectedGamePiece(selectedPiece: gamePiece) => {
          switch (selectedPiece.player, state.gameState) {
            | (Red, Playing(White))|(White, Playing(Red)) => state
            | _ => {
              let { gamePieceState: selState, x: selX, y: selY } = selectedPiece;
              let { checkerBoard, gameState } = state;

              let adjecentSlideMoves = [
                ( selX + 1, selY + 1),
                ( selX + 1, selY - 1),
                ( selX - 1, selY + 1),
                ( selX - 1, selY - 1),
              ];

              let { kingStatus } = selectedPiece;
              let validSlides = adjecentSlideMoves
              // Is move on board
              |> List.filter(Logic.isMoveOnBoard)
              // Is move in correct direction
              |> List.filter(((x, y)) => Logic.isLegalMove(
                (x, y), selX, selY, gameState, kingStatus
              ))
              // Is move to an empty square
              |> List.filter(((x, y)) => Logic.isLandingEmpty(
                (x, y), checkerBoard)
              );

              let rec buildJumps = (moves, jumps, selX, selY, rest:list(remaining)) => {
                let { kingStatus } = selectedPiece;
                let adjacentJumpMoves = [
                  (( selX + 1, selY + 1), ( selX + 2, selY + 2)),
                  (( selX + 1, selY - 1), ( selX + 2, selY - 2)),
                  (( selX - 1, selY + 1), ( selX - 2, selY + 2)),
                  (( selX - 1, selY - 1), ( selX - 2, selY - 2)),
                ];

                let validLandings = (adjacentJumpMoves
                // Ensure we are not jumping back to the start of our jump
                |> List.filter(((_, (lx, ly))) => {
                  lx !== selectedPiece.x || ly !== selectedPiece.y
                })
                // Ensure we haven't jumped here before
                |> List.filter((((cx, cy), _)) => {
                  switch (jumps |> List.find(((x, y)) => x === cx && y === cy)) {
                    | exception Not_found => true
                    | _ => false
                  }
                })
                // Is move on board
                |> List.filter((((x, y), _)) => Logic.isMoveOnBoard((x, y)))
                // Is Landing on the board
                |> List.filter(((_, (lx, ly))) => Logic.isMoveOnBoard((lx, ly)))
                // Is move in correct direction
                |> List.filter((((x, y), _)) => Logic.isLegalMove(
                  (x, y), selX, selY, gameState, kingStatus
                ))
                // Is the adjacent field our opponent's?
                |> List.filter((((x, y), _)) => {
                  let id = string_of_int(x) ++ string_of_int(y);
                  let foundField = Logic.findFieldById(checkerBoard, id); 
                  switch (foundField.player, gameState) {
                    | (Red, Playing(White))
                    | (White, Playing(Red)) => true
                    | _ => false
                  };
                })
                // Is landing to an empty square
                |> List.filter(((_, (lx, ly))) => Logic.isLandingEmpty(
                  (lx, ly), checkerBoard)
                ));

                Js.log((selX, selY, validLandings));

                switch (validLandings, rest) {
                  | ([], []) => moves
                  | ([(capture, (lx, ly))], _) => buildJumps(
                    moves @ [{ landingX: lx, landingY: ly, captures: jumps @ [capture] }],
                    jumps @ [capture],
                    lx, ly, rest
                  )
                  | ([(capture, (lx, ly)), ...tail], _) => buildJumps(
                    moves @ [{ landingX: lx, landingY: ly, captures: jumps @ [capture] }],
                    jumps @ [capture],
                    lx, ly,
                    rest @ [...tail |> List.map(((capture2, (lx2, ly2))) => {
                      moves: moves @ [{ landingX: lx2, landingY: ly2, captures: jumps @ [capture] }],
                      jumps: jumps @ [capture2],
                      selX: lx2,
                      selY: ly2,
                    }
                    )]
                  )
                  | ([], [{ jumps: restJumps, selX, selY }]) => {
                    buildJumps(
                      moves @ [{ landingX: selX, landingY: selY, captures: restJumps }], restJumps, selX, selY, []
                    )
                  }
                  | ([], [{ moves: restMoves, jumps: restJumps, selX, selY }, ...tail]) => buildJumps(
                    moves @ restMoves, jumps @ restJumps, selX, selY, tail
                  )
                }
              }

              let validJumps2 = buildJumps([], [], selX, selY, []);

              let updatedBoard = checkerBoard
              |> List.map((row: checkerBoardRow) => {
                {
                  ...row,
                  gamePieces: row.gamePieces
                  |> List.map((field: gamePiece) => {
                    let { gamePieceState: fieldState, x: fieldX, y: fieldY } = field;
                    let foundLanding = switch (validJumps2
                      |> List.find(({ landingY, landingX }) =>
                        landingX === fieldX && landingY === fieldY
                    )) {
                      | exception Not_found => None
                      | landing => Some(landing)
                    };
                    // Pattern-match on the field's x and y
                    // When x and y is a match on valid adjacent moves, set state to valid move
                    // When x and y is a match on selected x and y, set game state to valid move
                    switch (fieldX, fieldY, selState, fieldState) {
                      | (_, _, _, Default) when switch foundLanding {
                        | Some(_) => true
                        | None => false
                      } => {
                        ...field,
                        gamePieceState: ValidJump(switch foundLanding {
                          | Some({ captures }) => captures
                          | None => []
                        }),
                      }
                      // TODO: if jumps, do not show slides
                      | (x, y, _, Default) when switch (List.find(((x1, y1)) => x1 === x && y1 === y, validSlides)) {
                        | exception Not_found => false
                        | _ => true
                      } => { ...field, gamePieceState: ValidMove }
                      | (x, y, Default, _) when x === selX && y === selY => {
                        ...field,
                        gamePieceState: Selected
                      }
                      | _ => { ...field, gamePieceState: Default }
                    }
                  })
                }
              });
              // Return updated State
              {
                ...state,
                checkerBoard: updatedBoard,
              }
            }
          }
        }
      | SlideGamePiece(gamePieceToMove: gamePiece) => {
        let { x: selX, y: selY, kingStatus: selKingStatus } = state.checkerBoard
          |> List.map((row) => row.gamePieces)
          |> List.flatten
          |> List.find((gamePiece) => {
            switch gamePiece.gamePieceState {
              | Selected => true
              | _ => false
            }
          });
        let captures = switch gamePieceToMove.gamePieceState {
          | ValidJump(captures) => captures
          | _ => []
        }
        let { x: moveToX, y: moveToY, kingStatus } = gamePieceToMove;
        let updatedBoard = state.checkerBoard
        |> List.map((row: checkerBoardRow) => {
          {
            ...row,
            gamePieces: row.gamePieces
            |> List.map((field: gamePiece) => {
              let { x: fieldX, y: fieldY } = field;
              let foundCapture = switch (captures
                |> List.find(((cx, cy)) =>
                  cx === fieldX && cy === fieldY
              )) {
                | exception Not_found => None
                | capture => Some(capture)
              };
              let captured = switch foundCapture {
                | Some(_) => true
                | None => false
              };

              switch (fieldX, fieldY) {
                | (x, y) when
                  (x === selX && y === selY) || captured => {
                  ...field,
                  player: Empty,
                  gamePieceState: Default 
                }
                | (x, y) when x === moveToX && y === moveToY => {
                    switch kingStatus {
                      | King => Js.log("King")
                      | _ => Js.log("Normal")
                    };
                    {
                    ...field,
                    kingStatus: switch (moveToY, state.gameState, selKingStatus) {
                      | (_, _, King) => King
                      | (7, Playing(Red), Normal)
                      | (0, Playing(White), Normal) => King
                      | _ => Normal
                    },
                    player: switch state.gameState {
                      | Playing(Red) => Red
                      | _ => White
                    },
                    gamePieceState: Default 
                  }
                }
                | _ => { ...field, gamePieceState: Default }
              }
            })
          }
        });
        let piecesRemaining = (player) => updatedBoard
          |> List.map((row) => row.gamePieces)
          |> List.flatten
          |> List.filter((field) => player === field.player)
          |> List.length;

        Js.log(piecesRemaining(Red));
        Js.log(piecesRemaining(White));
        {
          checkerBoard: updatedBoard,
          gameState: switch (
            piecesRemaining(Red),
            piecesRemaining(White),
            state.gameState
          ) {
            | (0, _, _) => Winner(White)
            | (_, 0, _) => Winner(Red)
            | (_, _, Playing(Red)) => Playing(White)
            | (_, _, Playing(White)) => Playing(Red)
            | (_, _, Winner(x)) => Winner(x)
            // In theory, should never happen
            // Here to make the warning go away :D
            | (_, _, Playing(Empty)) => Winner(Empty)
          }
        };
      }
      | ResetGame => {...initialState, gameState: Playing(Red) }
    },
    initialState
  );

  // Styles
  let gameMain = Css.[
    // backgroundColor(red),
    // maxWidth(px(900)),
    // margin2(px(0), auto)
  ];

  let { checkerBoard } = state;
  <div className=Css.style(gameMain)>
    <div>
      <h3>
        {ReasonReact.string("Turn: ")}
        {
          switch state.gameState {
            | Playing(Red) => ReasonReact.string("Red")
            | Playing(White) => ReasonReact.string("White")
            | Playing(Empty) => React.string("Draw");
            | Winner(player) => {
              let winner = switch player {
                | Red => "Red"
                | White => "White"
                | _ => "Draw"
              }; 
              ReasonReact.string(winner++" Won!");
            }
          }
        }
      </h3>
      <button onClick=((_) => dispatch(ResetGame))>
        {React.string("Reset")}
      </button>
    </div>
    <div className=Css.style(gameOuter)>
      (
        checkerBoard
        |> List.map((row: checkerBoardRow) =>
          <BoardRow
            rowIndex=row.id
            onSelectGamePiece=((gamePiece) => dispatch(SelectedGamePiece(gamePiece)))
            onSlideGamePiece=((gamePiece) => dispatch(SlideGamePiece(gamePiece)))
            row=row.gamePieces
            key=string_of_int(row.id)
          />
        )
        |> Array.of_list
        |> ReasonReact.array
      )
    </div>
  </div>
};
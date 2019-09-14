open Shared;
open Logic;

type action =
| SelectedGamePiece(gamePiece)
| SlideGamePiece(gamePiece);

let initialState: state = {
  checkerBoard: Logic.buildBoard(),
  gameState: Playing(Red),
};

let gameOuter = Css.[
  border(px(4), solid, hex("236253")),
  width(px(400))
];

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

              let adjacentJumpMoves = [
                (( selX + 1, selY + 1), ( selX + 2, selY + 2)),
                (( selX + 1, selY - 1), ( selX + 2, selY - 2)),
                (( selX - 1, selY + 1), ( selX - 2, selY + 2)),
                (( selX - 1, selY - 1), ( selX - 2, selY - 2)),
              ];

              // Js.log("Adjacents");
              // Js.log(adjecents);
              
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

              // single Jump only for now
              let validSingleJumps = adjacentJumpMoves
              // Is move on board
              |> List.filter((((x, y), _)) => Logic.isMoveOnBoard((x, y)))
              // Is Landing on the board
              |> List.filter(((_, (lx, ly))) => Logic.isMoveOnBoard((lx, ly)))
              // Is move in correct direction
              |> List.filter((((x, y), _)) => Logic.isLegalMove(
                (x, y), selX, selY, gameState, kingStatus
              ))
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
              );

              let updatedBoard = checkerBoard
              |> List.map((row: checkerBoardRow) => {
                {
                  ...row,
                  gamePieces: row.gamePieces
                  |> List.map((field: gamePiece) => {
                    let { gamePieceState: fieldState, x: fieldX, y: fieldY } = field;
                    // Pattern-match on the field's x and y
                    // When x and y is a match on valid adjacent moves, set state to valid move
                    // When x and y is a match on selected x and y, set game state to valid move
                    switch (fieldX, fieldY, selState, fieldState) {
                      | (x, y, _, Default) when switch (List.find(((_, (lx, ly))) => lx === x && ly === y, validSingleJumps)) {
                        | exception Not_found => false
                        | _ => true
                      } => {
                        ...field,
                        gamePieceState: ValidJump(switch (List.find(((_, (lx, ly))) => lx === x && ly === y, validSingleJumps)) {
                          | exception Not_found => (-1, -1)
                          | ((x, y), _) => (x, y)
                        }),
                      }
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
        let { x: selX, y: selY } = state.checkerBoard
          |> List.map((row) => row.gamePieces)
          |> List.flatten
          |> List.find((gamePiece) => {
            switch gamePiece.gamePieceState {
              | Selected => true
              | _ => false
            }
          });
        let (capX, capY) = switch gamePieceToMove.gamePieceState {
          | ValidJump((x, y)) => (x, y)
          | _ => (-1, -1)
        }
        let { x: moveToX, y: moveToY } = gamePieceToMove;
        let updatedBoard = state.checkerBoard
        |> List.map((row: checkerBoardRow) => {
          {
            ...row,
            gamePieces: row.gamePieces
            |> List.map((field: gamePiece) => {
              let { x: fieldX, y: fieldY } = field;
              switch (fieldX, fieldY) {
                | (x, y) when
                  (x === selX && y === selY) || (x === capX && y === capY) => {
                  ...field,
                  player: Empty,
                  gamePieceState: Default 
                }
                | (x, y) when x === moveToX && y === moveToY => {
                  ...field,
                  player: switch state.gameState {
                    | Playing(Red) => Red
                    | _ => White
                  },
                  gamePieceState: Default 
                }
                | _ => { ...field, gamePieceState: Default }
              }
            })
          }
        });
        {
          checkerBoard: updatedBoard,
          gameState: switch state.gameState {
            | Playing(Red) => Playing(White)
            | Playing(White) => Playing(Red)
            // TODO: finish this logic.  Winner captures all other players'
            // pieces.
            | _ => Winner(Red) 
          }
        };
      }
    },
    initialState
  );

  let { checkerBoard } = state;
  <div>
    <div>
      <h3>
        {ReasonReact.string("Turn: ")}
        {
          switch state.gameState {
            | Playing(Red) => ReasonReact.string("Red")
            | Playing(White) => ReasonReact.string("White")
            | _ => ReasonReact.string("Someone Won!")
          }
        }
      </h3>
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
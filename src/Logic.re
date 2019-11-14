open Shared;

module Logic = {
  /**
   * Compute a list of integers starting with `start`,
   * up to and excluding `end_`.
   */
  let rec range = (start: int, end_: int) =>
  if (start >= end_) {
    [];
  } else {
    [start, ...range(start + 1, end_)];
  };

  let boardSize = range(0, 8);
  
  /**
   * Given X and Y, return a new gamePiece
   */
  let getGamePiece = (x, y, player) => {
    id: string_of_int(x) ++ string_of_int(y),
    x, y, player, gamePieceState: Default, kingStatus: Normal
  };

  let buildBoard = (_) => {
    let boardRow = (y, player) =>
      boardSize
      |> List.map((x: int) => {
        // DEBUG
        /* Js.log((x mod 2, y mod 2, x, y)); */
        switch (x mod 2, y mod 2) {
          | (0, 1)|(1, 0) => getGamePiece(x, y, player)
          | _ => getGamePiece(x, y, Empty)
        }
      });
  
    boardSize
    |> List.map((y: int) => {
      switch y {
        | 0|1|2 => boardRow(y, Red)
        | 5|6|7 => boardRow(y, White)
        | _ => List.map((x: int) => getGamePiece(x, y, Empty), boardSize)
      }
    })
    |> List.mapi((id: int, boardRow) => {
      id,
      gamePieces: boardRow
    });
  }

  let isMoveOnBoard = ((x, y)) => switch((x, y)) {
    | (-1, _)|(_, -1) => false
    | (x, _) when x === List.length(boardSize) => false
    | (_, y) when y === List.length(boardSize) => false
    | (_) => true
  }

  let findFieldById = (checkerBoard, id) =>
    checkerBoard
    |> List.map((row) => row.gamePieces)
    |> List.flatten
    |> List.find((gamePiece: gamePiece) => id === gamePiece.id);

  let isLegalMove = ((x, y), selX, selY, gameState: gameState, kingStatus) =>
    switch(x, y, gameState, kingStatus) {
      | (_, y, Playing(Red), Normal) when y > selY => true
      | (_, y, Playing(White), Normal) when y < selY => true
      | (_, _, _, King) => true
      | (_) => false
    }
  
  let isLandingEmpty = ((x, y), checkerBoard) => {
    let id = string_of_int(x) ++ string_of_int(y);
    let foundField = findFieldById(checkerBoard, id);
                  
    switch foundField.player {
      | Empty => true
      | _ => false
    };
  }
}

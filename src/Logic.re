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
  
  /**
   * Given X and Y, return a new gamePiece
   */
  let getGamePiece = (x, y, player) => {
    id: string_of_int(x) ++ string_of_int(y),
    x, y, player, gamePieceState: Default, kingStatus: Normal
  };

  let buildBoard = (_) => {
    let boardSize = range(0, 8);
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
}

open Shared;
open BoardFieldStyles;


[@react.component]
let make = (~onSelectGamePiece, ~onSlideGamePiece, ~gamePiece: gamePiece) => {
  let {x, y, player, gamePieceState} = gamePiece;
  let rowColTuple = (x mod 2, y mod 2);
  let squareColor = switch rowColTuple {
    | (0, 0) => Css.style(BoardFieldStyles.offWhite)
    | (1, 1) => Css.style(BoardFieldStyles.offWhite)
    | (_) => Css.style(BoardFieldStyles.green)
  };

  let gamePieceColor = switch player {
  | Red => Css.style(BoardFieldStyles.red)
  | White => Css.style(BoardFieldStyles.white)
  | Empty => ""
  };

  let gamePieceJsx = switch (player) {
  | Empty => ReasonReact.null
  | _ => {
    <div className=Css.style(BoardFieldStyles.gamePieceWrapper)>
      <div
        className=(String.concat(" ", [Css.style(BoardFieldStyles.gamePieceStyle), gamePieceColor]))
        onClick=((_) => onSelectGamePiece(gamePiece))
      />
    </div>
    }
  }

  let squareClassNames = [
    Css.style(BoardFieldStyles.square),
    squareColor
  ]
  |> String.concat(" ");

  <div className=squareClassNames>
    {
      switch gamePieceState {
        | ValidJump(_) => <div>{ReasonReact.string("FUCK")}</div>
        | Selected
        | ValidMove =>
          <div
            className=Css.style(BoardFieldStyles.activeField)
            onClick=((_) => onSlideGamePiece(gamePiece))
          />
        | _ => ReasonReact.null
      }
    }
    {gamePieceJsx}
  </div>;
}
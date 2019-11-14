open Shared;
open BoardFieldStyles;


[@react.component]
let make = (~onSelectGamePiece, ~onSlideGamePiece, ~gamePiece: gamePiece) => {
  let {x, y, player, gamePieceState, kingStatus} = gamePiece;
  let rowColTuple = (x mod 2, y mod 2);
  let squareColor = switch rowColTuple {
    | (0, 0) => Css.style(BoardFieldStyles.offWhite)
    | (1, 1) => Css.style(BoardFieldStyles.offWhite)
    | (_) => Css.style(BoardFieldStyles.green)
  };

  let kingClass = switch kingStatus {
    | King => Css.style(BoardFieldStyles.kingPiece)
    | _ => ""
  }

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
        className=(String.concat(" ", [
          Css.style(BoardFieldStyles.gamePieceStyle),
          gamePieceColor,
          kingClass,
        ]))
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
        | ValidJump(_)
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
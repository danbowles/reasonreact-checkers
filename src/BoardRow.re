open Shared;

let rowStyle = Css.[
  borderBottom(px(2), solid, hex("898989")),
  display(flexBox)
];

[@react.component]
let make = (~rowIndex, ~onSelectGamePiece, ~onSlideGamePiece, ~row: list(gamePiece)) =>
  <div className=Css.style(rowStyle)>
    (
      row
      |> List.mapi((colIndex: int, gamePiece: gamePiece) =>
        <BoardField
          key=(string_of_int(rowIndex) ++ string_of_int(colIndex))
          onSelectGamePiece
          onSlideGamePiece
          gamePiece
        />
      )
      |> Array.of_list
      |> ReasonReact.array
    )
  </div>;
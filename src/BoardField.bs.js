// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var Css = require("bs-css/src/Css.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var $$String = require("bs-platform/lib/js/string.js");
var BoardFieldStyles$ReactHooksTemplate = require("./styles/BoardFieldStyles.bs.js");

function BoardField(Props) {
  var onSelectGamePiece = Props.onSelectGamePiece;
  var onSlideGamePiece = Props.onSlideGamePiece;
  var gamePiece = Props.gamePiece;
  var gamePieceState = gamePiece[/* gamePieceState */4];
  var player = gamePiece[/* player */3];
  var rowColTuple_000 = gamePiece[/* x */1] % 2;
  var rowColTuple_001 = gamePiece[/* y */2] % 2;
  var match = rowColTuple_000;
  var squareColor = match !== 0 ? (
      match !== 1 || rowColTuple_001 !== 1 ? Css.style(BoardFieldStyles$ReactHooksTemplate.BoardFieldStyles[/* green */7]) : Css.style(BoardFieldStyles$ReactHooksTemplate.BoardFieldStyles[/* offWhite */5])
    ) : (
      rowColTuple_001 !== 0 ? Css.style(BoardFieldStyles$ReactHooksTemplate.BoardFieldStyles[/* green */7]) : Css.style(BoardFieldStyles$ReactHooksTemplate.BoardFieldStyles[/* offWhite */5])
    );
  var kingClass = gamePiece[/* kingStatus */5] ? "" : Css.style(BoardFieldStyles$ReactHooksTemplate.BoardFieldStyles[/* kingPiece */4]);
  var gamePieceColor;
  switch (player) {
    case 0 : 
        gamePieceColor = Css.style(BoardFieldStyles$ReactHooksTemplate.BoardFieldStyles[/* white */8]);
        break;
    case 1 : 
        gamePieceColor = Css.style(BoardFieldStyles$ReactHooksTemplate.BoardFieldStyles[/* red */6]);
        break;
    case 2 : 
        gamePieceColor = "";
        break;
    
  }
  var gamePieceJsx = player >= 2 ? null : React.createElement("div", {
          className: Css.style(BoardFieldStyles$ReactHooksTemplate.BoardFieldStyles[/* gamePieceWrapper */2])
        }, React.createElement("div", {
              className: $$String.concat(" ", /* :: */[
                    Css.style(BoardFieldStyles$ReactHooksTemplate.BoardFieldStyles[/* gamePieceStyle */3]),
                    /* :: */[
                      gamePieceColor,
                      /* :: */[
                        kingClass,
                        /* [] */0
                      ]
                    ]
                  ]),
              onClick: (function (param) {
                  return Curry._1(onSelectGamePiece, gamePiece);
                })
            }));
  var squareClassNames = $$String.concat(" ", /* :: */[
        Css.style(BoardFieldStyles$ReactHooksTemplate.BoardFieldStyles[/* square */0]),
        /* :: */[
          squareColor,
          /* [] */0
        ]
      ]);
  var tmp;
  var exit = 0;
  if (typeof gamePieceState === "number" && gamePieceState === 0) {
    tmp = null;
  } else {
    exit = 1;
  }
  if (exit === 1) {
    tmp = React.createElement("div", {
          className: Css.style(BoardFieldStyles$ReactHooksTemplate.BoardFieldStyles[/* activeField */1]),
          onClick: (function (param) {
              return Curry._1(onSlideGamePiece, gamePiece);
            })
        });
  }
  return React.createElement("div", {
              className: squareClassNames
            }, tmp, gamePieceJsx);
}

var make = BoardField;

exports.make = make;
/* Css Not a pure module */

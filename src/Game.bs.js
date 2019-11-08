// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var Css = require("bs-css/src/Css.js");
var List = require("bs-platform/lib/js/list.js");
var $$Array = require("bs-platform/lib/js/array.js");
var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Pervasives = require("bs-platform/lib/js/pervasives.js");
var Caml_builtin_exceptions = require("bs-platform/lib/js/caml_builtin_exceptions.js");
var Logic$ReactHooksTemplate = require("./Logic.bs.js");
var BoardRow$ReactHooksTemplate = require("./BoardRow.bs.js");

var initialState_000 = /* checkerBoard */Logic$ReactHooksTemplate.Logic[/* buildBoard */3](/* () */0);

var initialState_001 = /* gameState : Playing */Block.__(0, [/* Red */1]);

var initialState = /* record */[
  initialState_000,
  initialState_001
];

var gameOuter_000 = Css.border(Css.px(4), Css.solid, Css.hex("236253"));

var gameOuter_001 = /* :: */[
  Css.width(Css.px(400)),
  /* [] */0
];

var gameOuter = /* :: */[
  gameOuter_000,
  gameOuter_001
];

function Game(Props) {
  var match = React.useReducer((function (state, action) {
          if (action.tag) {
            var gamePieceToMove = action[0];
            var match = List.find((function (gamePiece) {
                    var match = gamePiece[/* gamePieceState */4];
                    if (typeof match === "number") {
                      return match === 1;
                    } else {
                      return false;
                    }
                  }), List.flatten(List.map((function (row) {
                            return row[/* gamePieces */1];
                          }), state[/* checkerBoard */0])));
            var selY = match[/* y */2];
            var selX = match[/* x */1];
            var match$1 = gamePieceToMove[/* gamePieceState */4];
            var match$2;
            if (typeof match$1 === "number") {
              match$2 = /* tuple */[
                -1,
                -1
              ];
            } else {
              var match$3 = match$1[0];
              match$2 = /* tuple */[
                match$3[0],
                match$3[1]
              ];
            }
            var moveToY = gamePieceToMove[/* y */2];
            var moveToX = gamePieceToMove[/* x */1];
            var capY = match$2[1];
            var capX = match$2[0];
            var updatedBoard = List.map((function (row) {
                    return /* record */[
                            /* id */row[/* id */0],
                            /* gamePieces */List.map((function (field) {
                                    var fieldY = field[/* y */2];
                                    var fieldX = field[/* x */1];
                                    if (fieldX === selX && fieldY === selY || fieldX === capX && fieldY === capY) {
                                      return /* record */[
                                              /* id */field[/* id */0],
                                              /* x */field[/* x */1],
                                              /* y */field[/* y */2],
                                              /* player : Empty */2,
                                              /* gamePieceState : Default */0,
                                              /* kingStatus */field[/* kingStatus */5]
                                            ];
                                    } else if (fieldX === moveToX && fieldY === moveToY) {
                                      var match = state[/* gameState */1];
                                      var tmp;
                                      tmp = match.tag || match[0] !== 1 ? /* White */0 : /* Red */1;
                                      return /* record */[
                                              /* id */field[/* id */0],
                                              /* x */field[/* x */1],
                                              /* y */field[/* y */2],
                                              /* player */tmp,
                                              /* gamePieceState : Default */0,
                                              /* kingStatus */field[/* kingStatus */5]
                                            ];
                                    } else {
                                      return /* record */[
                                              /* id */field[/* id */0],
                                              /* x */field[/* x */1],
                                              /* y */field[/* y */2],
                                              /* player */field[/* player */3],
                                              /* gamePieceState : Default */0,
                                              /* kingStatus */field[/* kingStatus */5]
                                            ];
                                    }
                                  }), row[/* gamePieces */1])
                          ];
                  }), state[/* checkerBoard */0]);
            var match$4 = state[/* gameState */1];
            var tmp;
            if (match$4.tag) {
              tmp = /* Winner */Block.__(1, [/* Red */1]);
            } else {
              switch (match$4[0]) {
                case 0 : 
                    tmp = /* Playing */Block.__(0, [/* Red */1]);
                    break;
                case 1 : 
                    tmp = /* Playing */Block.__(0, [/* White */0]);
                    break;
                case 2 : 
                    tmp = /* Winner */Block.__(1, [/* Red */1]);
                    break;
                
              }
            }
            return /* record */[
                    /* checkerBoard */updatedBoard,
                    /* gameState */tmp
                  ];
          } else {
            var selectedPiece = action[0];
            var match$5 = selectedPiece[/* player */3];
            var match$6 = state[/* gameState */1];
            var exit = 0;
            switch (match$5) {
              case 0 : 
                  if (match$6.tag || match$6[0] !== 1) {
                    exit = 1;
                  } else {
                    return state;
                  }
                  break;
              case 1 : 
                  if (match$6.tag || match$6[0] !== 0) {
                    exit = 1;
                  } else {
                    return state;
                  }
                  break;
              case 2 : 
                  exit = 1;
                  break;
              
            }
            if (exit === 1) {
              var gameState = state[/* gameState */1];
              var checkerBoard = state[/* checkerBoard */0];
              var selState = selectedPiece[/* gamePieceState */4];
              var selY$1 = selectedPiece[/* y */2];
              var selX$1 = selectedPiece[/* x */1];
              var adjecentSlideMoves_000 = /* tuple */[
                selX$1 + 1 | 0,
                selY$1 + 1 | 0
              ];
              var adjecentSlideMoves_001 = /* :: */[
                /* tuple */[
                  selX$1 + 1 | 0,
                  selY$1 - 1 | 0
                ],
                /* :: */[
                  /* tuple */[
                    selX$1 - 1 | 0,
                    selY$1 + 1 | 0
                  ],
                  /* :: */[
                    /* tuple */[
                      selX$1 - 1 | 0,
                      selY$1 - 1 | 0
                    ],
                    /* [] */0
                  ]
                ]
              ];
              var adjecentSlideMoves = /* :: */[
                adjecentSlideMoves_000,
                adjecentSlideMoves_001
              ];
              var kingStatus = selectedPiece[/* kingStatus */5];
              var validSlides = List.filter((function (param) {
                        return Logic$ReactHooksTemplate.Logic[/* isLandingEmpty */7](/* tuple */[
                                    param[0],
                                    param[1]
                                  ], checkerBoard);
                      }))(List.filter((function (param) {
                            return Logic$ReactHooksTemplate.Logic[/* isLegalMove */6](/* tuple */[
                                        param[0],
                                        param[1]
                                      ], selX$1, selY$1, gameState, kingStatus);
                          }))(List.filter(Logic$ReactHooksTemplate.Logic[/* isMoveOnBoard */4])(adjecentSlideMoves)));
              var buildJumps2 = function (_moves, _jumps, _selX, _selY, _rest) {
                while(true) {
                  var rest = _rest;
                  var selY = _selY;
                  var selX = _selX;
                  var jumps = _jumps;
                  var moves = _moves;
                  var id = String(selX) + String(selY);
                  var match = Logic$ReactHooksTemplate.Logic[/* findFieldById */5](checkerBoard, id);
                  var kingStatus = match[/* kingStatus */5];
                  var adjacentJumpMoves_000 = /* tuple */[
                    /* tuple */[
                      selX + 1 | 0,
                      selY + 1 | 0
                    ],
                    /* tuple */[
                      selX + 2 | 0,
                      selY + 2 | 0
                    ]
                  ];
                  var adjacentJumpMoves_001 = /* :: */[
                    /* tuple */[
                      /* tuple */[
                        selX + 1 | 0,
                        selY - 1 | 0
                      ],
                      /* tuple */[
                        selX + 2 | 0,
                        selY - 2 | 0
                      ]
                    ],
                    /* :: */[
                      /* tuple */[
                        /* tuple */[
                          selX - 1 | 0,
                          selY + 1 | 0
                        ],
                        /* tuple */[
                          selX - 2 | 0,
                          selY + 2 | 0
                        ]
                      ],
                      /* :: */[
                        /* tuple */[
                          /* tuple */[
                            selX - 1 | 0,
                            selY - 1 | 0
                          ],
                          /* tuple */[
                            selX - 2 | 0,
                            selY - 2 | 0
                          ]
                        ],
                        /* [] */0
                      ]
                    ]
                  ];
                  var adjacentJumpMoves = /* :: */[
                    adjacentJumpMoves_000,
                    adjacentJumpMoves_001
                  ];
                  var validLandings = List.filter((function (param) {
                            var match = param[1];
                            return Logic$ReactHooksTemplate.Logic[/* isLandingEmpty */7](/* tuple */[
                                        match[0],
                                        match[1]
                                      ], checkerBoard);
                          }))(List.filter((function (param) {
                                var match = param[0];
                                var id = String(match[0]) + String(match[1]);
                                var foundField = Logic$ReactHooksTemplate.Logic[/* findFieldById */5](checkerBoard, id);
                                var match$1 = foundField[/* player */3];
                                switch (match$1) {
                                  case 0 : 
                                      if (gameState.tag) {
                                        return false;
                                      } else {
                                        return gameState[0] === 1;
                                      }
                                  case 1 : 
                                      if (gameState.tag) {
                                        return false;
                                      } else {
                                        return gameState[0] === 0;
                                      }
                                  case 2 : 
                                      return false;
                                  
                                }
                              }))(List.filter((function(selX,selY,kingStatus){
                                return function (param) {
                                  var match = param[0];
                                  return Logic$ReactHooksTemplate.Logic[/* isLegalMove */6](/* tuple */[
                                              match[0],
                                              match[1]
                                            ], selX, selY, gameState, kingStatus);
                                }
                                }(selX,selY,kingStatus)))(List.filter((function (param) {
                                        var match = param[1];
                                        return Logic$ReactHooksTemplate.Logic[/* isMoveOnBoard */4](/* tuple */[
                                                    match[0],
                                                    match[1]
                                                  ]);
                                      }))(List.filter((function (param) {
                                            var match = param[0];
                                            return Logic$ReactHooksTemplate.Logic[/* isMoveOnBoard */4](/* tuple */[
                                                        match[0],
                                                        match[1]
                                                      ]);
                                          }))(adjacentJumpMoves)))));
                  if (validLandings) {
                    var tail = validLandings[1];
                    var match$1 = validLandings[0];
                    var match$2 = match$1[1];
                    var ly = match$2[1];
                    var lx = match$2[0];
                    var capture = match$1[0];
                    if (tail) {
                      _rest = Pervasives.$at(rest, List.map((function(moves,jumps,capture){
                              return function (param) {
                                var match = param[1];
                                var ly2 = match[1];
                                var lx2 = match[0];
                                return /* record */[
                                        /* moves */Pervasives.$at(moves, /* :: */[
                                              /* record */[
                                                /* captures */Pervasives.$at(jumps, /* :: */[
                                                      capture,
                                                      /* [] */0
                                                    ]),
                                                /* landingX */lx2,
                                                /* landingY */ly2
                                              ],
                                              /* [] */0
                                            ]),
                                        /* jumps */Pervasives.$at(jumps, /* :: */[
                                              param[0],
                                              /* [] */0
                                            ]),
                                        /* selX */lx2,
                                        /* selY */ly2
                                      ];
                              }
                              }(moves,jumps,capture)), tail));
                      _selY = ly;
                      _selX = lx;
                      _jumps = Pervasives.$at(jumps, /* :: */[
                            capture,
                            /* [] */0
                          ]);
                      _moves = Pervasives.$at(moves, /* :: */[
                            /* record */[
                              /* captures */Pervasives.$at(jumps, /* :: */[
                                    capture,
                                    /* [] */0
                                  ]),
                              /* landingX */lx,
                              /* landingY */ly
                            ],
                            /* [] */0
                          ]);
                      continue ;
                    } else {
                      _selY = ly;
                      _selX = lx;
                      _jumps = Pervasives.$at(jumps, /* :: */[
                            capture,
                            /* [] */0
                          ]);
                      _moves = Pervasives.$at(moves, /* :: */[
                            /* record */[
                              /* captures */Pervasives.$at(jumps, /* :: */[
                                    capture,
                                    /* [] */0
                                  ]),
                              /* landingX */lx,
                              /* landingY */ly
                            ],
                            /* [] */0
                          ]);
                      continue ;
                    }
                  } else if (rest) {
                    var tail$1 = rest[1];
                    var match$3 = rest[0];
                    var selY$1 = match$3[/* selY */3];
                    var selX$1 = match$3[/* selX */2];
                    var restJumps = match$3[/* jumps */1];
                    if (tail$1) {
                      _rest = tail$1;
                      _selY = selY$1;
                      _selX = selX$1;
                      _jumps = Pervasives.$at(jumps, restJumps);
                      _moves = Pervasives.$at(moves, match$3[/* moves */0]);
                      continue ;
                    } else {
                      _rest = /* [] */0;
                      _selY = selY$1;
                      _selX = selX$1;
                      _jumps = restJumps;
                      _moves = Pervasives.$at(moves, /* :: */[
                            /* record */[
                              /* captures */restJumps,
                              /* landingX */selX$1,
                              /* landingY */selY$1
                            ],
                            /* [] */0
                          ]);
                      continue ;
                    }
                  } else {
                    return moves;
                  }
                };
              };
              var buildJumps = function (_param, _validJumps, _remainingJumps) {
                while(true) {
                  var param = _param;
                  var remainingJumps = _remainingJumps;
                  var validJumps = _validJumps;
                  var selY = param[1];
                  var selX = param[0];
                  var id = String(selX) + String(selY);
                  var match = Logic$ReactHooksTemplate.Logic[/* findFieldById */5](checkerBoard, id);
                  var kingStatus = match[/* kingStatus */5];
                  var adjacentJumpMoves_000 = /* tuple */[
                    /* tuple */[
                      selX + 1 | 0,
                      selY + 1 | 0
                    ],
                    /* tuple */[
                      selX + 2 | 0,
                      selY + 2 | 0
                    ]
                  ];
                  var adjacentJumpMoves_001 = /* :: */[
                    /* tuple */[
                      /* tuple */[
                        selX + 1 | 0,
                        selY - 1 | 0
                      ],
                      /* tuple */[
                        selX + 2 | 0,
                        selY - 2 | 0
                      ]
                    ],
                    /* :: */[
                      /* tuple */[
                        /* tuple */[
                          selX - 1 | 0,
                          selY + 1 | 0
                        ],
                        /* tuple */[
                          selX - 2 | 0,
                          selY + 2 | 0
                        ]
                      ],
                      /* :: */[
                        /* tuple */[
                          /* tuple */[
                            selX - 1 | 0,
                            selY - 1 | 0
                          ],
                          /* tuple */[
                            selX - 2 | 0,
                            selY - 2 | 0
                          ]
                        ],
                        /* [] */0
                      ]
                    ]
                  ];
                  var adjacentJumpMoves = /* :: */[
                    adjacentJumpMoves_000,
                    adjacentJumpMoves_001
                  ];
                  var currentJumps = Pervasives.$at(remainingJumps, List.filter((function (param) {
                                var match = param[1];
                                return Logic$ReactHooksTemplate.Logic[/* isLandingEmpty */7](/* tuple */[
                                            match[0],
                                            match[1]
                                          ], checkerBoard);
                              }))(List.filter((function (param) {
                                    var match = param[0];
                                    var id = String(match[0]) + String(match[1]);
                                    var foundField = Logic$ReactHooksTemplate.Logic[/* findFieldById */5](checkerBoard, id);
                                    var match$1 = foundField[/* player */3];
                                    switch (match$1) {
                                      case 0 : 
                                          if (gameState.tag) {
                                            return false;
                                          } else {
                                            return gameState[0] === 1;
                                          }
                                      case 1 : 
                                          if (gameState.tag) {
                                            return false;
                                          } else {
                                            return gameState[0] === 0;
                                          }
                                      case 2 : 
                                          return false;
                                      
                                    }
                                  }))(List.filter((function(selX,selY,kingStatus){
                                    return function (param) {
                                      var match = param[0];
                                      return Logic$ReactHooksTemplate.Logic[/* isLegalMove */6](/* tuple */[
                                                  match[0],
                                                  match[1]
                                                ], selX, selY, gameState, kingStatus);
                                    }
                                    }(selX,selY,kingStatus)))(List.filter((function (param) {
                                            var match = param[1];
                                            return Logic$ReactHooksTemplate.Logic[/* isMoveOnBoard */4](/* tuple */[
                                                        match[0],
                                                        match[1]
                                                      ]);
                                          }))(List.filter((function (param) {
                                                var match = param[0];
                                                return Logic$ReactHooksTemplate.Logic[/* isMoveOnBoard */4](/* tuple */[
                                                            match[0],
                                                            match[1]
                                                          ]);
                                              }))(adjacentJumpMoves))))));
                  if (currentJumps) {
                    var match$1 = currentJumps[0][1];
                    _remainingJumps = currentJumps[1];
                    _validJumps = Pervasives.$at(currentJumps, validJumps);
                    _param = /* tuple */[
                      match$1[0],
                      match$1[1]
                    ];
                    continue ;
                  } else {
                    return validJumps;
                  }
                };
              };
              var validJumps = buildJumps(/* tuple */[
                    selX$1,
                    selY$1
                  ], /* [] */0, /* [] */0);
              var validJumps2 = buildJumps2(/* [] */0, /* [] */0, selX$1, selY$1, /* [] */0);
              console.log(validJumps2);
              var updatedBoard$1 = List.map((function (row) {
                      return /* record */[
                              /* id */row[/* id */0],
                              /* gamePieces */List.map((function (field) {
                                      var fieldState = field[/* gamePieceState */4];
                                      var fieldY = field[/* y */2];
                                      var fieldX = field[/* x */1];
                                      var exit = 0;
                                      var exit$1 = 0;
                                      if (typeof fieldState === "number" && fieldState === 0) {
                                        var tmp;
                                        try {
                                          List.find((function (param) {
                                                  var match = param[1];
                                                  if (match[0] === fieldX) {
                                                    return match[1] === fieldY;
                                                  } else {
                                                    return false;
                                                  }
                                                }), validJumps);
                                          tmp = true;
                                        }
                                        catch (exn){
                                          if (exn === Caml_builtin_exceptions.not_found) {
                                            tmp = false;
                                          } else {
                                            throw exn;
                                          }
                                        }
                                        if (tmp) {
                                          var tmp$1;
                                          var exit$2 = 0;
                                          var val;
                                          try {
                                            val = List.find((function (param) {
                                                    var match = param[1];
                                                    if (match[0] === fieldX) {
                                                      return match[1] === fieldY;
                                                    } else {
                                                      return false;
                                                    }
                                                  }), validJumps);
                                            exit$2 = 3;
                                          }
                                          catch (exn$1){
                                            if (exn$1 === Caml_builtin_exceptions.not_found) {
                                              tmp$1 = /* tuple */[
                                                -1,
                                                -1
                                              ];
                                            } else {
                                              throw exn$1;
                                            }
                                          }
                                          if (exit$2 === 3) {
                                            var match = val[0];
                                            tmp$1 = /* tuple */[
                                              match[0],
                                              match[1]
                                            ];
                                          }
                                          return /* record */[
                                                  /* id */field[/* id */0],
                                                  /* x */field[/* x */1],
                                                  /* y */field[/* y */2],
                                                  /* player */field[/* player */3],
                                                  /* gamePieceState : ValidJump */[tmp$1],
                                                  /* kingStatus */field[/* kingStatus */5]
                                                ];
                                        } else {
                                          var tmp$2;
                                          try {
                                            List.find((function (param) {
                                                    if (param[0] === fieldX) {
                                                      return param[1] === fieldY;
                                                    } else {
                                                      return false;
                                                    }
                                                  }), validSlides);
                                            tmp$2 = true;
                                          }
                                          catch (exn$2){
                                            if (exn$2 === Caml_builtin_exceptions.not_found) {
                                              tmp$2 = false;
                                            } else {
                                              throw exn$2;
                                            }
                                          }
                                          if (tmp$2) {
                                            return /* record */[
                                                    /* id */field[/* id */0],
                                                    /* x */field[/* x */1],
                                                    /* y */field[/* y */2],
                                                    /* player */field[/* player */3],
                                                    /* gamePieceState : ValidMove */2,
                                                    /* kingStatus */field[/* kingStatus */5]
                                                  ];
                                          } else {
                                            exit$1 = 2;
                                          }
                                        }
                                      } else {
                                        exit$1 = 2;
                                      }
                                      if (exit$1 === 2) {
                                        if (typeof selState === "number" && !(selState !== 0 || !(fieldX === selX$1 && fieldY === selY$1))) {
                                          return /* record */[
                                                  /* id */field[/* id */0],
                                                  /* x */field[/* x */1],
                                                  /* y */field[/* y */2],
                                                  /* player */field[/* player */3],
                                                  /* gamePieceState : Selected */1,
                                                  /* kingStatus */field[/* kingStatus */5]
                                                ];
                                        } else {
                                          exit = 1;
                                        }
                                      }
                                      if (exit === 1) {
                                        return /* record */[
                                                /* id */field[/* id */0],
                                                /* x */field[/* x */1],
                                                /* y */field[/* y */2],
                                                /* player */field[/* player */3],
                                                /* gamePieceState : Default */0,
                                                /* kingStatus */field[/* kingStatus */5]
                                              ];
                                      }
                                      
                                    }), row[/* gamePieces */1])
                            ];
                    }), checkerBoard);
              return /* record */[
                      /* checkerBoard */updatedBoard$1,
                      /* gameState */state[/* gameState */1]
                    ];
            }
            
          }
        }), initialState);
  var state = match[0];
  var dispatch = match[1];
  var match$1 = state[/* gameState */1];
  var tmp;
  if (match$1.tag) {
    tmp = "Someone Won!";
  } else {
    switch (match$1[0]) {
      case 0 : 
          tmp = "White";
          break;
      case 1 : 
          tmp = "Red";
          break;
      case 2 : 
          tmp = "Someone Won!";
          break;
      
    }
  }
  return React.createElement("div", undefined, React.createElement("div", undefined, React.createElement("h3", undefined, "Turn: ", tmp)), React.createElement("div", {
                  className: Css.style(gameOuter)
                }, $$Array.of_list(List.map((function (row) {
                            return React.createElement(BoardRow$ReactHooksTemplate.make, {
                                        rowIndex: row[/* id */0],
                                        onSelectGamePiece: (function (gamePiece) {
                                            return Curry._1(dispatch, /* SelectedGamePiece */Block.__(0, [gamePiece]));
                                          }),
                                        onSlideGamePiece: (function (gamePiece) {
                                            return Curry._1(dispatch, /* SlideGamePiece */Block.__(1, [gamePiece]));
                                          }),
                                        row: row[/* gamePieces */1],
                                        key: String(row[/* id */0])
                                      });
                          }), state[/* checkerBoard */0]))));
}

var make = Game;

exports.initialState = initialState;
exports.gameOuter = gameOuter;
exports.make = make;
/* initialState Not a pure module */

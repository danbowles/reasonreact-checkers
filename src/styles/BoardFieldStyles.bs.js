// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var Css = require("bs-css/src/Css.js");

var square_000 = Css.color(Css.white);

var square_001 = /* :: */[
  Css.display(Css.flexBox),
  /* :: */[
    Css.height(Css.px(50)),
    /* :: */[
      Css.position(Css.relative),
      /* :: */[
        Css.width(Css.px(50)),
        /* [] */0
      ]
    ]
  ]
];

var square = /* :: */[
  square_000,
  square_001
];

var activeField_000 = Css.background(Css.rgba(210, 54, 44, 0.7));

var activeField_001 = /* :: */[
  Css.height(Css.pct(100.0)),
  /* :: */[
    Css.position(Css.absolute),
    /* :: */[
      Css.width(Css.pct(100.0)),
      /* [] */0
    ]
  ]
];

var activeField = /* :: */[
  activeField_000,
  activeField_001
];

var gamePieceWrapper_000 = Css.boxSizing(Css.borderBox);

var gamePieceWrapper_001 = /* :: */[
  Css.height(Css.pct(100.0)),
  /* :: */[
    Css.padding(Css.px(10)),
    /* :: */[
      Css.width(Css.pct(100.0)),
      /* :: */[
        Css.zIndex(1),
        /* [] */0
      ]
    ]
  ]
];

var gamePieceWrapper = /* :: */[
  gamePieceWrapper_000,
  gamePieceWrapper_001
];

var gamePieceStyle_000 = Css.borderRadius(Css.pct(100.0));

var gamePieceStyle_001 = /* :: */[
  Css.height(Css.pct(100.0)),
  /* :: */[
    Css.position(Css.relative),
    /* :: */[
      Css.width(Css.pct(100.0)),
      /* [] */0
    ]
  ]
];

var gamePieceStyle = /* :: */[
  gamePieceStyle_000,
  gamePieceStyle_001
];

var kingPiece_000 = Css.after(/* :: */[
      Css.contentRule("\\2654"),
      /* :: */[
        Css.fontSize(Css.em(1.3)),
        /* :: */[
          Css.height(Css.pct(100.0)),
          /* :: */[
            Css.fontWeight(Css.extraBold),
            /* :: */[
              Css.left(Css.px(4)),
              /* :: */[
                Css.position(Css.absolute),
                /* :: */[
                  Css.top(Css.px(-2)),
                  /* [] */0
                ]
              ]
            ]
          ]
        ]
      ]
    ]);

var kingPiece = /* :: */[
  kingPiece_000,
  /* [] */0
];

var offWhite_000 = Css.backgroundColor(Css.hex("F2E786"));

var offWhite = /* :: */[
  offWhite_000,
  /* [] */0
];

var red_000 = Css.backgroundColor(Css.hex("990000"));

var red_001 = /* :: */[
  Css.after(/* :: */[
        Css.color(Css.white),
        /* [] */0
      ]),
  /* :: */[
    Css.boxShadows(/* :: */[
          Css.boxShadow(undefined, Css.px(2), Css.px(0), undefined, undefined, Css.hex("660000")),
          /* :: */[
            Css.boxShadow(undefined, Css.px(3), Css.px(5), undefined, undefined, Css.rgba(0, 0, 0, 0.3)),
            /* [] */0
          ]
        ]),
    /* [] */0
  ]
];

var red = /* :: */[
  red_000,
  red_001
];

var green_000 = Css.backgroundColor(Css.hex("638321"));

var green = /* :: */[
  green_000,
  /* [] */0
];

var white_000 = Css.backgroundColor(Css.white);

var white_001 = /* :: */[
  Css.after(/* :: */[
        Css.color(Css.hex("222222")),
        /* [] */0
      ]),
  /* :: */[
    Css.boxShadows(/* :: */[
          Css.boxShadow(undefined, Css.px(2), Css.px(0), undefined, undefined, Css.hex("cccccc")),
          /* :: */[
            Css.boxShadow(undefined, Css.px(3), Css.px(5), undefined, undefined, Css.rgba(0, 0, 0, 0.3)),
            /* [] */0
          ]
        ]),
    /* [] */0
  ]
];

var white = /* :: */[
  white_000,
  white_001
];

var BoardFieldStyles = /* module */[
  /* square */square,
  /* activeField */activeField,
  /* gamePieceWrapper */gamePieceWrapper,
  /* gamePieceStyle */gamePieceStyle,
  /* kingPiece */kingPiece,
  /* offWhite */offWhite,
  /* red */red,
  /* green */green,
  /* white */white
];

exports.BoardFieldStyles = BoardFieldStyles;
/* square Not a pure module */

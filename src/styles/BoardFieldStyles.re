module BoardFieldStyles = {
let square = Css.[
  color(white),
  display(flexBox),
  height(px(50)),
  position(relative),
  width(px(50))
];

let activeField =  Css.[
  background(rgba(210, 54, 44, 0.7)),
  height(pct(100.0)),
  position(absolute),
  width(pct(100.0)),
];

let gamePieceWrapper = Css.[
  boxSizing(borderBox),
  height(pct(100.0)),
  padding(px(10)),
  width(pct(100.0)),
  zIndex(1)
];
let gamePieceStyle = Css.[
  borderRadius(pct(100.0)),
  height(pct(100.0)),
  position(relative),
  width(pct(100.0)),
];

  let kingPiece = Css.[
    after([
      contentRule("\\2654"),
      fontSize(em(1.3)),
      height(pct(100.0)),
      fontWeight(extraBold),
      left(px(4)),
      position(absolute),
      top(px(-2)),
    ])
];

let offWhite = Css.[
  backgroundColor(hex("F2E786"))
];

let red = Css.[
  backgroundColor(hex("990000")),
  after([
    color(white),
    ]),
  boxShadows([
    boxShadow(~y=px(2), ~blur=px(0), hex("660000")),
    boxShadow(~y=px(3), ~blur=px(5), rgba(0, 0, 0, 0.3)),
  ]),
];

let green = Css.[
  backgroundColor(hex("638321"))
];

let white = Css.[
  backgroundColor(white),
  after([
    color(hex("222222")),
  ]),
  boxShadows([
    boxShadow(~y=px(2), ~blur=px(0), hex("cccccc")),
    boxShadow(~y=px(3), ~blur=px(5), rgba(0, 0, 0, 0.3)),
  ]),
];
};

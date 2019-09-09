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
  width(pct(100.0))
];

let offWhite = Css.[
  backgroundColor(hex("F2E786"))
];

let red = Css.[
  backgroundColor(hex("990000"))
];

let green = Css.[
  backgroundColor(hex("638321"))
];

let white = Css.[
  backgroundColor(white)
];
};
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
  // after([
  //   contentRule("\\2654"),
  //   fontSize(em(1.3)),
  //   height(pct(100.0)),
  //   fontWeight(extraBold),
  //   left(px(4)),
  //   position(absolute),
  //   top(px(-2)),
  // ])
];

// <style>
// .css-avmwmv::after {
//     content: "\2654";
//     position: absolute;
//     height: 100%;
//     width: 100%;
//     display: block;
//     text-align: center;
//     top: 0;
//     font-weight: 700;
//     font-size: 1.2em;
//     color: rgba(255,255,255,0.6);
//     text-shadow: -1px -1px 0 rgba(0, 0, 0, 0.8);

let offWhite = Css.[
  backgroundColor(hex("F2E786"))
];

let red = Css.[
  backgroundColor(hex("990000")),
  after([
    color(white)
  ]),
];

let green = Css.[
  backgroundColor(hex("638321"))
];

let white = Css.[
  backgroundColor(white),
  after([
    color(black)
  ]),
];
};
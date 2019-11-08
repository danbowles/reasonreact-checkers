type player =
| White
| Red
| Empty;

type gameState =
| Playing(player)
| Winner(player);

type kingStatus =
| King
| Normal;

type gamePieceState =
| Default
| Selected
| ValidMove
| ValidJump((int, int));

type gamePiece = {
  id: string,
  x: int,
  y: int,
  player,
  gamePieceState,
  kingStatus,
};

type checkerBoardRow = {
  id: int,
  gamePieces: list(gamePiece)
};

type checkerBoard = list(checkerBoardRow);

type state = {
  checkerBoard,
  gameState,
  /* TODO - Ideally, show how many of each player has been king'd/captured */
  // capturedAndKings: list(gamePieceState),
};

open Logic;
open Shared;

module TestBoards = {
  let singleJump: checkerBoard = [
    {
      id: 0,
      gamePieces: [
        Logic.getGamePiece(0, 0, Red),
        Logic.getGamePiece(1, 0, Empty),
        Logic.getGamePiece(2, 0, Empty),
      ]
    },
    {
      id: 1,
      gamePieces: [
        Logic.getGamePiece(0, 1, Empty),
        Logic.getGamePiece(1, 1, White),
        Logic.getGamePiece(2, 1, Empty),
      ]
    },
    {
      id: 2,
      gamePieces: [
        Logic.getGamePiece(0, 2, Empty),
        Logic.getGamePiece(1, 2, Empty),
        Logic.getGamePiece(2, 2, Empty),
      ]
    }
  ];

  let doubleJump: checkerBoard = [
    {
      id: 0,
      gamePieces: [
        Logic.getGamePiece(0, 0, Red),
        Logic.getGamePiece(1, 0, Empty),
        Logic.getGamePiece(2, 0, Empty),
        Logic.getGamePiece(3, 0, Empty),
        Logic.getGamePiece(4, 0, Empty),
        Logic.getGamePiece(5, 0, Empty),
        Logic.getGamePiece(6, 0, Empty),
        Logic.getGamePiece(7, 0, Empty),
      ]
    },
    {
      id: 1,
      gamePieces: [
        Logic.getGamePiece(0, 1, Empty),
        Logic.getGamePiece(1, 1, White),
        Logic.getGamePiece(2, 1, Empty),
        Logic.getGamePiece(3, 1, Empty),
        Logic.getGamePiece(4, 1, Empty),
        Logic.getGamePiece(5, 1, Empty),
        Logic.getGamePiece(6, 1, Empty),
        Logic.getGamePiece(7, 1, Empty),
      ]
    },
    {
      id: 2,
      gamePieces: [
        Logic.getGamePiece(0, 2, Empty),
        Logic.getGamePiece(1, 2, Empty),
        Logic.getGamePiece(2, 2, Empty),
        Logic.getGamePiece(3, 2, Empty),
        Logic.getGamePiece(4, 2, Empty),
        Logic.getGamePiece(5, 2, Empty),
        Logic.getGamePiece(6, 2, Empty),
        Logic.getGamePiece(7, 2, Empty),
      ]
    },
    {
      id: 3,
      gamePieces: [
        Logic.getGamePiece(0, 3, Empty),
        Logic.getGamePiece(1, 3, Empty),
        Logic.getGamePiece(2, 3, Empty),
        Logic.getGamePiece(3, 3, White),
        Logic.getGamePiece(4, 3, Empty),
        Logic.getGamePiece(5, 3, Empty),
        Logic.getGamePiece(6, 3, Empty),
        Logic.getGamePiece(7, 3, Empty),
      ]
    },
    {
      id: 4,
      gamePieces: [
        Logic.getGamePiece(0, 4, Empty),
        Logic.getGamePiece(1, 4, Empty),
        Logic.getGamePiece(2, 4, Empty),
        Logic.getGamePiece(3, 4, Empty),
        Logic.getGamePiece(4, 4, Empty),
        Logic.getGamePiece(5, 4, Empty),
        Logic.getGamePiece(6, 4, Empty),
        Logic.getGamePiece(7, 4, Empty),
      ]
    },
    {
      id: 5,
      gamePieces: [
        Logic.getGamePiece(0, 5, Empty),
        Logic.getGamePiece(1, 5, Empty),
        Logic.getGamePiece(2, 5, Empty),
        Logic.getGamePiece(3, 5, White),
        Logic.getGamePiece(4, 5, Empty),
        Logic.getGamePiece(5, 5, White),
        Logic.getGamePiece(6, 5, Empty),
        Logic.getGamePiece(7, 5, Empty),
      ]
    },
    {
      id: 6,
      gamePieces: [
        Logic.getGamePiece(0, 6, Empty),
        Logic.getGamePiece(1, 6, Empty),
        Logic.getGamePiece(2, 6, Empty),
        Logic.getGamePiece(3, 6, Empty),
        Logic.getGamePiece(4, 6, Empty),
        Logic.getGamePiece(5, 6, Empty),
        Logic.getGamePiece(6, 6, Red),
        Logic.getGamePiece(7, 6, Empty),
      ]
    },
    {
      id: 7,
      gamePieces: [
        Logic.getGamePiece(0, 7, Empty),
        Logic.getGamePiece(1, 7, Empty),
        Logic.getGamePiece(2, 7, Empty),
        Logic.getGamePiece(3, 7, Empty),
        Logic.getGamePiece(4, 7, Empty),
        Logic.getGamePiece(5, 7, Empty),
        Logic.getGamePiece(6, 7, Empty),
        Logic.getGamePiece(7, 7, Empty),
      ]
    },
  ]
  let kingDoubleJumps: checkerBoard = [
    {
      id: 0,
      gamePieces: [
        Logic.getGamePiece(0, 0, Empty),
        Logic.getGamePiece(1, 0, Empty),
        Logic.getGamePiece(2, 0, Empty),
        Logic.getGamePiece(3, 0, Empty),
        Logic.getGamePiece(4, 0, Empty),
        Logic.getGamePiece(5, 0, Empty),
        Logic.getGamePiece(6, 0, Empty),
        Logic.getGamePiece(7, 0, Empty),
      ]
    },
    {
      id: 1,
      gamePieces: [
        Logic.getGamePiece(0, 1, Empty),
        Logic.getGamePiece(1, 1, Empty),
        Logic.getGamePiece(2, 1, Empty),
        Logic.getGamePiece(3, 1, Empty),
        Logic.getGamePiece(4, 1, Empty),
        Logic.getGamePiece(5, 1, Empty),
        Logic.getGamePiece(6, 1, Empty),
        Logic.getGamePiece(7, 1, Empty),
      ]
    },
    {
      id: 2,
      gamePieces: [
        Logic.getGamePiece(0, 2, Empty),
        Logic.getGamePiece(1, 2, Empty),
        Logic.getGamePiece(2, 2, Empty),
        Logic.getGamePiece(3, 2, Empty),
        Logic.getGamePiece(4, 2, Empty),
        Logic.getGamePiece(5, 2, Empty),
        Logic.getGamePiece(6, 2, Empty),
        Logic.getGamePiece(7, 2, Empty),
      ]
    },
    {
      id: 3,
      gamePieces: [
        Logic.getGamePiece(0, 3, Empty),
        Logic.getGamePiece(1, 3, Empty),
        Logic.getGamePiece(2, 3, Empty),
        Logic.getGamePiece(3, 3, Empty),
        Logic.getGamePiece(4, 3, Empty),
        Logic.getGamePiece(5, 3, Empty),
        Logic.getGamePiece(6, 3, Empty),
        Logic.getGamePiece(7, 3, Empty),
      ]
    },
    {
      id: 4,
      gamePieces: [
        Logic.getGamePiece(0, 4, Empty),
        Logic.getGamePiece(1, 4, Empty),
        Logic.getGamePiece(2, 4, Empty),
        Logic.getGamePiece(3, 4, White),
        Logic.getGamePiece(4, 4, Empty),
        Logic.getGamePiece(5, 4, Empty),
        Logic.getGamePiece(6, 4, Empty),
        Logic.getGamePiece(7, 4, Empty),
      ]
    },
    {
      id: 5,
      gamePieces: [
        Logic.getGamePiece(0, 5, Empty),
        Logic.getGamePiece(1, 5, Empty),
        Logic.getGamePiece(2, 5, Empty),
        Logic.getGamePiece(3, 5, Empty),
        Logic.getGamePiece(4, 5, Empty),
        Logic.getGamePiece(5, 5, Empty),
        Logic.getGamePiece(6, 5, Empty),
        Logic.getGamePiece(7, 5, Empty),
      ]
    },
    {
      id: 6,
      gamePieces: [
        Logic.getGamePiece(0, 6, Empty),
        Logic.getGamePiece(1, 6, Empty),
        Logic.getGamePiece(2, 6, Empty),
        Logic.getGamePiece(3, 6, White),
        Logic.getGamePiece(4, 6, Empty),
        Logic.getGamePiece(5, 6, White),
        Logic.getGamePiece(6, 6, Empty),
        Logic.getGamePiece(7, 6, Empty),
      ]
    },
    {
      id: 7,
      gamePieces: [
        Logic.getGamePiece(0, 7, Empty),
        Logic.getGamePiece(1, 7, Empty),
        Logic.getGamePiece(2, 7, Empty),
        Logic.getGamePiece(3, 7, Empty),
        Logic.getGamePiece(4, 7, Red),
        Logic.getGamePiece(5, 7, Empty),
        Logic.getGamePiece(6, 7, Empty),
        Logic.getGamePiece(7, 7, Empty),
      ]
    },
  ]
}

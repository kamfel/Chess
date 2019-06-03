#include "pch.h"
#include "Fixtures/MockBoardFixture.h"
#include "Logic/Pieces/Pawn.h"
#include <vector>

using namespace testing;

struct ValidMoves {
	std::vector<sf::Vector2u> moves_for_11 = {
		()
	};
};

TEST_P(MockBoardFixture, GeneratedMovesForWhiteShouldBeValid) {
	Pawn pawn;
	pawn.Move(GetParam());
	pawn.SetColor(true);
	pawn.GeneratePossibleMoves(*shared_mock_board);


}
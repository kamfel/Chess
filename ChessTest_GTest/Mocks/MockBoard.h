#pragma once

#include "../pch.h"
#include "Logic/Board.h"

class MockBoard : public Board
{
public:
	
	MOCK_CONST_METHOD1(IsFieldEmpty, bool(const sf::Vector2u pos));
	MOCK_CONST_METHOD1(IsBlackPieceOnField, bool(const sf::Vector2u pos));
	MOCK_CONST_METHOD1(IsWhitePieceOnField, bool(const sf::Vector2u pos));

};
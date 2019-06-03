#pragma once
#include "pch.h"
#include "Mocks/MockBoard.h"
#include "gtest/gtest.h"

using namespace testing;

class MockBoardFixture : public TestWithParam<sf::Vector2u>
{
public:
	sf::Vector2u fields[9] = {
		sf::Vector2u(2, 0),
		sf::Vector2u(5, 1),
		sf::Vector2u(1, 3),
		sf::Vector2u(2, 3),
		sf::Vector2u(4, 4),
		sf::Vector2u(7, 4),
		sf::Vector2u(1, 5),
		sf::Vector2u(5, 5),
		sf::Vector2u(6, 7)
	};
public:
	static MockBoard* shared_mock_board;

	static void SetUpTestSuite() {
		shared_mock_board = new MockBoard();
	}

	static void TearDownTestSuite() {
		delete shared_mock_board;
		shared_mock_board = nullptr;
	}

	void SetUp() override {
		//For every empty field the mock method should return true
		EXPECT_CALL(*shared_mock_board, IsFieldEmpty(_))
			.WillRepeatedly(Return(true));

		//Listed fields arent empty and should return false
		for (int i = 0; i < 9; i++)
		{
			EXPECT_CALL(*shared_mock_board, IsFieldEmpty(fields[i]))
				.WillOnce(Return(false));
		}
	}
};

MockBoard* MockBoardFixture::shared_mock_board = nullptr;
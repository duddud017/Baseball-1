#include "pch.h"
#include "../BaseBallGame/baseball.cpp"

TEST(BaseBallGame, ThrowException) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), std::length_error);
}

TEST(BaseBallGame, ThrowExceptionWrongLetters) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12s")), std::invalid_argument);
}

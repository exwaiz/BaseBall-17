#include "pch.h"
#include "../BaseBall-17/baseball.cpp"

TEST(BaseballGame, ThrowExceptionWhenInputLengthIsUnmached) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}
TEST(BaseballGame, ThrowExceptionWhenInvalidChar) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12s")), invalid_argument);
}
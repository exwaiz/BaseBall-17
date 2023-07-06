#include "pch.h"
#include "../BaseBall-17/baseball.cpp"

class BaseballFixture : public testing::Test
{
public:
	Baseball game {"123"};
	/*explicit BaseballFixture(string guessNumber)
	{
		game = new game
		question = guessNumber;
	}*/
	void assertIllegalArgument(string guessNumber)
	{
		try
		{
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e)
		{
			//PASS
		}
	}
private:
	string  question;

};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
	assertIllegalArgument(string("12"));
	assertIllegalArgument(string("12s"));
	assertIllegalArgument(string("121"));
}
TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber) {
	GuessResult result = game.guess("123");
	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, Get2Strike0BallCase) {
	GuessResult result = game.guess("103");
	EXPECT_FALSE(result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);
}
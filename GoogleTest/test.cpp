#include "pch.h"
#include "../BaseBall-17/baseball.cpp"

class BaseballFixture : public testing::Test
{
public:
	Baseball game;
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
};


TEST_F(BaseballFixture, ThrowExceptionWhenInputLengthIsUnmached) {
	assertIllegalArgument(string("12"));
}
TEST_F(BaseballFixture, ThrowExceptionWhenInvalidChar) {
	assertIllegalArgument(string("12s"));
}
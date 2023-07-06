#include <iostream>
#include <string>
using namespace std;

struct GuessResult
{
	bool solved;
	int strikes;
	int balls;
};


class Baseball
{
public:

	explicit Baseball(const string& question) :
		question(question)
	{
		result = { false,0,0 };
	}

	bool isDuplicatedNumber(const string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}

	void assertIllegalArgument(const string& guessNumber)
	{
		if (guessNumber.length() != 3)
		{
			throw length_error("Must be three letters.");
		}

		for (char ch : guessNumber)
		{
			if ( ch >= '0' && ch <= '9')
				continue;
			throw invalid_argument("Must be number.");
		}
		if (isDuplicatedNumber(guessNumber))
		{
			throw invalid_argument("Must not have the same number.");
		}
	}

	int getStrikeCnt(const string& guessNumber)
	{
		int strike_cnt = 0;
		for (int i = 0; i < 3; i++)
		{
			if (guessNumber[i] == question[i])
				strike_cnt++;
		}
		return strike_cnt;
	}


	int getBallCnt(const string& guessNumber) {
		int ball_cnt = 0;
		for (int i = 0; i < guessNumber.size(); i++) {
			for (int x = 0; x < question.size(); x++) {
				if (i == x) continue;
				if (guessNumber[i] != question[x]) continue;
				ball_cnt++;
				break;
			}
		}
		return ball_cnt;
	}

	GuessResult guess(const string & guessNumber)
	{
		char guessN[3];
		assertIllegalArgument(guessNumber);
		if (guessNumber == question)
		{
			return { true, 3, 0 };
		}

		result.balls = getBallCnt(guessNumber);
		result.strikes = getStrikeCnt(guessNumber);
		result.solved = (result.strikes == 3 && result.balls == 0);

		return result;
	}
private:
	string question;
	GuessResult result;

};
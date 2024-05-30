#include <string>
#include <stdexcept>
using namespace std;

struct GuessResult{
	bool solved;
	int strikes;
	int balls;	
};

bool operator ==(const GuessResult t1, const GuessResult t2) {
	if (t1.solved == t2.solved &&
		t1.strikes == t2.strikes &&
		t1.balls == t2.balls)
		return true;
	return false;
}


int checkPos[3][2] = { {1,2}, {0,2},{0,1} };
class Baseball {
public:
	Baseball(string initialQuestion):
		question(initialQuestion) {
	}

	GuessResult guess(const string guessNumber) {
		assertIllegalArgument(guessNumber);
		if(question == guessNumber)
			return { true, 3, 0 };
		
		return { false, getStrikeCount(guessNumber), getBallCount(guessNumber) };
	}

	int getBallCount(const std::string& guessNumber)
	{
		int result{ 0 };
		for (int idx = 0; idx < 3; ++idx) {
			if (guessNumber[idx] == question[checkPos[idx][0]] ||
				guessNumber[idx] == question[checkPos[idx][1]])
				result++;
		}
		return result;
	}

	int getStrikeCount(const std::string& guessNumber)
	{
		int result{ 0 };
		for (int idx = 0; idx < 3; ++idx) {
			if (question[idx] == guessNumber[idx]) {
				result++;
			}
		}
		return result;
	}

	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.size() != 3)
			throw length_error("Must be 3 letters");

		for (char ch : guessNumber) {
			if (ch < '0' || ch > '9')
				throw invalid_argument("Must 0~9 letters valid");
		}

		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Need 3 different letters");
		}
	}

	bool isDuplicatedNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1] ||
			guessNumber[0] == guessNumber[2] ||
			guessNumber[1] == guessNumber[2];
	}
private:
	string question;

};
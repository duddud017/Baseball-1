#include <string>
#include <stdexcept>
using namespace std;

class Baseball {
public:
	void guess(const string guessNumber) {
		assertIllegalArgument(guessNumber);
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

};
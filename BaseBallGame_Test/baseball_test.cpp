#include "pch.h"
#include "../BaseBallGame/baseball.cpp"

class BaseBallFixture : public testing::Test {
public:
	Baseball game{ "123" };
	void assertIllegalArgument(string guessNumber) {
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e) {
			//PASS
		}
	}

	void checkGuessResult(string input, GuessResult expected) {
		GuessResult actual= game.guess(input);
		EXPECT_EQ(expected, actual);
	}
};

TEST_F(BaseBallFixture, ThrowExceptionTest) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

TEST_F(BaseBallFixture, StrikeTest) {
	checkGuessResult("143", { false,2,0 });
}

TEST_F(BaseBallFixture, BallTest) {
	checkGuessResult("192", { false,1,1 });
}

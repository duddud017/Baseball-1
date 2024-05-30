#include <string>
#include <stdexcept>
using namespace std;

class Baseball {
public:

	void guess(const string letters) {
		if(letters.size() != 3)
			throw length_error("Must be 3 letters");

		for (char ch : letters) {
			if (ch < '0' || ch > '9')
				throw invalid_argument("Must 0~9 letters valid");
		}
	}

};
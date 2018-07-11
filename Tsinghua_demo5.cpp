#include <iostream>
/*√∂æŸ–ÕΩÈ…‹*/

using namespace std;
enum GameResult {WIN, LOST, TIE, CANCEL};

int main()
{
	GameResult result;
	enum GameResult omit = CANCEL;
	for (int count = WIN; count <= CANCEL; count++)
	{
		result = GameResult(count);
		if (result == omit)
		{
			cout << "The game was cancelled." << endl;
		}
		else
		{
			cout << "The game was palyed";
			if (result == WIN)
				cout << " and we won!";
			if (result == LOST)
				cout << " and we lost.";
			if (result == TIE)
				cout << " and we tie.";
			cout << endl;
		}
	}
	return 0;
}
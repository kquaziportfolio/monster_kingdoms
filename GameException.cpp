#include "GameException.h"

GameException::GameException(string msg)
{
	message = msg;
}

string GameException::GetMessage() const
{
	return message;
}

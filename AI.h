//
// Created by Mitchell van Es on 11/07/2021.
//

#ifndef AI_H
#define AI_H

class GameHandler;

class AI {
public:
	AI(int instance);
	~AI();

	void setItsGameHandler(GameHandler* p_GameHandler);
	int generateMove();

private:
	GameHandler* itsGameHandler;
	int instance;
};


#endif //AI_H

#pragma once
#include <string>
#include <iostream>
#include "Field.h"
#include "ArrayList.h"
class GameManager
{
private:

	

	Field field;
	bool current_turn_is_cross;
	bool over;
	std::string turn_story;

	ArrayList<std::string> getLines(int x, int y) {
		ArrayList <std::string> res;
		res.insert("");
		res.insert("");
		res.insert("");
		res.insert("");
		int yT = fmin(y, 4);
		int yR = fmin(field.getSize() - x - 1, 4);
		int yB = fmin(field.getSize() - y - 1, 4);
		int yL = fmin(x, 4);



		for (int j = y - yT; j <= y + yB; j++)
			res[0] += std::to_string(field.get(x, j));
		for (int i = x - yL; i <= x + yR; i++)
			res[1] += std::to_string(field.get(i, y));
		for (int i = -fmin(yT, yL); i <= fmin(yR, yB); i++)
			res[2] += std::to_string(field.get(x + i, y + i));
		for (int i = -fmin(yB, yL); i <= fmin(yR, yT); i++)
			res[3] += std::to_string(field.get(x + i, y - i));
		return res;

	}

	std::string prrep(std::string item, int count) {
		std::string res = "";
		for (int i = 0; i < count; i++)
		{
			res += item;
		}

		return res;
	}

	bool windetect(int x, int y, int count = 0, int direction = 0, int what_search = 0) {
		if (what_search == 0) what_search = field.get(x, y);

		ArrayList<std::string> lines = getLines(x, y);
		std::string winpatern = prrep(std::to_string(what_search), 5);

		for (int i = 0; i < 4; i++)
		{
			if (lines[i].find(winpatern) != lines[i].npos) return true;
		}
		return false;

	}




public:


	GameManager(int size) {
		startup(size);

	}

	std::string getStory() {
		return turn_story;
	}
	void startup(int size) {
		field = new Field(size);
		turn_story = "";
		over = false;
		current_turn_is_cross = true;
	}
	void restart() {
		field.clear();
		turn_story = "";
		over = false;
		current_turn_is_cross = true;
	}

	int check() {
		
		for (int y = 0; y < field.getSize(); y++)
		{
			for (int x = 0; x < field.getSize(); x++)
			{
				if (x != 0 && field.get(x, y) == field.get(x - 1, y)) continue;
				if (windetect(x,y)) return field.get(x,y);
			
			}
		}


		return 0;
	}

	void gameOver(int result) {
		over = true;
		char a = (result == 1) ? ('X') : ('O');
		std::cout << "Game over! winner is " << a << std::endl;
		turn_story += "win #" + result;
	}
	bool isGameOver() { return over; }
	

	bool turn(int x, int y) {
		if (over || field.get(x, y) != 0) return false;
		field.set(x, y, current_turn_is_cross ? (1) : (2));
		turn_story += std::to_string(x) +":"+ std::to_string(y) + "\n";
		current_turn_is_cross = !current_turn_is_cross;
		int result = windetect(x,y);
		if (result != 0) gameOver(field.get(x,y));
		return true;
	}

	bool correct(int x, int y) {
		if (x < 0 || y < 0 || y >= field.getSize() || x >= field.getSize()) return false;
		return (field.get(x, y) == 0);
	}

	std::string print() {
		std::string  result = prrep(" ",1+std::to_string(field.getSize()).length());
		for (int i = 0; i < field.getSize(); i++)
		{
			result += " " +std::to_string(i) + prrep(" ", std::to_string(field.getSize()).length()- std::to_string(i).length());
		}
		result += "\n";
		for (int y = 0; y < field.getSize(); y++)
		{
			result += " " + std::to_string(y) + prrep(" ", std::to_string(field.getSize()).length() - std::to_string(y).length());
			for (int x = 0; x < field.getSize(); x++)
			{
				switch (field.get(x,y))
				{
				case 1:
					result += "[X]";
					break;
				case 2:
					result += "[O]";
					break;
				default:
					result += "[ ]";
					break;
				}
			}
			result += "\n";
		}
		return result;

	}




};


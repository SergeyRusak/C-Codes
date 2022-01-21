#pragma once
#include "Field.h"
#include "ArrayList.h"
#include <math.h>
#include "paterns.h"
#include "Move.h"


class GameAI
{
	Field field;
	ArrayList<Move> possible_moves, good_moves;
	bool my_turn_first = false;

	bool exist(ArrayList<Move> moves, Move move) {
		for (int i = 0; i < moves.getSize(); i++)
		{
			if ((move.x == moves[i].x) && (move.y == moves[i].y)) return true;
		}
		return false;
	}

	ArrayList<Move> findPosibles() {
		ArrayList<Move> possible = ArrayList<Move>();

		for (int i = 0; i < field.getSize(); i++)
		{
			for (int j = 0; j < field.getSize(); j++) {
				if (field.get(j, i) != 0) { // поиск всех доступных ходов
					if (j + 1 < field.getSize())
						if (field.get(j + 1, i) == 0)
							if (!exist(possible, Move(j + 1, i)))
								possible.insert(Move(j + 1, i));

					if (i + 1 < field.getSize())
						if (field.get(j , i+1) == 0)
							if (!exist(possible, Move(j , i+1)))
								possible.insert(Move(j , i+1));

					if (j - 1 >=0)
						if (field.get(j - 1, i) == 0)
							if (!exist(possible, Move(j - 1, i)))
								possible.insert(Move(j - 1, i));

					if (i - 1 >= 0)
						if (field.get(j, i-1) == 0)
							if (!exist(possible, Move(j, i-1)))
								possible.insert(Move(j, i-1));


					if (j + 1 < field.getSize() && i - 1 >= 0)
						if (field.get(j + 1, i - 1) == 0)
							if (!exist(possible, Move(j + 1, i - 1)))
								possible.insert(Move(j + 1, i - 1));

					if (i + 1 < field.getSize() && j + 1 < field.getSize())
						if (field.get(j + 1, i + 1) == 0)
							if (!exist(possible, Move(j + 1, i + 1)))
								possible.insert(Move(j + 1, i + 1));

					if (j - 1 >= 0 && i + 1 < field.getSize())
						if (field.get(j - 1, i + 1) == 0)
							if (!exist(possible, Move(j - 1, i + 1)))
								possible.insert(Move(j - 1, i + 1));

					if (i - 1 >= 0 && j - 1 >= 0)
						if (field.get(j - 1, i - 1) == 0)
							if (!exist(possible, Move(j - 1, i - 1)))
								possible.insert(Move(j - 1, i - 1));



					if (j + 2 < field.getSize())
						if (field.get(j + 2, i) == 0)
							if (!exist(possible, Move(j + 2, i)))
								possible.insert(Move(j + 2, i));

					if (i + 2 < field.getSize())
						if (field.get(j, i + 2) == 0)
							if (!exist(possible, Move(j, i + 2)))
								possible.insert(Move(j, i + 2));

					if (j - 2 >= 0)
						if (field.get(j - 2, i) == 0)
							if (!exist(possible, Move(j - 2, i)))
								possible.insert(Move(j - 2, i));

					if (i - 2 >= 0)
						if (field.get(j, i - 2) == 0)
							if (!exist(possible, Move(j, i - 2)))
								possible.insert(Move(j, i - 2));


					if (j + 2 < field.getSize() && i - 2 >= 0)
						if (field.get(j + 2, i - 2) == 0)
							if (!exist(possible, Move(j + 2, i - 2)))
								possible.insert(Move(j + 2, i - 2));

					if (i + 2 < field.getSize() && j + 2 < field.getSize())
						if (field.get(j + 2, i + 2) == 0)
							if (!exist(possible, Move(j + 2, i + 2)))
								possible.insert(Move(j + 2, i + 2));

					if (j - 2 >= 0 && i + 2 < field.getSize())
						if (field.get(j - 2, i + 2) == 0)
							if (!exist(possible, Move(j - 2, i + 2)))
								possible.insert(Move(j - 2, i + 2));

					if (i - 2 >= 0 && j - 2 >= 0)
						if (field.get(j - 2, i - 2) == 0)
							if (!exist(possible, Move(j - 2, i - 2)))
								possible.insert(Move(j - 2, i - 2));


				}





			}
			
		}

		return possible;
	}

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
			res[0] += (j == y) ? "7" : std::to_string(field.get(x,j));
		for (int i = x - yL; i <= x + yR; i++)
			res[1] += (i == x) ? "7" : std::to_string(field.get(y,i));
		for (int i = -fmin(yT, yL); i <= fmin(yR, yB); i++)
			res[2] += (i == 0) ? "7" : std::to_string(field.get(y + i,x + i));
		for (int i = -fmin(yB, yL); i <= fmin(yR, yT); i++)
			res[3] += (i == 0) ? "7" : std::to_string(field.get(y - i,x + i));
		return res;

	}

	void analysisMoves() {
		paterns pt;
		possible_moves = findPosibles();
		for (int i = 0; i < possible_moves.getSize(); i++)
		{
			ArrayList<std::string> lines = getLines(possible_moves[i].x, possible_moves[i].y);
			int score1 = 0;
			int score2 = 0;
			
			for (int i = 0; i < 4; i++)
			{
				score1 += pt.getScore(lines[i], 1);
				score2 += pt.getScore(lines[i], 2);
			}

			if (my_turn_first) {
				possible_moves[i].att = score1;
				possible_moves[i].def = score2;
			}
			else {
				possible_moves[i].att = score2;
				possible_moves[i].def = score1;

			}


		}



	}

	void updateGoodMoves() {
		ArrayList<Move> good = ArrayList<Move>();
		
		int maxScore = 0;
		for (int i = 0; i < possible_moves.getSize(); i++)
		{
			if (possible_moves[i].att + possible_moves[i].def > maxScore) maxScore = possible_moves[i].att + possible_moves[i].def;
		}
		maxScore = 0.9 * maxScore;
		for (int i = 0; i < possible_moves.getSize(); i++)
		{
			if (possible_moves[i].att + possible_moves[i].def >= maxScore) good.insert(possible_moves[i]);
		}


		good_moves = good;
	}

	std::string prrep(std::string item, int count) {
		std::string res = "";
		for (int i = 0; i < count; i++)
		{
			res += item;
		}

		return res;
	}
public:
	GameAI(int n = 5) {
		field = new Field(n);
		possible_moves = new ArrayList<Move>();
		good_moves = new ArrayList<Move>();

	}

	std::string print() {
		std::string  result = prrep(" ", 1 + std::to_string(field.getSize()).length());
		for (int i = 0; i < field.getSize(); i++)
		{
			result += " " + std::to_string(i) + prrep(" ", std::to_string(field.getSize()).length() - std::to_string(i).length());
		}
		result += "\n";
		for (int y = 0; y < field.getSize(); y++)
		{
			result += " " + std::to_string(y) + prrep(" ", std::to_string(field.getSize()).length() - std::to_string(y).length());
			for (int x = 0; x < field.getSize(); x++)
			{
				switch (field.get(x, y))
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

	Move generate(bool is_predict = false) { //первый ход в игре
		my_turn_first = true;

		if (!is_predict) field.set(7, 7, 1);
		return  Move(7, 7);
	}

	Move generate(int x, int y, bool is_predict = false) {
		if (my_turn_first)
			field.set(x, y, 2);
		else
			field.set(x, y, 1);

		possible_moves = findPosibles();
		analysisMoves();
		updateGoodMoves();





		if (good_moves.getSize() == 0)
			good_moves.insert(possible_moves[0]);
		int BAI(0), BDI(0), BAS(0), BDS(0);
		Move selected;
		for (int i = 0; i < good_moves.getSize(); i++)
		{
			if (BAS < good_moves[i].att) {
				BAI = i;
				BAS = good_moves[i].att;
			}
			if (BDS < good_moves[i].def) {
				BDI = i;
				BDS = good_moves[i].def;
			}
		}
		if (BAS >= BDS) selected = good_moves[BAI]; else selected = good_moves[BDI];





		//TODO: выбор лучшего хода из лучших ( или что-то интереснее)
		
		if (!is_predict) {
			if (!my_turn_first)
				field.set(selected.x, selected.y, 2);
			else
				field.set(selected.x, selected.y, 1);
		}
		return selected;



	}
};




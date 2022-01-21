#pragma once
#include "Field.h"
#include "ArrayList.h"
#include <math.h>
#include "paterns.h"
#include "Move.h"
#include <iostream>


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

	void addPosibleMove(int x, int y, ArrayList<Move>* arr) {
		if (x < 0 || x >= field.getSize() || y < 0 || y >= field.getSize()) return;
		if (field.get(x, y) == 0 && !exist(*arr, Move(x, y))) arr->insert(Move(x, y));
	}

	ArrayList<Move> findPosibles() {
		ArrayList<Move> possible = ArrayList<Move>();

		for (int i = 0; i < field.getSize(); i++)
		{
			for (int j = 0; j < field.getSize(); j++) {
				if (field.get(j, i) != 0) { // ����� ���� ��������� �����
					addPosibleMove(j + 1, i    , &possible);
					addPosibleMove(j - 1, i    , &possible);
					addPosibleMove(j    , i + 1, &possible);
					addPosibleMove(j    , i - 1, &possible);
					addPosibleMove(j + 1, i + 1, &possible);
					addPosibleMove(j + 1, i - 1, &possible);
					addPosibleMove(j - 1, i + 1, &possible);
					addPosibleMove(j - 1, i - 1, &possible);
					addPosibleMove(j + 2, i    , &possible);
					addPosibleMove(j - 2, i    , &possible);
					addPosibleMove(j    , i + 2, &possible);
					addPosibleMove(j    , i - 2, &possible);
					addPosibleMove(j + 2, i + 2, &possible);
					addPosibleMove(j + 2, i - 2, &possible);
					addPosibleMove(j - 2, i + 2, &possible);
					addPosibleMove(j - 2, i - 2, &possible);

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
			res[1] += (i == x) ? "7" : std::to_string(field.get(i,y));
		for (int i = -fmin(yT, yL); i <= fmin(yR, yB); i++)
			res[2] += (i == 0) ? "7" : std::to_string(field.get(x + i,y + i));
		for (int i = -fmin(yB, yL); i <= fmin(yR, yT); i++)
			res[3] += (i == 0) ? "7" : std::to_string(field.get(x + i,y - i));
		return res;

	}

	void analysisMoves(int my_tile) {
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

			if (my_tile == 1) {
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


	void addturn(int x, int y, int type) {
		field.set(x, y, type);
	}


	Move generate(bool first_turn,int my_tile, bool is_predict) {
		my_turn_first = first_turn;

		if (!is_predict && first_turn) {
			field.set(field.getSize() / 2, field.getSize() / 2, 1);
			return  Move(field.getSize() / 2, field.getSize() / 2);
		}

		possible_moves = findPosibles();
		analysisMoves(my_tile);
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





		//TODO: ����� ������� ���� �� ������ ( ��� ���-�� ����������)
		
		if (!is_predict) {
				field.set(selected.x, selected.y, my_tile);
		}
		else {
			std::cout << "Predicted turns:";
			for (int i = 0; i < good_moves.getSize(); i++)
			{
				std::cout << "[" << good_moves[i].x << ":" << good_moves[i].y << "]";
			}
			std::cout << std::endl;
		}
		return selected;



	}
};




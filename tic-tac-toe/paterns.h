#pragma once
#include <string>
#include "ArrayList.h"
class element {
public:
	int score;
	std::string patern;

	element(int sc=0, std::string pt="") {
		score = sc;
		patern = pt;
	}
};

class paterns
{
public:
	ArrayList<element> elems;
	std::string empty;

	paterns() {
		init();
	}

	void init() {

		elems = new ArrayList<element>();
		elems.insert(element(99999, "xxxxx"));
		elems.insert(element(7000, "0xxxx0"));
		elems.insert(element(4000, "0xxxx" ));
		elems.insert(element(4000, "xxxx0" ));
		elems.insert(element(2000, "0x0xxx"));
		elems.insert(element(2000, "xxx0x0"));
		elems.insert(element(2000, "0xx0xx"));
		elems.insert(element(2000, "xx0xx0"));
		elems.insert(element(2000, "0xxx0x"));
		elems.insert(element(2000, "x0xxx0"));
		elems.insert(element(3000, "0xxx0" ));
		elems.insert(element(1500, "0xxx"  ));
		elems.insert(element(1500, "xxx0"  ));
		elems.insert(element(800,  "0xx0x" ));
		elems.insert(element(800,  "x0xx0" ));
		elems.insert(element(800,  "0x0xx" ));
		elems.insert(element(800,  "xx0x0" ));
		elems.insert(element(200,  "0xx0"  ));
		elems.insert(element(100, "0xx"));
		elems.insert(element(100, "xx0"));

		empty = "000070000";

	}

	int getScore(std::string line, int main) {
		if (line == empty) return 0;
		size_t pos;
		while ((pos = line.find(std::to_string(main))) != line.npos)
			line.replace(pos, 1, "x");
		while ((pos = line.find("7")) != line.npos)
			line.replace(pos, 1, "0");
		int result = 2;
		for (int i = 0; i < elems.getSize(); i++)
		{
			if ((pos = line.find(elems[i].patern)) != line.npos) {
				result += elems[i].score;
			}
		}
		return result;
	}
	

	



 

};


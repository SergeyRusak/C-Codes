#pragma once
#include <string>
#include <fstream>

class TextFile
{
	std::string path;
	std::string path_tmp_file;
	char current_mode, origin_mode;
	std::ifstream input_file;
	std::ofstream output_file;
	bool is_temp;

public:
	TextFile(std::string path, char mode);// r - read, w - write
	TextFile(std::string path); //default read
	TextFile(const TextFile& file);
	TextFile();
	~TextFile();

	TextFile& operator = ( TextFile& file);
	TextFile operator +=(TextFile file);
	TextFile operator -=(TextFile file);
	TextFile operator +(TextFile file);
	TextFile operator -(TextFile file);
	TextFile operator +=(std::string text);
	TextFile operator -=(std::string text);



	bool belong(std::string text);
	void switch_mode(char next_mode);
	void switch_mode();
	char get_mode();
	bool good();
	bool save_file(std::string path);

	




};


#include "TextFile.h"
#include <iostream>



TextFile::TextFile(std::string path, char mode) {
	this->path = path;
	origin_mode = mode;
	if (mode == 'w') {
		output_file.open(path);
		current_mode = 'w';
	}
	else {
		input_file.open(path);
		current_mode = 'r';
	}
	is_temp = false;

}
TextFile::TextFile(std::string path) {
	this->path = path;
	origin_mode = 'r';
	input_file.open(path);
	current_mode = 'r';
	is_temp = false;
	
}
TextFile::TextFile() {
	std::srand(time(NULL));
	this->path = "../File/temp" +std::to_string( rand()) + ".dump";// генерация временного файла, который будет удалён в деструкторе
	origin_mode = 'w';
	output_file.open(path);
	current_mode = 'w';
	is_temp = true;

}

TextFile::TextFile(const TextFile& file) {
	this->path = file.path;
	origin_mode = file.origin_mode;
	if (file.current_mode == 'w') {
		output_file.open(path);
		current_mode = 'w';
	}
	else {
		input_file.open(path);
		current_mode = 'r';
	}
	is_temp =file.is_temp;
}



TextFile::~TextFile()
{
	if (input_file.is_open()) {
		input_file.close();
	}
	if (output_file.is_open()) {
		output_file.close();
	}
	if (is_temp) {
		std::remove(path.c_str());
	}


}











bool TextFile::belong(std::string text) // проверка на принадлежность строки к файлу
{
	switch_mode('r');
	bool unique = true;

	while (good()) {
		std::string line;
		do {
			std::getline(input_file, line);
		} while (line == "");
		if (line == text) {
			unique = false;
			break;
		}

	}
	return !unique; // belongs - пренадлежать; unique - уникальный => инвертируем результат
}

void TextFile::switch_mode(char next_mode) // переключение режима с чтения в режим записи и наоборот
{
	if (next_mode != current_mode) {
		if (next_mode == 'w') {
			input_file.close();
			output_file.open(path);
			current_mode = 'w';
		}
		else {
			output_file.close();
			input_file.open(path);
			current_mode = 'r';
		}


	}
}

void TextFile::switch_mode()  // сброс режима до origin_mode
{
	if (origin_mode != current_mode) {
		if (current_mode == 'r') {
			input_file.close();
			output_file.open(path, std::ios_base::app);
			current_mode = 'w';
		}
		else {
			output_file.close();
			input_file.open(path);
			current_mode = 'r';
		}

	}
}

char TextFile::get_mode()
{
	return current_mode;
}

bool TextFile::good()
{
	if (current_mode == 'r') return input_file.good();
	else return output_file.good();
	
}




TextFile TextFile::operator +=(std::string text) {
	std::cout << text << std::endl;
	if (!belong(text)) {
		switch_mode('w');
		if (text[text.size() - 1] != '\n') text.append("\n");
		output_file << text;

	}
	return *this;
}




TextFile& TextFile::operator=(TextFile& file)
{
	if (this == &file)return *this;
	path = file.path;
	is_temp = file.is_temp;
	origin_mode = file.origin_mode;
	current_mode = file.current_mode;
	if (current_mode == 'w') {
		output_file.open(path);
	}
	else {
		input_file.open(path);
	}
	return *this;
}

TextFile TextFile::operator+=(TextFile file)
{
	file.switch_mode('r');
	std::string text;
	while (file.good()) {
		std::getline(file.input_file, text);
	}while (text == "");
	*this += text;

	return *this;
}

TextFile TextFile::operator+ (TextFile file) {
	TextFile res(*this);
	res += file;
	return res;
}



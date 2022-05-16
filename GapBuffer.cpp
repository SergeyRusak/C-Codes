#include <string>
#include <iostream>
char buffer[50];


int gap_size = 10;

int gap_left = 0;
int gap_right = gap_size - gap_left - 1;

int size = 10;


void print(std::string msg) {
    std::cout << msg;
}
void print() {
    std::cout << "Output: ";
    for (int i = 0; i < size; i++) {
        std::cout << buffer[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

}

void grow(int k, int position)
{
    print("(grow)");

    char* a = new char[size];

   
    for (int i = position; i < size; i++) {
        a[i - position] = buffer[i];

    }

    
    for (int i = 0; i < k; i++) {
        buffer[i + position] = '_';
    }

    
    for (int i = 0; i < position + k; i++) {
        buffer[position + k + i] = a[i];
    }

    size += k;
    gap_right += k;
}

void left(int position)
{
    print("to left)");
    while (position < gap_left) {
        gap_left--;
        gap_right--;
        buffer[gap_right + 1] = buffer[gap_left];
        buffer[gap_left] = '_';
    }
}

void right(int position)
{
    print("to right)");
    while (position > gap_left) {
        gap_left++;
        gap_right++;
        buffer[gap_left - 1] = buffer[gap_right];
        buffer[gap_right] = '_';
    }
}

 
void move_cursor(int position)
{
    print("(move_cursor ");

    if (position < gap_left) {
        left(position);
    }
    else {
        right(position);
    }
}


void insert(std::string input, int position)
{
    print("(insert)");

    int len = input.length();
    int i = 0;

    if (position != gap_left) {
        move_cursor(position);
    }

    while (i < len) {
        if (gap_right == gap_left) {
            int k = 10;
            grow(k, gap_left);
        }

        buffer[gap_left] = input[i];
        gap_left++;
        i++;
        
    }
    print();
}
void insert(std::string input)
{
    print("(insert)");

    int len = input.length();
    int i = 0;

    while (i < len) {
        if (gap_right == gap_left) {
            int k = 10;
            grow(k, gap_left);
        }

        buffer[gap_left] = input[i];
        gap_left++;
        i++;
    }
    print();
}




int main()
{
    for (int i = 0; i < 10; i++) {
        buffer[i] = '_';
    }

    std::cout << "Initializing the gap buffer "<< "with size 10" << std::endl;
    print();
    
    insert("Test");

    insert("FOR");

    insert("Dummy", 0);


    move_cursor(10);
    print();

    insert("Stupid", 0);

    

    return 0;
}

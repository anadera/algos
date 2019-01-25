#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};
int main() {
    std::string text;
    int result = -1;
    int position = 0;
    getline(std::cin, text);
    std::stack <Bracket> opening_brackets_stack;
    while (position < text.length() && result == -1) {
        char next = text[position];
        //std::cout << "START LOOP: " << position << text[position] << "\n";
        if (next == '(' || next == '[' || next == '{')
        {
            // Process opening bracket, write your code here
            Bracket bracket(next, position);
            opening_brackets_stack.push(bracket);
        }
        else
        {
            if ((next == ')' || next == ']' || next == '}') && (!opening_brackets_stack.empty()) )
            {
                // Process closing bracket, write your code here
                Bracket b(opening_brackets_stack.top());
                opening_brackets_stack.pop();
                if (!b.Matchc(next))
                {
                    result = position + 1;
                }
            }
            else if ((next == ')' || next == ']' || next == '}') && (opening_brackets_stack.empty()) ) {
                result = position + 1;
            }
        }
        //std::cout << "FINISH LOOP: " << result << "\n";
        position ++;
    }
    if (result != -1)
    {
        std::cout << result << "\n";
        return 0;
    }
    else if ( not opening_brackets_stack.empty())
    {
        Bracket bb(opening_brackets_stack.top());
        opening_brackets_stack.pop();
        result = bb.position + 1;
        std::cout << result << "\n";
        return 0;
    }
    else
    {
        std::cout << "Success" << "\n";
        return 0;
    }
}
#include <iostream>
#include <vector>

class MaxStack
{
    std::vector<int> stack_;
    std::vector<int> max_stack_;

public:
    MaxStack(){};
    ~MaxStack(){};

    void push(int element)
    {
        if(max_stack_.empty()){
            max_stack_.push_back(element);
            stack_.push_back(element);
            return;
        }
        max_stack_.back() <= element? max_stack_.push_back(element):max_stack_.push_back(stack_.back());
        stack_.push_back(element);
    }

    int pop()
    {
        int last_element;

        if(stack_.empty()){
            std::cerr << "pop(): stack is empty!" << std::endl;
            return 0;
        }
        last_element = stack_.back();
        stack_.pop_back();
        max_stack_.pop_back();
        return last_element;
    }

    int max()
    {   
         if(max_stack_.empty()){
            std::cerr << "max(): stack is empty!" << std::endl;
            return 0;
        }     
        return max_stack_.back();
    }
};

int main()
{
    MaxStack max_stack;

    max_stack.pop();
    max_stack.max();

    max_stack.push(5);
    max_stack.push(3);
    max_stack.push(7);
    max_stack.push(1);

    std::cout << "Max Element ist " << max_stack.max() << " - richtiges Ergebnis ist 7" << std::endl;

    max_stack.pop();
    max_stack.pop();
    std::cout << "Max Element ist " << max_stack.max() << " - richtiges Ergebnis ist 5" << std::endl;

    return 0;
}
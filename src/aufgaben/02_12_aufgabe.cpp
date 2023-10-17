
#include <iostream>
#include <string>

class Tier
{
protected:
    int alter_;
public:
    Tier(){ alter_ = 10;};
    virtual ~Tier(){};

    void ausgabeTier() {
        std::cout << "Ich bin ein Tier." << std::endl;
    }
    int nenneAlter(){
        return alter_;
    }
    virtual void machGerausch() = 0;
};

class Tiger : public Tier{
public:
    Tiger(){alter_ = 15;};
    virtual ~Tiger(){};

    void machGerausch(){
        std::cout << "*Tigergeräusch*" << std::endl;
    }
};

class Elefant : public Tier{
public:
    Elefant(){alter_ = 30;};
    virtual ~Elefant(){};

    void machGerausch(){
        std::cout << "*Elefantengeräusch*" << std::endl;
    }
};

class Wolf : public Tier{
public:
    Wolf(){alter_ = 5;};
    virtual ~Wolf(){};

    void machGerausch(){
        std::cout << "*Wolfgeräusch*" << std::endl;
    }
};

int main()
{
    Tiger tiger;
    Elefant elefant;
    Wolf wolf;

    tiger.ausgabeTier();
    tiger.machGerausch();
    std::cout << "Ich bin " << tiger.nenneAlter() << " Jahre alt." << std::endl;
    elefant.ausgabeTier();
    elefant.machGerausch();
    std::cout << "Ich bin " << elefant.nenneAlter() << " Jahre alt." << std::endl;
    wolf.ausgabeTier();
    wolf.machGerausch();
    std::cout << "Ich bin " << wolf.nenneAlter() << " Jahre alt." << std::endl;

    return 0;
}
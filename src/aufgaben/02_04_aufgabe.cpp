#include <string>
#include <iostream>

class CaesarCipher{
    int key_ = 0;
    char first_upper_, first_lower_, last_upper_, last_lower_;

public:
    CaesarCipher(int key){
        setKey(key);
        first_upper_ = 'A';
        first_lower_ = 'a';
        last_upper_ = 'Z';
        last_lower_ = 'z';
    }
    void setKey(int key){
        key_ = key;
    }
    char encode(char character){
        if(isupper(character)){
            character = character + key_;
            if(character > last_upper_){
                character = first_upper_ + (character - last_upper_ - 1);
            }
        }else if (islower(character))
        {
            character = character + key_;
            if(character > last_lower_){
                character = first_lower_ + (character - last_lower_ - 1);
            }
        }
        
        return character;
    }
    char decode(char character){
        if(isupper(character)){
            character = character - key_;
            if(character < first_upper_){
                character = last_upper_ - (first_upper_ - character - 1);
            }
        }else if (islower(character))
        {
            character = character - key_;
            if(character > last_lower_){
                character = last_lower_ - (first_lower_ - character - 1);
            }
        }
        
        return character;
    }
};

std::string verschluesseln(std::string eingabe, int schluessel)
{
    std::string resultat("");
    CaesarCipher cc = CaesarCipher(schluessel);

    for(auto it=eingabe.begin();it!=eingabe.end();++it){
        resultat += cc.encode(*it);
    }

    return resultat;
}

std::string entschluesseln(std::string eingabe, int schluessel)
{
    CaesarCipher cc = CaesarCipher(schluessel);
    std::string resultat("");

    for(auto it=eingabe.begin();it!=eingabe.end();++it){
        resultat += cc.decode(*it);
    }

    return resultat;
}

int main()
{
    std::string eingabe("Koennen Sie diese Aufgabe loesen?");

    int schluessel = 3;
    std::string verschluesselte_eingabe = verschluesseln(eingabe, schluessel);
    std::string entluesselte_eingabe = entschluesseln(verschluesselte_eingabe, schluessel);

    std::cout << "Eingabe:                 " << eingabe << std::endl;
    std::cout << "Verschluesselte Eingabe: " << verschluesselte_eingabe << std::endl;
    std::cout << "Entschluesselte Eingabe: " << entluesselte_eingabe << std::endl;

    return 0;
}
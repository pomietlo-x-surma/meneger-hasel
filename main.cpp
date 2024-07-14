#include <regex>
#include <iostream>
#include <string>

bool pass_check(std::string password) {
    std::regex wzorzec_nalfa("[^a-zA-Z0-9\\s]"); // znak specjalny
    std::regex wzorzec_liczba("[0-9]");         // cyfra
    std::regex wzorzec_AZ("[A-Z]");             // duża litera
    std::regex wzorzec_az("[a-z]");             // mała litera
    std::regex wzorzec_rozmiar(".{8,50}");



    if (std::regex_search(password, wzorzec_nalfa) &&
        std::regex_search(password, wzorzec_liczba) &&
        std::regex_search(password, wzorzec_AZ) &&
        std::regex_search(password, wzorzec_az) &&
        std::regex_search(password, wzorzec_rozmiar)) {
        std::cout << "Haslo jest poprawne!" << std::endl;
        return true;
    }
    else {
        if (!std::regex_search(password, wzorzec_nalfa)) {
            std::cout << "Haslo musi zawierac przynajmniej jeden znak specjalny (np. !,@,#,$,%,^)!" << std::endl;
        }
        if (!std::regex_search(password, wzorzec_liczba)) {
            std::cout << "Haslo musi zawierac przynajmniej jedna liczbe!" << std::endl;
        }
        if (!std::regex_search(password, wzorzec_AZ)) {
            std::cout << "Haslo musi zawierac przynajmniej jedna wielka litere!" << std::endl;
        }
        if (!std::regex_search(password, wzorzec_az)) {
            std::cout << "Haslo musi zawierac przynajmniej jedna mala litere!" << std::endl;
        }
        if (!std::regex_search(password, wzorzec_rozmiar)) {
            if (password.length() < 8) {
                std::cout << "Haslo musi miec dlugosc przynajmniej 8 znakow!" << std::endl;
            }
            else {
                std::cout << "Zbyt dlugie haslo!" << std::endl;
            }

        }

    }
    return false;
}


int main() {
    std::string napis = "^8A2aaaaaaaaa";
    std::cout << pass_check(napis);


    return 0;
}

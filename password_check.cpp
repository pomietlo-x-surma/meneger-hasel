#include <password_check.h>
#include <regex>
#include <sstream>
#include <fstream>
#include <string>
#include <stream>
#include <iostream>


bool pass_check(std::string& password) {
    std::regex wzorzec_nalfa("[^a-zA-Z0-9\\s]"); // znak specjalny
    std::regex wzorzec_liczba("[0-9]");         // cyfra
    std::regex wzorzec_AZ("[A-Z]");             // du¿a litera
    std::regex wzorzec_az("[a-z]");             // ma³a litera
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


bool correct_password_check(const std::string& file_path, const std::string& site, const std::string& input_login, const std::string& input_pass) {
    std::ifstream file(file_path);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << file_path << " for reading." << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string stored_site, stored_login, stored_pass;

        std::getline(ss, stored_site, ',');
        std::getline(ss, stored_login, ',');
        std::getline(ss, stored_pass, ',');

        if (stored_site == site) {
            if (stored_login != input_login || stored_pass != input_pass) {
                std::cout << "Podany login lub has³o jest niepoprawne" << std::endl;
                file.close();
                return false;
            }
            else {
                file.close();
                return true;
            }
        }
    }

    file.close();
    return false;
}
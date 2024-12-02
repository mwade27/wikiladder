#include "wikiladder.h"
#include <iostream>



int main(){

    WikiLadder wikiLadder;
    //std::string pageTitle = "Soccer"; // Example page
    //std::string htmlContent = wikiLadder.fetchpagecontent(pageTitle);

    

    std::string startPage = "Dog";
    std::string endPage = "/wiki/Greeks";

    std::vector<std::string> ladder = wikiLadder.findLadder(startPage, endPage);

    if (!ladder.empty()) {
        std::cout << "Found ladder:\n";
        for (const std::string& step : ladder) {
            std::cout << step << "\n";
        }
    } else {
        std::cout << "No ladder found.\n";
    }
    /*
    std::string startPage, endPage;


    std::cout << "Enter a starting page: " << std::endl;

    std::cin >> startPage;

    std::cout << "Enter a end page: " << std::endl;

    std::cin >> endPage;
    */


}

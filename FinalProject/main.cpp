#include "wikiladder.h"
#include <iostream>



int main(){

    WikiLadder wikiLadder;
    std::string pageTitle = "Soccer"; // Example page
    std::string htmlContent = wikiLadder.fetchpagecontent(pageTitle);

    if (!htmlContent.empty()) {
        std::cout << "Fetched content for " << pageTitle << ":\n";
        std::cout << htmlContent.substr(0, 1000) << "...\n"; // Print first 500 characters
    } else {
        std::cout << "Failed to fetch content.\n";
    }

    std::vector<std::string> links = wikiLadder.parseLinks(htmlContent);

    for (const auto& link : links) {
        std::cout << link << std::endl;
    }
    /*
    std::string startPage, endPage;


    std::cout << "Enter a starting page: " << std::endl;

    std::cin >> startPage;

    std::cout << "Enter a end page: " << std::endl;

    std::cin >> endPage;
    */


}

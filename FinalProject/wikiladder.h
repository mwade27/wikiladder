#ifndef WIKILADDER_H
#define WIKILADDER_H
#include <string>
#include <vector>
#include <unordered_set>




class WikiLadder{

    public:
        WikiLadder();

        ~WikiLadder();

        /*
            gets page content of the wikipedia page       
        */
        std::string fetchpagecontent(const std::string& pageTitle);

        /*
            Parses links from the fetched wiki page 
        */
       std::vector<std::string> parseLinks(const std::string& htmlContent);

        /*
            Finds the ladder between the start and the target pages 
            implement the BFS algorithm 
            uses queue to track paths and unordered_set        
        */
        std::vector<std::string> findLadder(const std::string& startPage, const std::string& targetPage);

    private:

        //the unordered set has a faster time complexity then the vector, and should automatically ensure that all elements are unique
       std::unordered_set<std::string> visited;

        //helper function to validate the wiki link 
       bool isvalidlink (const std::string link);

        //base link to wiki
       const std::string baseURL = "https://en.wikipedia.org/wiki/";

};




#endif
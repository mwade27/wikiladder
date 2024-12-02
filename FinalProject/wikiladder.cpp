#include "wikiladder.h"
#include <queue>
#include<vector>
#include <curl/curl.h>
#include <sstream>
#include <string>
#include <iostream>
#include <regex>



WikiLadder::WikiLadder(){}

WikiLadder::~WikiLadder(){}

static size_t writeCallback(char* ptr, size_t size, size_t nmemb, std::string* data) {
    if (data) {
        data->append(ptr, size * nmemb);
        return size * nmemb; // Return the size of the data written
    }
    return 0; // If no data, return 0
}

std::string WikiLadder::fetchpagecontent(const std::string& pageTitle){
    std::string url = baseURL + pageTitle;
    //set up of curl pointer and 
    CURL* curl;
    CURLcode res; 
    //string to store wikipage content 
    std::string htmlContent;


    //intialize the curl 
    curl = curl_easy_init();

    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &htmlContent);



    
    res = curl_easy_perform(curl);


    if(res != CURLE_OK){
        std::cerr << "cURL error: " << curl_easy_strerror(res) << std::endl;
    }
        //clean up curl pointer
        curl_easy_cleanup(curl);
    }
    else{
        std::cerr << "Failed to intialize cURL" << std::endl;
    }


    
    //return content 
    return htmlContent;

}

std::vector<std::string> WikiLadder::parseLinks(const std::string& pageContent){
    //vector to store all links

    std::vector<std::string> links;

    //checks for patterns to find the links
   std::regex linkPattern(R"end(<a\s+href="(/wiki/[^"]+)")end");


    auto begin = std::sregex_iterator(pageContent.begin(), pageContent.end(), linkPattern);
    auto end = std::sregex_iterator();

    //loop for to add links to a vector
    for(auto it = begin; it != end; ++it){
        std::smatch match = *it;
        std::string link = match[1];


        //check links to filter them so there wont be so many add to the graph
        /*
            string::npos is the largest possible size you could return for a specific element
             in c++ 
            npos is used with find to help with the indexing
            
        */
        if( link.find("/wiki/Category:") != std::string::npos ||
            link.find("/wiki/Template:") != std::string::npos ||
            link.find("/wiki/Help:") != std::string::npos ||
            link.find("/wiki/File:") != std::string::npos ||
            link.find("/wiki/Talk:") != std::string::npos ||
            link.find("/wiki/List_of_") != std::string::npos ||
            link.find("/wiki/Wikipedia:") != std::string::npos ||
            link.find("/wiki/Portal:") != std::string::npos){
                continue;
            }

        
            links.push_back(link);
    }

    return links;
}



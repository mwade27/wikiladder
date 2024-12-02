#include "wikiladder.h"
#include <queue>
#include<vector>
#include <curl/curl.h>
#include <sstream>
#include <string>
#include <iostream>


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



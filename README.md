# WikiLadder



# Features
   Allows user to input a startpage and an endpage 
   and searches for the shortest path to the endpage 
   from the startpage

# 1. WikiLadder(Base Class)
  This class creates a wikiladder object to find shortest path between wiki sites.
## Key Methods:
### std::string fetchpagecontent(const std::string& pageTitle)
        This function get the html content from the 
        current page and save it all to a string 
        It uses the curl library to gather the 
        content and make the HTTPS request

   ### std::vector<std::string> WikiLadder::parseLinks(const std::string& pageContent)
        This function gathers all the links 
        from the html content by using  
        regex to find what is consider a link
        This function also filters out useless
        links 
   ### std::vector<std::string> WikiLadder::findLadder(const std::string& startPage, const std::string endPage)

   This function use Breadth First search to find the 
   shortest path between the startpage and the end page 
   the function returns a vector with the path from the 
   start to the finish


# Compilation Process
  use make to compile all files 
  

# Usage
 use make run 


# Future Improvements
    Make search for ladder faster 
    Could use threads to search 
    multiple pages at once 

    Use Natural Language processing and heuristics to 
    filter out more links so then we arent searching 
    and adding useless links
  
# Technologies used
  The entire program is written in C++20 utilizing standard libraries such iostream 
  vector, curl, and regex


# Repository Link 
https://github.com/mwade27/wikiladder.git
brew install curl

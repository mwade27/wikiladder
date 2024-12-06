# WikiLadder
The questions from the assignment are at the bottom


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
https://github.com/mwade27/CS300.git


## How did you Contribrute to the final Project
    I work on the entire project by myself
## How did your partener contribrute to the final project
    I did it by myself
## What is your biggest takeaway from this course 
     I would say my biggest takeway is how 
     I design and set up my projects. This class 
     has helped me to put more thought into 
     the way I write code 
## What is one you would change about this course
    I don't really have anything that i would 
    I really enjoyed course 









brew install curl

got cURL error: Timeout was reached 
probably due to the network being slow 
but gonna try to optimize the code to be faster 


So im running into the issue of the code just being really and using up alot memory the longer 
that it keeps running 

Some pontential solutions
Natural language processing could help with finding words closer to my target 
it could help by adding better links to lead to finding the target page faster
issue: i feel like it would take some time to learn, but could be very efficient 

if a human was playing the game, one could assume that they would know 
something about the topic they are trying to find 
so could we use the end page and check link from there to narrow down our 
links and which links are getting added to the queue 
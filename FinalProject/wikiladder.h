#ifndef WIKILADDER_H
#define WIKILADDER_H

#include <string>
#include <vector>
#include <unordered_set>

/// @class WikiLadder
/// @brief A class to find a ladder between two Wikipedia pages using the BFS algorithm.
class WikiLadder {

public:
    /// @brief Default constructor for WikiLadder.
    /// Initializes the WikiLadder object.
    WikiLadder();

    /// @brief Destructor for WikiLadder.
    /// Cleans up any resources if necessary.
    ~WikiLadder();

    /// @brief Fetches the HTML content of a Wikipedia page.
    /// 
    /// This method uses the curl/curl.h library to fetch the HTML content of the given
    /// Wikipedia page title.
    /// @param pageTitle The title of the Wikipedia page.
    /// @return A string containing the HTML content of the page.
    std::string fetchpagecontent(const std::string& pageTitle);

    /// @brief Parses the links from the fetched HTML content.
    ///
    /// This method extracts all the valid Wikipedia links from the given HTML content.
    /// @param htmlContent The HTML content of the page.
    /// @return A vector of strings containing the extracted links.
    std::vector<std::string> parseLinks(const std::string& htmlContent);

    /// @brief Finds the ladder (path) between two Wikipedia pages.
    ///
    /// This method implements the Breadth-First Search (BFS) algorithm to find the shortest
    /// path (ladder) between the start and target Wikipedia pages. It uses a queue to track
    /// the paths and an unordered set to track visited pages.
    /// @param startPage The starting Wikipedia page.
    /// @param targetPage The target Wikipedia page.
    /// @return A vector of strings representing the path from the start page to the target page.
    std::vector<std::string> findLadder(const std::string& startPage, const std::string& targetPage);

private:

    /// @brief The set of visited Wikipedia pages.
    /// 
    /// This unordered set is used to track the pages that have already been visited to avoid cycles.
    std::unordered_set<std::string> visited;

    /// @brief Ensures a Wikipedia link.
    ///
    /// This helper function checks whether a link is a valid Wikipedia link.
    /// @param link The link to be validated.
    /// @return True if the link is valid, false otherwise.
    bool isvalidlink(const std::string link);

    /// @brief The base URL for Wikipedia.
    ///
    /// This constant holds the base URL for Wikipedia used for fetching pages.
    const std::string baseURL = "https://en.wikipedia.org/wiki/";
};

#endif

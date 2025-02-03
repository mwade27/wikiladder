#include "gtest/gtest.h"
#include "WikiLadder.h" // Adjust the path as needed
#include <string>
#include <vector>

// Test for WikiLadder::fetchpagecontent
TEST(WikiLadderTest, FetchPageContent_ValidPage) {
    WikiLadder ladder;
    std::string content = ladder.fetchpagecontent("Dog");

    // Verify that the fetched content is not empty
    EXPECT_FALSE(content.empty());

    // Optionally, verify specific content (example may vary)
    EXPECT_NE(content.find("Dog"), std::string::npos);
}

// Test for WikiLadder::parseLinks
TEST(WikiLadderTest, ParseLinks_ValidContent) {
    WikiLadder ladder;
    std::string testContent = "<a href=\"/wiki/Dog\">Dog</a><a href=\"/wiki/Cat\">Cat</a>";
    std::vector<std::string> links = ladder.parseLinks(testContent);

    // Check the expected links
    std::vector<std::string> expectedLinks = {"/wiki/Dog", "/wiki/Cat"};
    EXPECT_EQ(links, expectedLinks);
}

// Test for WikiLadder::findLadder
TEST(WikiLadderTest, FindLadder_ValidPath) {
    WikiLadder ladder;
    std::string startPage = "Dog";
    std::string endPage = "Moose";

    std::vector<std::string> path = ladder.findLadder(startPage, endPage);

    // Check that the path starts with the start page and ends with the end page
    ASSERT_FALSE(path.empty());
    EXPECT_EQ(path.front(), startPage);
    EXPECT_EQ(path.back(), endPage);

    // Optionally, check the intermediate steps (adjust expectedPath as needed)
    std::vector<std::string> expectedPath = {"Dog", "Wolf", "Moose"};
    EXPECT_EQ(path, expectedPath);
}

// Test for edge cases
TEST(WikiLadderTest, FindLadder_NoPath) {
    WikiLadder ladder;
    std::string startPage = "Dog";
    std::string endPage = "NonExistentPage";

    std::vector<std::string> path = ladder.findLadder(startPage, endPage);

    // Verify that no path exists
    EXPECT_TRUE(path.empty());
}

TEST(WikiLadderTest, ParseLinks_EmptyContent) {
    WikiLadder ladder;
    std::string emptyContent = "";
    std::vector<std::string> links = ladder.parseLinks(emptyContent);

    // Verify that no links are returned for empty content
    EXPECT_TRUE(links.empty());
}

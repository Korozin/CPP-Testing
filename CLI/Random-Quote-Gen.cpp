#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <curl/curl.h>
#include "json.hpp"

using json = nlohmann::json;

// The callback function for curl to write the response into a string
static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    size_t realsize = size * nmemb;
    std::string* response = static_cast<std::string*>(userdata);
    response->append(ptr, realsize);
    return realsize;
}

int main() {
    // Initialize curl
    curl_global_init(CURL_GLOBAL_ALL);
    CURL* curl = curl_easy_init();

    // Set the options for the curl request
    std::string url = "https://type.fit/api/quotes";
    std::string response;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    // Perform the HTTP request
    CURLcode res = curl_easy_perform(curl);

    // Check if the request was successful
    if (res != CURLE_OK) {
        std::cerr << "Failed to fetch quotes: " << curl_easy_strerror(res) << std::endl;
        return 1;
    }

    // Clean up curl
    curl_easy_cleanup(curl);
    curl_global_cleanup();

    // Parse the JSON response into a vector of dictionaries
    auto quotes = json::parse(response);

    // Extract the text of each quote into a vector
    std::vector<std::string> quote_texts;
    for (auto& quote : quotes) {
        quote_texts.push_back(quote["text"]);
    }

    // Select a random quote
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, quote_texts.size()-1);
    std::string quote = quote_texts[dist(gen)];

    // Print the quote
    std::cout << quote << std::endl;

    return 0;
}

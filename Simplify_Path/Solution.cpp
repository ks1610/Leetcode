#include <iostream>
#include <string>
#include <deque>

std::string simplifyPath(std::string path) {
    std::deque<std::string> pathParts;
    size_t i = 0;

    while (i < path.size()) {
        // Skip multiple slashes
        while (i < path.size() && path[i] == '/') {
            ++i;
        }

        // Find the next part
        size_t start = i;
        while (i < path.size() && path[i] != '/') {
            ++i;
        }

        std::string part = path.substr(start, i - start);

        if (part == "..") {
            if (!pathParts.empty() && pathParts.back() != "..") {
                pathParts.pop_back();
            }
        } else if (!part.empty() && part != ".") {
            pathParts.push_back(part);
        }
    }

    // Construct the simplified path
    std::string simplifiedPath;
    for (const auto& part : pathParts) {
        simplifiedPath += "/" + part;
    }

    // Ensure the result is "/" if pathParts is empty
    if (simplifiedPath.empty()) {
        simplifiedPath = "/";
    }

    return simplifiedPath;
}

int main() {
    // Input string
    std::string input = "/.../a/../b/";

    // Call the simplifyPath function
    std::string result = simplifyPath(input);

    // Output the result
    std::cout << "Modified string: " << result << std::endl;

    return 0;
}

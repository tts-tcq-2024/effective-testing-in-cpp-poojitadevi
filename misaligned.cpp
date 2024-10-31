#include <iostream>
#include <assert.h>
#include <sstream>

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    return i * j;
}

// Test function that captures the output of printColorMap
void testPrintColorMap() {
    // Redirect std::cout to a stringstream to capture the output
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

    // Call the function and capture the output
    int result = printColorMap();

    // Restore std::cout
    std::cout.rdbuf(oldCout);

    // Check if the result is correct (25 entries)
    assert(result == 25);

    // Define the expected output (correct pairing of major and minor colors)
    const char* expectedOutput =
        "0 | White | Blue\n"
        "1 | White | Orange\n"
        "2 | White | Green\n"
        "3 | White | Brown\n"
        "4 | White | Slate\n"
        "5 | Red | Blue\n"
        "6 | Red | Orange\n"
        "7 | Red | Green\n"
        "8 | Red | Brown\n"
        "9 | Red | Slate\n"
        "10 | Black | Blue\n"
        "11 | Black | Orange\n"
        "12 | Black | Green\n"
        "13 | Black | Brown\n"
        "14 | Black | Slate\n"
        "15 | Yellow | Blue\n"
        "16 | Yellow | Orange\n"
        "17 | Yellow | Green\n"
        "18 | Yellow | Brown\n"
        "19 | Yellow | Slate\n"
        "20 | Violet | Blue\n"
        "21 | Violet | Orange\n"
        "22 | Violet | Green\n"
        "23 | Violet | Brown\n"
        "24 | Violet | Slate\n";

    // Compare the captured output with the expected output
    std::string actualOutput = buffer.str();
    assert(actualOutput.length() == std::strlen(expectedOutput)); // Check output length first

    // Ensure that each line in the output is correct by comparing line-by-line
    std::istringstream actualStream(actualOutput);
    std::istringstream expectedStream(expectedOutput);
    std::string actualLine, expectedLine;
    int lineCount = 0;

    while (std::getline(actualStream, actualLine) && std::getline(expectedStream, expectedLine)) {
        assert(actualLine == expectedLine && "Mismatch in color mapping output");
        lineCount++;
    }
    assert(lineCount == 25 && "Output should contain exactly 25 lines");

    std::cout << "Test passed. The color map is correct!\n";
}

int main() {
    testPrintColorMap();
    std::cout << "All is well (maybe!)\n";
    return 0;
}

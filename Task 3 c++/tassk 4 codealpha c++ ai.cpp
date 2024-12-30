#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <ctime>
#include <algorithm>

// AI Chatbot in C++
using namespace std;

// Global variable to store the user's name
string userName = "";

// ANSI escape codes for text colors
const string RESET = "\033[0m";
const string GREEN = "\033[32m";
const string CYAN = "\033[36m";
const string MAGENTA = "\033[35m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string RED = "\033[31m";
const string WHITE = "\033[97m";

// Helper function to convert input to lowercase for case-insensitive matching
void toLower(string &str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

// Function to print AI responses with a delay to simulate natural conversation
void printWithDelay(const string& message) {
    clock_t start_time = clock();
    while (clock() - start_time < 1 * CLOCKS_PER_SEC);  // Simulate typing delay
    cout << message << endl;
}

// Function to set the user's name if not already set
void setUserName() {
    if (userName.empty()) {
        printWithDelay(CYAN + "Hello, what's your name?" + RESET);
        cout << GREEN << "You: " << RESET;
        getline(cin, userName);
        toLower(userName);
        userName[0] = toupper(userName[0]);  // Capitalize first letter
        printWithDelay(MAGENTA + "Nice to meet you, " + userName + "!" + RESET);
    }
}

// Define a simple structure for a tree (graph) for more complex word relationships
struct TreeNode {
    string word;
    string response;
    vector<TreeNode*> children;
};

// Function to add a word and its response to the tree structure
void addToTree(TreeNode* root, const string& word, const string& response) {
    TreeNode* newNode = new TreeNode{word, response, {}};
    root->children.push_back(newNode);
}

// Function to find a word in the tree (graph) and return a response if found
string searchInTree(TreeNode* root, const string& word) {
    for (auto child : root->children) {
        if (child->word == word) {
            return child->response;
        }
    }
    return "";
}

// Function to respond with a generic message if a word is not found
string respondDefault() {
    return CYAN + "I'm sorry, I don't understand that. Could you rephrase?" + RESET;
}

// Function to get the current time
string getCurrentTime() {
    time_t t = time(0);
    struct tm* now = localtime(&t);
    int hour = now->tm_hour;
    int minute = now->tm_min;
    int second = now->tm_sec;
    char buffer[9];
    sprintf(buffer, "%02d:%02d:%02d", hour, minute, second);  // Formatting time as HH:MM:SS
    return string(buffer);
}

// Function to respond to basic greetings
string respondToGreetings(const string& input) {
    if (input.find("hi") != string::npos || input.find("hello") != string::npos) {
        return GREEN + "Hello! How can I assist you today?" + RESET;
    } else if (input.find("good morning") != string::npos) {
        return YELLOW + "Good morning! Hope you're having a great day!" + RESET;
    } else if (input.find("good evening") != string::npos) {
        return CYAN + "Good evening! How was your day?" + RESET;
    } else if (input.find("good night") != string::npos) {
        return MAGENTA + "Good night! Sleep well!" + RESET;
    } else {
        return "";
    }
}

// Function to handle user input, check against the dictionary, and return appropriate responses
string handleUserInput(const string& input, TreeNode* root) {
    string lowerInput = input;
    toLower(lowerInput);

    // Look for specific keywords in the dictionary
    string response = searchInTree(root, lowerInput);
    if (!response.empty()) {
        return response;
    }

    // Additional specific responses based on keywords
    if (lowerInput.find("python") != string::npos) {
        return BLUE + "Python is a versatile language! What do you need help with?" + RESET;
    } else if (lowerInput.find("weather") != string::npos) {
        return CYAN + "I'm sorry, I can't check the weather right now. You could try asking a voice assistant for that!" + RESET;
    } else if (lowerInput.find("time") != string::npos) {
        return YELLOW + "The current time is: " + getCurrentTime() + RESET;
    } else {
        return respondDefault();  // Default response if no matches are found
    }
}

// Function to show ASCII art of a robot
void printRobot() {
    cout << MAGENTA << "   _______    " << endl;
    cout << MAGENTA << "  /       \\   " << endl;
    cout << MAGENTA << " |  O   O  |  " << endl;
    cout << MAGENTA << " |    ^    |  " << endl;
    cout << MAGENTA << " |   '-'   |  " << endl;
    cout << MAGENTA << "  \\_______/   " << RESET << endl;
}

// Main chat function
void startChat() {
    string userInput;
    TreeNode* root = new TreeNode{"root", "root", {}};

    // Set the user's name at the beginning
    setUserName();

    // Add words to the tree with their corresponding responses
    addToTree(root, "hello", "Hello! How can I assist you today?");
    addToTree(root, "hi", "Hello! How can I assist you today?");
    addToTree(root, "good morning", "Good morning! Hope you're having a great day!");
    addToTree(root, "good evening", "Good evening! How was your day?");
    addToTree(root, "good night", "Good night! Sleep well!");
    addToTree(root, "math", "I can help you with math! What calculation would you like to perform?");
    addToTree(root, "programming", "I can help you with programming! Which language are you learning?");
    addToTree(root, "code", "I can help you with programming! Which language are you learning?");
    addToTree(root, "time", "The current time is: " + getCurrentTime());  // Add time response
// we can also add further different situations for it to answer
// for simplicity i have added few 
// like for example:
   addToTree(root, "i am feeling low today...", "Ohh! What happened? Did something wrong happened?");
   addToTree(root, "yes, i had a very bad migraine", "Did you consult a doctor? or took medicine for that?");
    // Start conversation
    printWithDelay(MAGENTA + "Welcome, " + userName + "! I'm your virtual assistant. Type 'exit' to quit." + RESET);
    while (true) {
        cout << GREEN << "You: " << RESET;
        getline(cin, userInput);
        toLower(userInput);

        if (userInput == "exit") {
            printWithDelay(YELLOW + "Goodbye, " + userName + "! It was nice talking to you." + RESET);
            break;
        }

        // Show robot visual
        printRobot();

        // Handle user input and get appropriate response
        string response = handleUserInput(userInput, root);
        printWithDelay(response);
    }
}

int main() {
    startChat();
    return 0;
}

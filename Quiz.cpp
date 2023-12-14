#include "Quiz.h"
#include "Question.h"
#include <cctype>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

Quiz::Quiz() : score(0) {}

void Quiz::loadQuestions() {
  questions.push_back(std::make_shared<Question>(
      "Who painted the Mona Lisa?", " Sigmond Freid", " Mother Teresa",
      " Leonardo Da Vinci", " Craig",
      'c' // Correct answer as a character
      ));

  questions.push_back(std::make_shared<Question>(
      "Elon Musk, the new owner of Twitter, said that he will revive this "
      "social media platform. What platform was it?",
      " MySpace", " Vine", " Club Penguin", " OnlyFriends",
      'b' // Correct answer as a character
      ));

  questions.push_back(
      std::make_shared<Question>("What does a Camel store in its hump?",
                                 " Water", " Fat", " Blood", " Urine",
                                 'b' // Correct answer as a character
                                 ));

  questions.push_back(std::make_shared<Question>(
      "What are all the layers inside Earth?",
      " Crust, Mantle, Outer Core, Inner Core",
      " Surface, Deeper Core, Inner Core, Center Core",
      " Crust, Inner Core, Outer Center, Nucleus", " Fee, Fye, Foe, Fum",
      'a' // Correct answer as a character
      ));

  questions.push_back(std::make_shared<Question>(
      "What sport could you receive the Heisman Trophy?", " Basketball",
      " American Football", " Cricket", " Golf",
      'b' // Correct answer as a character
      ));

  questions.push_back(std::make_shared<Question>(
      "In the cartoon “Spongebob Squarepants” which holiday was Spongebob "
      "excited for, that made him go “Hinga Dinga Durgen!”?",
      " Inauguration Day", " Scrabble Day", " Leif Erikson Day", " Arbor Day",
      'c' // Correct answer as a character
      ));

  // Add more questions here...
}

void Quiz::start() {
  try {
    std::cout << "Welcome to SUPER DUPER TRIVIA!\n What is your team name? ";
    std::cin >> teamName;

    if (teamName.empty()) {
      throw std::invalid_argument("Team name cannot be empty.");
    }

    std::cout << "Let's give it up for, " << teamName << "!" << std::endl;

    for (const auto &question : questions) {
      displayQuestion(question);

      char userAnswer;
      bool validInput = false;

      while (!validInput) {
        std::cout << "Your answer (A/B/C/D): ";
        std::cin >> userAnswer;
        userAnswer = std::toupper(userAnswer);

        if (userAnswer == 'A' || userAnswer == 'B' || userAnswer == 'C' ||
            userAnswer == 'D') {
          validInput = true;
        } else {
          throw std::invalid_argument(
              "Invalid input. Please enter 'A', 'B', 'C', or 'D'.");
        }
      }

      if (question->isCorrect(userAnswer)) {
        std::cout << "BOOM! Correct!" << std::endl;
        score++;
      } else {
        std::cout << "Incorrect. The correct answer was: "
                  << question->getCorrectAnswer() << std::endl;
      }

      std::cout << std::endl;
    }

    std::cout << teamName << ", your score: " << score << "/"
              << questions.size() << std::endl;
  } catch (const std::exception &ex) {
    std::cerr << "An error occurred: " << ex.what() << std::endl;
  }
}

void Quiz::displayQuestion(const std::shared_ptr<Question> &question) {
  // Display the question with boxes
  std::cout << "-----------------------------" << std::endl;
  std::cout << "| Question: " << question->getQuestionText() << std::endl;
  std::cout << "| Options:" << std::endl;
  std::cout << "| A. " << question->getOptionA() << std::endl;
  std::cout << "| B. " << question->getOptionB() << std::endl;
  std::cout << "| C. " << question->getOptionC() << std::endl;
  std::cout << "| D. " << question->getOptionD() << std::endl;
  std::cout << "-----------------------------" << std::endl;
}

// Destructor definition
Quiz::~Quiz() {
  // Clean up questions
  questions.clear();
}

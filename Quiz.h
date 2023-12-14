#ifndef QUIZ_H
#define QUIZ_H

#include <iostream>
#include <vector>
#include <memory>
#include "Question.h"

class Quiz {
public:
    Quiz();
    void loadQuestions();
    void start();
    void displayQuestion(const std::shared_ptr<Question>& question);
    ~Quiz();

private:
    std::vector<std::shared_ptr<Question>> questions;
    std::string teamName;
    int score;
};

#endif // QUIZ_H

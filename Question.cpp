#include "Question.h"

Question::Question(const std::string &questionText, const std::string &optionA,
                   const std::string &optionB, const std::string &optionC,
                   const std::string &optionD, char correctAnswer)
    : questionText(questionText), optionA(optionA), optionB(optionB),
      optionC(optionC), optionD(optionD), correctAnswer(correctAnswer) {}

const std::string &Question::getQuestionText() const { return questionText; }

const std::string &Question::getOptionA() const { return optionA; }

const std::string &Question::getOptionB() const { return optionB; }

const std::string &Question::getOptionC() const { return optionC; }

const std::string &Question::getOptionD() const { return optionD; }

char Question::getCorrectAnswer() const { return correctAnswer; }

bool Question::isCorrect(char userAnswer) const {
  return std::toupper(userAnswer) == std::toupper(correctAnswer);
}

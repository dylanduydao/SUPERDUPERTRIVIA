#ifndef QUESTION_H
#define QUESTION_H

#include <string>

class Question {
public:
  Question(const std::string &questionText, const std::string &optionA,
           const std::string &optionB, const std::string &optionC,
           const std::string &optionD, char correctAnswer);

  const std::string &getQuestionText() const;
  const std::string &getOptionA() const;
  const std::string &getOptionB() const;
  const std::string &getOptionC() const;
  const std::string &getOptionD() const;
  char getCorrectAnswer() const;
  bool isCorrect(char userAnswer) const;

private:
  std::string questionText;
  std::string optionA;
  std::string optionB;
  std::string optionC;
  std::string optionD;
  char correctAnswer;
};

#endif // QUESTION_H

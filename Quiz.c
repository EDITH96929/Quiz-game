#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_LENGTH 100

// Structure Definitions
typedef struct {
    char question[MAX_LENGTH];
    char options[4][MAX_LENGTH];
    char correctOption;
    int points; // Points for each question
} Question;

// Global Variables
Question quiz[MAX_QUESTIONS];
int totalQuestions = 0;
int score = 0;

// Function Prototypes
void addQuestions();
void startQuiz();
void displayResults();
void shuffleQuestions();

// Main Function
int main() {
    int choice;

    addQuestions(); // Preload questions

    while (1) {
        printf("\nQuiz Game\n");
        printf("1. Start Quiz\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                shuffleQuestions();
                startQuiz();
                break;
            case 2:
                printf("Thank you for playing the Quiz Game. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to Preload Questions
void addQuestions() {
    strcpy(quiz[0].question, "What is the capital of France?");
    strcpy(quiz[0].options[0], "A. Berlin");
    strcpy(quiz[0].options[1], "B. Madrid");
    strcpy(quiz[0].options[2], "C. Paris");
    strcpy(quiz[0].options[3], "D. Rome");
    quiz[0].correctOption = 'C';
    quiz[0].points = 10;

    strcpy(quiz[1].question, "Which planet is known as the Red Planet?");
    strcpy(quiz[1].options[0], "A. Earth");
    strcpy(quiz[1].options[1], "B. Mars");
    strcpy(quiz[1].options[2], "C. Jupiter");
    strcpy(quiz[1].options[3], "D. Venus");
    quiz[1].correctOption = 'B';
    quiz[1].points = 10;

    strcpy(quiz[2].question, "Who wrote 'Hamlet'?");
    strcpy(quiz[2].options[0], "A. Charles Dickens");
    strcpy(quiz[2].options[1], "B. Jane Austen");
    strcpy(quiz[2].options[2], "C. William Shakespeare");
    strcpy(quiz[2].options[3], "D. Mark Twain");
    quiz[2].correctOption = 'C';
    quiz[2].points = 10;

    strcpy(quiz[3].question, "Which is the largest ocean on Earth?");
    strcpy(quiz[3].options[0], "A. Indian Ocean");
    strcpy(quiz[3].options[1], "B. Pacific Ocean");
    strcpy(quiz[3].options[2], "C. Atlantic Ocean");
    strcpy(quiz[3].options[3], "D. Arctic Ocean");
    quiz[3].correctOption = 'B';
    quiz[3].points = 10;

    totalQuestions = 4; // Number of questions added
}

// Function to Shuffle Questions
void shuffleQuestions() {
    srand(time(0));
    for (int i = totalQuestions - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Question temp = quiz[i];
        quiz[i] = quiz[j];
        quiz[j] = temp;
    }
}

// Function to Start the Quiz
void startQuiz() {
    char answer;

    printf("\nStarting the Quiz!\n");

    for (int i = 0; i < totalQuestions; i++) {
        printf("\nQuestion %d: %s\n", i + 1, quiz[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", quiz[i].options[j]);
        }

        printf("Enter your answer (A/B/C/D): ");
        getchar(); // To clear the newline character from the buffer
        scanf("%c", &answer);

        if (toupper(answer) == quiz[i].correctOption) {
            printf("Correct! You earned %d points.\n", quiz[i].points);
            score += quiz[i].points;
        } else {
            printf("Wrong! The correct answer is %c.\n", quiz[i].correctOption);
        }
    }

    displayResults();
}

// Function to Display Results
void displayResults() {
    printf("\nQuiz Over!\n");
    printf("Your total score is: %d\n", score);

    if (score == totalQuestions * 10) {
        printf("Excellent! You got all questions correct!\n");
    } else if (score >= (totalQuestions * 10) / 2) {
        printf("Good job! You passed the quiz!\n");
    } else {
        printf("Better luck next time!\n");
    }

    // Reset score for next attempt
    score = 0;
}

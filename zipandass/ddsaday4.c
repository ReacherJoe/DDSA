#include <stdio.h>

void mark(int marks);
void Marks(int marks[][5]);
void whodistinction(int marks[][5]) ;
int HighestTotalmarks(int marks[][5]);

int main() {
    int marks[3][5];

    Marks(marks);

    whodistinction(marks);

    int highestTotal = HighestTotalmarks(marks);
    printf("Student with the highest total marks: %d\n", highestTotal);

    return 0;
}
void mark(int marks) {
  if (marks >= 40) {
        printf("Pass\n");
    } else {
        printf("Fail\n");
    }
}
void Marks(int marks[][5]) {
    for (int i = 0; i < 3; ++i) {
        printf("Enter marks for student %d (5 subjects): ", i + 1);
        for (int j = 0; j < 5; ++j) {
            scanf("%d", &marks[i][j]);
        }
    }
}
int HighestTotalmarks(int marks[][5]) {
    int highestTotal = 0;

    for (int i = 0; i < 3; ++i) {
        int total = 0;
        for (int j = 0; j < 5; ++j) {
            total += marks[i][j];
        }

        if (total > highestTotal) {
            highestTotal = total;
        }
    }

    return highestTotal;
}
void whodistinction(int marks[][5]) {
    for (int i = 0; i < 3; ++i) {
        printf("Student%d ", i + 1);
        mark(marks[i][0]);
        
        int distinctionCount = 0;
        for (int j = 0; j < 5; ++j) {
            if (marks[i][j] >= 75) {
                distinctionCount++;
            }
        }

        if (distinctionCount > 0) {
            printf("Student%d got %d distinction(s)\n", i + 1, distinctionCount);
        } else {
            printf("Student%d got no distinction\n", i + 1);
        }
    }
}

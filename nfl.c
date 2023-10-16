/*
Author: Tanushri Sakaray
KUID: 3080571
Date: 10/12/23
Lab: lab05
Last modified: 10/15/2023
Purpose: determines all possible combinations of scoring plays that can result in a score
*/

#include <stdio.h>

void printCombinations(int touchdown2, int touchdownFieldGoal, int touchdown, int fieldGoal3pt, int safety) {
    printf("\n%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety", touchdown2, touchdownFieldGoal, touchdown, fieldGoal3pt, safety);
}

void generateCombinations(int totalScore) {
    for (int td2 = 0; td2 <= totalScore / 8; td2++) {
        for (int tdfg = 0; tdfg <= (totalScore - td2 * 8) / 7; tdfg++) {
            for (int td = 0; td <= (totalScore - td2 * 8 - tdfg * 7) / 6; td++) {
                for (int fg = 0; fg <= (totalScore - td2 * 8 - tdfg * 7 - td * 6) / 3; fg++) {
                    for (int safety = 0; safety <= (totalScore - td2 * 8 - tdfg * 7 - td * 6 - fg * 3) / 2; safety++) {
                        if (totalScore == td2 * 8 + tdfg * 7 + td * 6 + fg * 3 + safety * 2) {
                            printCombinations(td2, tdfg, td, fg, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int totalScore;
    do {
        printf("\nEnter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%d", &totalScore);
        if (totalScore > 1) {
            generateCombinations(totalScore);
        }
    } while (totalScore > 1);
    return 0;
}











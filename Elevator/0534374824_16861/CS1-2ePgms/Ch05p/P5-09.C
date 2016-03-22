/*	****************************************************************
	**  This program is provided to the professors and students   **
	**  using "Computer Science: A Structured Approach Using C,   **
	**  Second Edition." All reprints in any form must cite this  **
	**  copyright.                                                **
    **                                                            **
	**  Copyright(c) 2001 by Brooks/Cole                          **
	**  A division of Thomson Learning                            **
	****************************************************************
*/

/*	This program reads a test score, calculates the letter 
	grade based on the absolute scale, and prints it.
	   Written by: 
	   Date: 
*/
#include <stdio.h>

/*	Prototype Declarations */
 char scoreToGrade (int score);

int main (void)
{
/*	Local Definitions */
	int  score;
	char grade;

/*	Statements */
	printf("Enter the test score (0-100): ");
	scanf ("%d", &score);

	grade = scoreToGrade (score);
	printf("The grade is: %c\n", grade);

	return 0;
}	/* main */

/*	==================== scoreToGrade ===================
	This function calculates the letter grade for a score.
	   Pre   the parameter score
	   Post  returns the grade
*/
char scoreToGrade (int score)
{
/*	Local Definitions */
	char grade;

/*	Statements */
	if (score >= 90)
	   grade = 'A';
	else if (score >= 80)
	   grade = 'B';
	else if (score >= 70)
	   grade = 'C';
	else if (score >= 60)
	   grade = 'D';
	else
	   grade = 'F';
	return grade;
}/* scoreToGrade*/

/*	Results
	Enter the test score (0-100): 90
	The grade is: A
*/

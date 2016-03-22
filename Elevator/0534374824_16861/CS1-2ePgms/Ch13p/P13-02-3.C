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

/*	This program is a driver to test program 1 (read
	student file) and 2 (write student file).
	   Written by: 
	   Date: 
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Global Structures */
typedef struct stuData
	{
	 char     name[26];
	 int      id;
	 int      exams[3];
	 int      problems[8];
	 char     grade;
	} STU;

/*  Prototype Declarations */
	void writeStudent (STU *aStudent,   FILE *fileOut);
	int  readStudent  (STU *oneStudent, FILE *stuFile);

int main (void)
{
/* Local Variables */
	char stuFileID[] = "students.bin";
	char outFileID[] = "students.out";
	char more;

	STU aStudent;

	FILE *stuFile;
	FILE *outFile;

/* Statements */
	printf("\nBegin Test. Enter data to create file.\n\n");

	if (!(outFile = fopen(outFileID, "wb"))) 
		{
		 printf("\nCannot open %s for creation\n", outFileID);
		 exit (200);
		} /* if */
	
	do
	   {
	    printf("Enter student name  : ");
	    scanf ("%25s", aStudent.name);
	    printf("Enter student id    : ");
	    scanf ("%d",  &aStudent.id);
	    printf("Enter student grade : ");
	    scanf (" %c", &aStudent.grade);
	    
	    /* Create test scores based on grade */
	    switch(toupper(aStudent.grade))
	       {
	        case 'A': aStudent.exams[0] = 90;
	                  aStudent.exams[1] = 91;
	                  aStudent.exams[2] = 92;

	                  aStudent.problems[0] = 90;
	                  aStudent.problems[1] = 91;
	                  aStudent.problems[2] = 92;
	                  aStudent.problems[3] = 93;
	                  aStudent.problems[4] = 94;
	                  aStudent.problems[5] = 95;
	                  aStudent.problems[6] = 96;
	                  aStudent.problems[7] = 97;
	                  break;

	        case 'B': aStudent.exams[0] = 80;
	                  aStudent.exams[1] = 81;
	                  aStudent.exams[2] = 82;

	                  aStudent.problems[0] = 80;
	                  aStudent.problems[1] = 81;
	                  aStudent.problems[2] = 82;
	                  aStudent.problems[3] = 83;
	                  aStudent.problems[4] = 84;
	                  aStudent.problems[5] = 85;
	                  aStudent.problems[6] = 86;
	                  aStudent.problems[7] = 87;
	                  break;

	        case 'C': aStudent.exams[0] = 70;
	                  aStudent.exams[1] = 71;
	                  aStudent.exams[2] = 72;
	                  
	                  aStudent.problems[0] = 70;
	                  aStudent.problems[1] = 71;
	                  aStudent.problems[2] = 72;
	                  aStudent.problems[3] = 73;
	                  aStudent.problems[4] = 74;
	                  aStudent.problems[5] = 75;
	                  aStudent.problems[6] = 76;
	                  aStudent.problems[7] = 77;
	                  break;

	        case 'D': aStudent.exams[0] = 60;
	                  aStudent.exams[1] = 61;
	                  aStudent.exams[2] = 62;
	                  
	                  aStudent.problems[0] = 60;
	                  aStudent.problems[1] = 61;
	                  aStudent.problems[2] = 62;
	                  aStudent.problems[3] = 63;
	                  aStudent.problems[4] = 64;
	                  aStudent.problems[5] = 65;
	                  aStudent.problems[6] = 66;
	                  aStudent.problems[7] = 67;
	                  break;

	        case 'F': aStudent.exams[0] = 50;
	                  aStudent.exams[1] = 51;
	                  aStudent.exams[2] = 52;

	                  aStudent.problems[0] = 50;
	                  aStudent.problems[1] = 51;
	                  aStudent.problems[2] = 52;
	                  aStudent.problems[3] = 53;
	                  aStudent.problems[4] = 54;
	                  aStudent.problems[5] = 55;
	                  aStudent.problems[6] = 56;
	                  aStudent.problems[7] = 57;
	                  break;
	                      
	        default:  printf("Invalid grade. Reenter all data.\n");
	                  break;
	       } /* switch */
	    
	    writeStudent (&aStudent, outFile);               
	    printf("Another student <Y/N>: ");
	    scanf (" %c", &more);
	   } while (toupper(more) == 'Y');                   

	fclose(outFile);

	/* Now read file */
	if (!(stuFile = fopen(outFileID, "rb"))) 
		{
		 printf("\nCannot open %s for reading\n", outFileID);
		 exit (200);
		} /* if */
	
	printf("\n");
	readStudent (&aStudent, stuFile);
	while (!feof(stuFile))
		{
	     printf("%-25s", aStudent.name);
	     printf("%6d",   aStudent.id);
	     printf("%2c\n", aStudent.grade);
		 
		 readStudent  (&aStudent, stuFile);
		} /* while */

	fclose(stuFile);
	printf("\nEnd of Test\n"); 

	return 0;
}	/* main */

/*	Reads one student’s data from a file 
	   Pre   stuFile is opened for reading
	   Post  stu data structure filled
	         ioResults returned
*/
int readStudent (STU  *oneStudent,
                 FILE *stuFile)
{
/*	Local Definitions */
	int ioResults;
	
/*	Statements */
	ioResults = fread(oneStudent, 
	                  sizeof(STU), 1, stuFile);
	return ioResults;
} /* readStudent */

/*	Writes one student’s record to a binary file. 
	   Pre  aStudent has been filled 
	        fileOut is open for writing 
	   Post aStudent written to fileOut 
*/
void writeStudent  (STU  *aStudent,
                    FILE *fileOut)
{
/*	Local Definitions */
	int ioResult;

/*	Statements */
	ioResult = fwrite(aStudent, 
	                  sizeof(STU), 1, fileOut);
	if (ioResult != 1) 
	   {
	    printf("\a Error writing student file \a\n");
	    exit (100);
	   } /* if */
	return;
}	/* writeStudent */

/*	Results:
	Begin Test. Enter data to create file.
	
	Enter student name  : A.Student
	Enter student id    : 9999
	Enter student grade : A
	Another student <Y/N>: y
	Enter student name  : B.Student
	Enter student id    : 8888
	Enter student grade : B
	Another student <Y/N>: y
	Enter student name  : C.Student
	Enter student id    : 7777
	Enter student grade : C
	Another student <Y/N>: y
	Enter student name  : D.Student
	Enter student id    : 6666
	Enter student grade : D
	Another student <Y/N>: y
	Enter student name  : F.Student
	Enter student id    : 5555
	Enter student grade : F
	Another student <Y/N>: n
	
	A.Student                  9999 A
	B.Student                  8888 B
	C.Student                  7777 C
	D.Student                  6666 D
	F.Student                  5555 F
	
	End of Test
*/

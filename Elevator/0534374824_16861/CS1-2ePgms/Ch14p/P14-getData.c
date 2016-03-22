/*	Prototype Declaration */
int getData (FILE *fpData, DATA *pData);

/*	==================== getData ====================
	Reads data from file.
	   Pre   fpData is an open file
	         pData is pointer to input structure
	   Post  data read
             returns success/failure
*/
int getData (FILE *fpData,
             DATA *pData)
{
/*	Local Definitions */
	int ioResult;

/*	Statements */
	ioResult = fscanf (fpData, "%d", &(pData->key));	
	if (ioResult == 1)
	   return 1;
	else
	   return 0;
}	/* getData */ 

#include "dict.h"

int writedict(const char *dictname, struct dict_elem *elist){

	int j;
	FILE *outf;

	if ((outf = fopen(dictname, "w")) == NULL){
		return ERROR;
	}

	//cculate length of the aray
	for (j = 0; elist[j].d_length != 0; j++)
		;

	//write out list of dict_elem structures
	if (fwrite((void*)elist, sizeof(struct dict_elem), j, outf)<j){
		fclose(outf);
		return ERROR;
	}


	fclose(outf);
	return SUCCESS;
}

//**************************************************************************


struct dict_elem * readdict(const char *dictname, 
  				     struct dict_elem *inlist, int maxlength)
{

	int i;
	FILE *inf;

	if ((inf = fopen(dictname, "r")) == NULL){
		return NULL;
	}
	//read in dict_elem structures from file
	for (i = 0; i < maxlength - 1; i++)
	{
		if (fread((void*)&inlist[i], sizeof(struct dict_elem), 1, inf)<1)
		{
			break;
		}
	}


	fclose(inf);

      //mark end of list

	inlist[i].d_length = 0;

	return inlist;
}


// your main function goes here.
int main(void) {

	/**
	  * We must write the contents of dict_elem array to some file
	  * with the use of the writedict() function provided above.
	  * Reading from the file will into dict_elem array is also done. 
	  */

	//Declaration of values within array
	struct dict_elem array[4] = {{"Edxio", 0, 5, 1}, {"Danny", 0, 5, 1}, {"Paulo", 0, 5, 1}, {"David", 0, 5, 1}};
	
	//Writing the contents of the array above to testD.txt
	if (writedict("testD.txt", array) != SUCCESS) {
		printf("Writing error!\n");
	}
	
	const int max = 4;
	struct dict_elem readArray[max];

	if (readdict("testD.txt", readArray, max) == NULL) {
		printf("Reading error!\n");
	}

	for (int x = 0; x < max - 1; x++) {
		printf("%s\n", readArray[x].d_name);
	}
	
	return 0;

}

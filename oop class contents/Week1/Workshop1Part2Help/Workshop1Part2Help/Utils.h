#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds {

	bool getInt(void); // this function makes sure a correct user input is provided with no tailing char
	                   // the code of this function will look something like:
	/*
	int value, keeptrying = 1, rc;
    char after;

   do {
      rc = scanf("%d%c", &value, &after); // keep in mind that scanf return number of correctly read inputs
      if (rc == 0) {  // 0 means no correct input
         printf("Invalid Number, try again: ");
         clear();
      }
      else if (after != '\n') {
         printf("Invalid trailing characters, try again: ");
         clear(); // clear buffer from any trailing char and try again
      }
      else
         keeptrying = 0;
   } while (keeptrying == 1);

   return value;
	*/
	int getIntRange(int min, int max);//exactly same as your function in IPC144 that make sure that
	                                  // the int read is within the provided range
	                                  //this function uses getInt function
	void clear(void); // clear keyboard from IPC144 final project
	void selectSort(int a[], int n); // algorithm in IPC144 algorithm chapter

}
#endif
#ifndef SDDS_MARKS_H
#define SDDS_MARKS_H
namespace sdds {
	void markstat(); // reads name of test, call getMarks and report
	void getMarks(int marks[], int num); // uses getInt and getIntRange to reak #of marks and mrks required
	void report(const char name[], int marks[], int num); // print out the report with marks
}
#endif
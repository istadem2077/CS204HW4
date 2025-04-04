#include <iostream>
#include <fstream>
#include "scatterplot.h"
using namespace std;

// Compare two ScatterPlots for equality using the == operator
void compareScatterPlots(const ScatterPlot& sp1, const ScatterPlot& sp2) 
{
    if (sp1 == sp2) 
    {
        cout << "The ScatterPlots are equal" << endl;
    }
    else 
    {
        cout << "The ScatterPlots are NOT equal" << endl;
    }
    cout << endl;
}

// display all non-zero counts within a range using the [] operator
void displayNonZeroXValues(const ScatterPlot& sp, int start_range, int end_range) 
{
    cout << "X values with non-zero y-counts in range [" << start_range << ", " << end_range << "]:" << endl;
    bool foundAny = false;

    for (int x = start_range; x <= end_range; x++) 
    {
        int count = sp[x];

        if (count > 0) 
        {
            cout << "x = " << x << ": " << count << " y value(s)" << endl;
            foundAny = true;
        }
    }

    if (!foundAny) 
    {
        cout << "No x values with points in this range." << endl;
    }

    cout << endl;
}

// open a file 
ifstream openInputFile(string& filename) 
{
    ifstream file;
    file.open(filename);
    while (file.fail())
    {
        cout << "The file " << filename << " couldn't be opened." << endl;
        cout << "Please enter a valid file name:" << endl;
        cin >> filename;
        file.clear();
        file.open(filename);
    }
    return file;
}

// read points from a file and add them to a ScatterPlot
void readPointsFromFile(ifstream& file, ScatterPlot& plot, const string& filename, int file_rank) 
{
    Point p;
    cout << "Reading points from " << filename << ":" << endl;
    while (file >> p) 
    {
        if (file_rank == 1)
			plot = p + plot;
		else if (file_rank == 2)
            plot = plot + p;
    }
    file.close();
}

int main()
{
    // Create ScatterPlot instances
    ScatterPlot scatterPlot1, scatterPlot2;
    cout << scatterPlot1 + scatterPlot2;

    string file1_name, file2_name;

    cout << "Enter filename for scatterPlot1:" << endl;
    cin >> file1_name;
    ifstream file1 = openInputFile(file1_name);    
    readPointsFromFile(file1, scatterPlot1, file1_name, 1);
    cout << "scatterPlot1:" << scatterPlot1 << endl << endl;

    // Test intersection operator between scatterPlot1 and scatterPlot2
    cout << "Testing intersection (empty case) (scatterPlot1 * scatterPlot2):" << endl;
    cout << scatterPlot1 * scatterPlot2 << endl;

    cout << "Enter filename for scatterPlot2:"<< endl;
    cin >> file2_name;
    ifstream file2 = openInputFile(file2_name);
    readPointsFromFile(file2, scatterPlot2, file2_name, 2);
    cout << "scatterPlot2:" << scatterPlot2 << endl << endl;

    // Get 3 input points from the user
    Point p1, p2, p3;
    cout << "Enter 3 points (x y format):" << endl;
    cin >> p1 >> p2 >> p3;
    
    // Test Point + Point
    cout << "pointsPlot = p1 + p2" << endl;
    ScatterPlot pointsPlot = p1 + p2;
    cout << "pointsPlot:" << pointsPlot << endl << endl;

	// Test equality operator between scatterPlot1 and scatterPlot2
	cout << "Comparing scatterPlot1 with scatterPlot2:" << endl;
	compareScatterPlots(scatterPlot1, scatterPlot2);

	// Test intersection operator between scatterPlot1 and scatterPlot2
	cout << "Testing intersection (scatterPlot1 * scatterPlot2):" << endl;
	cout << scatterPlot1 * scatterPlot2 << endl;
    
    // Test ScatterPlot + ScatterPlot
    cout << "scatterPlot1 = scatterPlot1 + scatterPlot2:" << endl;
    ScatterPlot originalPlot1 = scatterPlot1;
    scatterPlot1 = scatterPlot1 + scatterPlot2;
    cout << scatterPlot1 << endl << endl;

	// Test cascading assignment operator
	cout << "Testing cascading assignment: cascadedPlot1 = scatterPlot2 = scatterPlot1" << endl;
    ScatterPlot cascadedPlot1;
    cascadedPlot1 = scatterPlot2 = scatterPlot1;
	cout << "cascadedPlot1:" << cascadedPlot1 << endl << endl;

    // Test self-assignment 
	cout << "Testing self-assignment: scatterPlot2 = scatterPlot2" << endl;
    scatterPlot2 = scatterPlot2;
	cout << "scatterPlot2:" << scatterPlot2 << endl << endl;


    // Test Point + ScatterPlot 
    cout << "Testing pointPlusPlot = p3 + pointsPlot" << endl;
    ScatterPlot pointPlusPlot = p3 + pointsPlot;
    cout << "Point + ScatterPlot:" << pointPlusPlot << endl << endl;

    // Test ScatterPlot + Point   
    cout << "Testing plotPlusPoint = scatterPlot1 + p1" << endl;
    ScatterPlot plotPlusPoint = scatterPlot1 + p1;
    cout << "ScatterPlot + Point:" << plotPlusPoint << endl << endl;

    // Test cascading addition 1
    cout << "Testing cascading addition (points): cascadedPlot2 = p1 + p2 + p3;" << endl;
    ScatterPlot cascadedPlot2;
    cascadedPlot2 = p1 + p2 + p3;
    cout << "cascadedPlot2:" << cascadedPlot2 << endl << endl;

    // Test cascading addition 2
    cout << "Testing cascading addition (plots and points): cascadedPlot3 = scatterPlot1 + scatterPlot2 + p1" << endl;
    ScatterPlot cascadedPlot3;
    cascadedPlot3 = scatterPlot1 + scatterPlot2 + p1;
    cout << "cascadedPlot3:" << cascadedPlot3 << endl << endl;

    // Test += operator 
    cout << "Testing += operator: scatterPlot2 += pointPlusPlot" << endl;
    ScatterPlot originalPlot2 = scatterPlot2;
    scatterPlot2 += pointPlusPlot;
    cout << "scatterPlot2:" << scatterPlot2 << endl << endl;

    // Test += operator cascading.
    cout << "Testing += operator cascading: cascadedPLusEqual = scatterPlot1 += cascadedPlot2 += scatterPlot2" << endl;
    ScatterPlot cascadedPLusEqual;
    cascadedPLusEqual = scatterPlot1 += cascadedPlot2 += scatterPlot2;
    cout << "cascadedPLusEqual:" << cascadedPLusEqual << endl;
    cout << "scatterPlot1:" << scatterPlot1 << endl;
    cout << "cascadedPlot2:" << cascadedPlot2 << endl;
    cout << "scatterPlot2:" << scatterPlot2 << endl << endl;

    // Test [] operator
    displayNonZeroXValues(scatterPlot1, -100, 100);

	// Displaying scatterPlot1 and scatterPlot2
	cout << "scatterPlot1:" << scatterPlot1 << endl;
	cout << "scatterPlot2:" << scatterPlot2 << endl << endl;

    // Test equality operator
    cout<< "Comparing scatterPlot1 with scatterPlot2:" << endl;
    compareScatterPlots(scatterPlot1, scatterPlot2);

	// Displaying originalPlot1 and scatterPlot1
	cout << "originalPlot1:" << originalPlot1 << endl;
	cout << "scatterPlot1:" << scatterPlot1 << endl <<endl;

    // Test equality after addition
    cout << "Comparing originalPlot1 with scatterPlot1:" << endl;
    compareScatterPlots(originalPlot1, scatterPlot1);

    // Test intersection operator
    cout << "Testing intersection (scatterPlot1 * scatterPlot2):" << endl;
    ScatterPlot intersection = scatterPlot1 * scatterPlot2;
    cout << "intersection:" << intersection << endl << endl;

    // Test intersection cascading operator
    cout << "Testing intersection (scatterPlot1 * scatterPlot2 * cascadedPlot1):" << endl;
    ScatterPlot intersection1 = scatterPlot1 * scatterPlot2 * cascadedPlot1;
    cout << "intersection1:" << intersection1 << endl << endl;

    // Test intersection operator with + operator
    cout << "Testing intersection and plus (scatterPlot1 * (scatterPlot2 + cascadedPLusEqual)):" << endl;
    ScatterPlot intersection2; 
    intersection2 = scatterPlot1 * (scatterPlot2 + cascadedPLusEqual);
    cout << "intersection2:" << intersection2 << endl << endl;

    //// Test [] operator on intersection result
    //displayNonZeroXValues(intersection, -50, 50);


    return 0;
}
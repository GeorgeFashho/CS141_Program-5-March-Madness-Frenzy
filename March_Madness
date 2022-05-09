/* ---------------------------------------------
Program 4: Billboard Analysis
--
    A C++ program that will quantify and summarize Billboard chart data
The dataset covers the top 50 songs from "The Hot 100" charts over the time period of 1960-2020,
and is broken up into three different files by time period.
You can access different information for each time period by choosing different
menu options.
--

Course: CS 141, Spring 2022
System: Windows 10 Using Clion collaborative
Authors: George Fashho & Aditya Kapoor
---------------------------------------------
*/

#include <iostream>   // For Input and Output
#include <vector>     // For vectors
#include <fstream>    // For file input and output
#include <cassert>    // For the assert statement used to validate file open
#include <cctype>     // Allows using the tolower() function
#include <string>     // To manipulate strings
#include <sstream>    // Stream Class to Operate on strings
#include <algorithm>  // Allows using transform() and unique() function

using namespace std;

//---------------------------------------------------------------------------
// Class to hold all the data from csv files includes default constructor
// and getter functions
class Data {

private:
    string date, song, artist;
    int rank, lastWeek, peakRank, weeksOnBoard;

public:
    Data() { date = "", rank = 0, song = "", artist = "", lastWeek = 0, peakRank = 0, weeksOnBoard = 0; }

    Data(string date, int rank, string song, string artist, int lastWeek,
         int peakRank, int weeksOnBoard) {

        this->date = date;
        this->rank = rank;
        this->song = song;
        this->artist = artist;
        this->lastWeek = lastWeek;
        this->peakRank = peakRank;
        this->weeksOnBoard = weeksOnBoard;
    }

    void display() {
        cout << date << rank << song << artist << lastWeek << peakRank << weeksOnBoard << endl;
    }

    string getDate() {
        return date;
    }

    int getRank() {
        return rank;
    }

    string getSong() {
        return song;
    }

    string getArtist() {
        return artist;
    }

    int getLastWeek() {
        return lastWeek;
    }

    int getPeakRank() {
        return peakRank;
    }

    int getWeeksOnBoard() {
        return weeksOnBoard;
    }

}; //end Class declaration

//---------------------------------------------------------------------------
// Function to read in data from the csv file that the user inputs
// and pushes the data back into a single vector.
void readToVector(string fileName, vector<Data> &allData) {
    ifstream inputFile;                      // Declare an input stream for reading
    inputFile.open(fileName);               // Opening CSV according to the value of fileName
    assert(inputFile.fail() == false);     // Ensure file open worked

    allData.clear();                    // Clearing vector incase it wasn't empty
    string line = "";                  // Declaring string line
    getline(inputFile, line);         // Skipping the first line of the CSV to remove headers

    // Keep repeating while input from the CSV file
    while (getline(inputFile, line)) {

        stringstream inputString(line);     // Converting the whole line into
                                           // into one string
        string date, song, artist, tempString;
        int rank, lastWeek, peakRank, weeksOnBoard;

        // Splitting up the inputString into individual elements whenever there is "," found
        getline(inputString, date, ',');
        getline(inputString, tempString, ',');
        rank = atoi(tempString.c_str());            // Storing a string element into a temp string
        getline(inputString, song, ',');          // and converting it into an integer using
        getline(inputString, artist, ',');       // atoi() ;
        getline(inputString, tempString, ',');
        lastWeek = atoi(tempString.c_str());
        getline(inputString, tempString, ',');
        peakRank = atoi(tempString.c_str());
        getline(inputString, tempString);
        weeksOnBoard = atoi(tempString.c_str());

        // Storing all the extracted data from the line into a class and
        // storing it into a single vector using push_back();
        Data data1(date, rank, song, artist, lastWeek, peakRank, weeksOnBoard);
        allData.push_back(data1);
        line = "";

    }

} //end readToVector()

//---------------------------------------------------------------------------
// Function used to extract a vector of unique songs from the
// vector that contains all the data
int uniqueSongs(vector<Data> allData, vector<string> &songs) {

    int count = 0;
    string song;

    // For loop to cycle through all the songs in the allData vector and extracting
    // every unique song into a separate vector
    for (int i = 0; i < allData.size(); i++) {
        if (find(songs.begin(), songs.end(), allData.at(i).getSong()) != songs.end()) {
            continue;       // Checking if the song at i is already inside of the unique
                           // songs vector and skipping the value if it is
        } else {
            songs.push_back(allData.at(i).getSong());
            count++;      // Adding the song at i into a vector and incrementing count
        }
    }
    return count;       // Returing the count of unique songs
} //end uniqueSongs

//---------------------------------------------------------------------------
// Outputting the options for the second menu
void menuTwoOptions() {

    cout << "\nSelect a menu option: \n"
            "   1. Display overall information about the data\n"
            "   2. Display the Billboard info of the song with the most #1 occurrences for a given decade or year\n"
            "   3. Display the Billboard info for the most long-lasting song on the charts for a given decade or year\n"
            "   4. Display the Billboard info for the song with the greatest weekly climb on the charts given a decade or year\n"
            "   5. Artist Search - Return the Billboard info for records that matches user input for artist search\n"
            "   6. Exit\n"
            "Your choice --> ";
}//end menuTwoOptions

//---------------------------------------------------------------------------
// Function to find the songs with the most #1 occurences
void longestNumOneSongs(vector<Data> allData, int decade, int inputYear, char userInput) {

    vector<Data> songsWithArtist;       // vector to store classes with data of
                                       // the artist and their song
    cout << "The song(s) with the most #1 occurrences for selected time period is: \n";

    //for loop to to cycle through all items in allData vector
    for (int i = 0; i < allData.size(); i++) {
        string year;

        // finding the year that the song was made
        int position = allData.at(i).getDate().find_last_of('/'); //finding position of last "/" in date
        year = (allData.at(i).getDate().substr(position + 1, 4)); //extracting the year from the full date

        if (userInput == 'D' || userInput == 'd') {

            if (stoi(year) >= decade && stoi(year) <= (decade + 9)) // only looking at
            {                                               // songs in the user inputted decade
                if (allData.at(i).getRank() == 1)   // if the rank of the song is one
                {                                  // store it in the vector
                    string song = allData.at(i).getSong();
                    string artist = allData.at(i).getArtist();
                    Data songsAndArtists("", 0, song, artist, 0, 0, 0);
                    songsWithArtist.push_back(songsAndArtists);
                }
            }
        } else {
            if (stoi(year) == inputYear) // only looking at songs withen the year of the user inputs
            {
                if (allData.at(i).getRank() == 1) {
                    string song = allData.at(i).getSong();
                    string artist = allData.at(i).getArtist();
                    Data songsAndArtists("", 0, song, artist, 0, 0, 0);
                    songsWithArtist.push_back(songsAndArtists);
                }
            }
        }
    }
    int maxCount = 0;

    // Algorithm to find the number for what the most occuring #1 song is
    for (int i = 0; i < songsWithArtist.size(); i++) {
        int count = 0;
        for (int j = 0; j < songsWithArtist.size(); j++) {
            if (songsWithArtist.at(i).getSong() == songsWithArtist.at(j).getSong()) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
        }
    }

    vector<string> songs;
    vector<string> artist;

    // Finding the songs that occur at #1 the same amount of times as maxCount
    for (int i = 0; i < songsWithArtist.size(); i++) {  //and matching it with its
        int count = 0;                                 //artist
        for (int j = 0; j < songsWithArtist.size(); j++) {
            if (songsWithArtist.at(i).getSong() == songsWithArtist.at(j).getSong())
                count++;
        }
        if (count == maxCount) {
            songs.push_back(songsWithArtist.at(i).getSong());
            artist.push_back(songsWithArtist.at(i).getArtist());
        }
    }
    artist.erase(unique(artist.begin(), artist.end()), artist.end()); //erasing none maxCount elements
    songs.erase(unique(songs.begin(), songs.end()), songs.end());

    for (int i = 0; i < songs.size(); i++)  //Printing the most occuring #1 song with its artist and
    {                                      //amount of occurrences
        cout << "        Song Title: " << songs.at(i) << endl
             << "        Artist: " << artist.at(i) << endl
             << "        # of occurrences: " << maxCount << endl;
    }
}//end longestNumOneSong()

//---------------------------------------------------------------------------
// Function to find the song that stayed on the charts for the longest amount of time
// regardless of rank
void longestLastingSong(vector<Data> allData, int decade, int inputYear, char userInput) {
    int longestTime = 0;
    string song, artist;

    if (userInput == 'D' || userInput == 'd') {     //if statement for decade
        for (int i = 0; i < allData.size(); i++) {

            string year;

            // finding the year that the song was made
            int position = allData.at(i).getDate().find_last_of('/');
            year = (allData.at(i).getDate().substr(position + 1, 4));
            if (stoi(year) >= decade && stoi(year) <= (decade + 9)) {

                if (allData.at(i).getWeeksOnBoard() > longestTime) //finding the longest time on
                {                                                 //charts
                    longestTime = allData.at(i).getWeeksOnBoard();
                    song = allData.at(i).getSong();
                    artist = allData.at(i).getArtist();
                }
            }
        }
    } else {
        for (int i = 0; i < allData.size(); i++) {

            string year;

            int position = allData.at(i).getDate().find_last_of('/');
            year = (allData.at(i).getDate().substr(position + 1, 4));

            if (stoi(year) == inputYear)  //if statement for year if it is withen the range
            {                            //user inputted
                if (allData.at(i).getWeeksOnBoard() > longestTime) {
                    longestTime = allData.at(i).getWeeksOnBoard();
                    song = allData.at(i).getSong();
                    artist = allData.at(i).getArtist();
                }
            }
        }
    }
    // Printing the song with artist and amount of time spent on charts
    cout << "The song with the highest number of weeks on the charts is: \n"
         << "        " << song << " by " << artist << " with " << longestTime << " weeks on the chart.";
}//end longestLastingSong()

//---------------------------------------------------------------------------
// Function used to check if the users inputted artist is inside of the vector
// of all artists
void checkArtist(string inputArtist, vector<Data> allData, bool &foundOrNot, string &artist) {

    //transforming both user input and artist from allData to uppercase to be able to compare them
    transform(inputArtist.begin(), inputArtist.end(), inputArtist.begin(), ::toupper);
    for (int i = 0; i < allData.size(); i++) {
        string artistName = allData.at(i).getArtist();
        transform(artistName.begin(), artistName.end(), artistName.begin(), ::toupper);

        if ((artistName.find(inputArtist)) != string::npos)
        {                        //if the artist is found set bool to true and
            foundOrNot = true;  //get the artists full name

            artist = allData.at(i).getArtist();
            break;
        }
    }
}//end checkArtist()

//---------------------------------------------------------------------------
//Function to find the first #1 songs on the charts by the user inputted artist
void firstTenSongs(vector<Data> allData, string artistName) {

    vector<string> numOneSongs;
    vector<string> dates;
    vector<string> artist;

    transform(artistName.begin(), artistName.end(), artistName.begin(), ::toupper);

    for (int i = 0; i < allData.size(); i++) {
        string artists = allData.at(i).getArtist();
        transform(artists.begin(), artists.end(), artists.begin(), ::toupper);

        if ((allData.at(i).getRank() == 1) &&              //if rank is =1 and the artist
            (artists.find(artistName) != string::npos)) { //is found in the list then it adds
                                                         //the song,artist and date to vectors
            numOneSongs.push_back(allData.at(i).getSong());
            dates.push_back(allData.at(i).getDate());
            artist.push_back((allData.at(i).getArtist()));

        }
    }

    //Outputting #1 songs with artist,song,week and position depending on the length of the vector
    if (numOneSongs.size() == 0) {
        cout << "No matching artists were found.";

    } else if (numOneSongs.size() < 10)
    {
        cout << "Retrieval of first 10 #1 records found based upon search by artist name: \n";
        for (int i = 0; i < numOneSongs.size(); i++) {
            cout << i + 1 << ") Song: " << numOneSongs.at(i) << endl
                 << "Artist: " << artist.at(i) << endl
                 << "Week of: " << dates.at(i) << endl
                 << "Week Position: " << "1" << endl;
        }
    } else {
        cout << "Retrieval of first 10 #1 records found based upon search by artist name: \n";

        for (int i = 0; i < 10; i++) {
            cout << i + 1 << ") Song: " << numOneSongs.at(i) << endl
                 << "Artist: " << artist.at(i) << endl
                 << "Week of: " << dates.at(i) << endl
                 << "Week Position: " << "1" << endl;
        }
    }
}//end firstTenSongs()

//---------------------------------------------------------------------------
//Function that controls user input for the second menu option #2
//User either enters Y for year or D for decade and function checks if the inputted number
//is valid within the range of the years selected in the first menu
void menuOptionTwo(char userInput, vector<Data> allData, int decade, int year, int upperYearLimit, int lowerYearLimit) {

    //prompting user to input D or Y
    cout << "Enter D to select a decade or Y to select a year.\n" << "Your choice --> ";
    cin >> userInput;
    while (userInput != 'D' && userInput != 'd' && userInput != 'Y' && userInput != 'y') //checking whether user inputted
    {                                                                                   // a Y or D if not, prompts user to
        cout << "Invalid entry. Try again.\n";                                         // try again
        cout << "Enter D to select a decade or Y to select a year.\n" << "Your choice --> ";
        cin >> userInput;
        if (userInput == 'D' || userInput == 'd' || userInput == 'Y' || userInput == 'y') {
            break;
        }
    }

    if (userInput == 'D' || userInput == 'd') {

        cout << "Enter the decade you would like to choose, as a multiple of 10 (e.g. 2010).";
        cin >> decade;

        decade = decade - decade % 10; //subtracting decade by the remainder when divided by 10
        if (decade < lowerYearLimit || decade > upperYearLimit ) //Checking whether decade is within the range
        {
            cout<< "No songs found in that timeframe. Be sure that the timeframe you enter is within the one covered by the dataset chosen.";
        } else //If the user inputted decade is valid then the function longestNumOneSongs is run to find
        {                                                           // the songs with the most #1 occurrences
            longestNumOneSongs(allData, decade, year, userInput);
        }

    } else if (userInput == 'Y' || userInput == 'y')
    {
        cout << "Enter the year you would like to choose (e.g. 2001).";
        cin >> year;
        if (year < lowerYearLimit || year > upperYearLimit) //Checking whether year is within the correct range
        {
            cout<< "No songs found in that timeframe. Be sure that the timeframe you enter is within the one covered by the dataset chosen.";
        } else //If the user inputted decade is valid then the function longestNumOneSongs is run to find
        {                                                           //the songs with the most #1 occurrences
            longestNumOneSongs(allData, decade, year, userInput);
        }
    }
} //end menuOptionTwo()

//---------------------------------------------------------------------------
//Function that controls user input for the second menu option #3
//User either enters Y for year or D for decade and function checks if the inputted number
//is valid within the range of the years selected in the first menu
void menuOptionThree(char userInput, vector<Data> allData, int decade, int year, int upperYearLimit, int lowerYearLimit) {

    //prompting user to input either Y for year of D for decade
    cout << "Enter D to select a decade or Y to select a year.\n"
         << "Your choice --> ";

    cin >> userInput;
    while (userInput != 'D' && userInput != 'd' && userInput != 'Y' && userInput != 'y')
    {                                     //checking whether user inputteda Y or D, if not prompts user to try again
        cout << "Invalid entry. Try again.\n";
        cout << "Enter D to select a decade or Y to select a year.\n"
             << "Your choice --> ";
        cin >> userInput;

        if (userInput == 'D' || userInput == 'd' || userInput == 'Y' || userInput == 'y') {
            break;
        }
    }
    if (userInput == 'D' || userInput == 'd') {

        cout << "Enter the decade you would like to choose, as a multiple of 10 (e.g. 2010).";
        cin >> decade;
        decade = decade - decade % 10;  //subtracting decade by the remainder when divided by 10

        if (decade < lowerYearLimit || decade > upperYearLimit ) //Checking whether decade is within the range
        {
            cout<< "No songs found in that timeframe. Be sure that the timeframe you enter is within the one covered by the dataset chosen.";

        } else      //if decade is within the range then the function longestLastingSong() is called to find the song
        {          //that had the longest duration on the charts
            longestLastingSong(allData, decade, year, userInput);

        }

    } else if (userInput == 'Y' || userInput == 'y')
    {
        cout << "Enter the year you would like to choose (e.g. 2001).";
        cin >> year;

        if (year < lowerYearLimit || year > upperYearLimit)  //Checking whether year is within the range
        {
            cout<< "No songs found in that timeframe. Be sure that the timeframe you enter is within the one covered by the dataset chosen.";

        } else      //if decade is within the range then the function longestLastingSong() is called to find the song
        {          ////that had the longest duration on the charts
            longestLastingSong(allData, decade, year, userInput);
        }
    }
}//end menuOptionThree()

//---------------------------------------------------------------------------
//Function used to output the header of the Program
void displayProgramHeader()
{
    cout << "Program 4: BillBoard Analysis \n"
         << "CS 141, Spring 2022, UIC \n " << endl
         << "This program will analyze weekly Billboard data spanning from 1960 - 2020.\n\n";
}//end displayProgramHeader()

//---------------------------------------------------------------------------
//Function used to get the users input when there is a space involved in
//the name inputted, used to ignore the space and continue collecting input
void getUserInput(string &userInput) {
    getline(cin, userInput);
}//end getUserInput()

//---------------------------------------------------------------------------
//Function that controls user input for the second menu option #5
//Prompts the user to input a name of an artist, checks if the artists
//is a valid artist name for the year or decade then outputs the first
//10 #1 ranked songs by that artist with any features
void menuOptionFive(string inputArtistName, string fullArtistName, bool foundOrNot, vector<Data> allData) {

    cout << "Enter search text to retrieve first 10 records of #1 songs that match by artist name: ";
    getUserInput(inputArtistName); //calling getUserInput twice to ignore any space that the user
    getUserInput(inputArtistName);//inputs

    //Checking whether the artist name is inside of the vector for the user inputted year or decade
    checkArtist(inputArtistName, allData, foundOrNot, fullArtistName); //if found bool foundOrNot is set
                                                                      // to true
    if (foundOrNot) //if bool foundOrNot is true then the function firstTenSongs() is called to find the
    {              //first ten #1 ranked songs by the artist with any features else if false
        firstTenSongs(allData, inputArtistName);    //No matching artists is outputted
    } else {
        cout << "No matching artists were found.";
    }
}//end menuOptionFive()

//---------------------------------------------------------------------------
//Function used to calculate the greatest climb in charts rank and returning that
//value
int greatestWeeklyClimb(vector<Data> allData, int decade, int inputYear, int userInput) {

    int maxClimb = 0, climb = 0;    //initializing maxClimb and climb to 0, climb used to calculate each songs climb
    string song, artist, week;      //strings to store data                 //and maxClimb to find the largest value
    int prevWeek, curWeek;          // integers for previous week rank and current week ranks

    if (userInput == 'D' || userInput == 'd') {

        for (int i = 0; i < allData.size(); i++) {
            string year;

            int position = allData.at(i).getDate().find_last_of('/'); //finding position of last "/" in date format
            year = (allData.at(i).getDate().substr(position + 1, 4)); //extracting year from full date

            if (stoi(year) >= decade && stoi(year) <= (decade + 9)) //getting only data within the decade
            {
                if (allData.at(i).getLastWeek() == 0) { //skipping any song that had no previous ranking
                    continue;

                } else if (allData.at(i).getRank() < allData.at(i).getLastWeek())
                {
                    climb = allData.at(i).getLastWeek() - allData.at(i).getRank(); //calculating rank climb
                    if (climb > maxClimb)                       //by subtracting last weeks rank by current weeks only
                    { //getting highest climb value            // if current week is larger than last weeks rank
                        maxClimb = climb;
                    }
                }
            }
        }
        return maxClimb;    //returning value of maxClimb

    } else {
        for (int i = 0; i < allData.size(); i++) {

            string year;

            int position = allData.at(i).getDate().find_last_of('/');//finding position of last "/" in date format
            year = (allData.at(i).getDate().substr(position + 1, 4));//extracting year from full date

            if (stoi(year) == inputYear) //getting only data within the given year
            {
                if (allData.at(i).getLastWeek() == 0) //skipping any song that had no previous ranking
                {
                    continue;
                }
                else if (allData.at(i).getRank() < allData.at(i).getLastWeek())
                {   //calculating value of climb
                    climb = allData.at(i).getLastWeek() - allData.at(i).getRank();
                    if (climb > maxClimb)
                    {   //finding max climb value
                        maxClimb = climb;
                    }
                }
            }
        }
    }
    return maxClimb; //returning value of maxClimb
}//end greatestWeeklyClimb()

//---------------------------------------------------------------------------
//Function output the songs that had the greatest climb along with their artists,
//date,last week rank and current rank
void greatestClimbOutput(vector<Data> allData, int decade, int inputYear, int userInput) {
    //calling in function greatestWeeklyClimb() to find the largest rank climb and setting it to int maxClimb
    int maxClimb = greatestWeeklyClimb(allData, decade, inputYear, userInput), climb = 0;
    string song, artist, week;  // declaring strings used to store data
    int prevWeek, curWeek;      //declaring integers to store last weeks rank in prevWeek and current weeks rank in
    vector<string> songs;       // vector to store songs that match maxClimb                              //curWeek
    vector<string> artists;     // vector to store artists that match the song
    vector<string> dates;       //vector to store song release dates
    vector<int> lastWeekRank;   //vector to store songs rank from last week
    vector<int> currentRank;    //vector to store a songs current rank

    if (userInput == 'D' || userInput == 'd')
    {
        for (int i = 0; i < allData.size(); i++) {

            string year;

            int position = allData.at(i).getDate().find_last_of('/');//finding position of last "/" in date format
            year = (allData.at(i).getDate().substr(position + 1, 4));//extracting year from full date
            if (stoi(year) >= decade && stoi(year) <= (decade + 9))
            {
                if (allData.at(i).getLastWeek() == 0)
                {
                    continue; //skipping any song that didnt have a last week rank
                }
                else if (allData.at(i).getRank() < allData.at(i).getLastWeek())
                {   //calculating a songs rank climb
                    climb = allData.at(i).getLastWeek() - allData.at(i).getRank();
                    if (climb == maxClimb) //if the songs climb matches the maxClimb then store the songs information
                    {                       //in the vector along with its artist date,last week rank and current rank
                        songs.push_back(allData.at(i).getSong());
                        artists.push_back(allData.at(i).getArtist());
                        dates.push_back(allData.at(i).getDate());
                        lastWeekRank.push_back(allData.at(i).getLastWeek());
                        currentRank.push_back(allData.at(i).getRank());
                    }
                }
            }
        }
    } else {

        for (int i = 0; i < allData.size(); i++) {

            string year;

            int position = allData.at(i).getDate().find_last_of('/');//finding position of last "/" in date format
            year = (allData.at(i).getDate().substr(position + 1, 4));//extracting year from full date

            if (stoi(year) == inputYear) //only getting data that matches the input year
            {
                if (allData.at(i).getLastWeek() == 0) {
                    continue;
                }
                else if (allData.at(i).getRank() < allData.at(i).getLastWeek()) {
                    climb = allData.at(i).getLastWeek() - allData.at(i).getRank();

                    if (climb == maxClimb) {
                        songs.push_back(allData.at(i).getSong());
                        artists.push_back(allData.at(i).getArtist());
                        dates.push_back(allData.at(i).getDate());
                        lastWeekRank.push_back(allData.at(i).getLastWeek());
                        currentRank.push_back(allData.at(i).getRank());
                    }
                }
            }
        }
    }
    //outputting the song with the greatest climb with its information
    cout << "The song(s) with the greatest climb from previous week to current week position: \n";

    for (int i = 0; i < songs.size(); i++) {
        cout << "        Song Title: " << songs.at(i) << "\n" <<
             "         Artist: " << artists.at(i) << "\n" <<
             "         Week of: " << dates.at(i) << "\n" <<
             "         Previous Week Position: " << lastWeekRank.at(i) << "\n" <<
             "         Current Week Position: " << currentRank.at(i) << "\n" <<
             "         Difference of " << maxClimb << " between previous week and current week position\n";
    }
}//end greatestClimbOutput()

//---------------------------------------------------------------------------
//Function that controls user input for the second menu option #4
//User either enters Y for year or D for decade and function checks if the inputted number
//is valid within the range of the years selected in the first menu
void menuOptionFour(char userInput, vector<Data> allData, int decade, int year, int upperYearLimit, int lowerYearLimit) {

    //prompting user to input either Y for year of D for decade
    cout << "Enter D to select a decade or Y to select a year.\n"
         << "Your choice --> ";

    cin >> userInput;
    while (userInput != 'D' && userInput != 'd' && userInput != 'Y' && userInput != 'y')
    {                                     //checking whether user inputteda Y or D, if not prompts user to try again
        cout << "Invalid entry. Try again.\n";
        cout << "Enter D to select a decade or Y to select a year.\n"
             << "Your choice --> ";
        cin >> userInput;

        if (userInput == 'D' || userInput == 'd' || userInput == 'Y' || userInput == 'y') {
            break;
        }
    }
    if (userInput == 'D' || userInput == 'd') {

        cout << "Enter the decade you would like to choose, as a multiple of 10 (e.g. 2010).";
        cin >> decade;
        decade = decade - decade % 10; //subtracting decade by the remainder when divided by 10

        if (decade < lowerYearLimit || decade > upperYearLimit) //Checking whether decade is within the range
        {           //if not in the range output this
            cout<< "No songs found in that timeframe. Be sure that the timeframe you enter is within the one covered by the dataset chosen.";

        } else //else call function greatestClimbOutput() to output the song with the greatest climb
        {
            greatestClimbOutput(allData, decade, year, userInput);
        }

    } else if (userInput == 'Y' || userInput == 'y')
    {
        cout << "Enter the year you would like to choose (e.g. 2001).";
        cin >> year;
        if (year < lowerYearLimit || year > upperYearLimit) //if year inputted not in the range output
        {                                                   //below
            cout<< "No songs found in that timeframe. Be sure that the timeframe you enter is within the one covered by the dataset chosen.";
        }
        else {
            //else call function greatestClimbOutput() to output the song with the greatest climb
            greatestClimbOutput(allData, decade, year, userInput);
        }
    }
}//end menuOptionFour()

//---------------------------------------------------------------------------
//Function used to get user input for the second menu options
void menuTwo(int menuTwoOption, vector<Data> allData, int upperYearLimit, int lowerYearLimit) {
    //while the user doesnt input 6 the program keeps asking for a new menuOption
    while (menuTwoOption != 6) {

        //calling menuTwoOptions() showing the user their options to chose from
        menuTwoOptions();
        cin >> menuTwoOption; //getting user input

        if (!cin || menuTwoOption > 6 || menuTwoOption < 1) //if the menuOption is out of the range 1-6
        {                                           //prompt user to re input a menu option
            cout << "\nInvalid value.  Please re-enter a value from the menu options below.\n";
            continue;
        }
        else if (menuTwoOption == 1) //if user inputs 1 then call function uniqueSongs to display
        {                           //general information about the dataset that has been read in.
            int countSongs;
            vector<string> songs;
            countSongs = uniqueSongs(allData, songs);
            cout << "Total number of rows: " << allData.size() << endl
                 << "Number of unique songs represented in the dataset: " << countSongs;

        } else if (menuTwoOption == 2) //if user inputs 2 then call function menuOptionTwo() to display
        {                             // the Billboard info of the song with the most #1 occurrences for
            char userInput;         // a given decade or year.
            int decade, year;

            menuOptionTwo(userInput, allData, decade, year, upperYearLimit, lowerYearLimit);

        } else if (menuTwoOption == 3) //if user inputs 3 then call function menuOptionThree() to display
        {                             //the Billboard info for the most long-lasting song on the charts for
            char userInput;          // a given decade or year
            int decade, year;
            menuOptionThree(userInput, allData, decade, year, upperYearLimit, lowerYearLimit);

        } else if (menuTwoOption == 4) //if user inputs 3 then call function menuOptionThree() to display
        {                             //the Billboard info for the song with the greatest weekly climb on
            char userInput;          //the charts given a decade or year.
            int decade, year;
            menuOptionFour(userInput, allData, decade, year, upperYearLimit, lowerYearLimit);

        } else if (menuTwoOption == 5)//if user inputs 3 then call function menuOptionThree() to display
        {                            //Return the Billboard info for records that matches user input for artist search.
            string inputArtisitName;//Displays the firs ten #1 songs
            string fullArtistName;
            bool foundOrNot = false;
            menuOptionFive(inputArtisitName, fullArtistName, foundOrNot, allData);
        }
    }
}//end menuTwo()

int main() {
    int menuOption, menuTwoOption;  // Integers to store user input for menu 1 & 2
    string fileName;               // String to hold CSV file name
    vector<Data> allData;         // Vector to hold all the CSV file information when called in

    // Call function displayProgramHeader() to output the programs information
    displayProgramHeader();

    // Prompting user to input a menu option
    cout << "Select file option:\n"
         << "   1. To analyze charts top 50: 1960 - 1980 data file\n"
         << "   2. To analyze charts top 50: 1981 - 2000 data file\n"
         << "   3. To analyze charts top 50: 2001 - 2020 data file\n"
         << "Your choice --> \n";
    cin >> menuOption;

    // If menuOption not in the range 1-3, exit the program
    if (!cin || menuOption > 3 || menuOption < 1) {
        cout << "Invalid value. Exiting Program.";
    }

    if (menuOption == 1) //Data for when menuOption 1 is chosen
    {
        fileName = "charts_top50_1960_1980.csv"; // Name of CSV file to read
        readToVector(fileName, allData);    // Calling function to read CSV file into vector
        int upperYearLimit = 1980;         // Upper limit of song release year
        int lowerYearLimit = 1960;        // Lower Limit of song release year
        menuTwo(menuTwoOption, allData, upperYearLimit, lowerYearLimit);//Calling function MenuTwo to prompt user
                                                                       //to enter a value for the second menu
    } else if (menuOption == 2) //Data for when menuOption 2 is chosen
    {
        fileName = "charts_top50_1981_2000.csv"; // Name of CSV file to read
        readToVector(fileName, allData);  // Calling function to read CSV file into vector
        int upperYearLimit = 2000;       // Upper limit of song release year
        int lowerYearLimit = 1980;      // Lower Limit of song release year
        menuTwo(menuTwoOption, allData, upperYearLimit, lowerYearLimit);//Calling function MenuTwo to prompt user
                                                                       //to enter a value for the second menu
    } else if (menuOption == 3) //Data for when menuOption 3 is chosen
    {
        fileName = "charts_top50_2001_2020.csv"; // Name of CSV file to read
        readToVector(fileName, allData);// Calling function to read CSV file into vector
        int upperYearLimit = 2020;     // Upper limit of song release year
        int lowerYearLimit = 2000;    // Lower Limit of song release year
        menuTwo(menuTwoOption, allData, upperYearLimit, lowerYearLimit); //Calling function MenuTwo to prompt user
                                                                        //to enter a value for the second menu
    }
    return 0;

}//end of Main



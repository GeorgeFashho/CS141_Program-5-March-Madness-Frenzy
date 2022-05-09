/* ---------------------------------------------
Program 5: March Madness Frenzy
--
    A C++ program that reads in data from NCAA Basketball Tournaments (aka March Madness) and then
    provides information regarding that data. User is prompted to input a csv file name and asked
    to choose a menu option that will display various data about the tournaments.
--

Course: CS 141, Spring 2022
System: Windows 10 Using Clion
Authors: George Fashho
---------------------------------------------
*/

#include <iostream>   // For Input and Output
#include <vector>     // For vectors
#include <fstream>    // For file input and output
#include <cassert>    // For the assert statement used to validate file open
#include <string>     // To manipulate strings
#include <sstream>    // Stream Class to Operate on strings
#include <algorithm>  // Allows using transform() and unique() function

using namespace std;

class Data {

private:    //private members
    string region,teamOne,teamTwo,winningTeam;
    int rankOne,scoreOne,rankTwo,scoreTwo,roundNum,gameNum;

public:

    void printWinningTeam() ;   //utility function to print winning team

    Data(){                 //default constructor
        region,teamOne,teamTwo,winningTeam = " ";
        rankOne,scoreOne,rankTwo,scoreTwo,roundNum,gameNum  = 0 ;
    }

    Data(string region , int rankOne , string teamOne , int scoreOne , int rankTwo , string teamTwo ,
         int scoreTwo , string winningTeam , int roundNum , int gameNum){   //fully qualified constructor
                                                                //setter functions
        this->region = region;
        this->rankOne = rankOne;
        this->teamOne = teamOne;
        this->scoreOne = scoreOne;
        this->rankTwo = rankTwo;
        this->teamTwo = teamTwo;
        this->scoreTwo = scoreTwo;
        this->winningTeam = winningTeam;
        this->roundNum = roundNum;
        this-> gameNum = gameNum;
    }
                            //getter functions
    string getRegion(){
        return region;
    }
    string getTeamOne(){
        return teamOne;
    }
    string getTeamTwo(){
        return teamTwo;
    }
    string getWinningTeam(){
        return winningTeam;
    }
    int getRankOne(){
        return rankOne;
    }
    int getRankTwo(){
        return rankTwo;
    }
    int getScoreOne(){
        return scoreOne;
    }
    int getScoreTwo(){
        return scoreTwo;
    }
    int getRoundNum(){
        return roundNum;
    }
    int getGameNum(){
        return gameNum;
    }
};

void Data::printWinningTeam() { //utility function that prints the winning team

    cout<<winningTeam<<endl;
}

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
                                                //  one string
        string region,teamOne,teamTwo,winningTeam,tempString ;
        int rankOne,scoreOne,rankTwo,scoreTwo,roundNum,gameNum ;

        // Splitting up the inputString into individual elements whenever there is "," found
        getline(inputString, region, ',');
        getline(inputString, tempString, ',');
        rankOne = atoi(tempString.c_str());            // Storing a string element into a temp string
        getline(inputString, teamOne, ',');          // and converting it into an integer using
        getline(inputString, tempString, ',');
        scoreOne = atoi(tempString.c_str());
        getline(inputString, tempString, ',');
        rankTwo = atoi(tempString.c_str());
        getline(inputString, teamTwo, ',');
        getline(inputString, tempString, ',');
        scoreTwo = atoi(tempString.c_str());
        getline(inputString, winningTeam, ',');
        getline(inputString, tempString, ',');
        roundNum = atoi(tempString.c_str());
        getline(inputString, tempString,',');
        gameNum = atoi(tempString.c_str());

        // Storing all the extracted data from the line into a class and
        // storing it into a single vector using push_back();
        Data data1(region,rankOne,teamOne,scoreOne,rankTwo,teamTwo,scoreTwo,winningTeam,roundNum,gameNum);
        allData.push_back(data1);
        line = "";
    }
} //end readToVector()

//---------------------------------------------------------------------------
// Function to display menu options for user to choose from
void menuOptions(){

    cout<<"\n"
          "Select a menu option: \n"
          "   1. Display overall information about the data\n"
          "   2. Display the path of the winning team to the championship\n"
          "   3. Determine which region is expected to win the championship based on a given round\n"
          "   4. Identify the best underdog within a given round\n"
          "   5. Find the shoo-in and nail-biting games within a given round, or overall\n"
          "   6. Compare the actual brackets to your predicted brackets\n"
          "   7. Exit\n"
          "Your choice --> \n";
}//end menuOptions()

//---------------------------------------------------------------------------
// Function to display the program header and game instruction
void starterMenu(){

    cout<<"Program 5: March Madness Frenzy\n"
          "CS 141, Spring 2022, UIC\n"
          "\n"
          "This program reads in data from NCAA Basketball Tournaments (aka March \n"
          "Madness). It provides overall information regarding the data, allows you to \n"
          "see the path taken to the championship, uses rankings of teams to determine \n"
          "which region is expected to win at a given round and to find the best underdog \n"
          "team, and calculates point differences within the games. You can also compare \n"
          "the actual brackets to your own predictions!\n";
}//end starterMenu()

//---------------------------------------------------------------------------
// Function to display sub-menu options for every menu options 3,4, and 5
void roundSelectionMenus(int menuOption){

    switch(menuOption){             //switch that takes the users inputted menu option

        case 3:
            cout<<"Enter a round to be evaluated: \n"
                  "   Select 2 for round 2\n"
                  "   Select 3 for round 3 'Sweet 16'\n"
                  "   Select 4 for round 4 'Elite 8'\n"
                  "   Select 5 for round 5 'Final 4'\n"
                  "Your choice --> ";
            break;

        case 4:
            cout<<"Enter a round to be evaluated: \n"
                  "   Select 2 for round 2\n"
                  "   Select 3 for round 3 'Sweet 16'\n"
                  "   Select 4 for round 4 'Elite 8'\n"
                  "   Select 5 for round 5 'Final 4'\n"
                  "   Select 6 for round 6 'Championship'\n"
                  "Your choice --> \n";
            break;

        case 5:
            cout<<"Enter a round to be evaluated: \n"
                  "   Select 1 for round 1\n"
                  "   Select 2 for round 2\n"
                  "   Select 3 for round 3 'Sweet 16'\n"
                  "   Select 4 for round 4 'Elite 8'\n"
                  "   Select 5 for round 5 'Final 4'\n"
                  "   Select 6 for round 6 'Championship'\n"
                  "   Select 7 for the overall tournament\n"
                  "Your choice --> \n";
            break;
    }
}//end roundSelectionMenus()

//---------------------------------------------------------------------------
// Function to extract every region one time from the vector that holds the data
int uniqueRegions(vector<Data> allData, vector<string> &regions) {

    for (int i = 0; i < allData.size(); i++) {
        if (find(regions.begin(), regions.end(), allData.at(i).getRegion()) != regions.end()) {
            continue;       //checking if the region has already been extracted and skipping if it's not unique

        } else {
            if(allData.at(i).getRegion() == "Championship" || allData.at(i).getRegion() == "Final Four" )
                continue;       //skipping any value that isn't a region
            else
                regions.push_back(allData.at(i).getRegion());   //adding the unique regions into a vector
        }
    }
} //end uniqueRegions()

//---------------------------------------------------------------------------
// Function to find who is most expected to win the championship
void expectedChampionshipWinner(int round, vector<Data>allData ){

    string expectedWinningRegion,teamName;
    int rank=0;
    int lowestRank = 10000;
    if(round == 5){

        // for loop that finds if the round number is 5 and finding which team has the lowest rank
       // in that round for both team1 and team2
        for(int i = 0 ; i < allData.size() ; i++){
            if(allData.at(i).getRoundNum() == 5){
                rank = allData.at(i).getRankOne(); //getting the rank of team one

                if(rank<lowestRank){
                    teamName = allData.at(i).getTeamOne();  //checking to see if it has the lowest ranking and
                    lowestRank = rank;                        //changing the lowest rank to that if it is
                }
                rank = allData.at(i).getRankTwo();  //getting the rank of the team two

                if(rank<lowestRank){
                    teamName = allData.at(i).getTeamTwo();//checking to see if it has the lowest ranking and
                    lowestRank = rank;                        //changing the lowest rank to that if it is
                }
            }
        }

        for(int i = 3 ; i< allData.size();i++){     //for loop to find the region of the winning team
            if(allData.at(i).getTeamTwo() == teamName || allData.at(i).getTeamOne() == teamName){
                expectedWinningRegion = allData.at(i).getRegion();
                break;
            }
        }

        cout<<"The region expected to win is: "<<expectedWinningRegion; //outputting the expected winner
    }
    else{
        vector<string>regions; //vector to hold unique regions
        vector<int>ranks;       //vector to hold total rank of all teams in a region
        uniqueRegions(allData,regions);

        for(int j = 0 ; j < regions.size(); j++) {  //nested for loop to loop through all the data for every unique
            for (int i = 0; i < allData.size(); i++) {  //region there is

                if (allData.at(i).getRoundNum() == round) {
                    if(allData.at(i).getRegion() == regions.at(j)){

                        if(allData.at(i).getWinningTeam() == allData.at(i).getTeamOne()){
                            rank += allData.at(i).getRankOne();
                        }
                        else{
                            rank += allData.at(i).getRankTwo();
                        }
                    }
                }
            }
            ranks.push_back(rank);
            rank = 0 ;
        }

        int lowestRank = 10000 ;
        for(int i = 0 ; i < ranks.size() ; i++) {   //finding what the lowest ranking region is

            if(ranks.at(i)<lowestRank){
                lowestRank = ranks.at(i);
            }
        }
        int vectorLocation; //finding the index of the region in the vector
        __gnu_cxx::__normal_iterator<int *, vector<int>> location;  //finding the iterator of the element

        location = find(ranks.begin(),ranks.end(),lowestRank);
        vectorLocation = location - ranks.begin();

        cout<<"The region expected to win is: "<<regions.at(vectorLocation); //outputting the region that is expected
    }                                                                          //to win
}

//---------------------------------------------------------------------------
// Function to find the underdog team, the team with the lowest ranking in a specific round
void underdogTeam(int round, vector<Data>allData){

    int rank ;
    int highestRank = 0 ;
    string underDogTeam;

    for(int i = 0 ; i < allData.size() ; i++){ //for loop to go through all the data in the vector

        if(allData.at(i).getRoundNum() == round){   // seeing if the games round number is equal to the user
            rank = allData.at(i).getRankOne();  //getting the rank for team one           // inputted round

            if(rank>highestRank) {  //finding what the highest rank was
                highestRank = rank;
                underDogTeam = allData.at(i).getTeamOne();
            }

            rank = allData.at(i).getRankTwo();  //getting the rank for team two

            if(rank>highestRank){
                highestRank = rank;
                underDogTeam = allData.at(i).getTeamTwo();  //checking for the highest rank and setting that team
                                                              //to be the underdog team
            }
        }
    }
    cout<<"The best underdog team is "<<underDogTeam<<" which has rank "<<highestRank<<"."; //outputting underdog
}                                                                                          //team with rank

//---------------------------------------------------------------------------
// function to find the shoo-in and nail-biting games
void shooInAndNailBitingGames(int roundNum, vector<Data>allData){

    int shooInMax = 0,nailBitingMax = 1000;
    int gameNumShooIn,gameNumNailBiting,roundNumShooIn,roundNumNailBiting;  //declaring integers & strings
    string teamOneShooIn,teamTwoShooIn,winningTeamShooIn,teamOneNailBiting,teamTwoNailBiting,winningTeamNailBiting;

    if(roundNum<7){ //when round is less than 7 for loop only evaluates values of the inputted round
        for(int i = 0 ; i<allData.size(); i++ ){
            if(allData.at(i).getRoundNum() == roundNum ){

                //calculating the difference of score between two teams for all the games of the round
                int shooIn = abs(allData.at(i).getScoreOne() - allData.at(i).getScoreTwo());

                if(shooIn>shooInMax){   //finding the largest difference in score between two teams
                    shooInMax=shooIn;
                    teamOneShooIn=allData.at(i).getTeamOne(); //getting the shooIn team One
                    teamTwoShooIn=allData.at(i).getTeamTwo();//getting the shooIn team Two
                    winningTeamShooIn = allData.at(i).getWinningTeam();//getting the winning team
                    gameNumShooIn = allData.at(i).getGameNum();//getting the shooIn game number
                    roundNumShooIn = allData.at(i).getRoundNum();//getting the shooIn round number
                }

                //calculating the difference of score between two teams for all the games of the round
                int nailBiting = abs(allData.at(i).getScoreOne()-allData.at(i).getScoreTwo());

                if(nailBiting<nailBitingMax){   //finding the lowest difference in score between two teams
                    nailBitingMax=nailBiting;
                    teamOneNailBiting=allData.at(i).getTeamOne(); //getting the nailBiting team One
                    teamTwoNailBiting=allData.at(i).getTeamTwo(); //getting the nailBiting team Two
                    winningTeamNailBiting = allData.at(i).getWinningTeam(); //getting the winning team
                    gameNumNailBiting = allData.at(i).getGameNum(); //getting the game number
                    roundNumNailBiting = allData.at(i).getRoundNum(); //getting the round number
                }
            }
        }
    }
    else{
        for(int i = 0 ; i<allData.size(); i++ ) {   //looping through all of the data in the csv file
            //calculating the difference of score between two teams for all the games of the round
            int shooIn = abs(allData.at(i).getScoreOne() - allData.at(i).getScoreTwo());

            if (shooIn > shooInMax) {
                shooInMax = shooIn;
                teamOneShooIn = allData.at(i).getTeamOne();
                teamTwoShooIn = allData.at(i).getTeamTwo();
                winningTeamShooIn = allData.at(i).getWinningTeam();
                gameNumShooIn = allData.at(i).getGameNum();
                roundNumShooIn = allData.at(i).getRoundNum();
            }
            //calculating the difference of score between two teams for all the games of the round
            int nailBiting = abs(allData.at(i).getScoreOne() - allData.at(i).getScoreTwo());

            if (nailBiting < nailBitingMax) {
                nailBitingMax = nailBiting;
                teamOneNailBiting = allData.at(i).getTeamOne();
                teamTwoNailBiting = allData.at(i).getTeamTwo();
                winningTeamNailBiting = allData.at(i).getWinningTeam();
                gameNumNailBiting = allData.at(i).getGameNum();
                roundNumNailBiting = allData.at(i).getRoundNum();
            }
        }
    }
    //outputting the shoo-in and nail-biting game information
    cout<<"The shoo-in game was: \n"
          "Round "<<roundNumShooIn<<", Game "<<gameNumShooIn<<": "<<teamOneShooIn<< " vs " <<teamTwoShooIn<<". Winner: "
        <<winningTeamShooIn<<"\n"
        <<"The difference was "<<shooInMax<<" points.\n"
        <<"\n"
        <<"The nail-biting game was: \n"
          "Round "<<roundNumNailBiting<<", Game "<<gameNumNailBiting<<": "<<teamOneNailBiting<<" vs "<<teamTwoNailBiting
        <<". Winner: "<<winningTeamNailBiting<<"\n"<<
        "The difference was "<<nailBitingMax<<" points.";
}

//---------------------------------------------------------------------------
// Function that checks how many of your predictions were correct and
//calculating a score based on that
void predictedOutcomes(vector<Data>allData, vector<Data>predictedData){

    int score = 0,count = 0;

    for(int i = 0 ; i < allData.size() ; i++){  //for loop to go through all data and checking if actual winning team -
        if(allData.at(i).getWinningTeam() == predictedData.at(i).getWinningTeam()){ //is equal to the prediction
            count++;    //if they are equal increase count by one
            score = score + (allData.at(i).getRoundNum()*5);    //calculate score by multiplying the game round by 5
        }
    }
    //outputting the statistics of the predictions
    cout<<"You correctly predicted the winner for "<<count<<" games.\n"
        <<"This means that you have a score of "<<score<<".\n";
    if(score>=250) {
        cout << "Great job! You could consider entering your predictions to win money!";

    }else{
        cout<<" You may want to learn more about basketball to improve your predictions next year.";
    }
}

//---------------------------------------------------------------------------
// function to find the total number of games played in the tournament along with the final
// four teams and their regions
void finalFourTeams(vector<Data>allData, vector<string>&finalFourTeams, vector<string>regions){

    for(int i = 0 ; i < allData.size() ; i++){  //looping through all the data and getting all the teams that are at
        if(allData.at(i).getRoundNum() == 4){   //round number 4 and pushing it into a vector
            finalFourTeams.push_back(allData.at(i).getWinningTeam());
        }
    }

    //outputting the total number of games and final four teams with their regions
    cout<<"Total number of games played in tournament: "<<allData.size()<<endl
        <<"The Final Four contestants are: "<<endl;

    for(int i = 0 ; i< regions.size() ; i++){
        cout<<regions.at(i)<<" region: "<<finalFourTeams.at(i)<<endl;
    }
}

//---------------------------------------------------------------------------
// function to find the path taken for the winner of the tournament
void pathsOfWinningTeams(vector<Data>allData){

    vector<Data>winningTeamPaths;   //vector to hold all the winning games of the winner
    string winningTeam = allData.at(0).getWinningTeam(); //getting the winner of the tournament

    for(int i = 0 ; i < allData.size() ; i++){  //looping through all the data and finding every game that the winning
        if(allData.at(i).getTeamOne() == winningTeam ||                                         //team played and won
           allData.at(i).getTeamTwo() == winningTeam  ){
            string teamOne,teamTwo;
            int gameNum ;
            teamOne = allData.at(i).getTeamOne();
            teamTwo = allData.at(i).getTeamTwo();
            gameNum = allData.at(i).getGameNum();
            Data winningTeamPath(" ",0,teamOne,0,0,teamTwo,0," ",0,gameNum);
            winningTeamPaths.push_back(winningTeamPath);
        }
    }

    //reversing the vector to print the data in the correct order
    reverse(winningTeamPaths.begin(),winningTeamPaths.end());

    //outputting every game played by the winning team and who they were against
    cout<<"Path to the championship: \n";
    for(int j = 0 ; j<winningTeamPaths.size(); j++){

        cout<<"Round "<<j+1<<", "<<"Game "<<winningTeamPaths.at(j).getGameNum()<<
            ": "<<winningTeamPaths.at(j).getTeamOne()<< " vs "<<winningTeamPaths.at(j).getTeamTwo()<<
            ". Winner: "<<winningTeam<<endl ;
    }
}

// ----------------------------------------------------------------------
// Main() function of the program
int main() {

    int userMenuOption;         // integer to hold to menu option the user chooses
    vector<Data>allData;       // vector to hold all the data from the first CSV user inputs
    string fileName;          // string to hold the name of the csv file inputted

    starterMenu();           // outputting the starter menu
    cout<<"Enter the name of the file with the data for the NCAA tournament: ";
    cin>>fileName;      // taking an input for the csv file name

    readToVector(fileName,allData);     //calling a function to read the csv file contents into a vector

    while(userMenuOption !=7){      //while loop to keep asking for user input as long as menu option isn't 7

        menuOptions();          //outputting the menu
        cin >> userMenuOption;      //taking user input and checking if it's in the range (1-6), if not ask user to
                                   // re-enter a menu optiion and try again.
        if(userMenuOption > 7 || userMenuOption < 1){
            cout<<"Invalid value.  Please re-enter a value from the menu options below.\n";
            continue;
        }
        else if(userMenuOption == 1){

            vector<string>regions;    //vector to hold regions of the final four teams
            vector<string>finalFour; //vector to hold the final four teams
            uniqueRegions(allData,regions); //calling function uniqueRegions() to get one copy of every region from the
            finalFourTeams(allData,finalFour,regions);  //calling function finalFourTeams()                  //csv
        }
        else if (userMenuOption == 2){
            pathsOfWinningTeams(allData);   //calling function pathsOfWinningTeams()
        }
        else if (userMenuOption == 3){

            int userRoundInput; // integer to hold the round inputted by the user
            roundSelectionMenus(userMenuOption);    //outputting menu options for rounds
            cin>>userRoundInput;
            cout<<"Analyzing round "<<userRoundInput<<"...\n";
            expectedChampionshipWinner(userRoundInput,allData); // calling function expectedChampionshipWinner()
        }
        else if (userMenuOption == 4){

            int userRoundInput;
            roundSelectionMenus(userMenuOption);
            cin>>userRoundInput;
            underdogTeam(userRoundInput,allData); // calling function underdogTeam()

        }
        else if (userMenuOption == 5){

            int userRoundInput;
            roundSelectionMenus(userMenuOption);

            cin>>userRoundInput;
            if(userRoundInput<7) {
                cout << "Analyzing round " << userRoundInput << "...\n";
            }else{
                cout<<"Analyzing the overall tournament...";
            }
            shooInAndNailBitingGames(userRoundInput,allData); // calling function shooInAndNailBitingGames()
        }
        else if (userMenuOption == 6){

            string predictedBracketsFileName;
            vector<Data>predictedData; //vector to hold data from predictions csv

            cout<<"Enter the name of the file with your predicted brackets: \n";
            cin>>predictedBracketsFileName;
            readToVector(predictedBracketsFileName,predictedData);  //reading csv into vector
            predictedOutcomes(allData,predictedData);   //calling function predictedOutcomes()
        }
    }//end while()
    cout<<"Exiting program...";

    return 0;
}//end main()

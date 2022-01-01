/****
 * Title: Project 2 Playlist System
 * Course: Computational Problem Solving II (CPET-321.01.2211)
 * Developer: Yin Hinton
 * Date: Nov 6, 2021
 * Description: [Main.cpp]Using supporting files, opens a link to a youtube window and plays the video
 ***/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include "Song.h"

using namespace std;
//	QUESTIONS:
//how to deal with quit option? do we need a default in a case statement?
//its not cheating to look up syntax, right?
//what using a constructor versus an intializer means???

//  Things To Do
//window size doesn't work?? polishing matter doesn't need to be addressed atm
//create playlist needs work
//  vector shadowing???
// Doesn't like adding the last song from master... something about out of range
// doesn't like taking in q... how to quit the create function
//limit amount of makeable playlists to four; premake the playlists
//save the unlimited version though; could be cool to have later on

//  DONE
//vector set up??
//class set up??
//the right or syntax for cpp is || not or
//how to get eclipse to update??? multiple ways, actually closing programs correctly is a good option or restarting eclipse
//**when making a project/file manually set file type
//create a source file to hold the rest of your files within

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Prints menu of songs based on vector of objects
void printMasterPlaylist (vector<song> playlist){
	cout << "Song Menu : " << endl;
	for (unsigned i = 0; i < playlist.size(); ++i){
		cout << "   [" << i + 1 << "] : " << playlist.at(i).getSongName() << endl;
	}
}
//Place function container around this;
void selectAndPlay(string songString, string command, vector<song> songMasterList) {
	//Strange behavior here
	if (songString == "q" && songString == "Q"){
		cout << "Bye, Thanks For Playing" << endl;
	}
	else {
		int songNum = stoi(songString);
		if ((unsigned)songNum > songMasterList.size() || songNum < 1) {
			cout << "Sorry that place doesn't exist on the master play list, please try again" << endl;
		} else {
			cout << "Playing : ";
			songMasterList.at(songNum - 1).displaySongInfo();
		}
		// Create Command Line & Call It
		command = "start firefox --window-size=700,650 " + songMasterList.at(songNum - 1).getSongURL();
		const char *system_command = command.c_str();
		system(system_command);

		// Close the Browser Window to continue
		cout << "\n Close the Browser Window to Continue, then ..." << endl;
		system("pause");
		cin.ignore();
	}
}
void printMenu(){
	// how to deal with quit option? do we need a default in a case statement?
	cout << " Welcome to playlist maker: please select an option" << endl;
	cout << "   [ 1 ] : Create"  << endl;
	cout << "   [ 2 ] : Display"  << endl;
	cout << "   [ 3 ] : Delete"  << endl;
	cout << "   [ 4 ] : Play1"  << endl;
	cout << "   [ 5 ] : Play2"  << endl;
	cout << "   [ 6 ] : Quit"  << endl;
}
//Hmm not sure how to approach this??
//I'm thinking user will enter a playlist title that the function will take in as listName

vector<song> create_playlist(vector<song> songMasterList, vector<song> list1, vector<song> list2, vector<song> list3, vector<song> list4){
	int listCounter = 0;
	string songSelection;
	string listName1;
	string listName2;
	string listName3;
	string listName4;
	vector<string> listOfPlaylists;
	map<string, vector<song>> playlistMap;
	listOfPlaylists.push_back(listName1);
	listOfPlaylists.push_back(listName2);
	listOfPlaylists.push_back(listName3);
	listOfPlaylists.push_back(listName4);
	// NOT SURE ABOUT THIS
	return listOfPlaylists;
	//list 1
	if (listCounter == 0){
		playlistMap.emplace(listName1, list1);
		cout << "Please enter a new playlist title" << endl;
		cin >> listName1;
		//playlistPair.first = listName (title), playlistPair.second = playlist (vector)
		printMasterPlaylist(songMasterList);
		cout << "Please enter a song number to add to the new playlist or q to quit" << endl;
		cin >> songSelection;
		//checks to see if string is q or not
		while (songSelection != "q" && songSelection != "Q"){
			// change string to integer
			int songNum = stoi(songSelection);
			if (songNum < 1 || songNum > (signed)songMasterList.size()){
				cout << "Sorry that song doesn't exist on the master play list, please try again" << endl;
				// this takes me to the bottom of the loop?
			}
			else {
				list1.push_back(songMasterList.at(songNum));
				//should listName be changed to playlist within the string?
				songMasterList.at(songNum).displaySongInfo();
				cout << " has been added to " << listName1 << endl;

			}
			// song has been added to new playlist, now checking to see if new list has reached max size
			if  (list1.size() > 4) {
				//should listName be changed to playlist within the string?
				cout << listName1 << " size has reached max. Returning to main menu" << endl;
			}
			else {
				printMasterPlaylist(songMasterList);
				cout <<"To continue enter another song number from the master playlist, to exit enter 'q'." << endl;
			}
			cin >> songSelection;
		}
		cout << "Playlist creation complete" << endl;
		return playlistMap.at(listName1);
		++listCounter;
	}
	//list 2
	if (listCounter == 1) {
		playlistMap.emplace(listName2, list2);
		cout << "Please enter a new playlist title" << endl;
		cin >> listName2;
		//playlistPair.first = listName (title), playlistPair.second = playlist (vector)
		printMasterPlaylist(songMasterList);
		cout << "Please enter a song number to add to the new playlist or q to quit" << endl;
		cin >> songSelection;
		//checks to see if string is q or not
		while (songSelection != "q" && songSelection != "Q"){
			// change string to integer
			int songNum = stoi(songSelection);
			if (songNum < 1 || songNum > (signed)songMasterList.size()){
				cout << "Sorry that song doesn't exist on the master play list, please try again" << endl;
				// this takes me to the bottom of the loop?
			}
			else {
				list2.push_back(songMasterList.at(songNum));
				//should listName be changed to playlist within the string?
				songMasterList.at(songNum).displaySongInfo();
				cout << " has been added to " << listName2 << endl;

			}
			// song has been added to new playlist, now checking to see if new list has reached max size
			if  (list2.size() > 4) {
				//should listName be changed to playlist within the string?
				cout << listName2 << " size has reached max. Returning to main menu" << endl;
			}
			else {
				printMasterPlaylist(songMasterList);
				cout <<"To continue enter another song number from the master playlist, to exit enter 'q'." << endl;
			}
			cin >> songSelection;
		}
		cout << "Playlist creation complete" << endl;
		return playlistMap.at(listName2);
		++listCounter;
	}
	//list 3
	if (listCounter == 2){
		playlistMap.emplace(listName3, list3);
		cout << "Please enter a new playlist title" << endl;
		cin >> listName3;
		//playlistPair.first = listName (title), playlistPair.second = playlist (vector)
		printMasterPlaylist(songMasterList);
		cout << "Please enter a song number to add to the new playlist or q to quit" << endl;
		cin >> songSelection;
		//checks to see if string is q or not
		while (songSelection != "q" && songSelection != "Q"){
			// change string to integer
			int songNum = stoi(songSelection);
			if (songNum < 1 || songNum > (signed)songMasterList.size()){
				cout << "Sorry that song doesn't exist on the master play list, please try again" << endl;
				// this takes me to the bottom of the loop?
			}
			else {
				list3.push_back(songMasterList.at(songNum));
				//should listName be changed to playlist within the string?
				songMasterList.at(songNum).displaySongInfo();
				cout << " has been added to " << listName3 << endl;

			}
			// song has been added to new playlist, now checking to see if new list has reached max size
			if  (list3.size() > 4) {
				//should listName be changed to playlist within the string?
				cout << listName3 << " size has reached max. Returning to main menu" << endl;
			}
			else {
				printMasterPlaylist(songMasterList);
				cout <<"To continue enter another song number from the master playlist, to exit enter 'q'." << endl;
			}
			cin >> songSelection;
		}
		cout << "Playlist creation complete" << endl;
		return playlistMap.at(listName4);
		++listCounter;
	}
	//list4
	if (listCounter == 3){
		playlistMap.emplace(listName4, list4);
		cout << "Please enter a new playlist title" << endl;
		cin >> listName4;
		//playlistPair.first = listName (title), playlistPair.second = playlist (vector)
		printMasterPlaylist(songMasterList);
		cout << "Please enter a song number to add to the new playlist or q to quit" << endl;
		cin >> songSelection;
		//checks to see if string is q or not
		while (songSelection != "q" && songSelection != "Q"){
			// change string to integer
			int songNum = stoi(songSelection);
			if (songNum < 1 || songNum > (signed)songMasterList.size()){
				cout << "Sorry that song doesn't exist on the master play list, please try again" << endl;
				// this takes me to the bottom of the loop?
			}
			else {
				list4.push_back(songMasterList.at(songNum));
				//should listName be changed to playlist within the string?
				songMasterList.at(songNum).displaySongInfo();
				cout << " has been added to " << listName4 << endl;

			}
			// song has been added to new playlist, now checking to see if new list has reached max size
			if  (list4.size() > 4) {
				//should listName be changed to playlist within the string?
				cout << listName4 << " size has reached max. Returning to main menu" << endl;
			}
			else {
				printMasterPlaylist(songMasterList);
				cout <<"To continue enter another song number from the master playlist, to exit enter 'q'." << endl;
			}
			cin >> songSelection;
		}
		cout << "Playlist creation complete" << endl;
		return playlistMap.at(listName4);
		++listCounter;
	}

}
void displayPlaylists(vector<string> listOfPlaylists){
	cout << "   [ 1 ] : " << "songMasterList" << endl;
	cout << "   [ 2 ] : " << listOfPlaylists.at(0)  << endl;
	cout << "   [ 3 ] : " << listOfPlaylists.at(1)   << endl;
	cout << "   [ 4 ] : " << listOfPlaylists.at(2)   << endl;
	cout << "   [ 5 ] : " << listOfPlaylists.at(3)   << endl;
}
void deletePlaylist(/* Fill in Paramenters*/){
	int choice;
	cout << "Which playlist would you like to delete?(MasterPlaylist is not an option)" << endl;
	cin >> choice;
	if (choice == 1) {
		cout << "Sorry thats an invalid option." << endl;
		mainMenu; // consider putting main Menu function as a part of main
	}
	if (choice == 2) {
		for (song : choice){
			playlistMap.at(listName1).clear();
		}
	}
	if (choice == 3) {
		for (song : choice){
			playlistMap.at(listName2).clear();
		}
	}
	if (choice == 4) {
		for (song : choice){
			playlistMap.at(listName3).clear();
		}
	}
	if (choice == 5) {
		for (song : choice){
			playlistMap.at(listName4).clear();
		}
	}
}
//integeral part of the menu functionality
//each case should place a function call thats it
void mainMenu (vector<song> songMasterList, vector<song> list1, vector<song> list2, vector<song> list3, vector<song> list4, string songEntry, string command){
	printMenu();
	int actionSelect;
	cin >> actionSelect;
	switch(actionSelect){
	//create
	case 1:
		// makes a playlist; prints it to a file?? whats a good way to keep track of the different playlists made?
		create_playlist(songMasterList, list1, list2, list3, list4);
		break;

		//display
	case 2:
		// prints name of master playlist
		// prints vector of playlists that have been made
		displayPlaylists(listOfPlaylists);
		break;

		//delete
	case 3:
		// calls display and prompts for a playlist to be deleted
		// master playlist is not an option there
		// use vectorName [prolly playlistList].erase (vectorName.begin() + i);
		//break;

		//play1
	case 4:
		selectAndPlay(songEntry, command, songMasterList);
		break;

		//play2
		//case 5:
		//
		//break;

		//quit
	case 6:
		cout << "Bye, Thanks For Playing" << endl;
		break;

	default:
		cout << "invalid case" << endl;
	}
}

int main() {
	string artist;
	string title;
	string url;
	string songEntry;
	//allows for system commands to do their thing
	string command;
	//vector to contain songs within
	vector<song> songMasterList;
	vector<song> list1;
	vector<song> list2;
	vector<song> list3;
	vector<song> list4;
	// sets up file stream
	ifstream inFS;

	//int selection;

	//opens the file; error message if file couldn't open
	inFS.open("yins_master_playlist.txt");
	if (!inFS.is_open()) {
		cout << "Could not open file yins_master_playlist.txt." << endl;
		return 1; // 1 indicates error
	}
	//reads through file and makes object of songs based on each line
	while (!inFS.eof()) {
		//int i;
		//need a way to name each object created w/o hard coding names
		//string objectName = "track" + to_string(i);
		getline(inFS, title);
		getline(inFS, artist);
		getline(inFS, url);
		// might need to make a string called objectName???
		song objectName (title, artist, url);
		//fill the vector with objects
		songMasterList.push_back(objectName);
		//++i;
	}
	inFS.close();
	/* part b
	printMenu();
	printMasterPlaylist(songMasterList);
	cout << "Please enter the song number you wish to play." << endl;
	cin >> songEntry;
	selectAndPlay(songEntry, command, songMasterList);
	 */
	// Part c
	mainMenu(songMasterList, list1, list2, list3, list4, songEntry, command);
	//selectAndPlay(songEntry, command, songMasterList);
	return 0;
}















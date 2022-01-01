/****
* Title: Project 2 Playlist System
 * Course: Computational Problem Solving II (CPET-321.01.2211)
 * Developer: Yin Hinton
 * Date: Nov 6, 2021
 * Description: [Main.cpp]Using supporting files, opens a link to a youtube window and plays the video
 ***/

#ifndef SONG_H
#define SONG_H

 #include <iostream>
 #include <string>
 #include <fstream>
 #include <vector>

using namespace std;
class song {
	 public:
		 //why are these nessecary?? what's the point??
		 //to set up for object
	 	 song();
	 	 song(string title, string musician, string link);
	 	 //to allocate memory for the vector
	 	 //vector<string> songList(string title, string artist, string url);
	 	 string getSongName();
	 	 string getSongArtist();
	 	 string getSongURL();
	 	 void displaySongInfo();

	 private:
		 string name;
		 string artist;
		 string url;
 };
#endif

/****
 * Title: Project 2 Playlist System
 * Course: Computational Problem Solving II (CPET-321.01.2211)
 * Developer: Yin Hinton
 * Date: Nov 6, 2021
 * Description: [Main.cpp]Using supporting files, opens a link to a youtube window and plays the video
 ***/

 #include "Song.h"
 #include <iostream>
 #include <string>
 #include <fstream>
 #include <vector>

using namespace std;
//its not cheating to look up syntax right?
//what using a constructor versus an intializer means???
song::song(string title, string musician, string link){
	name = title;
	artist = musician;
	url = link;
}
string song::getSongName(){
	return name;
}
string song::getSongArtist(){
	return artist;
}
string song::getSongURL(){
	return url;
}
void song::displaySongInfo(){
	cout << getSongName() << " by " << getSongArtist();
}

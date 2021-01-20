#pragma once

#include <vector>
#include <string>
#include "Song.h"

class PlayList
{
public:
	PlayList(std::vector<Song*> songs, std::string name);
	std::string GetName();
	std::vector<Song*> GetSongs();
	void SetName(std::string name);
	void SetSongs(std::vector<Song*> songs);
	void AddSong(Song* song);
	bool RemoveSong(std::string songName);
private:
	std::vector<Song*> mSongs;
	std::string mName;
	std::vector<Song*>::iterator findSong(std::string songName);
};
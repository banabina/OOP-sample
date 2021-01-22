#pragma once
#include <vector>
#include <string>

#include "Song.h"
#include "Playlist.h"

class JkTunes
{
public:
	JkTunes() = default;
	JkTunes(std::vector<Song*> songs, std::vector<PlayList*> playLists);
	JkTunes(const JkTunes& other) = delete;
	JkTunes& operator=(const JkTunes& rhs) = delete;
	int GetSongCount() const;
	void AddSong(Song* song);
	bool RemoveSong(std::string songName);
	void AddPlayList(PlayList* playList);
	bool RemovePlayList(std::string playListName);
	void PlaySong(std::string songName);
	void PlayPlayList(std::string playListName);
private:
	std::vector<Song*> mSongs;
	std::vector<PlayList*> mPlayLists;
	std::vector<Song*>::iterator findSong(std::string songName);
	std::vector<PlayList*>::iterator findPlayList(std::string playListName);
};
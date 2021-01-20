#include "JkTunes.h"

JkTunes::JkTunes(std::vector<Song*> songs, std::vector<PlayList*> playLists)
	: mSongs(songs)
	, mPlayLists(playLists)
{
}

int JkTunes::GetSongCount()
{
	return mSongs.size();
}

void JkTunes::AddSong(Song* song)
{
	mSongs.push_back(song);
}

bool JkTunes::RemoveSong(std::string songName)
{
	std::vector<Song*>::iterator iter = findSong(songName);
	if (iter == mSongs.end())
	{
		return false;
	}
	else
	{
		mSongs.erase(iter);
	}
	return true;
}

void JkTunes::AddPlayList(PlayList* playList)
{
	mPlayLists.push_back(playList);
}

bool JkTunes::RemovePlayList(std::string playListName)
{
	std::vector<PlayList*>::iterator iter = findPlayList(playListName);
	if (iter == mPlayLists.end())
	{
		return false;
	}
	else
	{
		mPlayLists.erase(iter);
	}
	return true;
}

void JkTunes::PlaySong(std::string songName)
{
	std::vector<Song*>::iterator iter = findSong(songName);
	if (iter != mSongs.end())
	{
		(*iter)->Play();
	}
}

void JkTunes::PlayPlayList(std::string playListName)
{
	std::vector<PlayList*>::iterator iter = findPlayList(playListName);
	if (iter != mPlayLists.end())
	{
		auto songs = (*iter)->GetSongs();
		for (auto song : songs)
		{
			song->Play();
		}
	}
}

std::vector<Song*>::iterator JkTunes::findSong(std::string songName)
{
	for (auto iter = mSongs.begin(); iter < mSongs.end(); ++iter)
	{
		if ((*iter)->GetName() == songName)
		{
			return iter;
		}
	}
	return mSongs.end();
}

std::vector<PlayList*>::iterator JkTunes::findPlayList(std::string playListName)
{
	for (auto iter = mPlayLists.begin(); iter < mPlayLists.end(); ++iter)
	{
		if ((*iter)->GetName() == playListName)
		{
			return iter;
		}
	}
	return mPlayLists.end();
}

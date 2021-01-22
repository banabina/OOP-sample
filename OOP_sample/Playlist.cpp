#include "Playlist.h"

PlayList::PlayList(std::vector<Song*> songs, std::string name)
	: mSongs(songs)
	, mName(name)
{
}

std::string PlayList::GetName() const
{
	return mName;
}

std::vector<Song*> PlayList::GetSongs() const
{
	return mSongs;
}

void PlayList::SetName(std::string name)
{
	mName = name;
}

void PlayList::SetSongs(std::vector<Song*> songs)
{
	mSongs = songs;
}

void PlayList::AddSong(Song* song)
{
	mSongs.push_back(song);
}

bool PlayList::RemoveSong(std::string songName)
{
	std::vector<Song*>::iterator it = findSong(songName);
	if (it == mSongs.end())
	{
		return false;
	}
	else
	{
		mSongs.erase(it);
	}
	return true;
}

std::vector<Song*>::iterator PlayList::findSong(std::string songName)
{
	for (std::vector<Song*>::iterator iter = mSongs.begin(); iter < mSongs.end(); ++iter)
	{
		if ((*iter)->GetName() == songName)
		{
			return iter;
		}
	}
	return mSongs.end();
}

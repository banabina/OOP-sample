#include "Song.h"

Song::Song(std::string name, std::string artist, int playTimeInMilliSeconds)
	: mName(name)
	, mArtist(artist)
	, mPlayTimeInMilliSeconds(playTimeInMilliSeconds)
{
}

std::string Song::GetName()
{
	return mName;
}

std::string Song::GetArtist()
{
	return mArtist;
}

int Song::GetPlayTimeInMilliSeconds()
{
	return mPlayTimeInMilliSeconds;
}

void Song::SetName(std::string name)
{
	mName = name;
}

void Song::SetArtist(std::string artist)
{
	mArtist = artist;
}

void Song::SetPlayTimeInMilliSeconds(int playTimeInMilliSeconds)
{
	mPlayTimeInMilliSeconds = playTimeInMilliSeconds;
}

void Song::Play()
{
	std::cout << "Playing " << mName << " by " << mArtist 
		<< ". Duration is " << mPlayTimeInMilliSeconds << " milliseconds" << std::endl;
}

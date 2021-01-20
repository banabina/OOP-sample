#pragma once

#include <string>
#include <iostream>

class Song
{
public:
	Song(std::string name, std::string artist, int playTimeInMilliSeconds);
	std::string GetName();
	std::string GetArtist();
	int GetPlayTimeInMilliSeconds();
	void SetName(std::string name);
	void SetArtist(std::string artist);
	void SetPlayTimeInMilliSeconds(int playTimeInMilliSeconds);
	void Play();
private:
	std::string mArtist;
	std::string mName;
	int mPlayTimeInMilliSeconds;
};
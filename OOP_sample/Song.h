#pragma once

#include <string>
#include <iostream>

class Song
{
public:
	Song(std::string name, std::string artist, int playTimeInMilliSeconds);
	Song(const Song& other) = default;
	Song& operator=(const Song& rhs) = default;
	~Song() = default;
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
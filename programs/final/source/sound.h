/*
This is a game demo written by Wingo Sai-Keung Wong.
Date: Dec 2006 - May 2011
Email: wingo.wong@gmail.com
*/
#ifndef __SOUND_H__
#define __SOUND_H__
#include <windows.h>
#include "Framework.h"
#include "CWaves.h"



//control sound
class SOUND {
private:

	
protected:
	ALuint		    uiBuffers[22];
	ALuint		    uiSource;
	ALuint			uiBuffer[4];
	ALint			iState;
	CWaves *		pWaveLoader;
	WAVEID			WaveID;
	ALint			iLoop;
	ALint			iBuffersProcessed, iTotalBuffersProcessed, iQueuedBuffers;
	WAVEFORMATEX	wfex;

	unsigned long	ulDataSize;
	unsigned long	ulFrequency;
	unsigned long	ulFormat;
	unsigned long	ulBufferSize;
	unsigned long	ulBytesWritten;
	void *			pData;
public:
	int mBufferIndex;
	char *mFileName;
public:
	SOUND();
	~SOUND();
	bool loadSound(char* pathName);
	void addSource(int i);
	bool init();
	bool isStopped() const;
private:
	void play(int i);
	
};
#endif
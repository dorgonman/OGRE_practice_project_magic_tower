/*
 * Copyright (c) 2006, Creative Labs Inc.
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided
 * that the following conditions are met:
 * 
 *     * Redistributions of source code must retain the above copyright notice, this list of conditions and
 * 	     the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright notice, this list of conditions
 * 	     and the following disclaimer in the documentation and/or other materials provided with the distribution.
 *     * Neither the name of Creative Labs Inc. nor the names of its contributors may be used to endorse or
 * 	     promote products derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
/*
This is a game demo written by Wingo Sai-Keung Wong.
OGRE is employed for graphics rendering.

Date: Dec 2006 - May 2011
Email: wingo.wong@gmail.com

Sound Demo using OpenAL.
The source code is from "PlayStatic Test Application" in OpenAL SDK.
*/
#include "sound.h"
#include <vector>

#define NUMBUFFERS              (22)
#define	SERVICE_UPDATE_PERIOD	(20)

#define	TEST_WAVE_FILE1		"stereo.wav"
//#define	TEST_WAVE_FILE1		"music.mp3"
//#define	TEST_WAVE_FILE1		"Footsteps.wav"
#define	TEST_WAVE_FILE2		"GUN1.wav"
#define	TEST_WAVE_FILE3		"GUN2.wav"
#define	TEST_WAVE_FILE4		"waterdrop.wav"



using namespace std;

vector<ALuint> Sources;
//int SOUND::mBufferIndex = 0;
//GameControl* GameControl::instance = NULL;
SOUND::SOUND()
{
	pWaveLoader = NULL;


	ulDataSize = 0;
	ulFrequency = 0;
	ulFormat = 0;

	pData = NULL;	
	mBufferIndex = 0;
	init();
}

SOUND::~SOUND()
{
	//
	alSourcei(uiSource, AL_BUFFER, 0);
/*	alSourcei(uiSource[0], AL_BUFFER, 0);
	alSourcei(uiSource[1], AL_BUFFER, 0);
	alSourcei(uiSource[2], AL_BUFFER, 0);
	alSourcei(uiSource[3], AL_BUFFER, 0);
*/	// Release temporary storage
	free(pData);
	pData = NULL;

	//
	// Close Wave Handle
	pWaveLoader->DeleteWaveFile(WaveID);

	// Clean up buffers and sources
	alDeleteSources( 1, &uiSource );
	alDeleteBuffers( NUMBUFFERS, uiBuffers );

	if (pWaveLoader){
		delete pWaveLoader;
	}
	ALFWShutdownOpenAL();
	ALFWShutdown();	
}



bool SOUND::loadSound(char* pathName){
	if (!ALFWLoadWaveToBuffer((char*)ALFWaddMediaPath(pathName), uiBuffer[mBufferIndex]))
	{
		ALFWprintf("Failed to load %s\n", ALFWaddMediaPath(pathName));
		return false;
	}else{
		mFileName = pathName;
		mBufferIndex++;
	}
	return true;
}
void SOUND::addSource(int i)
{
	alGenSources( 1, &uiSource );
	
	alSourcei( uiSource, AL_BUFFER, uiBuffer[i] );
	play(i);
	//Sources.push_back(uiSource);
}




bool SOUND::init()
{
		// Initialize Framework
	ALFWInit();

	ALFWprintf("OpenAL PlayStatic Test Application\n");

	if (!ALFWInitOpenAL())
	{
		ALFWprintf("Failed to initialize OpenAL\n");
		ALFWShutdown();
		return 0;
	}

	// Generate an AL Buffer
	alGenBuffers(NUMBUFFERS, uiBuffer );
	return 0;
}

void SOUND::play(int i)
{
	alSourcePlay( uiSource );
}

bool SOUND::isStopped() const
{
	ALint       iState;
	alGetSourcei( uiSource, AL_SOURCE_STATE, &iState);
	return !(iState==AL_PLAYING);
}
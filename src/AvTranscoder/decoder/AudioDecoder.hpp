#ifndef _AV_TRANSCODER_ESSENCE_STREAM_AV_INPUT_AUDIO_HPP_
#define _AV_TRANSCODER_ESSENCE_STREAM_AV_INPUT_AUDIO_HPP_

#include "IDecoder.hpp"
#include <AvTranscoder/profile/ProfileLoader.hpp>

struct AVFrame;

namespace avtranscoder
{

class InputStream;

class AvExport AudioDecoder : public IDecoder
{
public:
	AudioDecoder( InputStream& inputStream );
	~AudioDecoder();

	void setup();

	bool decodeNextFrame( Frame& frameBuffer );
	bool decodeNextFrame( Frame& frameBuffer, const size_t subStreamIndex );

	void setProfile( const ProfileLoader::Profile& profile );

private:
	bool decodeNextFrame();

private:
	InputStream* _inputStream;  ///< Stream from which we read next frames (no ownership, has link)
	AVFrame* _frame;  ///< Libav object to store decoded data (has ownership)
};

}

#endif

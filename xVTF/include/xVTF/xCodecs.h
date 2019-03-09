#ifndef XVTF_CODECS_H__
#define XVTF_CODECS_H__

#include "xExports.h"

#include <memory>

namespace XVTF_NS
{
	namespace Codec
	{
		struct RGB888
		{
			unsigned char R;
			unsigned char G;
			unsigned char B;
		};

		struct RGBA8888 : public RGB888
		{
			unsigned char A;
		};

		struct ABGR8888
		{
			unsigned char A;
			unsigned char B;
			unsigned char G;
			unsigned char R;
		};

		struct BGR888
		{
			unsigned char B;
			unsigned char G;
			unsigned char R;
		};

		struct RGB565
		{
			unsigned char R : 5;
			unsigned char G : 6;
			unsigned char B : 5;
		};

		struct X8
		{
			unsigned char X;
		};

		struct XX88
		{
			unsigned char X1;
			unsigned char X2;
		};

		struct ARGB8888
		{
			unsigned char A;
			unsigned char R;
			unsigned char G;
			unsigned char B;
		};

		//----------------------------------------------------------------------------------------------------
		/// Mixes two RGB888 values together.
		/// @param[in] _A			The first colour to mix.
		/// @param[in] _B			The second colour to mix.
		/// @param[in] PartsA		How many parts of _A to mix in.
		/// @param[in] PartsB		How many parts of _B to mix in.
		/// @return RGB888			The blended colour.
		//----------------------------------------------------------------------------------------------------
		RGB888 Mix(const RGB888& _A, const RGB888& _B, const unsigned int& PartsA, const unsigned int& PartsB);

		//----------------------------------------------------------------------------------------------------
		/// Mixes two RGBA8888 values together.
		/// @param[in] _A			The first colour to mix.
		/// @param[in] _B			The second colour to mix.
		/// @param[in] PartsA		How many parts of _A to mix in.
		/// @param[in] PartsB		How many parts of _B to mix in.
		/// @return RGBA8888			The blended colour.
		//----------------------------------------------------------------------------------------------------
		RGBA8888 Mix(const RGBA8888& _A, const RGBA8888& _B, const unsigned int& PartsA, const unsigned int& PartsB);

		//----------------------------------------------------------------------------------------------------
		/// Decompresses a DXT1 (no alpha) file and returns a pointer to an array of RGB values.
		/// @param[in] buffer						The buffer of compressed data to decompress.
		/// @param[in] offset						Where in the buffer to start reading the data from.
		/// @param[in] width						Width of the image in pixels.
		/// @param[in] height						Height of the image in pixels.
		/// @return void*							The decompressed RGB888 values as an array of size width * height.
		//----------------------------------------------------------------------------------------------------
		void* DecompressDXT1(void* buffer, const unsigned int& offset, const unsigned int& width, const unsigned int& height);

		//----------------------------------------------------------------------------------------------------
		/// Decompresses a DXT1 (1-bit alpha) file and returns a pointer to an array of RGBA values.
		/// @param[in] buffer						The buffer of compressed data to decompress.
		/// @param[in] offset						Where in the buffer to start reading the data from.
		/// @param[in] width						Width of the image in pixels.
		/// @param[in] height						Height of the image in pixels.
		/// @return void*							The decompressed RGBA8888 values as an array of size width * height.
		//----------------------------------------------------------------------------------------------------
		void* DecompressDXT1_ONEBITALPHA(void* buffer, const unsigned int& offset, const unsigned int& width, const unsigned int& height);

		//----------------------------------------------------------------------------------------------------
		/// Decompresses a DXT3 (4-bit alpha) file and returns a pointer to an array of RGBA values.
		/// @param[in] buffer						The buffer of compressed data to decompress.
		/// @param[in] offset						Where in the buffer to start reading the data from.
		/// @param[in] width						Width of the image in pixels.
		/// @param[in] height						Height of the image in pixels.
		/// @return void*							The decompressed RGBA8888 values as an array of size width * height.
		//----------------------------------------------------------------------------------------------------
		void* DecompressDXT3(void* buffer, const unsigned int& offset, const unsigned int& width, const unsigned int& height);

		//----------------------------------------------------------------------------------------------------
		/// Decompresses a DXT5 (paletted alpha) file and returns a pointer to an array of RGBA values.
		/// @param[in] buffer						The buffer of compressed data to decompress.
		/// @param[in] offset						Where in the buffer to start reading the data from.
		/// @param[in] width						Width of the image in pixels.
		/// @param[in] height						Height of the image in pixels.
		/// @return void*							The decompressed RGBA8888 values as an array of size width * height.
		//----------------------------------------------------------------------------------------------------
		void* DecompressDXT5(void* buffer, const unsigned int& offset, const unsigned int& width, const unsigned int& height);
	}
}

#endif
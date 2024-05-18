/*
 * BitmapHelper.h
 *
 *  Created on: Jun 11, 2017
 *      Author: guoxs
 */

#ifndef _UTILS_BITMAP_HELPER_H_
#define _UTILS_BITMAP_HELPER_H_

#include <vector>
#include <string>
#include <stdint.h>
#include "system/Mutex.h"

struct _bitmap_t;

class BitmapHelper {
public:
	static bool loadBitmapFromFile(struct _bitmap_t *&pBmp, const char *pPath);
	static bool loadBitmapFromMem(struct _bitmap_t *&pBmp, const uint8_t *pData, uint32_t w, uint32_t h, uint32_t n);
	static void unloadBitmap(struct _bitmap_t *&pBmp);

private:
	
	typedef struct {
		std::string path;
		int refCount;
		struct _bitmap_t *pBmp;
	} SBitmapInfo;

	static std::vector<SBitmapInfo> sBitmapInfoList;
	static Mutex sLock;
};

#endif /* _UTILS_BITMAP_HELPER_H_ */

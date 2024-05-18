

/*
 * ImageCache.cpp
 *
 *	Created on: 2023年7月1日
 *		Author: lzs2180
 */
#include "include.h"
#include <string.h>
#include "manager/ConfigManager.h"




ImageCache::ImageCache()
{
	// TODO 自动生成的构造函数存根
	memset(mCacheInfoList, 0, sizeof(mCacheInfoList));
}


ImageCache::~ImageCache()
{
	// TODO 自动生成的析构函数存根
	releaseAll();
}


void ImageCache::releaseAll()
{
	for (int i = 0; i < CACHE_SIZE; ++i) {
		if (mCacheInfoList[i].bmp) {
			BitmapHelper::unloadBitmap(mCacheInfoList[i].bmp);
		}
	}

	memset(mCacheInfoList, 0, sizeof(mCacheInfoList));
}


 void ImageCache::cache(const char * path) {

	bool isExist =	false;
	int index = 	-1;
	

	for (int i = 0; i < CACHE_SIZE; ++i) {

		if (strcmp(mCacheInfoList[i].path, path) == 0) {
			mCacheInfoList[i].weight++;
			isExist 			= true;
		}
		else if (mCacheInfoList[i].bmp) {
			mCacheInfoList[i].weight--;

			if ((index == -1) || (mCacheInfoList[index].bmp && (mCacheInfoList[index].weight > mCacheInfoList[i].weight))) {
				index				= i;
			}
		}
		else if ((index == -1) || mCacheInfoList[index].bmp) {
			index				= i;
		}
	}

	if (!isExist) {

		if (mCacheInfoList[index].bmp) {
			BitmapHelper::unloadBitmap(mCacheInfoList[index].bmp);
		}

		BitmapHelper::loadBitmapFromFile(mCacheInfoList[index].bmp, path);

		memset(mCacheInfoList[index].path, 0, 256);
		
		strcpy(mCacheInfoList[index].path, path);

		mCacheInfoList[index].weight = 1;

	}
	
}



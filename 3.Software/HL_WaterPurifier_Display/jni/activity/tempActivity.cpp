/***********************************************
/gen auto by zuitools
***********************************************/
#include "tempActivity.h"

/*TAG:GlobalVariable全局变量*/
static ZKListView* mListView2Ptr;
static ZKEditText* mEditText3Ptr;
static ZKEditText* mEditText2Ptr;
static ZKTextView* mTextView11Ptr;
static ZKButton* mButton15Ptr;
static ZKTextView* mTextView10Ptr;
static ZKCircleBar* mCircleBar5Ptr;
static ZKCircleBar* mCircleBar4Ptr;
static ZKCircleBar* mCircleBar3Ptr;
static ZKCircleBar* mCircleBar2Ptr;
static ZKWindow* mWindow10Ptr;
static ZKButton* mButton14Ptr;
static ZKButton* mButton13Ptr;
static ZKWindow* mWindow9Ptr;
static ZKButton* mButton12Ptr;
static ZKWindow* mWindow8Ptr;
static ZKTextView* mTextView9Ptr;
static ZKTextView* mTextView8Ptr;
static ZKTextView* mTextView7Ptr;
static ZKButton* mButton11Ptr;
static ZKWindow* mWindow7Ptr;
static ZKTextView* mTextView6Ptr;
static ZKTextView* mTextView5Ptr;
static ZKTextView* mTextView4Ptr;
static ZKWindow* mWindow6Ptr;
static ZKWindow* mWindow5Ptr;
static ZKEditText* mEditText1Ptr;
static ZKButton* mButton9Ptr;
static ZKButton* mButton10Ptr;
static ZKTextView* mTextView3Ptr;
static ZKListView* mListView1Ptr;
static ZKTextView* mTextView2Ptr;
static ZKWindow* mWindow1Ptr;
static ZKButton* mButton8Ptr;
static ZKButton* mButton7Ptr;
static ZKButton* mButton6Ptr;
static ZKButton* mButton5Ptr;
static ZKDigitalClock* mDigitalClock1Ptr;
static ZKTextView* mTextView1Ptr;
static ZKButton* mButton4Ptr;
static ZKButton* mButton3Ptr;
static ZKButton* mButton2Ptr;
static ZKWindow* mWindow4Ptr;
static ZKWindow* mWindow3Ptr;
static ZKWindow* mWindow2Ptr;
static ZKButton* mButton1Ptr;
static tempActivity* mActivityPtr;

/*register activity*/
REGISTER_ACTIVITY(tempActivity);

typedef struct {
	int id; // 定时器ID ， 不能重复
	int time; // 定时器  时间间隔  单位 毫秒
}S_ACTIVITY_TIMEER;

#include "logic/tempLogic.cc"

/***********/
typedef struct {
    int id;
    const char *pApp;
} SAppInfo;

/**
 *点击跳转window
 */
static SAppInfo sAppInfoTab[] = {
//  { ID_MAIN_TEXT, "TextViewActivity" },
};

/***************/
typedef bool (*ButtonCallback)(ZKButton *pButton);
/**
 * button onclick表
 */
typedef struct {
    int id;
    ButtonCallback callback;
}S_ButtonCallback;

/*TAG:ButtonCallbackTab按键映射表*/
static S_ButtonCallback sButtonCallbackTab[] = {
    ID_TEMP_Button15, onButtonClick_Button15,
    ID_TEMP_Button14, onButtonClick_Button14,
    ID_TEMP_Button13, onButtonClick_Button13,
    ID_TEMP_Button12, onButtonClick_Button12,
    ID_TEMP_Button11, onButtonClick_Button11,
    ID_TEMP_Button9, onButtonClick_Button9,
    ID_TEMP_Button10, onButtonClick_Button10,
    ID_TEMP_Button8, onButtonClick_Button8,
    ID_TEMP_Button7, onButtonClick_Button7,
    ID_TEMP_Button6, onButtonClick_Button6,
    ID_TEMP_Button5, onButtonClick_Button5,
    ID_TEMP_Button4, onButtonClick_Button4,
    ID_TEMP_Button3, onButtonClick_Button3,
    ID_TEMP_Button2, onButtonClick_Button2,
    ID_TEMP_Button1, onButtonClick_Button1,
};
/***************/


typedef void (*SeekBarCallback)(ZKSeekBar *pSeekBar, int progress);
typedef struct {
    int id;
    SeekBarCallback callback;
}S_ZKSeekBarCallback;
/*TAG:SeekBarCallbackTab*/
static S_ZKSeekBarCallback SZKSeekBarCallbackTab[] = {
};


typedef int (*ListViewGetItemCountCallback)(const ZKListView *pListView);
typedef void (*ListViewobtainListItemDataCallback)(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index);
typedef void (*ListViewonItemClickCallback)(ZKListView *pListView, int index, int id);
typedef struct {
    int id;
    ListViewGetItemCountCallback getListItemCountCallback;
    ListViewobtainListItemDataCallback obtainListItemDataCallback;
    ListViewonItemClickCallback onItemClickCallback;
}S_ListViewFunctionsCallback;
/*TAG:ListViewFunctionsCallback*/
static S_ListViewFunctionsCallback SListViewFunctionsCallbackTab[] = {
    ID_TEMP_ListView2, getListItemCount_ListView2, obtainListItemData_ListView2, onListItemClick_ListView2,
    ID_TEMP_ListView1, getListItemCount_ListView1, obtainListItemData_ListView1, onListItemClick_ListView1,
};


typedef void (*SlideWindowItemClickCallback)(ZKSlideWindow *pSlideWindow, int index);
typedef struct {
    int id;
    SlideWindowItemClickCallback onSlideItemClickCallback;
}S_SlideWindowItemClickCallback;
/*TAG:SlideWindowFunctionsCallbackTab*/
static S_SlideWindowItemClickCallback SSlideWindowItemClickCallbackTab[] = {
};


typedef void (*EditTextInputCallback)(const std::string &text);
typedef struct {
    int id;
    EditTextInputCallback onEditTextChangedCallback;
}S_EditTextInputCallback;
/*TAG:EditTextInputCallback*/
static S_EditTextInputCallback SEditTextInputCallbackTab[] = {
    ID_TEMP_EditText3, onEditTextChanged_EditText3,
    ID_TEMP_EditText2, onEditTextChanged_EditText2,
    ID_TEMP_EditText1, onEditTextChanged_EditText1,
};

typedef void (*VideoViewCallback)(ZKVideoView *pVideoView, int msg);
typedef struct {
    int id; //VideoView ID
    bool loop; // 是否是轮播类型
    int defaultvolume;//轮播类型时,默认视频音量
    VideoViewCallback onVideoViewCallback;
}S_VideoViewCallback;
/*TAG:VideoViewCallback*/
static S_VideoViewCallback SVideoViewCallbackTab[] = {
};


typedef void (*RadioGroupCallback)(ZKRadioGroup*, int);
typedef struct {
  int id;
  RadioGroupCallback onCheckedChanged;
}S_RadioGroupCallback;
/*TAG:RadioGroupCallbackTab*/
static S_RadioGroupCallback SRadioGroupCallbackTab[] = {
};

tempActivity::tempActivity() {
	//todo add init code here
	mVideoLoopIndex = -1;
	mVideoLoopErrorCount = 0;
}

tempActivity::~tempActivity() {
  //todo add init file here
  // 退出应用时需要反注册
    EASYUICONTEXT->unregisterGlobalTouchListener(this);
    unregisterProtocolDataUpdateListener(onProtocolDataUpdate);
    onUI_quit();
    mActivityPtr = NULL;
    mListView2Ptr = NULL;
    mEditText3Ptr = NULL;
    mEditText2Ptr = NULL;
    mTextView11Ptr = NULL;
    mButton15Ptr = NULL;
    mTextView10Ptr = NULL;
    mCircleBar5Ptr = NULL;
    mCircleBar4Ptr = NULL;
    mCircleBar3Ptr = NULL;
    mCircleBar2Ptr = NULL;
    mWindow10Ptr = NULL;
    mButton14Ptr = NULL;
    mButton13Ptr = NULL;
    mWindow9Ptr = NULL;
    mButton12Ptr = NULL;
    mWindow8Ptr = NULL;
    mTextView9Ptr = NULL;
    mTextView8Ptr = NULL;
    mTextView7Ptr = NULL;
    mButton11Ptr = NULL;
    mWindow7Ptr = NULL;
    mTextView6Ptr = NULL;
    mTextView5Ptr = NULL;
    mTextView4Ptr = NULL;
    mWindow6Ptr = NULL;
    mWindow5Ptr = NULL;
    mEditText1Ptr = NULL;
    mButton9Ptr = NULL;
    mButton10Ptr = NULL;
    mTextView3Ptr = NULL;
    mListView1Ptr = NULL;
    mTextView2Ptr = NULL;
    mWindow1Ptr = NULL;
    mButton8Ptr = NULL;
    mButton7Ptr = NULL;
    mButton6Ptr = NULL;
    mButton5Ptr = NULL;
    mDigitalClock1Ptr = NULL;
    mTextView1Ptr = NULL;
    mButton4Ptr = NULL;
    mButton3Ptr = NULL;
    mButton2Ptr = NULL;
    mWindow4Ptr = NULL;
    mWindow3Ptr = NULL;
    mWindow2Ptr = NULL;
    mButton1Ptr = NULL;
}

const char* tempActivity::getAppName() const{
	return "temp.ftu";
}

//TAG:onCreate
void tempActivity::onCreate() {
	Activity::onCreate();
    mListView2Ptr = (ZKListView*)findControlByID(ID_TEMP_ListView2);if(mListView2Ptr!= NULL){mListView2Ptr->setListAdapter(this);mListView2Ptr->setItemClickListener(this);}
    mEditText3Ptr = (ZKEditText*)findControlByID(ID_TEMP_EditText3);if(mEditText3Ptr!= NULL){mEditText3Ptr->setTextChangeListener(this);}
    mEditText2Ptr = (ZKEditText*)findControlByID(ID_TEMP_EditText2);if(mEditText2Ptr!= NULL){mEditText2Ptr->setTextChangeListener(this);}
    mTextView11Ptr = (ZKTextView*)findControlByID(ID_TEMP_TextView11);
    mButton15Ptr = (ZKButton*)findControlByID(ID_TEMP_Button15);
    mTextView10Ptr = (ZKTextView*)findControlByID(ID_TEMP_TextView10);
    mCircleBar5Ptr = (ZKCircleBar*)findControlByID(ID_TEMP_CircleBar5);
    mCircleBar4Ptr = (ZKCircleBar*)findControlByID(ID_TEMP_CircleBar4);
    mCircleBar3Ptr = (ZKCircleBar*)findControlByID(ID_TEMP_CircleBar3);
    mCircleBar2Ptr = (ZKCircleBar*)findControlByID(ID_TEMP_CircleBar2);
    mWindow10Ptr = (ZKWindow*)findControlByID(ID_TEMP_Window10);
    mButton14Ptr = (ZKButton*)findControlByID(ID_TEMP_Button14);
    mButton13Ptr = (ZKButton*)findControlByID(ID_TEMP_Button13);
    mWindow9Ptr = (ZKWindow*)findControlByID(ID_TEMP_Window9);
    mButton12Ptr = (ZKButton*)findControlByID(ID_TEMP_Button12);
    mWindow8Ptr = (ZKWindow*)findControlByID(ID_TEMP_Window8);
    mTextView9Ptr = (ZKTextView*)findControlByID(ID_TEMP_TextView9);
    mTextView8Ptr = (ZKTextView*)findControlByID(ID_TEMP_TextView8);
    mTextView7Ptr = (ZKTextView*)findControlByID(ID_TEMP_TextView7);
    mButton11Ptr = (ZKButton*)findControlByID(ID_TEMP_Button11);
    mWindow7Ptr = (ZKWindow*)findControlByID(ID_TEMP_Window7);
    mTextView6Ptr = (ZKTextView*)findControlByID(ID_TEMP_TextView6);
    mTextView5Ptr = (ZKTextView*)findControlByID(ID_TEMP_TextView5);
    mTextView4Ptr = (ZKTextView*)findControlByID(ID_TEMP_TextView4);
    mWindow6Ptr = (ZKWindow*)findControlByID(ID_TEMP_Window6);
    mWindow5Ptr = (ZKWindow*)findControlByID(ID_TEMP_Window5);
    mEditText1Ptr = (ZKEditText*)findControlByID(ID_TEMP_EditText1);if(mEditText1Ptr!= NULL){mEditText1Ptr->setTextChangeListener(this);}
    mButton9Ptr = (ZKButton*)findControlByID(ID_TEMP_Button9);
    mButton10Ptr = (ZKButton*)findControlByID(ID_TEMP_Button10);
    mTextView3Ptr = (ZKTextView*)findControlByID(ID_TEMP_TextView3);
    mListView1Ptr = (ZKListView*)findControlByID(ID_TEMP_ListView1);if(mListView1Ptr!= NULL){mListView1Ptr->setListAdapter(this);mListView1Ptr->setItemClickListener(this);}
    mTextView2Ptr = (ZKTextView*)findControlByID(ID_TEMP_TextView2);
    mWindow1Ptr = (ZKWindow*)findControlByID(ID_TEMP_Window1);
    mButton8Ptr = (ZKButton*)findControlByID(ID_TEMP_Button8);
    mButton7Ptr = (ZKButton*)findControlByID(ID_TEMP_Button7);
    mButton6Ptr = (ZKButton*)findControlByID(ID_TEMP_Button6);
    mButton5Ptr = (ZKButton*)findControlByID(ID_TEMP_Button5);
    mDigitalClock1Ptr = (ZKDigitalClock*)findControlByID(ID_TEMP_DigitalClock1);
    mTextView1Ptr = (ZKTextView*)findControlByID(ID_TEMP_TextView1);
    mButton4Ptr = (ZKButton*)findControlByID(ID_TEMP_Button4);
    mButton3Ptr = (ZKButton*)findControlByID(ID_TEMP_Button3);
    mButton2Ptr = (ZKButton*)findControlByID(ID_TEMP_Button2);
    mWindow4Ptr = (ZKWindow*)findControlByID(ID_TEMP_Window4);
    mWindow3Ptr = (ZKWindow*)findControlByID(ID_TEMP_Window3);
    mWindow2Ptr = (ZKWindow*)findControlByID(ID_TEMP_Window2);
    mButton1Ptr = (ZKButton*)findControlByID(ID_TEMP_Button1);
	mActivityPtr = this;
	onUI_init();
  registerProtocolDataUpdateListener(onProtocolDataUpdate);
  rigesterActivityTimer();
}

void tempActivity::onClick(ZKBase *pBase) {
	//TODO: add widget onClik code 
    int buttonTablen = sizeof(sButtonCallbackTab) / sizeof(S_ButtonCallback);
    for (int i = 0; i < buttonTablen; ++i) {
        if (sButtonCallbackTab[i].id == pBase->getID()) {
            if (sButtonCallbackTab[i].callback((ZKButton*)pBase)) {
            	return;
            }
            break;
        }
    }


    int len = sizeof(sAppInfoTab) / sizeof(sAppInfoTab[0]);
    for (int i = 0; i < len; ++i) {
        if (sAppInfoTab[i].id == pBase->getID()) {
            EASYUICONTEXT->openActivity(sAppInfoTab[i].pApp);
            return;
        }
    }

	Activity::onClick(pBase);
}

void tempActivity::onResume() {
	Activity::onResume();
	EASYUICONTEXT->registerGlobalTouchListener(this);
	startVideoLoopPlayback();
	onUI_show();
}

void tempActivity::onPause() {
	Activity::onPause();
	EASYUICONTEXT->unregisterGlobalTouchListener(this);
	stopVideoLoopPlayback();
	onUI_hide();
}

void tempActivity::onIntent(const Intent *intentPtr) {
	Activity::onIntent(intentPtr);
	onUI_intent(intentPtr);
}

bool tempActivity::onTimer(int id) {
	return onUI_Timer(id);
}

void tempActivity::onProgressChanged(ZKSeekBar *pSeekBar, int progress){

    int seekBarTablen = sizeof(SZKSeekBarCallbackTab) / sizeof(S_ZKSeekBarCallback);
    for (int i = 0; i < seekBarTablen; ++i) {
        if (SZKSeekBarCallbackTab[i].id == pSeekBar->getID()) {
            SZKSeekBarCallbackTab[i].callback(pSeekBar, progress);
            break;
        }
    }
}

int tempActivity::getListItemCount(const ZKListView *pListView) const{
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            return SListViewFunctionsCallbackTab[i].getListItemCountCallback(pListView);
            break;
        }
    }
    return 0;
}

void tempActivity::obtainListItemData(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index){
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            SListViewFunctionsCallbackTab[i].obtainListItemDataCallback(pListView, pListItem, index);
            break;
        }
    }
}

void tempActivity::onItemClick(ZKListView *pListView, int index, int id){
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            SListViewFunctionsCallbackTab[i].onItemClickCallback(pListView, index, id);
            break;
        }
    }
}

void tempActivity::onSlideItemClick(ZKSlideWindow *pSlideWindow, int index) {
    int tablen = sizeof(SSlideWindowItemClickCallbackTab) / sizeof(S_SlideWindowItemClickCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SSlideWindowItemClickCallbackTab[i].id == pSlideWindow->getID()) {
            SSlideWindowItemClickCallbackTab[i].onSlideItemClickCallback(pSlideWindow, index);
            break;
        }
    }
}

bool tempActivity::onTouchEvent(const MotionEvent &ev) {
    return ontempActivityTouchEvent(ev);
}

void tempActivity::onTextChanged(ZKTextView *pTextView, const std::string &text) {
    int tablen = sizeof(SEditTextInputCallbackTab) / sizeof(S_EditTextInputCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SEditTextInputCallbackTab[i].id == pTextView->getID()) {
            SEditTextInputCallbackTab[i].onEditTextChangedCallback(text);
            break;
        }
    }
}

void tempActivity::rigesterActivityTimer() {
    int tablen = sizeof(REGISTER_ACTIVITY_TIMER_TAB) / sizeof(S_ACTIVITY_TIMEER);
    for (int i = 0; i < tablen; ++i) {
        S_ACTIVITY_TIMEER temp = REGISTER_ACTIVITY_TIMER_TAB[i];
        registerTimer(temp.id, temp.time);
    }
}


void tempActivity::onVideoPlayerMessage(ZKVideoView *pVideoView, int msg) {
    int tablen = sizeof(SVideoViewCallbackTab) / sizeof(S_VideoViewCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SVideoViewCallbackTab[i].id == pVideoView->getID()) {
        	if (SVideoViewCallbackTab[i].loop) {
                //循环播放
        		videoLoopPlayback(pVideoView, msg, i);
        	} else if (SVideoViewCallbackTab[i].onVideoViewCallback != NULL){
        	    SVideoViewCallbackTab[i].onVideoViewCallback(pVideoView, msg);
        	}
            break;
        }
    }
}

void tempActivity::videoLoopPlayback(ZKVideoView *pVideoView, int msg, size_t callbackTabIndex) {

	switch (msg) {
	case ZKVideoView::E_MSGTYPE_VIDEO_PLAY_STARTED:
		LOGD("ZKVideoView::E_MSGTYPE_VIDEO_PLAY_STARTED\n");
    if (callbackTabIndex >= (sizeof(SVideoViewCallbackTab)/sizeof(S_VideoViewCallback))) {
      break;
    }
		pVideoView->setVolume(SVideoViewCallbackTab[callbackTabIndex].defaultvolume / 10.0);
		mVideoLoopErrorCount = 0;
		break;
	case ZKVideoView::E_MSGTYPE_VIDEO_PLAY_ERROR:
		/**错误处理 */
		++mVideoLoopErrorCount;
		if (mVideoLoopErrorCount > 100) {
			LOGD("video loop error counts > 100, quit loop playback !");
            break;
		} //不用break, 继续尝试播放下一个
	case ZKVideoView::E_MSGTYPE_VIDEO_PLAY_COMPLETED:
		LOGD("ZKVideoView::E_MSGTYPE_VIDEO_PLAY_COMPLETED\n");
        std::vector<std::string> videolist;
        std::string fileName(getAppName());
        if (fileName.size() < 4) {
             LOGD("getAppName size < 4, ignore!");
             break;
        }
        fileName = fileName.substr(0, fileName.length() - 4) + "_video_list.txt";
        fileName = "/mnt/extsd/" + fileName;
        if (!parseVideoFileList(fileName.c_str(), videolist)) {
            LOGD("parseVideoFileList failed !");
		    break;
        }
		if (pVideoView && !videolist.empty()) {
			mVideoLoopIndex = (mVideoLoopIndex + 1) % videolist.size();
			pVideoView->play(videolist[mVideoLoopIndex].c_str());
		}
		break;
	}
}

void tempActivity::startVideoLoopPlayback() {
    int tablen = sizeof(SVideoViewCallbackTab) / sizeof(S_VideoViewCallback);
    for (int i = 0; i < tablen; ++i) {
    	if (SVideoViewCallbackTab[i].loop) {
    		ZKVideoView* videoView = (ZKVideoView*)findControlByID(SVideoViewCallbackTab[i].id);
    		if (!videoView) {
    			return;
    		}
    		//循环播放
    		videoLoopPlayback(videoView, ZKVideoView::E_MSGTYPE_VIDEO_PLAY_COMPLETED, i);
    		return;
    	}
    }
}

void tempActivity::stopVideoLoopPlayback() {
    int tablen = sizeof(SVideoViewCallbackTab) / sizeof(S_VideoViewCallback);
    for (int i = 0; i < tablen; ++i) {
    	if (SVideoViewCallbackTab[i].loop) {
    		ZKVideoView* videoView = (ZKVideoView*)findControlByID(SVideoViewCallbackTab[i].id);
    		if (!videoView) {
    			return;
    		}
    		if (videoView->isPlaying()) {
    		    videoView->stop();
    		}
    		return;
    	}
    }
}

bool tempActivity::parseVideoFileList(const char *pFileListPath, std::vector<string>& mediaFileList) {
	mediaFileList.clear();
	if (NULL == pFileListPath || 0 == strlen(pFileListPath)) {
        LOGD("video file list is null!");
		return false;
	}

	ifstream is(pFileListPath, ios_base::in);
	if (!is.is_open()) {
		LOGD("cann't open file %s \n", pFileListPath);
		return false;
	}
	char tmp[1024] = {0};
	while (is.getline(tmp, sizeof(tmp))) {
		string str = tmp;
		removeCharFromString(str, '\"');
		removeCharFromString(str, '\r');
		removeCharFromString(str, '\n');
		if (str.size() > 1) {
     		mediaFileList.push_back(str.c_str());
		}
	}
  LOGD("(f:%s, l:%d) parse fileList[%s], get [%d]files", __FUNCTION__,
      __LINE__, pFileListPath, int(mediaFileList.size()));
  for (std::vector<string>::size_type i = 0; i < mediaFileList.size(); i++) {
    LOGD("file[%u]:[%s]", ::size_t(i), mediaFileList[i].c_str());
  }
	is.close();

	return true;
}

int tempActivity::removeCharFromString(string& nString, char c) {
    string::size_type   pos;
    while(1) {
        pos = nString.find(c);
        if(pos != string::npos) {
            nString.erase(pos, 1);
        } else {
            break;
        }
    }
    return (int)nString.size();
}

void tempActivity::registerUserTimer(int id, int time) {
	registerTimer(id, time);
}

void tempActivity::unregisterUserTimer(int id) {
	unregisterTimer(id);
}

void tempActivity::resetUserTimer(int id, int time) {
	resetTimer(id, time);
}
void tempActivity::onCheckedChanged(ZKRadioGroup* pRadioGroup, int checkedID) {
    int tablen = sizeof(SRadioGroupCallbackTab) / sizeof(S_RadioGroupCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SRadioGroupCallbackTab[i].id == pRadioGroup->getID()) {
        	SRadioGroupCallbackTab[i].onCheckedChanged(pRadioGroup, checkedID);
            break;
        }
    }
}
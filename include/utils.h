#include <oslib/oslib.h>

#include <pspnet.h>	//PSP Net Stuff
#include <pspnet_inet.h>

//PSP USB
#include <pspusb.h>
#include <pspusbstor.h>
#include <pspmodulemgr.h>
#include <kubridge.h>
#include "pspusbdevice.h"

#include <sys/unistd.h>
#include <stdbool.h>

#define Address "www.google.com"

#define musicPath "ms0:/MUSIC"

OSL_IMAGE *dialog;

char tempMessage[20];
char tempPin[5];
char tempData[250];
char buffer[100];

bool connectionInitialized;

enum colors {
    RED =	0xFF0000FF,
    GREEN =	0xFF00FF00,
    BLUE =	0xFFFF0000,
    WHITE =	0xFFFFFFFF,
    LITEGRAY = 0xFFBFBFBF,
    GRAY =  0xFF7F7F7F,
    DARKGRAY = 0xFF3F3F3F,
    BLACK = 0xFF000000,
};

typedef struct
{
    unsigned long        maxclusters;
    unsigned long        freeclusters;
    int                    unk1;
    unsigned int        sectorsize;
    u64                    sectorcount;
    
} SystemDevCtl;

typedef struct
{
    SystemDevCtl *pdevinf;    
} SystemDevCommand;

void initDrawing();
void termDrawing();
void LowMemExit();
void debugDisplay();
void internet(); //Draws the browser
int getCpuClock();
int getBusClock();
char * getModel();
int setFileDefaultsInt(char *path, int value, int var);
float setFileDefaultsFloat(char *path, float value, float var);
char * setFileDefaultsChar(char path[], char data[], char var[]);
void installRequiredFiles();
void openOSK(char * message, char * initialMessage, int textLimit, int lang);
int isEmpty(FILE *file);
void fadeOut(OSL_IMAGE* bg,int x, int y);
void fadeIn(OSL_IMAGE* bg, int x, int y);
int disableUsb(void);
int enableUsb();
int enableUsbEx(u32 device);
int netInit(void);
int netShutdown(void);
int netDialogInit(void);
int netDialogUpdate(void);
void netGetFile(const char *url, const char *filepath);
int connectAPCallback(int state);
int connectToAP(int config);
void onlineUpdater();
void flashUpdate();
void removeUpdateContents();
int downloadUpdate();
u64 storageGetTotalSize();
u64 storageGetFreeSize();
int isUSBCableActivated();
int isUSBCableConnected();
char getPSPNickname();
unsigned concatenate(unsigned x, unsigned y);
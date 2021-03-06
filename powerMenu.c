#include "clock.h"
#include "homeMenu.h"
#include "include/utils.h"
#include "powerMenu.h"
#include "prx/scepower.h"
#include "recoveryMenu.h"
#include "screenshot.h"
#include "settingsMenu.h"

void powermenu()
{
	oslSetFont(Roboto);
	
	while (!osl_quit)
	{
		LowMemExit();
		
		initDrawing();

		controls();
		
		oslDrawImage(background);
		oslDrawImageXY(ic_launcher_apollo, 105, 190);
		oslDrawImageXY(ic_launcher_browser, 276, 190);
		oslDrawImageXY(ic_launcher_settings, 331, 190);
		oslDrawImageXY(ic_launcher_messenger, 160, 190);
		appDrawerIcon();
		oslDrawImageXY(power, 100, 61);
		
		oslIntraFontSetStyle(Roboto, 0.75f, BLACK, 0, 0);
		oslDrawStringf(165, 100, "Power off");
		oslDrawStringf(165, 165, "Recovery");
		
		if (cursor->x >= 116 && cursor->x <= 364 && cursor->y >= 55 && cursor->y <= 125) 
		{
			oslDrawImageXY(powerSelection, 100, 60);
			oslDrawStringf(165, 100, "Power off");
			oslDrawStringf(165, 165, "Recovery");
			
			if (osl_keys->pressed.cross)
			{	
				oslPlaySound(KeypressStandard, 1);  
				sceKernelExitGame();
			}
			/*else if (osl_pad.held.cross)
			{
				scePowerRequestColdReset(0);
				scePowerRequestColdReset(50000);
			}*/
		}
		if (cursor->x >= 116 && cursor->x <= 364 && cursor->y >= 126 && cursor->y <= 200) 
		{
			oslDrawImageXY(recoverySelection, 100, 60);
			oslDrawStringf(165, 100, "Power off");
			oslDrawStringf(165, 165, "Recovery");
			if (osl_keys->pressed.cross)
			{	
				oslPlaySound(KeypressStandard, 1);  
				oslSyncFrame();
				sceKernelDelayThread(3*1000000);
				mainRecoveryMenu();
			}
		}
		
		displayMenuBar(0);
	
		if (osl_keys->pressed.circle)
			return;
		
		captureScreenshot();
		
		termDrawing();
	}
}
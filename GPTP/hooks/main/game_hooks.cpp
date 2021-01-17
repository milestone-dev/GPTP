/// This is where the magic happens; program your plug-in's core behavior here.

#include "game_hooks.h"
#include <graphics/graphics.h>
#include <SCBW/api.h>
#include "../psi_field.h"
#include <cstdio>
#include "hooks/requirements/requirements_parser.h"
#include "hooks/interface/buttonsets_parser.h"


namespace hooks {

/// This hook is called every frame; most of your plugin's logic goes here.
bool nextFrame() {

	if (!scbw::isGamePaused()) { //If the game is not paused

		scbw::setInGameLoopState(true); //Needed for scbw::random() to work
		graphics::resetAllGraphics();
		hooks::updatePsiFieldProviders();
   

		//Loop through all visible units in the game.
		for (CUnit *unit = *firstVisibleUnit; unit; unit = unit->link.next) {
			//Write your code here
		}

		scbw::setInGameLoopState(false);
		
	}
  
	return true;
  
}

bool gameOn() {
	customRequirements::parseRequirementOverrides();
	customButtonSets::parseButtonSetOverrides();
	return true;
}

bool gameEnd() {
	return true;
}

} //hooks

#pragma once
#include <SCBW/api.h>

namespace hooks {

	s32 parseRequirementOpcodes(CUnit* unit, u32 datReqOffset, u16 techID, u32 player); //0x0046D610

	void injectParseRequirementOpcodesWrapper();

}
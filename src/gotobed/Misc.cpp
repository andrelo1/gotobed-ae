#include "Misc.h"
#include "Offsets.h"

namespace Gotobed::Misc
{
	void Init()
	{
		// don't show sleep menu
		REL::safe_write(Offsets::TESFurniture::Activate.address() + 0x016D, static_cast<std::uint16_t>(0x0AEB));
		// don't show "serve time" message
		REL::safe_write(Offsets::TESFurniture::Activate.address() + 0x010B, static_cast<std::uint8_t>(0xEB));
		// get up using movement keys
		REL::safe_write(Offsets::PlayerCharacter::Update.address() + 0x0255, static_cast<std::uint8_t>(0x02));
		// don't allow sleeping in reserved bed
		REL::safe_write(Offsets::PlayerCharacter::CanSleepWaitHere.address() + 0x01B0, static_cast<std::uint8_t>(0x00));
		// don't stop animations when sleeping
		REL::safe_write(Offsets::AIProcess::SitSleepStateUpdate.address() + 0x01C7, static_cast<std::uint8_t>(0xEB));
		REL::safe_write(Offsets::AIProcess::sub_674B60.address() + 0x017F, static_cast<std::uint8_t>(0xEB));
		REL::safe_write(Offsets::Actor::FinishLoadGame.address() + 0x01C3, static_cast<std::uint8_t>(0xEB));
	}
}
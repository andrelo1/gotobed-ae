#pragma once

namespace Gotobed::Offsets
{
	namespace
	{
		constexpr REL::ID ShowSleepWaitMenu{ static_cast<std::uint64_t>(51618) };
		constexpr REL::ID ShowMessageBox{ static_cast<std::uint64_t>(51420) };
		constexpr REL::ID unk_2FEA508{ static_cast<std::uint64_t>(519814) };
	}

	namespace TESFurniture
	{
		constexpr REL::ID Activate{ static_cast<std::uint64_t>(17034) };
	}

	namespace TESObjectREFR
	{
		constexpr REL::ID GetCurrentLocation{ static_cast<std::uint64_t>(19385) };
		constexpr REL::ID SetMarkerReserved{ static_cast<std::uint64_t>(19765) };
		constexpr REL::ID SetMarkerUsed{ static_cast<std::uint64_t>(19764) };
	}

	namespace Actor
	{
		constexpr REL::ID FinishLoadGame{ static_cast<std::uint64_t>(36644) };
	}

	namespace PlayerCharacter
	{
		constexpr REL::ID Update{ static_cast<std::uint64_t>(39375) };
		constexpr REL::ID CanSleepWaitHere{ static_cast<std::uint64_t>(39371) };
	}

	namespace ExtraReservedMarkers
	{
		constexpr REL::ID vtbl{ static_cast<std::uint64_t>(235661) };
	}

	namespace ExtraUsedMarkers
	{
		constexpr REL::ID vtbl{ static_cast<std::uint64_t>(235660) };
	}

	namespace AIProcess
	{
		constexpr REL::ID SitSleepStateUpdate{ static_cast<std::uint64_t>(38871) };
		constexpr REL::ID sub_674B60{ static_cast<std::uint64_t>(38317) };
	}

	namespace MenuOpenHandler
	{
		constexpr REL::ID ProcessButton{ static_cast<std::uint64_t>(51400) };
	}
}
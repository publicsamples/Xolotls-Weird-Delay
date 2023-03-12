/** Autogenerated Main.cpp. */

// =================================| Include only the DSP files  |=================================

#include <hi_dsp_library/hi_dsp_library.h>
#include <hi_faust/hi_faust.h>
#include "includes.h"
// ===========================| Now we can add the rest of the codebase |===========================

#include <JuceHeader.h>

// =======================================| Project Factory |=======================================

namespace project
{

struct Factory: public scriptnode::dll::StaticLibraryHostFactory
{
	Factory()
	{
		TempoSyncer::initTempoData();
		// Node registrations ---------------------------------------------------------------------
		
		registerPolyNode<project::klp<1>, project::klp<NUM_POLYPHONIC_VOICES>>();
		registerPolyNode<project::khp<1>, project::khp<NUM_POLYPHONIC_VOICES>>();
		registerPolyNode<project::granular<1>, project::granular<NUM_POLYPHONIC_VOICES>>();
		registerPolyNode<project::g<1>, project::g<NUM_POLYPHONIC_VOICES>>();
		registerPolyNode<project::Filter<1>, wrap::illegal_poly<project::Filter<1>>>();
		registerPolyNode<project::Gran<1>, wrap::illegal_poly<project::Gran<1>>>();
		registerPolyNode<project::jdel<1>, wrap::illegal_poly<project::jdel<1>>>();
		registerPolyNode<project::pitchshifter<1>, wrap::illegal_poly<project::pitchshifter<1>>>();
		registerDataNode<project::clone_networkdata>();
		registerDataNode<project::delay_networkdata>();
		registerDataNode<project::follower_networkdata>();
		registerDataNode<project::Granulator_networkdata>();
		registerDataNode<project::mod_networkdata>();
		registerDataNode<project::Switch_networkdata>();
		registerDataNode<project::wdelay_networkdata>();
		registerDataNode<project::wdelaymod_networkdata>();
		registerDataNode<project::wdeleay_networkdata>();
		registerDataNode<project::wdeleay_networkdata>();
		registerDataNode<project::wdeleay2_networkdata>();
		registerDataNode<project::wdeleay2_networkdata>();
		registerDataNode<project::wdeleay2_networkdata>();
		registerDataNode<project::wdeleay2mod_networkdata>();
		registerDataNode<project::wdeleay3_networkdata>();
		registerDataNode<project::WeirdDelay_networkdata>();
		registerDataNode<project::_4WaySwitch_networkdata>();
	}
};
}

scriptnode::dll::FactoryBase* hise::FrontendHostFactory::createStaticFactory()
{
	return new project::Factory();
}

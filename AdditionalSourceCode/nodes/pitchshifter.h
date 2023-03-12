#pragma once

// These will improve the readability of the connection definition

#define getT(Idx) template get<Idx>()
#define connectT(Idx, target) template connect<Idx>(target)
#define getParameterT(Idx) template getParameter<Idx>()
#define setParameterT(Idx, value) template setParameter<Idx>(value)
#define setParameterWT(Idx, value) template setWrapParameter<Idx>(value)
using namespace scriptnode;
using namespace snex;
using namespace snex::Types;

namespace pitchshifter_impl
{
// ===========================| Node & Parameter type declarations |===========================

template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<project::g<NV>, 4>, 
                               control::tempo_sync<NV>>;
using stereo_cable = cable::block<2>;

namespace pitchshifter_t_parameters
{
// Parameter list for pitchshifter_impl::pitchshifter_t --------------------------------------

template <int NV>
using xfda = parameter::plain<project::g<NV>, 0>;
template <int NV>
using shift = parameter::plain<project::g<NV>, 2>;
template <int NV>
using pich = parameter::plain<project::g<NV>, 3>;
template <int NV>
using Window = parameter::plain<pitchshifter_impl::tempo_sync_t<NV>, 
                                0>;
template <int NV>
using windowdiv = parameter::plain<pitchshifter_impl::tempo_sync_t<NV>, 
                                   1>;
using Feedback = parameter::plain<routing::receive<stereo_cable>, 
                                  0>;
template <int NV>
using pitchshifter_t_plist = parameter::list<xfda<NV>, 
                                             shift<NV>, 
                                             pich<NV>, 
                                             Window<NV>, 
                                             windowdiv<NV>, 
                                             Feedback>;
}

template <int NV>
using pitchshifter_t_ = container::chain<pitchshifter_t_parameters::pitchshifter_t_plist<NV>, 
                                         wrap::fix<2, tempo_sync_t<NV>>, 
                                         routing::receive<stereo_cable>, 
                                         project::g<NV>, 
                                         routing::send<stereo_cable>>;

// ==============================| Root node initialiser class |==============================

template <int NV> struct instance: public pitchshifter_impl::pitchshifter_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(pitchshifter);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(98)
		{
			0x005B, 0x0000, 0x7800, 0x6466, 0x0061, 0x0000, 0x3F80, 0x4000, 
            0x461C, 0x5800, 0x459B, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x015B, 
            0x0000, 0x7300, 0x6968, 0x7466, 0x0000, 0x4000, 0x00C1, 0x4000, 
            0x0041, 0x4000, 0x0034, 0x8000, 0xCD3F, 0xCCCC, 0x5B3D, 0x0002, 
            0x0000, 0x6970, 0x6863, 0x0000, 0x0000, 0x0000, 0x4000, 0x0041, 
            0x0000, 0x0000, 0x8000, 0x0A3F, 0x23D7, 0x5B3C, 0x0003, 0x0000, 
            0x6957, 0x646E, 0x776F, 0x0000, 0x0000, 0x0000, 0x9000, 0x0041, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0004, 0x0000, 
            0x6977, 0x646E, 0x776F, 0x6964, 0x0076, 0x0000, 0x3F80, 0x0000, 
            0x4180, 0x0000, 0x4110, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x055B, 
            0x0000, 0x4600, 0x6565, 0x6264, 0x6361, 0x006B, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0xCB85, 0x3F19, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------
		
		auto& tempo_sync = this->getT(0); // pitchshifter_impl::tempo_sync_t<NV>
		auto& receive = this->getT(1);    // routing::receive<stereo_cable>
		auto& faust = this->getT(2);      // project::g<NV>
		auto& send = this->getT(3);       // routing::send<stereo_cable>
		
		// Parameter Connections -------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, faust); // xfda -> faust::Crossfade
		
		this->getParameterT(1).connectT(0, faust); // shift -> faust::PitchShift
		
		this->getParameterT(2).connectT(0, faust); // pich -> faust::SuperPitch
		
		this->getParameterT(3).connectT(0, tempo_sync); // Window -> tempo_sync::Tempo
		
		this->getParameterT(4).connectT(0, tempo_sync); // windowdiv -> tempo_sync::Multiplier
		
		this->getParameterT(5).connectT(0, receive); // Feedback -> receive::Feedback
		
		// Modulation Connections ------------------------------------------------------------
		
		tempo_sync.getParameter().connectT(0, faust); // tempo_sync -> faust::Window
		
		// Send Connections ------------------------------------------------------------------
		
		send.connect(receive);
		
		// Default Values --------------------------------------------------------------------
		
		;                                // tempo_sync::Tempo is automated
		;                                // tempo_sync::Multiplier is automated
		tempo_sync.setParameterT(2, 1.); // control::tempo_sync::Enabled
		tempo_sync.setParameterT(3, 0.); // control::tempo_sync::UnsyncedTime
		
		; // receive::Feedback is automated
		
		;                          // faust::Crossfade is automated
		faust.setParameterT(1, 1); // core::faust::DryWet
		;                          // faust::PitchShift is automated
		;                          // faust::SuperPitch is automated
		;                          // faust::Window is automated
		
		this->setParameterT(0, 4971.);
		this->setParameterT(1, 1.78814e-07);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 9.);
		this->setParameterT(5, 0.600762);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool isProcessingHiseEvent() { return true; };
	
	static constexpr bool hasTail() { return true; };
};
}

#undef getT
#undef connectT
#undef setParameterT
#undef setParameterWT
#undef getParameterT
// ===================================| Public Definition |===================================

namespace project
{
// polyphonic template declaration

template <int NV>
using pitchshifter = wrap::node<pitchshifter_impl::instance<NV>>;
}



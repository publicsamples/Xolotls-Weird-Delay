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

namespace jdel_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using tempo_sync2_t = wrap::mod<parameter::plain<jdsp::jdelay, 1>, 
                                control::tempo_sync<NV>>;
DECLARE_PARAMETER_RANGE_STEP(pma_mod_0Range, 
                             0., 
                             18., 
                             1.);

template <int NV>
using pma_mod_0 = parameter::from0To1<tempo_sync2_t<NV>, 
                                      0, 
                                      pma_mod_0Range>;

DECLARE_PARAMETER_RANGE_STEP(pma_mod_1Range, 
                             0., 
                             1000., 
                             0.1);

template <int NV>
using pma_mod_1 = parameter::from0To1<tempo_sync2_t<NV>, 
                                      3, 
                                      pma_mod_1Range>;

template <int NV>
using pma_mod = parameter::chain<ranges::Identity, 
                                 pma_mod_0<NV>, 
                                 pma_mod_1<NV>>;

template <int NV>
using pma_t = control::pma<NV, pma_mod<NV>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, pma_t<NV>>, 
                                  tempo_sync2_t<NV>>;

template <int NV>
using tempo_sync3_t = wrap::mod<parameter::plain<jdsp::jdelay, 0>, 
                                control::tempo_sync<NV>>;
template <int NV>
using pma1_mod_0 = parameter::from0To1<tempo_sync3_t<NV>, 
                                       0, 
                                       pma_mod_0Range>;

template <int NV>
using pma1_mod_1 = parameter::from0To1<tempo_sync3_t<NV>, 
                                       3, 
                                       pma_mod_1Range>;

template <int NV>
using pma1_mod = parameter::chain<ranges::Identity, 
                                  pma1_mod_0<NV>, 
                                  pma1_mod_1<NV>>;

template <int NV>
using pma1_t = control::pma<NV, pma1_mod<NV>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<2, pma1_t<NV>>, 
                                  tempo_sync3_t<NV>>;
using stereo_cable = cable::block<2>;

template <int NV>
using fix32_block_t_ = container::chain<parameter::empty, 
                                        wrap::fix<2, routing::receive<stereo_cable>>, 
                                        jdsp::jdelay, 
                                        core::smoother<NV>, 
                                        routing::send<stereo_cable>>;

template <int NV>
using fix32_block_t = wrap::fix_block<32, fix32_block_t_<NV>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<2, fix32_block_t<NV>>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, chain1_t<NV>>, 
                                  chain3_t<NV>, 
                                  chain4_t<NV>>;

namespace jdel_t_parameters
{
// Parameter list for jdel_impl::jdel_t ------------------------------------------------------------

template <int NV>
using sync = parameter::chain<ranges::Identity, 
                              parameter::plain<jdel_impl::tempo_sync2_t<NV>, 2>, 
                              parameter::plain<jdel_impl::tempo_sync3_t<NV>, 2>>;

template <int NV>
using dtime = parameter::plain<jdel_impl::pma_t<NV>, 0>;
template <int NV>
using Limit = parameter::plain<jdel_impl::pma1_t<NV>, 0>;
template <int NV>
using dmulti = parameter::plain<jdel_impl::tempo_sync2_t<NV>, 
                                1>;
template <int NV>
using limmulti = parameter::plain<jdel_impl::tempo_sync3_t<NV>, 
                                  1>;
template <int NV>
using ignore = parameter::plain<core::smoother<NV>, 1>;
template <int NV>
using smooth = parameter::plain<core::smoother<NV>, 0>;
using feedbk = parameter::plain<routing::receive<stereo_cable>, 
                                0>;
template <int NV>
using jdel_t_plist = parameter::list<dtime<NV>, 
                                     Limit<NV>, 
                                     dmulti<NV>, 
                                     limmulti<NV>, 
                                     sync<NV>, 
                                     ignore<NV>, 
                                     smooth<NV>, 
                                     feedbk>;
}

template <int NV>
using jdel_t_ = container::chain<jdel_t_parameters::jdel_t_plist<NV>, 
                                 wrap::fix<2, chain2_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public jdel_impl::jdel_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(jdel);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(128)
		{
			0x005B, 0x0000, 0x6400, 0x6974, 0x656D, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x1000, 0x0041, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0001, 0x0000, 0x694C, 0x696D, 0x0074, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0xAD06, 0x3DFD, 0x0000, 0x3F80, 0x0000, 0x0000, 0x025B, 
            0x0000, 0x6400, 0x756D, 0x746C, 0x0069, 0x0000, 0x3F80, 0x0000, 
            0x4180, 0x0000, 0x4110, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x035B, 
            0x0000, 0x6C00, 0x6D69, 0x756D, 0x746C, 0x0069, 0x0000, 0x3F80, 
            0x0000, 0x4180, 0x0000, 0x40E0, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x045B, 0x0000, 0x7300, 0x6E79, 0x0063, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x055B, 
            0x0000, 0x6900, 0x6E67, 0x726F, 0x0065, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x065B, 
            0x0000, 0x7300, 0x6F6D, 0x746F, 0x0068, 0x0000, 0x0000, 0x0000, 
            0x44FA, 0x0000, 0x3F80, 0xEE69, 0x3E6C, 0xCCCD, 0x3DCC, 0x075B, 
            0x0000, 0x6600, 0x6565, 0x6264, 0x006B, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0xA3CF, 0x3EDB, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& chain2 = this->getT(0);                            // jdel_impl::chain2_t<NV>
		auto& chain1 = this->getT(0).getT(0);                    // jdel_impl::chain1_t<NV>
		auto& pma = this->getT(0).getT(0).getT(0);               // jdel_impl::pma_t<NV>
		auto& tempo_sync2 = this->getT(0).getT(0).getT(1);       // jdel_impl::tempo_sync2_t<NV>
		auto& chain3 = this->getT(0).getT(1);                    // jdel_impl::chain3_t<NV>
		auto& pma1 = this->getT(0).getT(1).getT(0);              // jdel_impl::pma1_t<NV>
		auto& tempo_sync3 = this->getT(0).getT(1).getT(1);       // jdel_impl::tempo_sync3_t<NV>
		auto& chain4 = this->getT(0).getT(2);                    // jdel_impl::chain4_t<NV>
		auto& fix32_block = this->getT(0).getT(2).getT(0);       // jdel_impl::fix32_block_t<NV>
		auto& receive = this->getT(0).getT(2).getT(0).getT(0);   // routing::receive<stereo_cable>
		auto& jdelay1 = this->getT(0).getT(2).getT(0).getT(1);   // jdsp::jdelay
		auto& smoother1 = this->getT(0).getT(2).getT(0).getT(2); // core::smoother<NV>
		auto& send = this->getT(0).getT(2).getT(0).getT(3);      // routing::send<stereo_cable>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma); // dtime -> pma::Value
		
		this->getParameterT(1).connectT(0, pma1); // Limit -> pma1::Value
		
		this->getParameterT(2).connectT(0, tempo_sync2); // dmulti -> tempo_sync2::Multiplier
		
		this->getParameterT(3).connectT(0, tempo_sync3); // limmulti -> tempo_sync3::Multiplier
		
		auto& sync_p = this->getParameterT(4);
		sync_p.connectT(0, tempo_sync2); // sync -> tempo_sync2::Enabled
		sync_p.connectT(1, tempo_sync3); // sync -> tempo_sync3::Enabled
		
		this->getParameterT(5).connectT(0, smoother1); // ignore -> smoother1::DefaultValue
		
		this->getParameterT(6).connectT(0, smoother1); // smooth -> smoother1::SmoothingTime
		
		this->getParameterT(7).connectT(0, receive); // feedbk -> receive::Feedback
		
		// Modulation Connections ------------------------------------------------------------------
		
		tempo_sync2.getParameter().connectT(0, jdelay1);                 // tempo_sync2 -> jdelay1::DelayTime
		pma.getWrappedObject().getParameter().connectT(0, tempo_sync2);  // pma -> tempo_sync2::Tempo
		pma.getWrappedObject().getParameter().connectT(1, tempo_sync2);  // pma -> tempo_sync2::UnsyncedTime
		tempo_sync3.getParameter().connectT(0, jdelay1);                 // tempo_sync3 -> jdelay1::Limit
		pma1.getWrappedObject().getParameter().connectT(0, tempo_sync3); // pma1 -> tempo_sync3::Tempo
		pma1.getWrappedObject().getParameter().connectT(1, tempo_sync3); // pma1 -> tempo_sync3::UnsyncedTime
		
		// Send Connections ------------------------------------------------------------------------
		
		send.connect(receive);
		
		// Default Values --------------------------------------------------------------------------
		
		;                         // pma::Value is automated
		pma.setParameterT(1, 1.); // control::pma::Multiply
		pma.setParameterT(2, 0.); // control::pma::Add
		
		; // tempo_sync2::Tempo is automated
		; // tempo_sync2::Multiplier is automated
		; // tempo_sync2::Enabled is automated
		; // tempo_sync2::UnsyncedTime is automated
		
		;                          // pma1::Value is automated
		pma1.setParameterT(1, 1.); // control::pma::Multiply
		pma1.setParameterT(2, 0.); // control::pma::Add
		
		; // tempo_sync3::Tempo is automated
		; // tempo_sync3::Multiplier is automated
		; // tempo_sync3::Enabled is automated
		; // tempo_sync3::UnsyncedTime is automated
		
		; // receive::Feedback is automated
		
		; // jdelay1::Limit is automated
		; // jdelay1::DelayTime is automated
		
		; // smoother1::SmoothingTime is automated
		; // smoother1::DefaultValue is automated
		
		this->setParameterT(0, 9.);
		this->setParameterT(1, 0.123865);
		this->setParameterT(2, 9.);
		this->setParameterT(3, 7.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 0.);
		this->setParameterT(6, 1.);
		this->setParameterT(7, 0.428984);
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
// ======================================| Public Definition |======================================

namespace project
{
// polyphonic template declaration

template <int NV>
using jdel = wrap::node<jdel_impl::instance<NV>>;
}



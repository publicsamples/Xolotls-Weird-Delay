import("stdfaust.lib");

transpose (w, x, s, sig)  =
	fdelay1s(d,sig)*ma.fmin(d/x,1) + fdelay1s(d+w,sig)*(1-ma.fmin(d/x,1))
	   	with {
			i = 1 - pow(2, s/12);
			d = i : (+ : +(w) : fmod(_,w)) ~ _;
	        };

pitchshifter = ef.transpose(hslider("Window[style:knob][OWL:PARAMETER_B]", 1000, 50, 1200000, 1),
	                 hslider("Crossfade[style:knob][OWL:PARAMETER_C]", 10, 1, 10000, 1),
	                 hslider("Pitch Shift[style:knob][OWL:PARAMETER_A]", 0, -12, +12, 0.1) +
	                 hslider("Super Pitch[style:knob][OWL:PARAMETER_E]", 0, 0, 12, 0.01)
		        );

// add dry wet control
stereodrywet (monofx) = _,_ <: *(1-dw), *(1-dw), monofx*dw, monofx*dw :> _,_
	with {
		dw = hslider("Dry/Wet[OWL:PARAMETER_D]",0.5,0,1,0.01);
	};

process = stereodrywet(pitchshifter);
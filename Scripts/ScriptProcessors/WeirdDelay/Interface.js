Content.makeFrontInterface(850, 475);

const var SliderPack4 = Content.getComponent("SliderPack4");

SliderPack4.setAllValues(0.5);

const simpleGain = [
	Synth.getEffect("Simple Gain1"),
	Synth.getEffect("Simple Gain2")
];

inline function onmastermixControl(component, value)
{
	local a = Math.sqr(value);
	local b = Math.sqr(1 - value);
	
	simpleGain[0].setAttribute(simpleGain[0].Gain, Engine.getDecibelsForGainFactor(b));
	simpleGain[1].setAttribute(simpleGain[1].Gain, Engine.getDecibelsForGainFactor(a));
};

Content.getComponent("mastermix").setControlCallback(onmastermixControl);
function onNoteOn()
{
	
}
 function onNoteOff()
{
	
}
 function onController()
{
	
}
 function onTimer()
{
	
}
 function onControl(number, value)
{
	
}
 
namespace project
{

struct wdeleay2mod_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "wdeleay2mod";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "1821.nT6K8CV+tzIN.XYNudBvVTM.SjKV6TVVL5moYQsLypP.22NfffqL.x0nrnTvJQl.berA4Gvn.TJ.lB.TSwH+bvyOl1NzqFcmqZVGnWMGt4uicFRF621tS3Z9.Uy3m6h6vBTKcUcUQMYEkbMPMty0dmHhyVM24h8Fd6HSLQryQtVNdAWpzwb0x04AXwBT2cUfZXG9yu1DO6vyMaS+bKPM865lbejn2pyLrH7uUm4sKli.Tmkmc7AeyXSKt.0O8tADTG8b.f5sasC+gzzqV7y7sO0iS.TSAFUf5RvWO4eiSVR4yh5JFkNF32Me66gmoKAalyQzROqmrh5RZhph5IklhN.cGmjvJHUk0kUD0BT6MKq6wYezWOITxRpp5UEiQonIWAn1yWxlFRAguKI3CtPJ0MbedyK.LNDB+BTixS2vfDR5HwmokqqRwLOo.k6Dc+44ENlHdJxa4zpctFKQcXUs41Gpm.rpUsvatSDPQY4olKPS0TfADkoFsuU03BT6.zUT5zwDe.C3sb3byhj6vsUY.BfJXmwy7Ft6MCKbwrHXUtdVY9MPZ5VEdF7W0.stnU+fdq3uCWijiRivcLV9vRBa6SmHWNsO6EP.Ezw.4Z7EnWMefpt+X4pYaGMnlZbUxvxUOa5laZw+Ib3YnWMbLcG05rgaPkH6EevUE9oSRP4h0KJflIb2k+t2iWjyVMKeuZvW0kj7AeRKQO9hI47z5Fe.uu07zCGf3SdAe0MktjpjWOXkU7BxPVl6oFH8mT5+VkjLcbdtzspmLI0rNNZGlXLBiSxpIqnpKq8gvpoHLZUIgRJITRZJJeRQWgFVRdhogmToMzgYdtOY40jTdYQAmfnM4wURIo0iJ6BLEgVQoqIMz+Iwwn85PopYep6PoJKXTJJiRX70vmo8o3AH4zI3NSPfSeJ8GQqhJWhdtq8OY6q7fRQKccfeZ0tIB6RfPiZv8HXF.....fff.DGC.fTXlTxLCHLdPzLHTLX.nbLH...H..PBDXDXD.H.fXX.hjadtsfDD2TTRSqvV4tcI3lBxmvFlmsapD7a.1ReTFE0tnpV70UebQEcPU8E5bHgZYI7zuWDnS28rHy+DHu5mbuynEnv6KgTr5zLotoPj.se7vpFwh4JSyYq1W.0sv5pEWcRnZXCb2wX4kkYb42RDQjWHov8xsBQKL.flAVeM1qP6s+nRDRvWCRUJG515rFKnaeLHpM+bQvnz0rwQVDI7DnViC2LNXA5RwtgyOg2H8T4bZDUBU3n.Vw8gWQ91k7p.SIHeDXgdyLYi.XTLGS7p3ExPQ5pUkHhTtttYiUILjqcPR.i.PeWeiTn.JrBIYqeehxbMxIhtWr61HNQ8Fc3PYcx6FMh40dWL7jZOIxMu4rQBNojmgHVKwPFAr43k7qkiplYOYAkWCjZb4P.o9AJbvWXea01E4G6DUS831DkOwmVFVOXDmMqFIQg29z+YURxAvWRfTdsuxAth4yWhCCBF3BKNQFcQRGjT9gY0QxibdjmdYjYAkSc4BkzsuB9SZ+VfHAJ4TFQEO6+CmRfBFOru6X0n1WIPWBqrqiWLpv.46KjTMkis18Kyx1kjMdHvBuloZFM9xwSMCUSRE2TORw7m10dcJibwI7l.IbhtQQJQUN1pLjz0MHqSPe5quZeZdPPQQMbQdy+avG68HMDx0W.lyBHw.4.uNhOQDowCUDjJ7FjME3FNp.0hbk1bIimfdqB+1DaGcg469p4vhl69fDB5rtGsT4DrY0ddPix9ktj1gLKFNNaOYA8JIXEzHwt8cCREp78TQzNLIooVxqiCErARKh3kzCu7MbSDjTfMiK6iGTB.e5NJDiFvB9T4QM.go4M08zY4G2ZJEnaYDtUmtHclbjA7Jf1IIO7gxnid.Sv7i6bHH+5o94o7UtLIsL+4BzWlwblSa+fmwLnQgX3w.GJn4RVjdS4OrXXFGZ3+YTgXIF4kKHB4gzBOfxECiBQJ2CXmkuybJ+IrODjfFLbgAJFWFKD3F9Cfcb2m9hm1yNtCRBgxXgBQ9+XaM3T4ospi5cNf99rP3DTZEfA5DXPvLYNgQWyz00zS2j7z4QO310mpAMwgRPDWekEigwnVwoksn8S9BhzuiKmL19oiGgdu6ebfL+vCA+1UzDjzFIm27QBXiaO2NgusMGb+chbW.vqnALIboLERXv5yBNWcf72Yc5x.L0HrCYvO7BqOvbCgPAd9o3f09nnLeZdXLY00NDxcb2KuXPjsFSBKks8L.dNLZ.eavokaC+pjIQcPqtwqPfomOjkE4ubQgYA3GqeYQitLgRSWWYTSKinlJa4ucGJJeN..N9uhzd3yWJ7xjwYCP+PXO7Zbx.qO8wrKO3xDJlXp9LUFJM8SRlhjnBkrVVBUhUgFmrmxZcTbBPup0du0miiczQnt5vRpXno5WSTbdPbbNZ3joe3";
	}
};
}


(function (){
	"use strict";
	window.Calculator = window.Calculator || {Routers: {}, Collections: {}, Models: {}, Views: {}, Values: {}};
	//Models instantiated 
	Calculator.Values.chainring = new Calculator.Models.ChainringTeeth();
	Calculator.Values.cog = new Calculator.Models.CogTeeth();
	Calculator.Values.cranks = new Calculator.Models.CrankLength();
	Calculator.Values.wheels = new Calculator.Collections.WheelSizes();
	Calculator.Values.profile = new Calculator.Models.Profile();

	Calculator.Values.calcGearInches = function (wheel, chainring, cog){
		//uses wheel diameter in inches
		return (wheel * (chainring/cog)).toFixed(1);
	};

	Calculator.Values.calcMetresOfDevelopment = function (gearInches){
		//convert to metres of development by multiplying by PI times imperial to metric conversion i.e. .0254
		return (gearInches * 0.0254*Math.PI).toFixed(1);
	};

	Calculator.Values.mmToInches = function (mm){
		return mm * 0.0393701;
	};

	Calculator.Values.calcGainRatio = function (wheelDiam, crank, chainring, cog){
		crank = Calculator.Values.mmToInches(crank);
		var radRatio = (wheelDiam/2)/crank;
		return (radRatio * (chainring/cog)).toFixed(1);
	};

	Calculator.Values.calcSkidPatches = function (chainring, cog, ambi){
		var factor = 0;
		var ratio = chainring/cog;
		var multiple = 0.1;

		//Find the decimal ratio, and multiply it under the lowest even number is found
		//this is the lowest denominator. 
		while(Math.floor(multiple) != multiple){
			factor ++;
			multiple = ratio * factor;
		}
		return ambi? factor*2 : factor;

	};

	Calculator.Values.calcCadenceKM = function (metres, cadence){
		var distance = metres * cadence;
		var speed = distance * 60;
		return (speed/1000).toFixed(1);
	};

	Calculator.Values.convertKMToMiles = function (km){
		return km *= 0.62137;
	};

	Calculator.Values.loadSizes() = function (){
		var sizes = [{value: 29, name: "29 inch (nominal)"},{value: 28, name: "28 inch (nominal)"},{value: 27, name: "27 inch (nominal)"},{value: 26, name: "26 inch (nominal)"},
		{value: 29.13, name: "700 X 56 / 56-622 / 29 inch"},{value: 28.94, name: "700 X 50 / 50-622 / 29 inch"},{value: 27.86, name: "700 X 44 / 44-622 / 29 inch"},{value: 27.32, name: "700 X 38 / 38-622"},
		{value: 27.17, name: "700 X 35 / 35-622"},{value: 27, name: "700 X 32 / 32-622 "},{value: 26.76, name: "700 X 28 / 28-622"},{value: 26.38, name: "700 X 25 / 25-622"},
		{value: 26.28, name: "700 X 23 / 23-622"},{value: 26.14, name: "700 X 20 / 20-622"},{value: 26.53, name: "Tubular / Wide"},{value: 26.38, name: "Tubular / Narrow"},
		{value: 28.15, name: "28 X 1 1/2 / 40-635 "},{value: 27.18, name: "27 X 1 3/8 / 35-630"},{value: 27.08, name: "27 X 1 1/4 / 32-630"},{value: 27, name: "27 X 1 1/8 / 28-630"},
		{value: 26.88, name: "27 X 1 / 25-630"},{value: 26.41, name: "26 X 2.35 / 60-559 / MTB"},{value: 25.94, name: "26 X 2.125 / 54-559 / MTB"},{value: 25.75, name: "26 X 1.9 / 47-559 / MTB"},
		{value: 24.87, name: "26 X 1.5 / 38-559 / MTB"},{value: 24.47, name: "26 X 1.25 / 32-559 / MTB"},{value: 23.97, name: "26 X 1.0 / 25-559 / MTB"},{value: 26, name: "650 x 38b / 38-584 650B"},
		{value: 24.7, name: "650 x 28C / 28-571 / 26' road/tri"},{value: 24.46, name: "650 x 25C / 25-571 / 26' road/tri"},{value: 24.31, name: "650 x 23C / 23-571 / 26' road/tri"},
		{value: 25.91, name: "26 X 1 3/8 / 35-590"},{value: 24, name: "24 inch (nominal)"},{value: 21.97, name: "24 x 1 / 25-520"},{value: 20.15, name: "32-451 /20 x 1 3/8"},
		{value: 19.9, name: "28-451/20 x 1 1/8"},{value: 18.68, name: "20 X 1.75 / 44-406 / BMX"},{value: 18.43, name: "20 X 1.25 / 32-406"},{value: 17.16, name: "18 x 1.5 / 40-355"},
		{value: 16.6, name: "17 x 1 1/4 / 28-369"},{value: 16.88, name: "16 x 1 1/2 / 40-349"},{value: 16.07, name: "16 x 1 3/8 / 35-349"},{value: 13.46, name: "16 x 1.5 / 37-305"}];

		Calculator.Values.wheels.add(sizes);
	}

	Calculator.Values.loadSizes();

	Calculator.Values.router = new Calculator.Routers.GearRouter();
}());
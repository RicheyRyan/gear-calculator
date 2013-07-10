(function (){
	"use strict";
	window.Calculator = window.Calculator || {Routers: {}, Collections: {}, Models: {}, Views: {}, Values: {}};

	Calculator.Routers.GearRouter = Backbone.Router.extend({
		routes: {
			"index" : "index"
		},

		initialize: function (){
			this.index();
		},

		index: function (){
			//Views Instantiated 
			Calculator.Values.chainringForm = new Calculator.Views.ChainringView({el: $("#chainring")});
			Calculator.Values.cogForm = new Calculator.Views.CogView({el: $("#cog")});
			Calculator.Values.wheelForm = new Calculator.Views.WheelView({el: $("#wheel")});
			Calculator.Values.crankForm = new Calculator.Views.CrankView({el: $("#crank")});

		}
	});
	//Models instantiated 
	Calculator.Values.chainring = new Calculator.Models.ChainringTeeth();
	Calculator.Values.cog = new Calculator.Models.CogTeeth();
	Calculator.Values.cranks = new Calculator.Models.CrankLength();
	Calculator.Values.wheels = new Calculator.Collections.WheelSizes();

	function loadSizes(){
		var sizes = [{name: "700x50 (622-50)", value: 0},{name: "700x44 (622-44)", value: 0}, { name: "700x38 (622-38)", value: 0},{name: "700x35 (622-35)", value: 0},
		{name: "700x32 (622-32)",value: 0},{name: "700x28 (622-28)",value: 0},{name: "700x25 (622-25)",value: 0},{name: "700x23 (622-23)",value: 0},{name: "700x20 (622-20)",value: 0},
		{name: "27x1'3/8 (630-35)",value: 0},{name: "27x1'1/4 (630-32)",value: 0},{name: "27x1'1/8 (630-28)",value: 0},{name: "27x1' (630-25)",value: 0},{name: "26x2'1/8 (559-54)",value: 0},
		{name: "26x1.9' (559-47)",value: 0},{name: "26x1'/2 (559-38)",value: 0},{name: "26x1'1/4 (559-32)",value: 0},{name: "26x1' (559-25)",value: 0},{name: "26x1' (571-25)",value: 0},
		{name: "650C (571-25)",value: 0},{name: "Tubular (Wide)",value: 0},{name: "Tubular (Narrow)",value: 0},{name: "26x1 3/8 (590-35)",value: 0},{name: "24 (Most)",value: 0},
		{name: "24x1 (520-25)",value: 0},{name: "20x1'3/4 (406-44)",value: 0},{name: "20x1'1/4 (451-28)",value: 0},{name: "18x1'1/2 (355-40)",value: 0},{name: "17x1'1/4 (369-28)",value: 0},
		{name: "16x1'3/8 (349-35)",value: 0},{name: "16x1'1/2 (305-37)",value: 0}];

		Calculator.Values.wheels.add(sizes);
	}

	loadSizes();

	Calculator.Values.router = new Calculator.Routers.GearRouter();

}());





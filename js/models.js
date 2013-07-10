(function (){
	"use strict";
	window.Calculator = window.Calculator || {Routers: {}, Collections: {}, Models: {}, Views: {}, Values: {}};

	Calculator.Models.WheelSize= Backbone.Model.extend({
		defaults: {
			name: "",
			value: ""
		}
	});

	Calculator.Models.ChainringTeeth = Backbone.Model.extend({
		defaults:{
			minTeeth: 28,
			maxTeeth: 59
		}
	});

	Calculator.Models.CogTeeth = Backbone.Model.extend({
		defaults:{
			minTeeth: 9,
			maxTeeth: 23
		}
	});

	Calculator.Models.WheelSize = Backbone.Model.extend({
		defaults:{
			name : "",
			value : ""
		}
	});

	Calculator.Models.CrankLength = Backbone.Model.extend({
		defaults: [150, 152, 155, 158, 160, 162.5, 165, 167.5, 170, 172.5, 175, 177.5, 180, 185, 190]
	});

	

	Calculator.Collections.WheelSizes = Backbone.Collection.extend({
		model: Calculator.Models.WheelSize
	});


}());
console.log("Finished Creating Models");


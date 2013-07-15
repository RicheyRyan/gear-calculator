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
			Calculator.Values.formView = new Calculator.Views.FormView({ el: $('#gear-form') });
			Calculator.Values.main = new Calculator.Views.Main({el : $('.main-content')});
		}
	});

	//Calculator.Values.router = new Calculator.Routers.GearRouter();

}());
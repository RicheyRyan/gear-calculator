(function (){
	"use strict";
	window.Calculator = window.Calculator || {Routers: {}, Collections: {}, Models: {}, Views: {}, Values: {}};

	Calculator.Views.ChainringView = Backbone.View.extend({

		initialize: function(){
			this.render();
		},

		render: function () {
			var max = Calculator.Values.chainring.attributes.maxTeeth;
			var min = Calculator.Values.chainring.attributes.minTeeth;
			var html = "";
			for(var i = min; i <= max; i ++){
				html += _.template($('#chainring-temp').html(), {value : i});
			}
			this.$el.html(html);
		}

	});

	Calculator.Views.CogView = Backbone.View.extend({

		initialize: function(){
			this.render();
		},

		render: function () {
			var max = Calculator.Values.cog.attributes.maxTeeth;
			var min = Calculator.Values.cog.attributes.minTeeth;
			var html = "";
			for(var i = min; i <= max; i ++){
				html += _.template($('#cog-temp').html(), {value : i});
			}
			this.$el.html(html);
		}

	});

	Calculator.Views.WheelView = Backbone.View.extend({

		initialize: function(){
			this.render();
		},

		render: function () {
			var sizes = [];
			_.map(Calculator.Values.wheels.models, function(obj){ sizes.push(obj.attributes);});
			var html = "";
			_.each(sizes, function(obj){ html += _.template($('#wheel-temp').html(), {name: obj.name, value: obj.value}); });
			this.$el.html(html);
		}

	});

	Calculator.Views.CrankView = Backbone.View.extend({

		initialize: function(){
			this.render();
		},

		render: function () {
			var lengths = [];
			_.map(Calculator.Values.cranks.attributes, function(obj){ lengths.push(obj);});
			var html = "";
			_.each(lengths, function(obj){ html += _.template($('#crank-temp').html(), {value: obj}); });
			this.$el.html(html);
		}

	});

	Calculator.Views.FormView = Backbone.View.extend({

		events: {
			"submit": "save"
		},

		save: function() {
			var arr = this.$el.serializeArray();
			var length = arr;
			var data = _(arr).reduce(function(acc, field) {
				acc[field.name] = field.value;
				return acc;
			}, {});
			Calculator.Values.profile = new Calculator.Models.Profile(data);
			console.log(arr);
			return false;
		}

	});

	Calculator.Views.Placeholder = Backbone.View.extend({
		initialize: function(){
			this.render();
		},

		render: function () {
			this.$el.html(_.template($('#placeholder').html(), {}));
		}

	});

}());
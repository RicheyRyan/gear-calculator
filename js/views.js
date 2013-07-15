(function (){
	"use strict";
	window.Calculator = window.Calculator || {Routers: {}, Collections: {}, Models: {}, Views: {}, Values: {}};

	Calculator.Views.ChainringView = Backbone.View.extend({

		initialize: function(){
			this.render();
		},

		render: function () {
			//Get the max and min values and populate the template with all the numbers in between.
			var max = Calculator.Values.chainring.attributes.maxTeeth;
			var min = Calculator.Values.chainring.attributes.minTeeth;
			var html = "";
			for(var i = min; i <= max; i ++){
				html += _.template($('#chainring-temp').html(), {value : i});
			}
			this.$el.html(html);

			$('#chainring').children().each(function(index, object){
				var element = $(object);
				if(element.html() == 46){
					element.attr("selected", "selected");
				}
			});
			return this;
		}

	});

	Calculator.Views.CogView = Backbone.View.extend({

		initialize: function(){
			this.render();
		},

		render: function () {
			//Get the max and min values and populate the template with all the numbers in between.
			var max = Calculator.Values.cog.attributes.maxTeeth;
			var min = Calculator.Values.cog.attributes.minTeeth;
			var html = "";
			for(var i = min; i <= max; i ++){
				html += _.template($('#cog-temp').html(), {value : i});
			}
			this.$el.html(html);
			$('#cog').children().each(function(index, object){
				var element = $(object);
				if(element.html() == 16){
					element.attr("selected", "selected");
				}
			});
			return this;
		}

	});

	Calculator.Views.WheelView = Backbone.View.extend({

		initialize: function(){
			this.render();
		},

		render: function () {
			//Go through th different wheel sizes and render them to the template.
			var sizes = [];
			_.map(Calculator.Values.wheels.models, function(obj){ sizes.push(obj.attributes);});
			var html = "";
			_.each(sizes, function(obj){ html += _.template($('#wheel-temp').html(), {name: obj.name, value: obj.value}); });
			this.$el.html(html);
			$('#wheel').children().each(function(index, object){
				var element = $(object);
				if(element.html() == "27 inch (nominal)"){
					element.attr("selected", "selected");
				}
			});
			return this;
		}

	});

	Calculator.Views.CrankView = Backbone.View.extend({

		initialize: function(){
			this.render();
		},

		render: function () {
			//Go through list of crank lengths and render them to the template.
			var lengths = [];
			_.map(Calculator.Values.cranks.attributes, function(obj){ lengths.push(obj);});
			var html = "";
			_.each(lengths, function(obj){ html += _.template($('#crank-temp').html(), {value: obj}); });
			this.$el.html(html);
			$("[value='165']").attr("selected", "selected");
			return this;
		}

	});

	Calculator.Views.FormView = Backbone.View.extend({

		events: {
			"submit": "save"
		},

		save: function() {
			//Save the information from the form to the profile model.
			var arr = this.$el.serializeArray();
			var length = arr;
			var data = _(arr).reduce(function(acc, field) {
				acc[field.name] = field.value;
				return acc;
			}, {});
			Calculator.Values.profile.set(data);
			return false;
		}

	});

	Calculator.Views.Numbers = Backbone.View.extend({
		initialize: function(){
			this.render();
		},

		render: function () {
			//Populate the numbers field.
			var chainring = Calculator.Values.profile.attributes.chainring;
			var cog = Calculator.Values.profile.attributes.cog;
			var wheel = Calculator.Values.profile.attributes.wheel;
			var crank = Calculator.Values.profile.attributes.crank;
			var skid = Calculator.Values.profile.attributes.skid;

			var inches = Calculator.Values.calcGearInches(wheel, chainring, cog);
			var dev = Calculator.Values.calcMetresOfDevelopment(inches);
			var gain = Calculator.Values.calcGainRatio(wheel, crank, chainring,cog);
			var patches = Calculator.Values.calcSkidPatches(chainring,cog, skid);

			this.$el.html(_.template($('#numbers-temp').html(), {gearInches: inches, development: dev, gainRatio: gain, skidPatches : patches }));

			return this;
		}
	});

	Calculator.Views.Cadence = Backbone.View.extend({
		initialize: function(){
			this.render();
		},

		render: function () {
			//Calculate the table of cadences
			var chainring = Calculator.Values.profile.attributes.chainring;
			var cog = Calculator.Values.profile.attributes.cog;
			var wheel = Calculator.Values.profile.attributes.wheel;

			var inches = Calculator.Values.calcGearInches(wheel, chainring, cog);
			var dev = Calculator.Values.calcMetresOfDevelopment(inches);

			var cadences = [];

			var min = 1;
			var max = 15;

			for(var i = 0; i <= max; i ++){
				var km = Calculator.Values.calcCadenceKM(dev, i*10);
				var miles = (Calculator.Values.convertKMToMiles(km)).toFixed(1);
				cadences[i] = {cadence: i*10, km: km, miles: miles  };
			}

			var html = "";
			_.each(cadences, function(obj){ html += _.template($('#cadence-temp').html(), obj); });
			this.$el.html(html);

			return this;
		}
	});

	Calculator.Views.Gearing = Backbone.View.extend({
		initialize: function(){
			this.render();
		},

		render: function () {
			//Calculate the equivalent cadences within 1 gear inch.
			var originalChainring = Calculator.Values.profile.attributes.chainring;
			var originalCog = Calculator.Values.profile.attributes.cog;
			var wheel = Calculator.Values.profile.attributes.wheel;

			var originalGearInches = Calculator.Values.calcGearInches(wheel, originalChainring, originalCog);
			var chainringMin = Calculator.Values.chainring.attributes.minTeeth;
			var chainringMax = Calculator.Values.chainring.attributes.maxTeeth;

			var cogMin = Calculator.Values.cog.attributes.minTeeth;
			var cogMax = Calculator.Values.cog.attributes.maxTeeth;
			var ratios = [];
			var originalRatio = originalChainring.toString() + "x" + originalCog.toString();

			for(var i = chainringMin; i <= chainringMax; i ++){
				var newCog = Math.round(wheel*i/originalGearInches);
				if(newCog > cogMin && newCog < cogMax){
					var newRatio = i.toString() + "x" + newCog;
					var newGearInches = Calculator.Values.calcGearInches(wheel,i,newCog);
					var diff  = originalGearInches - newGearInches;

					if(diff > -1 && diff < 1 && newRatio != originalRatio){
						ratios.push(newRatio);
					}

				}
			}

			var html = "";
			_.each(ratios, function(obj){ html += _.template($('#gearing-temp').html(), {gearing : obj}); });
			this.$el.html(html);

			return this;
		}
	});

Calculator.Views.Main = Backbone.View.extend({
	initialize: function(){
		this.listenTo(Calculator.Values.profile, "change", this.updatePage);
		this.render();
	},

	render: function () {
		this.$el.html(_.template($('#placeholder-temp').html(), {}));
		return this;
	},

	updatePage: function () {
			//Render all the sub views in the main view.
			this.$el.html(_.template($('#main-content-temp').html(), {}));
			$(document).foundation('section', 'reflow');

			Calculator.Values.numbers = new Calculator.Views.Numbers({el : $('.number-row')});
			Calculator.Values.cadence = new Calculator.Views.Cadence({ el: $('#cadence-table') });
			Calculator.Values.gearing = new Calculator.Views.Gearing({el : $('.gearing')});

			return this;
		}

	});

}());
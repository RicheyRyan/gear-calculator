Calculator.Models = function (){
	var wheelsList = [{ name: "700x50 (622-50)", value: 0},{name: "700x44 (622-44)", value: 0}, { name: "700x38 (622-38)", value: 0},{name: "700x35 (622-35)", value: 0},
	{name: "700x32 (622-32)",value: 0},{name: "700x28 (622-28)",value: 0},{name: "700x25 (622-25)",value: 0},{name: "700x23 (622-23)",value: 0},{name: "700x20 (622-20)",value: 0},
	{name: "27x1'3/8 (630-35)",value: 0},{name: "27x1'1/4 (630-32)",value: 0},{name: "27x1'1/8 (630-28)",value: 0},{name: "27x1' (630-25)",value: 0},{name: "26x2'1/8 (559-54)",value: 0},
	{name: "26x1.9' (559-47)",value: 0},{name: "26x1'/2 (559-38)",value: 0},{name: "26x1'1/4 (559-32)",value: 0},{name: "26x1' (559-25)",value: 0},{name: "26x1' (571-25)",value: 0},
	{name: "650C (571-25)",value: 0},{name: "Tubular (Wide)",value: 0},{name: "Tubular (Narrow)",value: 0},{name: "26x1 3/8 (590-35)",value: 0},{name: "24 (Most)",value: 0},
	{name: "24x1 (520-25)",value: 0},{name: "20x1'3/4 (406-44)",value: 0},{name: "20x1'1/4 (451-28)",value: 0},{name: "18x1'1/2 (355-40)",value: 0},{name: "17x1'1/4 (369-28)",value: 0},
	{name: "16x1'3/8 (349-35)",value: 0},{name: "16x1'1/2 (305-37)",value: 0}];

	var ChainringTeeth = Backbone.Model.extend({
		defaults:{
			minTeeth: 28,
			maxTeeth: 59
		}
	});

	var CogTeeth = Backbone.Model.extend({
		defaults:{
			minTeeth: 9,
			maxTeeth: 23
		}
	});

	var WheelSize = Backbone.Model.extend({
		defaults:{
			name : "",
			value : ""
		}
	});

	var wheelsCollection = new Backbone.Collection(wheelsList);

	var CrankLength = Backbone.Model.extend({
		defaults: [150, 152, 155, 158, 160, 162.5, 165, 167.5, 170, 172.5, 175, 177.5, 180, 185, 190]
	});

	var chainringTeeth = new ChainringTeeth();
	var cogTeeth = new CogTeeth();
	var crankLength = new CrankLength();

	return{
		chainringTeeth: chainringTeeth,
		cogTeeth: cogTeeth,
		crankLength: crankLength,
		wheelsCollection : wheelsCollection
	};

}();
console.log("Finished Creating Models");


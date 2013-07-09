Calculator = function (){
	var Models;

	var AppRouter = Backbone.Router.extend({
		routes: {
			"" : "home"
		}
	});

	var app = new AppRouter();

	app.on('route:home', function(actions){
		console.log(actions);
	});

	return{
		AppRouter: AppRouter,
		Models : Models
	};

}();
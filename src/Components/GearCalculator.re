let component = ReasonReact.statelessComponent(__MODULE__);

let defaultGear: Gearing.gearDetails = {
  gearInches: 0.0,
  development: 0.0,
  gainRatio: 0.0,
  skidPatches: 0,
  equivalentGears: [],
  cadences: [],
};

let createGearing = (gearing: Gearing.t): Gearing.gearDetails => {
  gearInches: Calculate.gearInches(gearing),
  development: Calculate.metresOfDevelopment(gearing),
  gainRatio: Calculate.gainRatio(gearing),
  skidPatches: Calculate.skidPatches(gearing)->int_of_float,
  equivalentGears: Calculate.equivalentGear(gearing),
  cadences: Calculate.generateCadences(gearing),
};

let make = (~gearing=?, ~render, _children) => {
  ...component,
  render: _self => {
    let details =
      switch (gearing) {
      | Some(g) => createGearing(g)
      | None => defaultGear
      };
    render(details);
  },
};
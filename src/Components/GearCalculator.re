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

[@react.component]
let make = (_gearing, _render, _children) => {
  <p>{React.string("hello")}</p>
};
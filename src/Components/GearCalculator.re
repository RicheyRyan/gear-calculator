type action =
  | GearDetails(Gearing.gearDetails);

let component = ReasonReact.reducerComponent(__MODULE__);

let make = (~gearing, ~render, _children) => {
  ...component,
  initialState: () => (
    {
      gearInches: 0.0,
      development: 0.0,
      gainRatio: 0.0,
      skidPatches: 0,
      equivalentGears: [],
      cadences: [],
    }: Gearing.gearDetails
  ),
  reducer: (action, _state: Gearing.gearDetails) =>
    switch (action) {
    | GearDetails(details) => ReasonReact.Update(details)
    },
  didMount: self => {
    self.send(
      GearDetails({
        gearInches: Calculate.gearInches(gearing),
        development: Calculate.metresOfDevelopment(gearing),
        gainRatio: Calculate.gainRatio(gearing),
        skidPatches: Calculate.skidPatches(gearing)->int_of_float,
        equivalentGears: Calculate.equivalentGear(gearing),
        cadences: Calculate.generateCadences(gearing),
      }),
    );
  },
  render: self => render(self.state),
};
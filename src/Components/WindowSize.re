[@bs.val]
external addEventListener: (string, Js.t({..}) => unit) => unit =
  "window.addEventListener";

[@bs.val] external innerWidth: int = "window.innerWidth";

[@bs.val] external innerHeight: int = "window.innerHeight";

type action =
  | Resize(Window.dimensions);

let component = ReasonReact.reducerComponent(__MODULE__);

let make = (~render, _children) => {
  ...component,
  initialState: () => (
    {width: innerWidth, height: innerHeight}: Window.dimensions
  ),
  reducer: (action, _state) =>
    switch (action) {
    | Resize(size) => ReasonReact.Update(size)
    },
  didMount: self => {
    self.send(Resize({width: innerWidth, height: innerHeight}));
    addEventListener("resize", _event =>
      self.send(Resize({width: innerWidth, height: innerHeight}))
    );
  },
  render: self => render(self.state),
};
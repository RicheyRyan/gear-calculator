[@bs.val]
external addEventListener: (string, Js.t({..}) => unit) => unit =
  "window.addEventListener";

[@bs.val] external innerWidth: int = "window.innerWidth";

[@bs.val] external innerHeight: int = "window.innerHeight";

type action =
  | Resize(Window.dimensions);

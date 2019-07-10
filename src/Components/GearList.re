let headerHeight = 64;

let emptyList = l => List.length(l) === 0;

[@react.component]
let make =
    (
      ~dimensions: Window.dimensions,
      ~gearings: list(Gearing.t),
      ~selectedGear: option(Gearing.t),
      ~onSelectItem,
      _children,
    ) => React.string("gears");
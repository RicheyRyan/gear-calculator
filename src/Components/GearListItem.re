let label = ({chainringTeeth, cogTeeth}: Gearing.t) =>
  {j|$chainringTeeth x $cogTeeth|j}->React.string;

[@react.component]
let make = (~gear: Gearing.t, _onClick, _selected, _children) => {
    <p>{label(gear)}</p>
};

module NoItems = {

  [@react.component]
  let make = _children => {
     <p>{React.string("No gears created yet")}</p>
  }
};
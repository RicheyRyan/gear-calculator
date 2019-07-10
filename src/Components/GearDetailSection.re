type state = {value: int};

type actions =
  | SelectTab(int);


let make = (_gearing: Gearing.t, ~details: Gearing.gearDetails, _children) => 
  <div>
  {
    details.gearInches
    ->Js.Float.toFixedWithPrecision(~digits=1)->React.string
  }
  {
    details.development
    ->Js.Float.toFixedWithPrecision(~digits=1)->React.string
  }
  {
    details.gainRatio
    ->Js.Float.toFixedWithPrecision(~digits=1)->React.string
  }
  {details.skidPatches->Js.Int.toString->React.string}
  </div>;
[@react.component]
let make = (~children, ~className=?, ~value, ~onChange) => {
  <div
    className={Classnames.make(["control", Classnames.unpack(className)])}>
    <div className="select"> <select value onChange> children </select> </div>
  </div>;
};
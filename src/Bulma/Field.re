[@react.component]
let make = (~children, ~className=?, ~label) => {
  <div className={Classnames.make(["field", Classnames.unpack(className)])}>
    <label className="label"> {React.string(label)} </label>
    children
  </div>;
};
[@react.component]
let make = (~children, ~className=?, ~label) => {
  <div className={Classnames.make(["field", Classnames.unpack(className)])}>
    <Label> {React.string(label)} </Label>
    children
  </div>;
};
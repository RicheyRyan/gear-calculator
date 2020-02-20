[@react.component]
let make = (~children, ~className=?) => {
  <label
    className={Classnames.make(["label", Classnames.unpack(className)])}>
    children
  </label>;
};
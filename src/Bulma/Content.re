[@react.component]
let make = (~children, ~className=?) => {
  <div
    className={Classnames.make(["content", Classnames.unpack(className)])}>
    children
  </div>;
};
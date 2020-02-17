[@react.component]
let make = (~children, ~className=?) => {
  <p
    className={Classnames.make(["menu-label", Classnames.unpack(className)])}>
    children
  </p>;
};
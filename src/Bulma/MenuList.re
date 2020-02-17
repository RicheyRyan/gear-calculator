[@react.component]
let make = (~children, ~className=?) => {
  <ul
    className={Classnames.make(["menu-list", Classnames.unpack(className)])}>
    children
  </ul>;
};
module Styles = {
  open Css;

  let columns = style([maxWidth(`percent(100.))]);
};

[@react.component]
let make = (~children, ~className=?) => {
  <div
    className={Classnames.make([
      "columns",
      Styles.columns,
      Classnames.unpack(className),
    ])}>
    children
  </div>;
};
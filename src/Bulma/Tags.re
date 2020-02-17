[@react.component]
let make = (~children, ~className=?, ~hasAddons=false) => {
  <div
    className={Classnames.make([
      "tags",
      Classnames.unpack(className),
      Classnames.ifTrue("has-addons", hasAddons),
    ])}>
    children
  </div>;
};
[@react.component]
let make = (~children, ~className=?, ~isMedium=false, ~isLarge=false) => {
  <section
    className={Classnames.make([
      "section",
      Classnames.unpack(className),
      Classnames.ifTrue("is-medium", isMedium),
      Classnames.ifTrue("is-large", isLarge),
    ])}>
    children
  </section>;
};
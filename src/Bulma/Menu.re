[@react.component]
let make = (~children, ~className=?) => {
  <aside className={Classnames.make(["menu", Classnames.unpack(className)])}>
    children
  </aside>;
};
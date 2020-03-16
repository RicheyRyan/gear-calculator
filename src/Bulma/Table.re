[@react.component]
let make = (~children, ~className=?) => {
  <table
    className={Classnames.make(["table", Classnames.unpack(className)])}>
    children
  </table>;
};
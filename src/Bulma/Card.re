[@react.component]
let make = (~children, ~className=?) => {
  <aside className={Classnames.make(["card", Classnames.unpack(className)])}>
    <div className="card-content"> children </div>
  </aside>;
};
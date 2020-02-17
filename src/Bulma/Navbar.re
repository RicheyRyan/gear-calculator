[@react.component]
let make = (~children) => {
  <nav
    className="navbar is-dark" role="navigation" ariaLabel="main navigation">
    <div className="navbar-item"> children </div>
  </nav>;
};
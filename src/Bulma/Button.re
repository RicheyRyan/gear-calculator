[@react.component]
let make =
    (
      ~children=?,
      ~disabled=false,
      ~className=?,
      ~isPrimary=false,
      ~isLink=false,
      ~isInfo=false,
      ~isSuccess=false,
      ~isWarning=false,
      ~isDanger=false,
      ~isOutlined=false,
      ~onClick,
    ) => {
  <button
    className={Classnames.make([
      "button",
      Classnames.unpack(className),
      Classnames.ifTrue(Bulma.Helpers.isPrimary, isPrimary),
      Classnames.ifTrue(Bulma.Helpers.isLink, isLink),
      Classnames.ifTrue(Bulma.Helpers.isInfo, isInfo),
      Classnames.ifTrue(Bulma.Helpers.isSuccess, isSuccess),
      Classnames.ifTrue(Bulma.Helpers.isWarning, isWarning),
      Classnames.ifTrue(Bulma.Helpers.isDanger, isDanger),
      Classnames.ifTrue(Bulma.Helpers.isOutlined, isOutlined),
    ])}
    disabled
    onClick>
    {switch (children) {
     | Some(child) => child
     | None => React.null
     }}
  </button>;
};
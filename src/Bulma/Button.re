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
      ~isDelete=false,
      ~isSmall=false,
      ~isMedium=false,
      ~isLarge=false,
      ~onClick,
    ) => {
  <button
    className={Classnames.make([
      Classnames.ifTrue("button", !isDelete),
      Classnames.unpack(className),
      Classnames.ifTrue(Bulma.Helpers.isPrimary, isPrimary),
      Classnames.ifTrue(Bulma.Helpers.isLink, isLink),
      Classnames.ifTrue(Bulma.Helpers.isInfo, isInfo),
      Classnames.ifTrue(Bulma.Helpers.isSuccess, isSuccess),
      Classnames.ifTrue(Bulma.Helpers.isWarning, isWarning),
      Classnames.ifTrue(Bulma.Helpers.isDanger, isDanger),
      Classnames.ifTrue(Bulma.Helpers.isOutlined, isOutlined),
      Classnames.ifTrue(Bulma.Helpers.isDelete, isDelete),
      Classnames.ifTrue(Bulma.Helpers.isSmall, isSmall),
      Classnames.ifTrue(Bulma.Helpers.isMedium, isMedium),
      Classnames.ifTrue(Bulma.Helpers.isLarge, isLarge),
    ])}
    disabled
    onClick>
    {switch (children) {
     | Some(child) => child
     | None => React.null
     }}
  </button>;
};
[@react.component]
let make =
    (
      ~children=?,
      ~className=?,
      ~isPrimary=false,
      ~isLink=false,
      ~isInfo=false,
      ~isSuccess=false,
      ~isWarning=false,
      ~isDanger=false,
      ~isDelete=false,
      ~isNormal=false,
      ~isMedium=false,
      ~isLarge=false,
    ) => {
  <span
    className={Classnames.make([
      "tag",
      Classnames.unpack(className),
      Classnames.ifTrue(Bulma.Helpers.isPrimary, isPrimary),
      Classnames.ifTrue(Bulma.Helpers.isLink, isLink),
      Classnames.ifTrue(Bulma.Helpers.isInfo, isInfo),
      Classnames.ifTrue(Bulma.Helpers.isSuccess, isSuccess),
      Classnames.ifTrue(Bulma.Helpers.isWarning, isWarning),
      Classnames.ifTrue(Bulma.Helpers.isDanger, isDanger),
      Classnames.ifTrue(Bulma.Helpers.isNormal, isNormal),
      Classnames.ifTrue(Bulma.Helpers.isMedium, isMedium),
      Classnames.ifTrue(Bulma.Helpers.isLarge, isLarge),
      Classnames.ifTrue("is-delete", isDelete),
    ])}>
    {switch (children) {
     | Some(child) => child
     | None => React.null
     }}
  </span>;
};
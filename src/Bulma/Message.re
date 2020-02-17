[@react.component]
let make =
    (
      ~children,
      ~className=?,
      ~isDark=false,
      ~isPrimary=false,
      ~isLink=false,
      ~isInfo=false,
      ~isSuccess=false,
      ~isWarning=false,
      ~isDanger=false,
      ~isSmall=false,
      ~isMedium=false,
      ~isLarge=false,
    ) => {
  <article
    className={Classnames.make([
      "message",
      Classnames.unpack(className),
      Classnames.ifTrue("is-dark", isDark),
      Classnames.ifTrue("is-primary", isPrimary),
      Classnames.ifTrue("is-link", isLink),
      Classnames.ifTrue("is-info", isInfo),
      Classnames.ifTrue("is-success", isSuccess),
      Classnames.ifTrue("is-warning", isWarning),
      Classnames.ifTrue("is-danger", isDanger),
      Classnames.ifTrue("is-small", isSmall),
      Classnames.ifTrue("is-medium", isMedium),
      Classnames.ifTrue("is-large", isLarge),
    ])}>
    <div className="message-body"> children </div>
  </article>;
};
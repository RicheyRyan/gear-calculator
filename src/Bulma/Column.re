[@react.component]
let make =
    (
      ~children,
      ~className=?,
      ~isNarrow=false,
      ~is1=false,
      ~is2=false,
      ~is3=false,
      ~is4=false,
      ~is5=false,
      ~is6=false,
      ~is7=false,
      ~is8=false,
      ~is9=false,
      ~is10=false,
      ~is11=false,
      ~is12=false,
    ) => {
  <div
    className={Classnames.make([
      "column",
      Classnames.unpack(className),
      Classnames.ifTrue("is-narrow", isNarrow),
      Classnames.ifTrue("is-1", is1),
      Classnames.ifTrue("is-2", is2),
      Classnames.ifTrue("is-3", is3),
      Classnames.ifTrue("is-4", is4),
      Classnames.ifTrue("is-5", is5),
      Classnames.ifTrue("is-6", is6),
      Classnames.ifTrue("is-7", is7),
      Classnames.ifTrue("is-8", is8),
      Classnames.ifTrue("is-9", is9),
      Classnames.ifTrue("is-10", is10),
      Classnames.ifTrue("is-11", is11),
      Classnames.ifTrue("is-12", is12),
    ])}>
    children
  </div>;
};
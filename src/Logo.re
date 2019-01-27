let component = ReasonReact.statelessComponent(__MODULE__);

[%mui.withStyles
  "Style"({logo: ReactDOMRe.Style.make(~marginRight="1.5em", ())})
];

let make = _children => {
  ...component,
  render: _self =>
    <Style>
      ...{classes =>
        <MaterialUi_Icons icon=`Settings className={classes.logo} />
      }
    </Style>,
};
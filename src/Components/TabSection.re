let component = ReasonReact.statelessComponent(__MODULE__);

[%mui.withStyles
  "Style"({section: ReactDOMRe.Style.make(~padding="1.5em", ())})
];

let make = children => {
  ...component,
  render: _self =>
    MaterialUi.(
      <Style>
        ...{classes =>
          <Typography
            component=?{Some(`String("div"))}
            className=?{Some(classes.section)}>
            children
          </Typography>
        }
      </Style>
    ),
};
let component = ReasonReact.statelessComponent(__MODULE__);

[%mui.withStyles
  "Style"({
    add:
      ReactDOMRe.Style.make(
        ~position="absolute",
        ~bottom="24px",
        ~right="36px",
        (),
      ),
  })
];

let make = (_children, ~onClick) => {
  ...component,
  render: _self =>
    <Style>
      ...{classes =>
        MaterialUi.(
          <Fab color=`Primary className={classes.add} onClick>
            <MscharleyBsMaterialUiIcons.Add.Filled />
          </Fab>
        )
      }
    </Style>,
};
let component = ReasonReact.statelessComponent(__MODULE__);

[%mui.withStyles
  "Style"({heading: ReactDOMRe.Style.make(~flexGrow="1", ())})
];

let make = (~onAddClick, ~onHelpClick, _children) => {
  ...component,
  render: _self => {
    MaterialUi.(
      <Style>
        ...{classes =>
          <AppBar position=`Relative>
            <Toolbar>
              <Logo />
              <Typography
                variant=`Title color=`Inherit className={classes.heading}>
                {ReasonReact.string("Gear Calculator")}
              </Typography>
              <IconButton color=`Inherit onClick=onHelpClick>
                <MaterialUi_Icons icon=`Help />
              </IconButton>
              <IconButton color=`Inherit onClick=onAddClick>
                <MaterialUi_Icons icon=`Add />
              </IconButton>
            </Toolbar>
          </AppBar>
        }
      </Style>
    );
  },
};
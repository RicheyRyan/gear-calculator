let component = ReasonReact.statelessComponent(__MODULE__);

[%mui.withStyles
  "Style"({heading: ReactDOMRe.Style.make(~flexGrow="1", ())})
];

let make = (~onHelpClick, _children) => {
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
                <MscharleyBsMaterialUiIcons.Help.Filled />
              </IconButton>
            </Toolbar>
          </AppBar>
        }
      </Style>
    );
  },
};

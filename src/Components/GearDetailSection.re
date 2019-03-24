type state = {value: int};

type actions =
  | SelectTab(int);

let component = ReasonReact.reducerComponent(__MODULE__);

[%mui.withStyles
  "Style"({
    container:
      ReactDOMRe.Style.make(
        ~padding="2.4em",
        ~maxWidth="100%",
        ~textAlign="center",
        (),
      ),
    row: ReactDOMRe.Style.make(~paddingBottom="2em", ()),
    tabSection: ReactDOMRe.Style.make(~backgroundColor="#ffffff", ()),
  })
];

let make = (~gearing: Gearing.t, ~details: Gearing.gearDetails, _children) => {
  ...component,
  initialState: () => {value: 0},
  reducer: (action, _state) => {
    switch (action) {
    | SelectTab(value) => ReasonReact.Update({value: value})
    };
  },
  render: self =>
    MaterialUi.(
      <Style>
        ...{classes =>
          <div className={classes.container}>
            <Grid container=true spacing=V24 className={classes.row}>
              <Grid item=true xs=V12 md=V3>
                <ValueCard
                  value={
                    details.gearInches
                    ->Js.Float.toFixedWithPrecision(~digits=1)
                  }
                  label="Gear Inches"
                />
              </Grid>
              <Grid item=true xs=V12 md=V3>
                <ValueCard
                  value={
                    details.development
                    ->Js.Float.toFixedWithPrecision(~digits=1)
                  }
                  label="Development"
                />
              </Grid>
              <Grid item=true xs=V12 md=V3>
                <ValueCard
                  value={
                    details.gainRatio
                    ->Js.Float.toFixedWithPrecision(~digits=1)
                  }
                  label="Gain Ratio"
                />
              </Grid>
              <Grid item=true xs=V12 md=V3>
                <ValueCard
                  value={details.skidPatches->Js.Int.toString}
                  label="Skid Patches"
                />
              </Grid>
            </Grid>
            <Grid
              container=true
              spacing=V24
              className={Cn.make([classes.row, classes.tabSection])}>
              <AppBar position=`Static color=`Default>
                <Tabs
                  value={self.state.value}
                  onChange={(_event, value) => self.send(SelectTab(value))}
                  indicatorColor=`Primary
                  textColor=`Primary
                  variant=`Standard>
                  <Tab label={ReasonReact.string("Cadence Chart")} />
                  <Tab label={ReasonReact.string("Equivalent Gearing")} />
                </Tabs>
              </AppBar>
              {switch (self.state.value) {
               | 0 =>
                 <TabSection> {ReasonReact.string("Item One")} </TabSection>
               | 1 =>
                 <TabSection> {ReasonReact.string("Item Two ")} </TabSection>
               | _ => <div />
               }}
            </Grid>
          </div>
        }
      </Style>
    ),
};
let component = ReasonReact.statelessComponent(__MODULE__);

[%mui.withStyles
  "Style"({field: ReactDOMRe.Style.make(~marginBottom="1.5em", ())})
];

let make = (_children, ~visible, ~handleClose) => {
  ...component,
  render: _self =>
    <Style>
      ...{classes =>
        MaterialUi.(
          <>
            <Dialog open_=visible>
              <DialogTitle>
                {ReasonReact.string("Enter your details")}
              </DialogTitle>
              <DialogContent>
                <DialogContentText>
                  <p>
                    {ReasonReact.string(
                       "Enter your component details below to calculate your gearing.",
                     )}
                  </p>
                </DialogContentText>
                <InputLabel> {ReasonReact.string("Chainring")} </InputLabel>
                <Select
                  value={`Int(46)} fullWidth=true className={classes.field}>
                  {Belt.List.map(GearingValues.chainringTeeth, teeth =>
                     <MenuItem value={`Int(teeth)}>
                       <em>
                         {teeth |> string_of_int |> ReasonReact.string}
                       </em>
                     </MenuItem>
                   )}
                </Select>
                <InputLabel> {ReasonReact.string("Cog")} </InputLabel>
                <Select
                  value={`Int(16)} fullWidth=true className={classes.field}>
                  {Belt.List.map(GearingValues.cogTeeth, teeth =>
                     <MenuItem value={`Int(teeth)}>
                       <em>
                         {teeth |> string_of_int |> ReasonReact.string}
                       </em>
                     </MenuItem>
                   )}
                </Select>
                <InputLabel> {ReasonReact.string("Wheel Size")} </InputLabel>
                <Select
                  value={`Float(27.0)}
                  fullWidth=true
                  className={classes.field}>
                  {Belt.List.map(GearingValues.wheelSizes, ({value, name}) =>
                     <MenuItem value={`Float(value)}>
                       <em> {name |> ReasonReact.string} </em>
                     </MenuItem>
                   )}
                </Select>
                <InputLabel>
                  {ReasonReact.string("Crank Length")}
                </InputLabel>
                <Select
                  value={`Float(165.0)}
                  fullWidth=true
                  className={classes.field}>
                  {Belt.List.map(GearingValues.crankLengths, length =>
                     <MenuItem value={`Float(length)}>
                       <em>
                         {length |> string_of_float |> ReasonReact.string}
                       </em>
                     </MenuItem>
                   )}
                </Select>
                <InputLabel>
                  {ReasonReact.string("Ambidextrous Skidder")}
                </InputLabel>
                <Switch checked={`Bool(true)} color=`Primary />
              </DialogContent>
              <DialogActions>
                <Button onClick=handleClose color=`Primary>
                  {ReasonReact.string("Ok")}
                </Button>
              </DialogActions>
            </Dialog>
          </>
        )
      }
    </Style>,
};
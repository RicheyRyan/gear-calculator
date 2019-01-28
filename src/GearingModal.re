let component = ReasonReact.statelessComponent(__MODULE__);

[%mui.withStyles
  "Style"({field: ReactDOMRe.Style.make(~marginBottom="1.5em", ())})
];

let formatFloat = str => {
  let len = String.length(str);
  str.[len - 1]
  |> (
    lastChar =>
      if (lastChar === '.') {
        String.sub(str, 0, len - 1);
      } else {
        str;
      }
  );
};

let make = (_children, ~visible, ~handleClose) => {
  ...component,
  render: _self =>
    <Style>
      ...{classes =>
        MaterialUi.(
          <>
            <Dialog
              open_=visible
              onEscapeKeyDown={_event => handleClose()}
              onBackdropClick={_event => handleClose()}>
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
                  value={`String("27-nom")}
                  fullWidth=true
                  className={classes.field}>
                  {Belt.List.map(GearingValues.wheelSizes, ({name, key}) =>
                     <MenuItem value={`String(key)}>
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
                         {length
                          |> string_of_float
                          |> formatFloat
                          |> ReasonReact.string}
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
                <Button onClick={_event => handleClose()} color=`Primary>
                  {ReasonReact.string("Ok")}
                </Button>
              </DialogActions>
            </Dialog>
          </>
        )
      }
    </Style>,
};
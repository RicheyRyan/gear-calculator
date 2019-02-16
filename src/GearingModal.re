type state = {
  chainringTeeth: int,
  cogTeeth: int,
  wheelSize: string,
  crankLength: float,
  ambidextrousSkidder: bool,
};

type actions =
  | UpdateChainringTeeth(int)
  | UpdateCogTeeth(int)
  | UpdateWheelSize(string)
  | UpdateCrankLength(float)
  | UpdateAmbidextrousSkidder(bool)
  | SubmitGearing;

let component = ReasonReact.reducerComponent(__MODULE__);

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

[%mui.withStyles
  "Style"({field: ReactDOMRe.Style.make(~marginBottom="1.5em", ())})
];

let make = (_children, ~visible, ~handleClose) => {
  ...component,
  initialState: () => {
    chainringTeeth: 46,
    cogTeeth: 16,
    wheelSize: "27-nom",
    crankLength: 165.,
    ambidextrousSkidder: false,
  },
  reducer: (action, state: state) =>
    switch (action) {
    | SubmitGearing =>
      ReasonReact.SideEffects(
        _self => {
          Js.log("hello");
          handleClose();
        },
      )
    | UpdateChainringTeeth(chainringTeeth) =>
      ReasonReact.Update({...state, chainringTeeth})
    | UpdateCogTeeth(cogTeeth) => ReasonReact.Update({...state, cogTeeth})
    | UpdateWheelSize(wheelSize) => ReasonReact.Update({...state, wheelSize})
    | UpdateCrankLength(crankLength) =>
      ReasonReact.Update({...state, crankLength})
    | UpdateAmbidextrousSkidder(ambidextrousSkidder) =>
      ReasonReact.Update({...state, ambidextrousSkidder})
    },
  render: self =>
    <Style>
      ...{classes =>
        MaterialUi.(
          <>
            <Dialog
              open_=visible
              onEscapeKeyDown={_event => handleClose()}
              onBackdropClick={_event => handleClose()}>
              <form>
                <DialogTitle>
                  {ReasonReact.string("Enter your details")}
                </DialogTitle>
                <DialogContent>
                  <DialogContentText paragraph=true>
                    {ReasonReact.string(
                       "Enter your component details below to calculate your gearing.",
                     )}
                  </DialogContentText>
                  <InputLabel> {ReasonReact.string("Chainring")} </InputLabel>
                  <Select
                    value={`Int(self.state.chainringTeeth)}
                    fullWidth=true
                    className={classes.field}
                    onChange={(e, _js) =>
                      self.send(
                        UpdateChainringTeeth(
                          e->ReactEvent.Form.target##value,
                        ),
                      )
                    }>
                    {Belt.List.map(GearingValues.chainringTeeth, teeth =>
                       <MenuItem
                         value={`Int(teeth)} key={teeth->string_of_int}>
                         <em>
                           {teeth |> string_of_int |> ReasonReact.string}
                         </em>
                       </MenuItem>
                     )}
                  </Select>
                  <InputLabel> {ReasonReact.string("Cog")} </InputLabel>
                  <Select
                    value={`Int(self.state.cogTeeth)}
                    fullWidth=true
                    className={classes.field}
                    onChange={(e, _js) =>
                      self.send(
                        UpdateCogTeeth(e->ReactEvent.Form.target##value),
                      )
                    }>
                    {Belt.List.map(GearingValues.cogTeeth, teeth =>
                       <MenuItem
                         value={`Int(teeth)} key={teeth->string_of_int}>
                         <em>
                           {teeth |> string_of_int |> ReasonReact.string}
                         </em>
                       </MenuItem>
                     )}
                  </Select>
                  <InputLabel>
                    {ReasonReact.string("Wheel Size")}
                  </InputLabel>
                  <Select
                    value={`String(self.state.wheelSize)}
                    fullWidth=true
                    className={classes.field}
                    onChange={(e, _js) =>
                      self.send(
                        UpdateWheelSize(e->ReactEvent.Form.target##value),
                      )
                    }>
                    {Belt.List.map(GearingValues.wheelSizes, ({name, key}) =>
                       <MenuItem value={`String(key)} key>
                         <em> {name |> ReasonReact.string} </em>
                       </MenuItem>
                     )}
                  </Select>
                  <InputLabel>
                    {ReasonReact.string("Crank Length")}
                  </InputLabel>
                  <Select
                    value={`Float(self.state.crankLength)}
                    fullWidth=true
                    className={classes.field}
                    onChange={(e, _js) =>
                      self.send(
                        UpdateCrankLength(e->ReactEvent.Form.target##value),
                      )
                    }>
                    {Belt.List.map(GearingValues.crankLengths, length =>
                       <MenuItem
                         value={`Float(length)} key={length->string_of_float}>
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
                  <Switch
                    checked={`Bool(self.state.ambidextrousSkidder)}
                    color=`Primary
                    onChange={(_e, checked) =>
                      self.send(UpdateAmbidextrousSkidder(checked))
                    }
                  />
                </DialogContent>
                <DialogActions>
                  <Button onClick={_e => handleClose()} color=`Primary>
                    {ReasonReact.string("Cancel")}
                  </Button>
                  <Button
                    onClick={_e => self.send(SubmitGearing)} color=`Primary>
                    {ReasonReact.string("Ok")}
                  </Button>
                </DialogActions>
              </form>
            </Dialog>
          </>
        )
      }
    </Style>,
};
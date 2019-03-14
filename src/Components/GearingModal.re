type state = {gearing: Gearing.t};

type actions =
  | UpdateChainringTeeth(float)
  | UpdateCogTeeth(float)
  | UpdateWheelSize(float)
  | UpdateCrankLength(float)
  | UpdateAmbidextrousSkidder(bool)
  | CloseModal
  | SubmitGearing;

let component = ReasonReact.reducerComponent(__MODULE__);

[%mui.withStyles
  "Style"({field: ReactDOMRe.Style.make(~marginBottom="1.5em", ())})
];

let defaultState = {
  gearing: {
    createdAt: Js.Date.make(),
    chainringTeeth: 46.,
    cogTeeth: 16.,
    wheelSize: 27.,
    crankLength: 165.,
    ambidextrousSkidder: false,
  },
};

let make = (_children, ~visible, ~handleClose, ~addGearing) => {
  ...component,
  initialState: () => defaultState,
  reducer: (action, state) =>
    switch (action) {
    | SubmitGearing =>
      ReasonReact.UpdateWithSideEffects(
        defaultState,
        _self => {
          addGearing(state.gearing);
          handleClose();
        },
      )
    | CloseModal =>
      ReasonReact.UpdateWithSideEffects(defaultState, _self => handleClose())
    | UpdateChainringTeeth(chainringTeeth) =>
      ReasonReact.Update({
        gearing: {
          ...state.gearing,
          chainringTeeth,
        },
      })
    | UpdateCogTeeth(cogTeeth) =>
      ReasonReact.Update({
        gearing: {
          ...state.gearing,
          cogTeeth,
        },
      })
    | UpdateWheelSize(wheelSize) =>
      ReasonReact.Update({
        gearing: {
          ...state.gearing,
          wheelSize,
        },
      })
    | UpdateCrankLength(crankLength) =>
      ReasonReact.Update({
        gearing: {
          ...state.gearing,
          crankLength,
        },
      })
    | UpdateAmbidextrousSkidder(ambidextrousSkidder) =>
      ReasonReact.Update({
        gearing: {
          ...state.gearing,
          ambidextrousSkidder,
        },
      })
    },
  render: self =>
    <Style>
      ...{classes =>
        MaterialUi.(
          <>
            <Dialog
              open_=visible
              onEscapeKeyDown={_e => self.send(CloseModal)}
              onBackdropClick={_e => self.send(CloseModal)}>
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
                    value={`Float(self.state.gearing.chainringTeeth)}
                    fullWidth=true
                    className={classes.field}
                    onChange={(e, _child) =>
                      self.send(
                        UpdateChainringTeeth(
                          e->ReactEvent.Form.target##value,
                        ),
                      )
                    }>
                    {Belt.List.map(GearingValues.chainringTeeth, teeth =>
                       <MenuItem
                         value={`Float(teeth)} key={teeth->string_of_float}>
                         <em>
                           {teeth |> string_of_float |> ReasonReact.string}
                         </em>
                       </MenuItem>
                     )}
                  </Select>
                  <InputLabel> {ReasonReact.string("Cog")} </InputLabel>
                  <Select
                    value={`Float(self.state.gearing.cogTeeth)}
                    fullWidth=true
                    className={classes.field}
                    onChange={(e, _child) =>
                      self.send(
                        UpdateCogTeeth(e->ReactEvent.Form.target##value),
                      )
                    }>
                    {Belt.List.map(GearingValues.cogTeeth, teeth =>
                       <MenuItem
                         value={`Float(teeth)} key={teeth->string_of_float}>
                         <em>
                           {teeth |> string_of_float |> ReasonReact.string}
                         </em>
                       </MenuItem>
                     )}
                  </Select>
                  <InputLabel>
                    {ReasonReact.string("Wheel Size")}
                  </InputLabel>
                  <Select
                    value={`Float(self.state.gearing.wheelSize)}
                    fullWidth=true
                    className={classes.field}
                    onChange={(e, _child) =>
                      self.send(
                        UpdateWheelSize(e->ReactEvent.Form.target##value),
                      )
                    }>
                    {Belt.List.map(
                       GearingValues.wheelSizes, ({name, key, value}) =>
                       <MenuItem value={`Float(value)} key>
                         <em> {name |> ReasonReact.string} </em>
                       </MenuItem>
                     )}
                  </Select>
                  <InputLabel>
                    {ReasonReact.string("Crank Length")}
                  </InputLabel>
                  <Select
                    value={`Float(self.state.gearing.crankLength)}
                    fullWidth=true
                    className={classes.field}
                    onChange={(e, _child) =>
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
                            |> Util.formatFloat
                            |> ReasonReact.string}
                         </em>
                       </MenuItem>
                     )}
                  </Select>
                  <InputLabel>
                    {ReasonReact.string("Ambidextrous Skidder")}
                  </InputLabel>
                  <Switch
                    checked={`Bool(self.state.gearing.ambidextrousSkidder)}
                    color=`Primary
                    onChange={(_e, checked) =>
                      self.send(UpdateAmbidextrousSkidder(checked))
                    }
                  />
                </DialogContent>
                <DialogActions>
                  <Button
                    onClick={_e => self.send(CloseModal)} color=`Primary>
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
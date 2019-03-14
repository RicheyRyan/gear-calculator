type modal =
  | Gearing
  | Help
  | None;

type state = {
  modal,
  gearings: list(Gearing.t),
  selectedGear: option(Gearing.t),
};

type action =
  | AddGearing(Gearing.t)
  | ModalOpen(modal)
  | ModalClose;

let component = ReasonReact.reducerComponent(__MODULE__);

let make = _children => {
  ...component,
  initialState: () => {modal: None, gearings: [], selectedGear: None},
  reducer: (action, state: state) =>
    switch (action) {
    | AddGearing(gearing) =>
      ReasonReact.Update({...state, gearings: state.gearings @ [gearing]})
    | ModalOpen(modal) => ReasonReact.Update({...state, modal})
    | ModalClose => ReasonReact.Update({...state, modal: None})
    },
  render: self =>
    <>
      <Header onHelpClick={_event => self.send(ModalOpen(Help))} />
      <HelpModal
        visible={self.state.modal === Help}
        handleClose={_event => self.send(ModalClose)}
      />
      <GearingModal
        visible={self.state.modal === Gearing}
        handleClose={_event => self.send(ModalClose)}
        addGearing={gearing => self.send(AddGearing(gearing))}
      />
      <WindowSize
        render={dimensions =>
          MaterialUi.(
            <Grid container=true spacing=V0>
              <Grid item=true xs=V12 md=V3>
                <GearList gearings={self.state.gearings} dimensions />
              </Grid>
              <GearCalculator
                gearing={
                  chainringTeeth: 46.,
                  cogTeeth: 16.,
                  ambidextrousSkidder: false,
                  createdAt: Js.Date.make(),
                  wheelSize: 27.,
                  crankLength: 165.,
                }
                render={d => {
                  Js.log(d);
                  ReasonReact.null;
                }}
              />
              <Grid item=true xs=V9> {ReasonReact.string("hello")} </Grid>
            </Grid>
          )
        }
      />
      <AddNewButton onClick={_event => self.send(ModalOpen(Gearing))} />
    </>,
};
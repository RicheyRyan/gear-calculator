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
  | SelectItem(Gearing.t)
  | ModalClose;

let component = ReasonReact.reducerComponent(__MODULE__);

let make = _children => {
  ...component,
  initialState: () => {modal: None, gearings: [], selectedGear: None},
  reducer: (action, state: state) =>
    switch (action) {
    | AddGearing(gearing) =>
      ReasonReact.Update({
        ...state,
        gearings: state.gearings @ [gearing],
        selectedGear:
          List.length(state.gearings) < 1 ?
            Some(gearing) : state.selectedGear,
      })
    | ModalOpen(modal) => ReasonReact.Update({...state, modal})
    | ModalClose => ReasonReact.Update({...state, modal: None})
    | SelectItem(gearing) =>
      ReasonReact.Update({...state, selectedGear: Some(gearing)})
    },
  render: self =>
    <WindowSize
      render={dimensions => {
        let isMobile = dimensions.width < 768;
        <>
          <Header onHelpClick={_event => self.send(ModalOpen(Help))} />
          <HelpModal
            visible={self.state.modal === Help}
            fullScreen=isMobile
            handleClose={_event => self.send(ModalClose)}
          />
          <GearingModal
            visible={self.state.modal === Gearing}
            fullScreen=isMobile
            handleClose={_event => self.send(ModalClose)}
            addGearing={gearing => self.send(AddGearing(gearing))}
          />
          MaterialUi.(
            <Grid container=true spacing=V0>
              <Grid item=true xs=V12 md=V3>
                <GearList
                  gearings={self.state.gearings}
                  selectedGear={self.state.selectedGear}
                  onSelectItem={gearing => self.send(SelectItem(gearing))}
                  dimensions
                />
              </Grid>
              <GearCalculator
                gearing=?{self.state.selectedGear}
                render={details =>
                  <Grid item=true xs=V9>
                    {switch (self.state.selectedGear) {
                     | Some(gearing) =>
                       <>
                         {ReasonReact.string(
                            gearing.wheelSize->string_of_float,
                          )}
                         {ReasonReact.string(
                            details.gearInches->string_of_float,
                          )}
                       </>
                     | None =>
                       ReasonReact.string("Create a gear to get started")
                     }}
                  </Grid>
                }
              />
            </Grid>
          )
          <AddNewButton onClick={_event => self.send(ModalOpen(Gearing))} />
        </>;
      }}
    />,
};
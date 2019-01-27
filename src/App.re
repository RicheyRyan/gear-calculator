type modal =
  | Gearing
  | Help
  | None;

type state = {modal};

type action =
  | ModalOpen(modal)
  | ModalClose;

let component = ReasonReact.reducerComponent(__MODULE__);

let make = _children => {
  ...component,
  initialState: () => {modal: None},
  reducer: (action, state: state) =>
    switch (action) {
    | ModalOpen(modal) => ReasonReact.Update({modal: modal})
    | ModalClose => ReasonReact.Update({modal: None})
    },
  render: self =>
    <>
      <Header
        onAddClick={_event => self.send(ModalOpen(Gearing))}
        onHelpClick={_event => self.send(ModalOpen(Help))}
      />
      <HelpModal
        visible={self.state.modal === Help}
        handleClose={_event => self.send(ModalClose)}
      />
      <GearingModal
        visible={self.state.modal === Gearing}
        handleClose={_event => self.send(ModalClose)}
      />
    </>,
};
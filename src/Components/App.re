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

[@react.component]
let make = () =>  {
  <p>{React.string("hello")}</p>;
}
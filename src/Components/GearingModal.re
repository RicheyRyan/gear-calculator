type state = {gearing: Gearing.t};

type actions =
  | UpdateChainringTeeth(float)
  | UpdateCogTeeth(float)
  | UpdateWheelSize(float)
  | UpdateCrankLength(float)
  | UpdateAmbidextrousSkidder(bool)
  | CloseModal
  | SubmitGearing;

let getDefaultState = () => {
  gearing: {
    createdAt: Js.Date.now()->truncate,
    chainringTeeth: 46.,
    cogTeeth: 16.,
    wheelSize: 27.,
    crankLength: 165.,
    ambidextrousSkidder: false,
  },
};

[@react.component]
let make = (_children, ~visible, ~handleClose, ~addGearing, ~fullScreen) => <p>{React.string("hello")}</p>;

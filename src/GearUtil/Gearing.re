type t = {
  createdAt: Js.Date.t,
  chainringTeeth: int,
  cogTeeth: int,
  wheelSize: string,
  crankLength: float,
  ambidextrousSkidder: bool,
};

type gearTeeth = Belt.List.t(int);

type wheel = {
  name: string,
  value: float,
  key: string,
};

type wheelSizes = list(wheel);

type crankLength = float;

type crankLengths = list(crankLength);
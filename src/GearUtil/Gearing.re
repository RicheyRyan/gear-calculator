type t = {
  createdAt: int,
  chainringTeeth: float,
  cogTeeth: float,
  wheelSize: float,
  crankLength: float,
  ambidextrousSkidder: bool,
};

type gearTeeth = Belt.List.t(float);

type wheel = {
  name: string,
  value: float,
  key: string,
};

type wheelSizes = list(wheel);

type crankLength = float;

type crankLengths = list(crankLength);

type ratio = {
  numerator: float,
  denominator: float,
};

type cadence = {
  rpm: float,
  mph: float,
  kmph: float,
};

type gearDetails = {
  gearInches: float,
  development: float,
  gainRatio: float,
  skidPatches: int,
  equivalentGears: list(ratio),
  cadences: list(cadence),
};
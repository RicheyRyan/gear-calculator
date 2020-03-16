type t = {
  createdAt: int,
  chainringTeeth: float,
  cogTeeth: float,
  wheelSize: float,
  crankLength: float,
  ambidextrousSkidder: bool,
};

let make = () => {
  createdAt: Js.Date.now()->int_of_float,
  chainringTeeth: 46.,
  cogTeeth: 16.,
  wheelSize: 27.,
  crankLength: 165.,
  ambidextrousSkidder: false,
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

let isEvenFloat = x => mod_float(x, 2.0) == 0.0;

let metreToKm = Unit.Distance.convert(Unit.Distance.Metre, Unit.Distance.Km);

let metreToMile =
  Unit.Distance.convert(Unit.Distance.Metre, Unit.Distance.Mile);

let inchToMetre =
  Unit.Distance.convert(Unit.Distance.Inch, Unit.Distance.Metre);

let mmToInch = Unit.Distance.convert(Unit.Distance.Mm, Unit.Distance.Inch);

let minuteToHour = Unit.Time.convert(Unit.Time.Minute, Unit.Time.Hour);

let distancePerMinute = (cadence: float, development: float) =>
  cadence *. development;

let distancePerHour = (cadence: float, development: float) =>
  distancePerMinute(cadence: float, development: float) |> minuteToHour;

let cadenceToSpeedKm = (cadence: float, metresOfDevelopment: float) =>
  metreToKm(metresOfDevelopment) |> distancePerHour(cadence);

let cadenceToSpeedMiles = (cadence: float, metresOfDevelopment: float) =>
  metreToMile(metresOfDevelopment) |> distancePerHour(cadence);

let equivalentGear = ({chainringTeeth, cogTeeth}: t) => {
  let ratio = chainringTeeth /. cogTeeth;
  let range = List.range(~from=1, 100);
  let baseRatio: ratio = {numerator: ratio, denominator: 1.0};
  List.fold(
    range,
    ~initial=[],
    ~f=(gears, i) => {
      let newRatio: ratio = {
        numerator: baseRatio.numerator *. Int.toFloat(i),
        denominator: baseRatio.denominator *. Int.toFloat(i),
      };
      isEvenFloat(newRatio.numerator)
      && newRatio.numerator < 60.
      && newRatio.denominator > 10.
        ? List.append(gears, [newRatio]) : gears;
    },
  );
};

let gearInches = ({wheelSize, chainringTeeth, cogTeeth}: t) =>
  wheelSize *. (chainringTeeth /. cogTeeth);

// Euclidean algorithm
let rec greatestCommonDivisor = (x: float, y: float) =>
  y > 0.0 ? greatestCommonDivisor(y, mod_float(x, y)) : x;

let lowestFraction = (numerator: float, denominator: float) => {
  let gcd = greatestCommonDivisor(numerator, denominator);
  {numerator: numerator /. gcd, denominator: denominator /. gcd};
};

let metresOfDevelopment = gearing =>
  gearInches(gearing) |> inchToMetre |> (gearMetre => gearMetre *. Float.pi);

let skidPatches = ({chainringTeeth, cogTeeth}: t) =>
  lowestFraction(chainringTeeth, cogTeeth)
  |> (gearRatio => gearRatio.denominator);

let ambidextrousSkidPatches = gearing =>
  skidPatches(gearing)
  |> (patches => isEvenFloat(patches) ? patches : patches *. 2.0);

let radiusRatio = (~wheelSize: float, ~crankLength: float) =>
  wheelSize /. 2.0 /. mmToInch(crankLength);

let gainRatio = ({wheelSize, crankLength, chainringTeeth, cogTeeth}: t) =>
  radiusRatio(~wheelSize, ~crankLength)
  |> (ratio => ratio *. chainringTeeth /. cogTeeth);

let generateCadences = (gearing): list(cadence) => {
  let development = metresOfDevelopment(gearing);
  List.range(~from=1, 15)
  ->List.map(~f=i => Int.toFloat(i * 10))
  ->List.map(~f=rpm => {
      let kmph = cadenceToSpeedKm(rpm, development);
      let mph = cadenceToSpeedMiles(rpm, development);
      {rpm, kmph, mph};
    });
};
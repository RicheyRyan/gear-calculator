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

let equivalentGear = ({chainringTeeth, cogTeeth}: Gearing.t) => {
  let ratio = chainringTeeth /. cogTeeth;
  let range = Belt.Array.range(1, 100);
  let baseRatio: Gearing.ratio = {numerator: ratio, denominator: 1.0};
  Belt.Array.reduce(
    range,
    [],
    (gears, i) => {
      let newRatio: Gearing.ratio = {
        numerator: baseRatio.numerator *. float_of_int(i),
        denominator: baseRatio.denominator *. float_of_int(i),
      };
      isEvenFloat(newRatio.numerator)
      && newRatio.numerator < 60.
      && newRatio.denominator > 10. ?
        List.concat([gears, [newRatio]]) : gears;
    },
  );
};

let gearInches = ({wheelSize, chainringTeeth, cogTeeth}: Gearing.t) =>
  wheelSize *. (chainringTeeth /. cogTeeth);

// Euclidean algorithm
let rec greatestCommonDivisor = (x: float, y: float) =>
  y > 0.0 ? greatestCommonDivisor(y, mod_float(x, y)) : x;

let lowestFraction = (numerator: float, denominator: float) =>
  greatestCommonDivisor(numerator, denominator)
  |> (
    (gcd) => (
      {numerator: numerator /. gcd, denominator: denominator /. gcd}: Gearing.ratio
    )
  );

let metresOfDevelopment = gearing =>
  gearInches(gearing)
  |> inchToMetre
  |> (gearMetre => gearMetre *. Js.Math._PI);

let skidPatches = ({chainringTeeth, cogTeeth}: Gearing.t) =>
  lowestFraction(chainringTeeth, cogTeeth)
  |> (gearRatio => gearRatio.denominator);

let ambidextrousSkidPatches = gearing =>
  skidPatches(gearing)
  |> (patches => isEvenFloat(patches) ? patches : patches *. 2.0);

let radiusRatio = (~wheelSize: float, ~crankLength: float) =>
  wheelSize /. 2.0 /. mmToInch(crankLength);

let gainRatio =
    ({wheelSize, crankLength, chainringTeeth, cogTeeth}: Gearing.t) =>
  radiusRatio(~wheelSize, ~crankLength)
  |> (ratio => ratio *. chainringTeeth /. cogTeeth);

let generateCadences = (gearing): list(Gearing.cadence) => {
  let development = metresOfDevelopment(gearing);
  let rpms =
    Belt.Array.range(1, 15)->Belt.Array.map(i => float_of_int(i * 10));
  let cadenceArr =
    Belt.Array.map(
      rpms,
      rpm => {
        let kmph = cadenceToSpeedKm(rpm, development);
        let mph = cadenceToSpeedMiles(rpm, development);
        let cadence: Gearing.cadence = {rpm, kmph, mph};
        cadence;
      },
    );
  Array.to_list(cadenceArr);
};
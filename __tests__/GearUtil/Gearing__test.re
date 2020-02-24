open Jest;

describe("Gearing", () => {
  open Expect;
  describe("greatestCommonDivisor", () => {
    test("Input of 2 and 2 to be 2", () =>
      expect(Gearing.greatestCommonDivisor(2., 2.)) |> toBe(2.)
    );
    test("Input of 15 and 20 to be 5", () =>
      expect(Gearing.greatestCommonDivisor(15., 20.)) |> toBe(5.)
    );
    test("Input of 32 and 24 to be 2", () =>
      expect(Gearing.greatestCommonDivisor(32., 24.)) |> toBe(8.)
    );
  });
  describe("isEvenFloat", () => {
    test("Even input results in true", () =>
      expect(Gearing.isEvenFloat(20.)) |> toBe(true)
    );
    test("Even input results in false", () =>
      expect(Gearing.isEvenFloat(17.)) |> toBe(false)
    );
  });
  describe("distancePerMinute", () => {
    test("Input of 90 and 1.5 results in 135.", () =>
      expect(Gearing.distancePerMinute(90., 1.5)) |> toBe(135.)
    )
  });
  describe("distancePerHour", () => {
    test("Input of 90 and 1.5 results in 8100.", () =>
      expect(Gearing.distancePerHour(90., 1.5)) |> toBe(8100.)
    )
  });
  describe("gearInches", () => {
    test(
      "Input of gearing with chainring 46, cog 16 and wheelsize 27. results in 77.625",
      () =>
      expect(
        Gearing.gearInches({
          createdAt: Js.Date.now()->int_of_float,
          chainringTeeth: 46.,
          cogTeeth: 16.,
          wheelSize: 27.,
          crankLength: 165.,
          ambidextrousSkidder: false,
        }),
      )
      |> toBe(77.625)
    )
  });
  describe("generateCadences", () => {
    test("Input of gearing results the expect array of cadences", () =>
      expect(
        Gearing.generateCadences({
          createdAt: Js.Date.now()->int_of_float,
          chainringTeeth: 46.,
          cogTeeth: 16.,
          wheelSize: 27.,
          crankLength: 165.,
          ambidextrousSkidder: false,
        }),
      )
      |> toMatchSnapshot
    )
  });
});
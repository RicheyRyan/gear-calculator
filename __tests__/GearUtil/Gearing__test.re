open Jest;

describe("Gearing", () => {
  Expect.(
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
    })
  )
});
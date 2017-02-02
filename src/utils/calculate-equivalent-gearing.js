function lowestFraction(num, denom) {
  const greatestCommonDivisor = calculateGreatestCommonDivisor(num, denom);
  const numSimplified = num / greatestCommonDivisor;
  const denomSimplified = denom / greatestCommonDivisor;
  return { num: numSimplified, denom: denomSimplified };
}

export default function ({ gearInches, delta, chainringOptions, cogOptions }) {

}

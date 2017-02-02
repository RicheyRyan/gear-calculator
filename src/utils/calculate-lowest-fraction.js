/**
 * calculateGreatestCommonDivisor - This implements Euclid's algorithm to get the greatest
 * common divisor of two numbers
 *
 * @param  {Number} x - first
 * @param  {Number} y - second
 * @return {Number} the common divisior
 */
function calculateGreatestCommonDivisor(x, y) {
  return y ? calculateGreatestCommonDivisor(y, x % y) : x;
}


/**
 * This simplifies fractions i.e 6/12 => 1/2
 *
 * @param  {type} numerator
 * @param  {type} denominator
 * @return {type} an object containing the new numerator and denominator
 */
export default function lowestFraction(numerator, denominator) {
  const greatestCommonDivisor = calculateGreatestCommonDivisor(numerator, denominator);
  return {
    numerator: numerator / greatestCommonDivisor,
    denominator: denominator / greatestCommonDivisor
  };
}

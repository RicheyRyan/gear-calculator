/**
 * calculateGreatestCommonDivisor - This mplements Euclid's algorithm to get the greatest
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
 * isEven - This checks if a number is even;
 *
 * @param  {Number} x
 * @return {Boolean} - true if the number is even otherwise false
 */
function isEven(x) {
  return x % 2 === 0;
}


/**
 * This calculates the number of skid patches for a rider.
 *
 * The fraction of the chainring teeth over the cog teeth is simplified. Then if
 * the rider has an odd chainring number and is ambidextrous in skidding, they will
 * have double the skid patches.
 *
 * @param  {Number} chainring - the number of teeth on the chainring
 * @param  {Number} cog - the number of teeth on the cog
 * @param  {Boolean} ambidextrousSkidder - Whether the rider is an ambidextrous skidder
 * @return {Number} the number of skid patches
 */
export default function ({ chainring, cog, ambidextrousSkidder }) {
  const greatestCommonDivisor = calculateGreatestCommonDivisor(chainring, cog);
  const chainringSimplified = chainring / greatestCommonDivisor;
  const cogSimplified = cog / greatestCommonDivisor;

  const oddChainring = !isEven(chainringSimplified);

  return oddChainring && ambidextrousSkidder ? cogSimplified * 2 : cogSimplified;
}

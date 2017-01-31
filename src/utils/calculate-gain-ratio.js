import convert from 'convert-units';

/**
 * This calculates the gain ratio for a gear, an abstract ratio that represents
 * the distance it will travel
 *
 * @param  {Number} wheelDiameter - wheel diameter in inches
 * @param  {Number} crankLength - crank length in mm
 * @param  {Number} chainring - the number of teeth on the chainring
 * @param  {Number} cog - the number of teeth on the cog
 * @return {String} gain ratio - the ratio of the gear's development
 */
export default function ({ wheelDiameter, crankLength, chainring, cog }) {
  const crankLengthInches = convert(crankLength).from('mm').to('in');
  const wheelRadius = wheelDiameter / 2;
  const wheelRadiusRatio = wheelRadius / crankLengthInches;
  return (wheelRadiusRatio * (chainring / cog)).toFixed(1);
}

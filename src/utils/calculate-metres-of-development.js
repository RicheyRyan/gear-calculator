import convert from 'convert-units';
import calculateGearInches from './calculate-gear-inches';

/**
 * This calculates the metres of development which is a product of the wheel diameter,
 * chainring teeth and cog teeth and converting the result to metric
 *
 * It first calculates the gear inches, translates it to metric and multiplying by PI
 * accounts for the rotations of the wheel
 *
 * @param  {Number} wheelDiameter - the wheel diameter in inches
 * @param  {Number} chainring - the number of teeth on the chainring
 * @param  {Number} cog - the number of teeth on the cog
 * @return {String} metres of development - metres travelled by single rotation of
 * the cranks
 */
export default function ({ wheelDiameter, chainring, cog }) {
  const gearInches = calculateGearInches({ wheelDiameter, chainring, cog });
  const gearMetres = convert(gearInches).from('in').to('m');
  return (gearMetres * Math.PI).toFixed(1);
}

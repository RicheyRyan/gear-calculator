/**
 * This calculates the gear inches which is a product of the wheel diameter,
 * chainring teeth and cog teeth
 *
 * @param  {Number} wheel - the wheel diameter in inches
 * @param  {Number} chainring - the number of teeth on the chainring
 * @param  {Number} cog - the number of teeth on the cog
 * @return {String} gear inches - the calculated gear inches
 */
export default function ({ wheelDiameter, chainring, cog }) {
  return (wheelDiameter * (chainring / cog)).toFixed(1);
}

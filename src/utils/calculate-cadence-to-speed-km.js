import convert from 'convert-units';
const minutesPerHour = 60;

/**
 * This calculates the speed in KM for a particular cadence and metres of development
 *
 * @param  {Number} cadence - The number of revolutions per minute
 * @param  {Number} metresOfDevelopment - The number of metres travelled per revolution of the crank
 * @return {String} km/hr
 */
export default function ({ cadence, metresOfDevelopment }) {
  const distancePerMinute = cadence * metresOfDevelopment;
  const distrancePerHour = distancePerMinute * minutesPerHour;
  return convert(distrancePerHour).from('m').to('km').toFixed(1);
}

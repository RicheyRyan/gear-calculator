export default function({
  wheel,
  chainring,
  cog
}) {
  //uses wheel diameter in inches
  return (wheel * (chainring / cog)).toFixed(1);
};

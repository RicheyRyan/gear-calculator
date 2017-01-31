import { should } from 'chai';
import calculateGainRatio from './calculate-gain-ratio';

should();

describe('Calculate gain ratio', function () {
  it('should calculate the correct gain ratio', function () {
    const ratio = calculateGainRatio({ wheelDiameter: 27, cog: 20, chainring: 50, crankLength: 170 });
    ratio.should.equal('5.0');
  });
});

import { should } from 'chai';
import calculateGearInches from './calculate-gear-inches';

should();

describe('Calculate gear inches', function () {
  it('should calculate the correct number of gear inches', function () {
    const inches = calculateGearInches({ wheelDiameter: 27, cog: 20, chainring: 50 });
    inches.should.equal('67.5');
  });
});

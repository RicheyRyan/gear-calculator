import { should } from 'chai';
import calculateMetresOfDevelopment from './calculate-metres-of-development';

should();

describe('Calculate metres of development', function () {
  it('should calculate the correct number of metres of development', function () {
    const inches = calculateMetresOfDevelopment({ wheelDiameter: 27, cog: 20, chainring: 50 });
    inches.should.equal('5.4');
  });
});

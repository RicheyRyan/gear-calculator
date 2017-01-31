import { should } from 'chai';
import calculateCadenceToSpeedMiles from './calculate-cadence-to-speed-miles';

should();

describe('Calculate the m/hr for a specific cadence and metres of development', function () {
  it('should calculate the correct the miles per hour', function () {
    const speed = calculateCadenceToSpeedMiles({ cadence: 90, metresOfDevelopment: 5 });
    speed.should.equal('16.8');
  });
});

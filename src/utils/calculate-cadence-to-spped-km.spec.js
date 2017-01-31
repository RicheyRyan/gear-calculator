import { should } from 'chai';
import calculateCadenceToSpeedKm from './calculate-cadence-to-speed-km';

should();

describe('Calculate the km/hr for a specific cadence and metres of development', function () {
  it('should calculate the correct the km per hour', function () {
    const speed = calculateCadenceToSpeedKm({ cadence: 90, metresOfDevelopment: 5 });
    speed.should.equal('27.0');
  });
});

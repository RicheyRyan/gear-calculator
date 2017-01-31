import { should } from 'chai';
import calculateSkidPatches from './calculate-skid-patches';

should();

describe('Calculate skid patches', function () {
  it('should calculate the correct number of patches for an ambidextrous skidder', function () {
    const patches = calculateSkidPatches({ cog: 20, chainring: 50, ambidextrousSkidder: true });
    patches.should.equal(4);
  });

  it('should calculate the correct number of patches for a non ambidextrous skidder', function () {
    const patches = calculateSkidPatches({ cog: 20, chainring: 50, ambidextrousSkidder: false });
    patches.should.equal(2);
  });
});

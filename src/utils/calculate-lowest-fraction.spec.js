import { should } from 'chai';
import calculateLowestFraction from './calculate-lowest-fraction';

should();

describe('Calculate lowest fraction', function () {
  it('should calculate correctly where the numberator is less than the denominator', function () {
    const result = calculateLowestFraction(6, 12);
    result.should.have.property('numerator', 1);
    result.should.have.property('denominator', 2);
  });

  it('should calculate correctly where the numberator is greater than the denominator', function () {
    const result = calculateLowestFraction(16, 18);
    result.should.have.property('numerator', 8);
    result.should.have.property('denominator', 9);
  });
});

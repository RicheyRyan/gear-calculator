// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var List = require("bs-platform/lib/js/list.js");
var $$Array = require("bs-platform/lib/js/array.js");
var Belt_Array = require("bs-platform/lib/js/belt_Array.js");
var Caml_int32 = require("bs-platform/lib/js/caml_int32.js");
var Unit$GearCalculator = require("../Unit.bs.js");

function isEvenFloat(x) {
  return x % 2.0 === 0.0;
}

var partial_arg = Unit$GearCalculator.Distance[/* convert */7];

function metreToKm(param) {
  return partial_arg(/* Metre */3, /* Km */4, param);
}

var partial_arg$1 = Unit$GearCalculator.Distance[/* convert */7];

function metreToMile(param) {
  return partial_arg$1(/* Metre */3, /* Mile */5, param);
}

var partial_arg$2 = Unit$GearCalculator.Distance[/* convert */7];

function inchToMetre(param) {
  return partial_arg$2(/* Inch */2, /* Metre */3, param);
}

var partial_arg$3 = Unit$GearCalculator.Distance[/* convert */7];

function mmToInch(param) {
  return partial_arg$3(/* Mm */0, /* Inch */2, param);
}

var partial_arg$4 = Unit$GearCalculator.Time[/* convert */8];

function minuteToHour(param) {
  return partial_arg$4(/* Minute */4, /* Hour */3, param);
}

function distancePerMinute(cadence, development) {
  return cadence * development;
}

function distancePerHour(cadence, development) {
  return minuteToHour(cadence * development);
}

function cadenceToSpeedKm(cadence, metresOfDevelopment) {
  var development = metreToKm(metresOfDevelopment);
  return minuteToHour(cadence * development);
}

function cadenceToSpeedMiles(cadence, metresOfDevelopment) {
  var development = metreToMile(metresOfDevelopment);
  return minuteToHour(cadence * development);
}

function equivalentGear(param) {
  var ratio = param[/* chainringTeeth */1] / param[/* cogTeeth */2];
  var range = Belt_Array.range(1, 100);
  return Belt_Array.reduce(range, /* [] */0, (function (gears, i) {
                var newRatio_000 = /* numerator *//* numerator */ratio * i;
                var newRatio_001 = /* denominator *//* denominator */1.0 * i;
                var newRatio = /* record */[
                  newRatio_000,
                  newRatio_001
                ];
                var match = isEvenFloat(newRatio_000) && newRatio_000 < 60 && newRatio_001 > 10;
                if (match) {
                  return List.concat(/* :: */[
                              gears,
                              /* :: */[
                                /* :: */[
                                  newRatio,
                                  /* [] */0
                                ],
                                /* [] */0
                              ]
                            ]);
                } else {
                  return gears;
                }
              }));
}

function gearInches(param) {
  return param[/* wheelSize */3] * (param[/* chainringTeeth */1] / param[/* cogTeeth */2]);
}

function greatestCommonDivisor(_x, _y) {
  while(true) {
    var y = _y;
    var x = _x;
    var match = y > 0.0;
    if (match) {
      _y = x % y;
      _x = y;
      continue ;
    } else {
      return x;
    }
  };
}

function lowestFraction(numerator, denominator) {
  var gcd = greatestCommonDivisor(numerator, denominator);
  return /* record */[
          /* numerator */numerator / gcd,
          /* denominator */denominator / gcd
        ];
}

function metresOfDevelopment(gearing) {
  var gearMetre = inchToMetre(gearInches(gearing));
  return gearMetre * Math.PI;
}

function skidPatches(param) {
  return lowestFraction(param[/* chainringTeeth */1], param[/* cogTeeth */2])[/* denominator */1];
}

function ambidextrousSkidPatches(gearing) {
  var patches = skidPatches(gearing);
  var match = isEvenFloat(patches);
  if (match) {
    return patches;
  } else {
    return patches * 2.0;
  }
}

function radiusRatio(wheelSize, crankLength) {
  return wheelSize / 2.0 / mmToInch(crankLength);
}

function gainRatio(param) {
  var ratio = radiusRatio(param[/* wheelSize */3], param[/* crankLength */4]);
  return ratio * param[/* chainringTeeth */1] / param[/* cogTeeth */2];
}

function generateCadences(gearing) {
  var development = metresOfDevelopment(gearing);
  var rpms = Belt_Array.map(Belt_Array.range(1, 15), (function (i) {
          return Caml_int32.imul(i, 10);
        }));
  return $$Array.to_list(Belt_Array.map(rpms, (function (rpm) {
                    var development$1 = metreToKm(development);
                    var kmph = minuteToHour(rpm * development$1);
                    var development$2 = metreToMile(development);
                    var mph = minuteToHour(rpm * development$2);
                    return /* record */[
                            /* rpm */rpm,
                            /* mph */mph,
                            /* kmph */kmph
                          ];
                  })));
}

exports.isEvenFloat = isEvenFloat;
exports.metreToKm = metreToKm;
exports.metreToMile = metreToMile;
exports.inchToMetre = inchToMetre;
exports.mmToInch = mmToInch;
exports.minuteToHour = minuteToHour;
exports.distancePerMinute = distancePerMinute;
exports.distancePerHour = distancePerHour;
exports.cadenceToSpeedKm = cadenceToSpeedKm;
exports.cadenceToSpeedMiles = cadenceToSpeedMiles;
exports.equivalentGear = equivalentGear;
exports.gearInches = gearInches;
exports.greatestCommonDivisor = greatestCommonDivisor;
exports.lowestFraction = lowestFraction;
exports.metresOfDevelopment = metresOfDevelopment;
exports.skidPatches = skidPatches;
exports.ambidextrousSkidPatches = ambidextrousSkidPatches;
exports.radiusRatio = radiusRatio;
exports.gainRatio = gainRatio;
exports.generateCadences = generateCadences;
/* No side effect */
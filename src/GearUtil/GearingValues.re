let chainringTeeth: Gearing.gearTeeth =
  Belt.Array.range(28, 59)
  ->Belt.List.fromArray
  ->Belt.List.map(i => i->float_of_int);

let cogTeeth: Gearing.gearTeeth =
  Belt.Array.range(9, 23)
  ->Belt.List.fromArray
  ->Belt.List.map(i => i->float_of_int);

let wheelSizes: Gearing.wheelSizes = [
  {value: 29., name: "29 inch (nominal)", key: "29-nom"},
  {value: 28., name: "28 inch (nominal)", key: "28-nom"},
  {value: 27., name: "27 inch (nominal)", key: "27-nom"},
  {value: 26., name: "26 inch (nominal)", key: "26-nom"},
  {value: 29.13, name: "700 X 56 / 56-622 / 29 inch", key: "700-56"},
  {value: 28.94, name: "700 X 50 / 50-622 / 29 inch", key: "700-50"},
  {value: 27.86, name: "700 X 44 / 44-622 / 29 inch", key: "700-44"},
  {value: 27.32, name: "700 X 38 / 38-622", key: "700-38"},
  {value: 27.17, name: "700 X 35 / 35-622", key: "700-35"},
  {value: 27., name: "700 X 32 / 32-622 ", key: "700-32"},
  {value: 26.76, name: "700 X 28 / 28-622", key: "700-28"},
  {value: 26.38, name: "700 X 25 / 25-622", key: "700-25"},
  {value: 26.28, name: "700 X 23 / 23-622", key: "700-23"},
  {value: 26.14, name: "700 X 20 / 20-622", key: "700-20"},
  {value: 26.53, name: "Tubular / Wide", key: "tub-wide"},
  {value: 26.38, name: "Tubular / Narrow", key: "tub-narrow"},
  {value: 28.15, name: "28 X 1 1/2 / 40-635 ", key: "40-635"},
  {value: 27.18, name: "27 X 1 3/8 / 35-630", key: "35-630"},
  {value: 27.08, name: "27 X 1 1/4 / 32-630", key: "32-630"},
  {value: 27., name: "27 X 1 1/8 / 28-630", key: "28-630"},
  {value: 26.88, name: "27 X 1 / 25-630", key: "25-630"},
  {value: 26.41, name: "26 X 2.35 / 60-559 / MTB", key: "60-559"},
  {value: 25.94, name: "26 X 2.125 / 54-559 / MTB", key: "54-559"},
  {value: 25.75, name: "26 X 1.9 / 47-559 / MTB", key: "47-559"},
  {value: 24.87, name: "26 X 1.5 / 38-559 / MTB", key: "38-559"},
  {value: 24.47, name: "26 X 1.25 / 32-559 / MTB", key: "32-559"},
  {value: 23.97, name: "26 X 1.0 / 25-559 / MTB", key: "25-559"},
  {value: 26., name: "650 x 38b / 38-584 650B", key: "38-584"},
  {value: 24.7, name: "650 x 28C / 28-571 / 26' road/tri", key: "28-571"},
  {value: 24.46, name: "650 x 25C / 25-571 / 26' road/tri", key: "25-571"},
  {value: 24.31, name: "650 x 23C / 23-571 / 26' road/tri", key: "23-571"},
  {value: 25.91, name: "26 X 1 3/8 / 35-590", key: "35-590"},
  {value: 24., name: "24 inch (nominal)", key: "24-num"},
  {value: 21.97, name: "24 x 1 / 25-520", key: "25-520"},
  {value: 20.15, name: "32-451 /20 x 1 3/8", key: "32-451"},
  {value: 19.9, name: "28-451/20 x 1 1/8", key: "28-451"},
  {value: 18.68, name: "20 X 1.75 / 44-406 / BMX", key: "44-406"},
  {value: 18.43, name: "20 X 1.25 / 32-406", key: "32-406"},
  {value: 17.16, name: "18 x 1.5 / 40-355", key: "40-355"},
  {value: 16.6, name: "17 x 1 1/4 / 28-369", key: "28-369"},
  {value: 16.88, name: "16 x 1 1/2 / 40-349", key: "40-349"},
  {value: 16.07, name: "16 x 1 3/8 / 35-349", key: "35-349"},
  {value: 13.46, name: "16 x 1.5 / 37-305", key: "37-305"},
];

let crankLengths: Gearing.crankLengths = [
  150.,
  152.,
  155.,
  158.,
  160.,
  162.5,
  165.,
  167.5,
  170.,
  172.5,
  175.,
  177.5,
  180.,
  185.,
  190.,
];
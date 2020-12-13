(ns gears.gears
  (:require [gears.units :as u]))

(defonce default-gear {:id nil
                       :chainring-teeth 46
                       :cog-teeth 16
                       :wheel-size 2
                       :crank-length 165
                       :ambidextrous-skidder false})

(defn make
  ([]
   (assoc default-gear :id (.now js/Date)))
  ([gear-values]
   (assoc gear-values :id (.now js/Date))))

(def chainring-teeth (range 28 59))

(def cog-teeth (range 9 23))

(def wheel-sizes
  [{:value 29 :label "29 inch (nominal)"}
   {:value 28 :label "28 inch (nominal)"}
   {:value 27 :label "27 inch (nominal)"}
   {:value 26 :label "26 inch (nominal)"}
   {:value 29.13 :label "700 X 56 / 56-622 / 29 inch"}
   {:value 28.94 :label "700 X 50 / 50-622 / 29 inch"}
   {:value 27.86 :label "700 X 44 / 44-622 / 29 inch"}
   {:value 27.32 :label "700 X 38 / 38-622"}
   {:value 27.17 :label "700 X 35 / 35-622"}
   {:value 27 :label "700 X 32 / 32-622 "}
   {:value 26.76 :label "700 X 28 / 28-622"}
   {:value 26.38 :label "700 X 25 / 25-622"}
   {:value 26.28 :label "700 X 23 / 23-622"}
   {:value 26.14 :label "700 X 20 / 20-622"}
   {:value 26.53 :label "Tubular / Wide"}
   {:value 26.38 :label "Tubular / Narrow"}
   {:value 28.15 :label "28 X 1 1/2 / 40-635 "}
   {:value 27.18 :label "27 X 1 3/8 / 35-630"}
   {:value 27.08 :label "27 X 1 1/4 / 32-630"}
   {:value 27 :label "27 X 1 1/8 / 28-630"}
   {:value 26.88 :label "27 X 1 / 25-630"}
   {:value 26.41 :label "26 X 2.35 / 60-559 / MTB"}
   {:value 25.94 :label "26 X 2.125 / 54-559 / MTB"}
   {:value 25.75 :label "26 X 1.9 / 47-559 / MTB"}
   {:value 24.87 :label "26 X 1.5 / 38-559 / MTB"}
   {:value 24.47 :label "26 X 1.25 / 32-559 / MTB"}
   {:value 23.97 :label "26 X 1.0 / 25-559 / MTB"}
   {:value 26 :label "650 x 38b / 38-584 650B"}
   {:value 24.7 :label "650 x 28C / 28-571 / 26' road/tri"}
   {:value 24.46 :label "650 x 25C / 25-571 / 26' road/tri"}
   {:value 24.31 :label "650 x 23C / 23-571 / 26' road/tri"}
   {:value 25.91 :label "26 X 1 3/8 / 35-590"}
   {:value 24 :label "24 inch (nominal)"}
   {:value 21.97 :label "24 x 1 / 25-520"}
   {:value 20.15 :label "32-451 /20 x 1 3/8"}
   {:value 19.9 :label "28-451/20 x 1 1/8"}
   {:value 18.68 :label "20 X 1.75 / 44-406 / BMX"}
   {:value 18.43 :label "20 X 1.25 / 32-406"}
   {:value 17.16 :label "18 x 1.5 / 40-355"}
   {:value 16.6 :label "17 x 1 1/4 / 28-369"}
   {:value 16.88 :label "16 x 1 1/2 / 40-349"}
   {:value 16.07 :label "16 x 1 3/8 / 35-349"}
   {:value 13.46 :label "16 x 1.5 / 37-305"}])

(def crank-lengths
  [150
   152
   155
   158
   160
   162.5
   165
   167.5
   170
   172.5
   175
   177.5
   180
   185
   190])

(defn gear-inches
  [{:keys [wheel-size chainring-teeth cog-teeth]}]
  (.toFixed
   (* wheel-size (/ chainring-teeth cog-teeth))
   1))

(defn metres-of-development
  [gearing]
  (.toFixed
   (* (u/inch-to-metre (gear-inches gearing))
      Math/PI)
   1))

(defn gain-ratio
  [{:keys [wheel-size
           crank-length
           chainring-teeth
           cog-teeth]}]
  (.toFixed
   (*
    (/
     (/ wheel-size 2.0)
     (u/mm-to-inch crank-length))
    (/ chainring-teeth cog-teeth))
   1))

(defn distance-per-minute
  [cadence development]
  (* cadence development))

(defn distance-per-hour
  [cadence development]
  (u/minute-to-hour
   (distance-per-minute cadence development)))

(defn cadence-to-speed-km
  [cadence, metres-development]
  (distance-per-hour cadence (u/metre-to-km metres-development)))

(defn cadence-to-speed-mile
  [cadence, metres-development]
  (distance-per-hour cadence (u/metre-to-mile metres-development)))

(defn make-cadence
  [cadence metres-development]
  {:rpm cadence
   :kmph
   (.toFixed (cadence-to-speed-km cadence metres-development) 2)
   :mph
   (.toFixed (cadence-to-speed-mile cadence metres-development) 2)})

(defn generate-cadences
  [gearing]
  (let [mod (metres-of-development gearing)]
    (map
     #(make-cadence % mod)
     (map #(* % 10) (range 1 15)))))

(defn filter-gears-in-bounds
  [inches coll]
  (filter
   #(let [new-gear-inches (gear-inches %)
          diff (- inches new-gear-inches)
          bound 0.5]
      (and
       (and
        (> diff (- bound)) (< diff bound))
       (not= gear-inches new-gear-inches)))
   coll))

(defn generate-potential-gears
  [gear-inches wheel]
  (for [chainring chainring-teeth]
    (make {:wheel-size wheel
           :chainring-teeth chainring
           :cog-teeth
           (Math/round
            (/
             (* chainring wheel)
             gear-inches))})))

(defn equivalent-gears [gearing]
  (let [inches (gear-inches gearing)
        wheel (:wheel-size gearing)]
    (filter-gears-in-bounds
     inches
     (generate-potential-gears inches wheel))))
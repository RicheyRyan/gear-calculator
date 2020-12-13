(ns gears.store
  (:require
   [reagent.core :as r]
   [gears.gears :as g]))

(defonce app-state (let [default-gear (g/make)]
                     (r/atom {:gears [default-gear]
                              :selected-gear 0})))

(defn reducer [state {type :type payload :payload}]
  (case type
    :create (update-in state [:gears] conj (g/make))
    :delete (update-in state [:gears] filter #(= payload %1) (:gears state))
    :select (assoc state :selected-gear payload)
    :change (update-in
             state
             [:gears (:selected-gear state)]
             assoc
             (:name payload)
             (:value payload))))

(defn dispatch [action]
  (println "dispatch" action)
  (println "new state" (reducer @app-state action))
  (reset! app-state (reducer @app-state action)))

; Selectors
(defn selected-gear? [i] (= i (:selected-gear @app-state)))
(defn get-selected []
  (let [{gears :gears
         selected-gear :selected-gear}
        @app-state]
    (update
     (get gears selected-gear)
     :wheel-size
     #(get-in g/wheel-sizes [% :value]))))

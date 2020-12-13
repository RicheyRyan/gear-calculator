(ns gears.core
  (:require
   [reagent.dom :as d]
   [reagent-material-ui.core.grid :refer [grid]]
   [reagent-material-ui.core.css-baseline :refer [css-baseline]]
   [reagent-material-ui.core.list :refer [list]]
   [gears.components :as c]
   [gears.store :as s]
   [reagent-material-ui.styles :as styles]))


(def main
  ((styles/with-styles
     (fn []
       {:scrollable {:height "100vh"
                     :overflow "auto"}}))
   (fn [{:keys [classes]}]
     [:<>
      (println "render" @s/app-state)
      [css-baseline]
      [c/topbar]
      [c/add-gear-button
       {:on-click #(s/dispatch {:type :create})}]
      [grid {:container true}
       [grid {:item true}
        [c/menu
         [list
          (doall
           (map-indexed
            (fn [i gear]
              [c/gear-list-item
               {:gear gear
                :key (:id gear)
                :selected (s/selected-gear? i)
                :on-select #(s/dispatch
                             {:type :select
                              :payload i})
                :on-delete #(s/dispatch
                             {:type :select
                              :payload (s/selected-gear? i)})}])
            (:gears @s/app-state)))]]]
       [grid {:item true :xs true :class (:scrollable classes)}
        [c/container
         [:<>
          [c/gear-form
           {:gear
            (get (:gears @s/app-state)
                 (:selected-gear @s/app-state))
            :on-change #(s/dispatch {:type :change
                                     :payload %})}]
          [c/separator]
          [c/gear-info (s/get-selected)]
          [c/separator]
          [grid {:container true :spacing 8}
           [grid {:item true :xs 12 :md 6}
            [c/cadence-table (s/get-selected)]]
           [grid {:item true :xs 12 :md 6}
            [c/equivalent-gears-list {:gearing (s/get-selected)}]]]]]]]])))

(defn mount-root []
  (d/render [main] (.getElementById js/document "app")))

(defn ^:export init! []
  (mount-root))

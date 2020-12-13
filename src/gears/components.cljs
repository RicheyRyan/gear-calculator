(ns gears.components
  (:require
   [gears.gears :as g]
   [class-names.core :refer [class-names]]
   [reagent-material-ui.core.grid :refer [grid]]
   [reagent-material-ui.core.chip  :refer [chip]]
   [reagent-material-ui.core.app-bar :refer [app-bar]]
   [reagent-material-ui.core.drawer :refer [drawer]]
   [reagent-material-ui.core.divider :refer [divider]]
   [reagent-material-ui.core.paper :refer [paper]]
   [reagent-material-ui.core.fab :refer [fab]]
   [reagent-material-ui.core.toolbar :refer [toolbar]]
   [reagent-material-ui.core.typography :refer [typography]]
   [reagent-material-ui.core.select :refer [select]]
   [reagent-material-ui.core.menu-item :refer [menu-item]]
   [reagent-material-ui.core.form-control :refer [form-control]]
   [reagent-material-ui.core.input-label :refer [input-label]]
   [reagent-material-ui.core.list-item :refer [list-item]]
   [reagent-material-ui.core.list-item-text :refer [list-item-text]]
   [reagent-material-ui.core.list-item-secondary-action :refer [list-item-secondary-action]]
   [reagent-material-ui.core.table-container :refer [table-container]]
   [reagent-material-ui.core.table :refer [table]]
   [reagent-material-ui.core.table-head :refer [table-head]]
   [reagent-material-ui.core.table-body :refer [table-body]]
   [reagent-material-ui.core.table-row :refer [table-row]]
   [reagent-material-ui.core.table-cell :refer [table-cell]]
   [reagent-material-ui.core.icon-button :refer [icon-button]]
   [reagent-material-ui.icons.delete-icon :refer [delete]]
   [reagent-material-ui.icons.add :refer [add]]
   [reagent-material-ui.styles :as styles]))

(defn event-value
  [^js/Event e]
  (.. e -target -value))

(def drawer-width 350)
(def menu
  ((styles/with-styles
     (fn []
       {:drawer {:width drawer-width}
        :drawer-paper
        {:width drawer-width
         :flex-shrink 0}}))
   (fn [{:keys [classes, children]}]
     [drawer
      {:variant "permanent"
       :class (:drawer classes)
       :classes {:paper (:drawer-paper classes)}}
      [toolbar]
      children])))

(def topbar
  ((styles/with-styles
     (fn [{:keys [z-index]}]
       {:bar {:z-index (+ 1 (:drawer z-index))}}))
   (fn [{:keys [classes]}]
     [app-bar {:class (:bar classes)}
      [toolbar {}
       [typography {:variant "h6"} "Gear Calculator"]]])))

(def add-gear-button
  ((styles/with-styles
     (fn []
       {:button
        {:position "absolute"
         :bottom 20
         :right 20}}))
   (fn [{:keys [classes on-click]}]
     [fab {:color "primary"
           :label "Add gear"
           :on-click on-click
           :class (:button classes)}
      [add]])))

(def gear-list-item
  ((styles/with-styles
     (fn []
       {:container
        {"&:hover .MuiButtonBase-root" {:display "block"}
         "&:hover" {:border-right "5px solid #ccc"}}
        :selected {:border-right "5px solid green"}
        :icon {:display "none"}
        :icon-visible {:display "block"}}))
   (fn [{:keys [classes gear selected on-select]}]
     [list-item
      {:button true
       :on-click #(on-select gear)
       :classes
       {:container
        (class-names
         {(keyword (:selected classes)) selected}
         (:container classes))}}
      [list-item-text {:primary
                       (str (:chainring-teeth gear)
                            " x "
                            (:cog-teeth gear))}]
      [list-item-secondary-action
       [icon-button {:edge "end"
                     :aria-label "delete"
                     :class (class-names
                             (:icon classes))}
        [delete]]]])))

(def container
  ((styles/with-styles
     (fn []
       {:root {:padding "5em 2em 2em"}
        :paper {:padding "2em"}}))
   (fn [{:keys [classes children]}]
     [:main {:className (:root classes)}
      [paper {:className (:paper classes)}
       children]])))

(def dropdown
  ((styles/with-styles
     (fn []
       {:label
        {:background-color "white"
         :padding ".1em .6em"}}))
   (fn [{:keys [on-change label classes items value]}]
     [form-control {:variant "outlined" :full-width true}
      [input-label {:shrink true
                    :className (:label classes)}
       label]
      [select {:label label
               :value value
               :on-change #(on-change (event-value %))}
       (for [{:keys [value label]} items]
         [menu-item {:value value :key label} label])]])))

(defn make-dropdown-items [items]
  (map (fn [item] {:value item :label item}) items))
(defn make-indexed-dropdown-items [items]
  (map-indexed (fn [i item] {:value i :label (:label item)}) items))

(defn gear-form
  [{:keys
    [on-change
     gear]}]
  [grid
   {:container true
    :spacing 8}
   [grid {:item true :xs 12 :md 3}
    [dropdown
     {:label "Chainring"
      :on-change #(on-change {:name :chainring-teeth :value %})
      :value (:chainring-teeth gear)
      :items (make-dropdown-items g/chainring-teeth)}]]
   [grid {:item true :xs 12 :md 3}
    [dropdown
     {:label "Cog"
      :on-change #(on-change {:name :cog-teeth :value %})
      :value (:cog-teeth gear)
      :items (make-dropdown-items g/cog-teeth)}]]
   [grid {:item true :xs 12 :md 3}
    [dropdown
     {:label "Wheel size"
      :on-change #(on-change {:name :wheel-size :value %})
      :value (:wheel-size gear)
      :items (make-indexed-dropdown-items g/wheel-sizes)}]]
   [grid {:item true :xs 12 :md 3}
    [dropdown
     {:label "Crank length"
      :on-change #(on-change {:name :crank-length :value %})
      :value (:crank-length gear)
      :items (make-dropdown-items g/crank-lengths)}]]])

(def separator
  ((styles/with-styles
     (fn [] {:root {:margin "2em 0 1em"}}))
   (fn [{:keys [classes]}]
     [divider {:className (:root classes)}])))

(def gear-value
  (fn [{:keys [label value]}]
    [:<>
     [typography {:gutter-bottom true :variant "h5"}
      value]
     [typography {:variant "body2"}
      label]]))

(defn gear-info [gear]
  [grid {:container true :spacing 8}
   [grid {:item true :xs 4 :md 3}
    [gear-value
     {:label "gear inches"
      :value (g/gear-inches gear)}]]
   [grid {:item true :xs 4 :md 3}
    [gear-value
     {:label "development"
      :value (g/metres-of-development gear)}]]
   [grid {:item true :xs 4 :md 3}
    [gear-value
     {:label "gain ratio"
      :value (g/gain-ratio gear)}]]])

(defn cadence-table [gear]
  [table-container {}
   [table {}
    [table-head {}
     [table-row {}
      [table-cell {} "Cadence"]
      [table-cell {} "Kmph"]
      [table-cell {} "Mph"]]]
    [table-body
     {} (doall
         (for [c (g/generate-cadences gear)]
           [table-row {:key (:rpm c)}
            [table-cell (:rpm c)]
            [table-cell (:kmph c)]
            [table-cell (:mph c)]]))]]])

(def equivalent-gears-list
  ((styles/with-styles
     (fn []
       {:root {:margin-top "1.2em"}
        :chip {:margin ".5em .5em 0 0"}}))
   (fn [{:keys [gearing classes]}]
     (println gearing classes)
     [grid {:class (:root classes)}
      [typography {:gutter-bottom true
                   :variant "caption"}
       "Equivalent gears"]
      [:div
       (doall
        (for
         [gear (g/equivalent-gears gearing)]
          [chip
           {:key
            (str (:cog-teeth gear)
                 (:chainring-teeth gear))
            :color "primary"
            :class (:chip classes)
            :label (str
                    (:chainring-teeth gear)
                    "x"
                    (:cog-teeth gear))}]))]])))

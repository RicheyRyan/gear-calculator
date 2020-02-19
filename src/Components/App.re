module Styles = {
  open Css;

  let sidebar =
    style([
      boxSizing(borderBox),
      padding(rem(0.75)),
      backgroundColor(white),
      unsafe("height", "calc(100vh - 52px)"),
    ]);

  let menuList = style([paddingBottom(rem(1.2))]);
};

type action =
  | AddGearing(Gearing.t)
  | RemoveGearing(Gearing.t)
  | UpdateGearing(Gearing.t)
  | SetSelectedGearing(int);

type state = {
  gearings: list(Gearing.t),
  selected: int,
};

let reducer = (state, action) =>
  switch (action) {
  | AddGearing(gearing) =>
    let newGearings = List.concat([state.gearings, [gearing]]);
    {gearings: newGearings, selected: List.length(newGearings) - 1};
  | RemoveGearing(gearing) =>
    let newGearings =
      List.length(state.gearings) > 0
        ? List.filter(g => g != gearing, state.gearings) : state.gearings;
    {gearings: newGearings, selected: List.length(newGearings) - 1};
  | UpdateGearing(gearing) => {
      ...state,
      gearings:
        List.map(
          (g: Gearing.t) => g.createdAt == gearing.createdAt ? gearing : g,
          state.gearings,
        ),
    }
  | SetSelectedGearing(gearing) => {...state, selected: gearing}
  };

let renderGearListItems = (~gearings, ~selected, ~dispatch) => {
  List.mapi(
    (i, gearing) =>
      <GearListItem
        key={gearing.createdAt->string_of_int}
        gearing
        handleView={_ => SetSelectedGearing(i)->dispatch}
        handleRemove={_ => RemoveGearing(gearing)->dispatch}
        isActive={selected == i}
        isOnlyItem={List.length(gearings) == 1}
      />,
    gearings,
  )
  ->Array.of_list
  ->React.array;
};

[@react.component]
let make = () => {
  let ({gearings, selected}, dispatch) =
    React.useReducer(reducer, {gearings: [Gearing.make()], selected: 0});
  <>
    <Navbar>
      <h1 className="title has-text-light is-size-4">
        {React.string("Gear Calculator")}
      </h1>
    </Navbar>
    <Columns>
      <Column is3=true>
        <Menu className=Styles.sidebar>
          <Columns>
            <Column>
              <MenuLabel> {React.string("Gearings")} </MenuLabel>
            </Column>
            <Column>
              <Button
                isPrimary=true
                className=Bulma.Helpers.isPulledRight
                onClick={_ => Gearing.make()->AddGearing->dispatch}>
                {React.string("Add gearing")}
              </Button>
            </Column>
          </Columns>
          <Columns>
            <Column>
              <MenuList className=Styles.menuList>
                {renderGearListItems(~gearings, ~selected, ~dispatch)}
              </MenuList>
            </Column>
          </Columns>
        </Menu>
      </Column>
      <Column>
        <GearCalculator
          gearing={List.nth(gearings, selected)}
          updateGear={gearing => UpdateGearing(gearing)->dispatch}
        />
      </Column>
    </Columns>
  </>;
};
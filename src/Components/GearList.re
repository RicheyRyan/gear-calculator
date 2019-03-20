let headerHeight = 64;

[%mui.withStyles
  "Style"({listHeading: ReactDOMRe.Style.make(~margin="0.6em 0", ())})
];

let getSectionHeight = windowHeight => {
  windowHeight - headerHeight |> string_of_int;
};

let label = ({chainringTeeth, cogTeeth}: Gearing.t) =>
  {j|$chainringTeeth x $cogTeeth|j}->ReasonReact.string;

let listGears = (gearings: list(Gearing.t), selectedGear, onSelectItem) =>
  List.map(
    (gear: Gearing.t) =>
      <GearListItem
        gear
        selected={
          switch (selectedGear) {
          | Some(g) => g === gear
          | None => false
          }
        }
        key={gear.createdAt->string_of_int}
        onClick={_event => onSelectItem(gear)}
      />,
    gearings,
  )
  |> Array.of_list
  |> ReasonReact.array;

let emptyList = l => List.length(l) === 0;

let component = ReasonReact.statelessComponent(__MODULE__);

let make =
    (
      ~dimensions: Window.dimensions,
      ~gearings: list(Gearing.t),
      ~selectedGear: option(Gearing.t),
      ~onSelectItem,
      _children,
    ) => {
  ...component,
  render: _self =>
    MaterialUi.(
      <Style>
        ...{classes =>
          <List
            subheader={
              <ListSubheader>
                <Typography variant=`H6 className={classes.listHeading}>
                  {ReasonReact.string("Gears")}
                </Typography>
              </ListSubheader>
            }
            component={`String("nav")}
            style={ReactDOMRe.Style.make(
              ~height=getSectionHeight(dimensions.height) ++ "px",
              ~overflowY="auto",
              ~padding="0",
              ~backgroundColor="#fff",
              (),
            )}>
            {emptyList(gearings) ?
               <GearListItem.NoItems /> :
               listGears(gearings, selectedGear, onSelectItem)}
          </List>
        }
      </Style>
    ),
};
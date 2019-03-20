let component = ReasonReact.statelessComponent(__MODULE__);

let label = ({chainringTeeth, cogTeeth}: Gearing.t) =>
  {j|$chainringTeeth x $cogTeeth|j}->ReasonReact.string;

let make = (~gear: Gearing.t, _children) => {
  ...component,
  render: _self => {
    MaterialUi.(
      <>
        <ListItem button=true>
          <ListItemText primary={label(gear)} />
        </ListItem>
        <Divider />
      </>
    );
  },
};

module NoItems = {
  let component = ReasonReact.statelessComponent(__MODULE__);

  let make = _children => {
    ...component,
    render: _self => {
      MaterialUi.(
        <ListItem>
          <Typography variant=`Subtitle1>
            {ReasonReact.string("No gears created yet")}
          </Typography>
        </ListItem>
      );
    },
  };
};
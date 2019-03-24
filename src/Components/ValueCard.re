let component = ReasonReact.statelessComponent(__MODULE__);

[%mui.withStyles
  "Style"({
    add:
      ReactDOMRe.Style.make(
        ~position="absolute",
        ~bottom="24px",
        ~right="36px",
        (),
      ),
  })
];

let make = (~value, ~label, _children) => {
  ...component,
  render: _self =>
    MaterialUi.(
      <Style>
        ...{classes =>
          <Card>
            <CardContent>
              <Typography
                gutterBottom=?{Some(true)}
                variant=`H5
                component=?{Some(`String("h2"))}>
                {ReasonReact.string(value)}
              </Typography>
              <Typography component=?{Some(`String("p"))}>
                {ReasonReact.string(label)}
              </Typography>
            </CardContent>
          </Card>
        }
      </Style>
    ),
};
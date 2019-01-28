let component = ReasonReact.statelessComponent(__MODULE__);

let make = (_children, ~visible, ~handleClose) => {
  ...component,
  render: _self =>
    MaterialUi.(
      <Dialog
        open_=visible
        onEscapeKeyDown={_event => handleClose()}
        onBackdropClick={_event => handleClose()}>
        <DialogTitle>
          {ReasonReact.string("About Gear Calculator")}
        </DialogTitle>
        <DialogContent>
          <DialogContentText paragraph=true>
            {ReasonReact.string(
               "This site was built by Richey Ryan, a programmer from Dublin Ireland. It is inspired by and based on the work of sheldonbrown.com.",
             )}
          </DialogContentText>
          <DialogContentText paragraph=true>
            {ReasonReact.string(
               "Fill out the form to see your gear inches, development in metres, gain ratio and skid patches calculated.",
             )}
          </DialogContentText>
          <DialogContentText paragraph=true>
            {ReasonReact.string(
               "You will also be able to see a cadence chart of your speed in miles per hour and kilometres per hour, depending on your RPM, as well as a list of equivalent gear ratios.",
             )}
          </DialogContentText>
          <DialogContentText paragraph=true>
            {ReasonReact.string(
               "The equilavent gear ratios are within one gear inch higher or lower than the original ratio to allow for a significant range of comparison.",
             )}
          </DialogContentText>
        </DialogContent>
        <DialogActions>
          <Button onClick={_event => handleClose()} color=`Primary>
            {ReasonReact.string("Ok")}
          </Button>
        </DialogActions>
      </Dialog>
    ),
};
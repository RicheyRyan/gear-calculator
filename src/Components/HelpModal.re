[@react.component]
let make = (_children, _visible, _handleClose, _fullScreen) => {
  <div>
            <p>{React.string(
               "This site was built by Richey Ryan, a programmer from Dublin Ireland. It is inspired by and based on the work of sheldonbrown.com.",
             )}</p>
             <p>
            {React.string(
               "Fill out the form to see your gear inches, development in metres, gain ratio and skid patches calculated.",
             )}
             </p>
             <p>
            {React.string(
               "You will also be able to see a cadence chart of your speed in miles per hour and kilometres per hour, depending on your RPM, as well as a list of equivalent gear ratios.",
             )}
             </p>
             <p>
            {React.string(
               "The equilavent gear ratios are within one gear inch higher or lower than the original ratio to allow for a significant range of comparison.",
             )}
             </p>
  </div>
};
module Styles = {
  open Css;

  let container = style([padding(rem(0.75))]);
};

type gearDetails = {
  gearInches: float,
  development: float,
  gainRatio: float,
  skidPatches: int,
  equivalentGears: list(Gearing.ratio),
  cadences: list(Gearing.cadence),
};

let createGearing = gearing => {
  gearInches: Gearing.gearInches(gearing),
  development: Gearing.metresOfDevelopment(gearing),
  gainRatio: Gearing.gainRatio(gearing),
  skidPatches: Gearing.skidPatches(gearing)->int_of_float,
  equivalentGears: Gearing.equivalentGear(gearing),
  cadences: Gearing.generateCadences(gearing),
};

[@react.component]
let make = (~gearing, ~updateGear) => {
  <section className=Styles.container>
    <div className="card">
      {switch (gearing) {
       | Some(selectedGear) =>
         let details = createGearing(selectedGear);
         let updateChainring = e =>
           {let value = e->ReactEvent.Form.target##value
            let chainringTeeth = Js.Float.fromString(value)
            updateGear({...selectedGear, chainringTeeth})};

         let updateCog = e =>
           {let value = e->ReactEvent.Form.target##value
            let cogTeeth = Js.Float.fromString(value)
            updateGear({...selectedGear, cogTeeth})};

         let updateWheelSize = e =>
           {let value = e->ReactEvent.Form.target##value
            let wheelSize = Js.Float.fromString(value)
            updateGear({...selectedGear, wheelSize})};

         let updateCrankLength = e =>
           {let value = e->ReactEvent.Form.target##value
            let crankLength = Js.Float.fromString(value)
            updateGear({...selectedGear, crankLength})};

         let updateAmbidextrousSkidder = e =>
           {updateGear({
              ...selectedGear,
              ambidextrousSkidder: !selectedGear.ambidextrousSkidder,
            })};

         <>
           <div className="card-content">
             <div className="content">
               <Columns>
                 <Column>
                   <Field label="Chainring">
                     <Select
                       value={selectedGear.chainringTeeth->Js.Float.toString}
                       onChange=updateChainring>
                       {Belt.List.map(GearingValues.chainringTeeth, tooth =>
                          <option key={Js.Float.toString(tooth)}>
                            {Js.Float.toString(tooth)->React.string}
                          </option>
                        )
                        ->Array.of_list
                        ->React.array}
                     </Select>
                   </Field>
                 </Column>
                 <Column>
                   <Field label="Cog">
                     <Select
                       value={selectedGear.cogTeeth->Js.Float.toString}
                       onChange=updateCog>
                       {Belt.List.map(
                          GearingValues.cogTeeth,
                          tooth => {
                            let toothString = Js.Float.toString(tooth);
                            <option value=toothString key=toothString>
                              toothString->React.string
                            </option>;
                          },
                        )
                        ->Array.of_list
                        ->React.array}
                     </Select>
                   </Field>
                 </Column>
                 <Column>
                   <Field label="Wheel size">
                     <Select
                       value={selectedGear.wheelSize->Js.Float.toString}
                       onChange=updateWheelSize>
                       {Belt.List.map(GearingValues.wheelSizes, wheel =>
                          <option
                            value={Js.Float.toString(wheel.value)}
                            key={wheel.key}>
                            wheel.name->React.string
                          </option>
                        )
                        ->Array.of_list
                        ->React.array}
                     </Select>
                   </Field>
                 </Column>
                 <Column>
                   <Field label="Crank length">
                     <Select
                       value={selectedGear.crankLength->Js.Float.toString}
                       onChange=updateCrankLength>
                       {Belt.List.map(
                          GearingValues.crankLengths,
                          crank => {
                            let crankString = crank->Js.Float.toString;
                            <option value=crankString key=crankString>
                              crankString->React.string
                            </option>;
                          },
                        )
                        ->Array.of_list
                        ->React.array}
                     </Select>
                   </Field>
                 </Column>
                 <Column>
                   <Field label="Ambidextrous Skidder">
                     <Checkbox
                       onChange=updateAmbidextrousSkidder
                       checked={selectedGear.ambidextrousSkidder}
                     />
                   </Field>
                 </Column>
               </Columns>
             </div>
             <hr />
             <div className="content">
               <Columns>
                 <Column>
                   <Field label="Gear inches">
                     {Js.Float.toFixedWithPrecision(details.gearInches, 1)
                      ->React.string}
                   </Field>
                 </Column>
                 <Column>
                   <Field label="Development">
                     {Js.Float.toFixedWithPrecision(details.development, 1)
                      ->React.string}
                   </Field>
                 </Column>
                 <Column>
                   <Field label="Gain ratio">
                     {Js.Float.toFixedWithPrecision(details.gainRatio, 1)
                      ->React.string}
                   </Field>
                 </Column>
                 <Column>
                   <Field label="Skid patches">
                     {string_of_int(details.skidPatches)->React.string}
                   </Field>
                 </Column>
               </Columns>
             </div>
           </div>
         </>;
       | None => React.string("None selected")
       }}
    </div>
  </section>;
};
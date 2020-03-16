module Styles = {
  open Css;

  let container = style([padding(rem(0.75))]);
};

type gearDetails = {
  gearInches: float,
  development: float,
  gainRatio: float,
  equivalentGears: list(Gearing.ratio),
  cadences: list(Gearing.cadence),
};

let createGearing = gearing => {
  gearInches: Gearing.gearInches(gearing),
  development: Gearing.metresOfDevelopment(gearing),
  gainRatio: Gearing.gainRatio(gearing),
  equivalentGears: Gearing.equivalentGear(gearing),
  cadences: Gearing.generateCadences(gearing),
};

[@react.component]
let make = (~gearing, ~updateGear) => {
  let details = createGearing(gearing);
  let updateChainring = e => {
    let value = e->ReactEvent.Form.target##value;
    let chainringTeeth = Float.ofString(value)->Option.get(~default=1.);
    updateGear({...gearing, chainringTeeth});
  };

  let updateCog = e => {
    let value = e->ReactEvent.Form.target##value;
    let cogTeeth = Js.Float.fromString(value);
    updateGear({...gearing, cogTeeth});
  };

  let updateWheelSize = e => {
    let value = e->ReactEvent.Form.target##value;
    let wheelSize = Float.ofString(value)->Option.get(~default=1.);
    updateGear({...gearing, wheelSize});
  };

  let updateCrankLength = e => {
    let value = e->ReactEvent.Form.target##value;
    let crankLength = Float.ofString(value)->Option.get(~default=1.);
    updateGear({...gearing, crankLength});
  };

  <section className=Styles.container>
    <Card>
      <Content>
        <Columns>
          <Column>
            <Field label="Chainring">
              <Select
                value={gearing.chainringTeeth->Js.Float.toString}
                onChange=updateChainring>
                {List.map(GearingValues.chainringTeeth, ~f=tooth =>
                   <option key={Float.toString(tooth)}>
                     {Float.toString(tooth)->React.string}
                   </option>
                 )
                 ->List.toArray
                 ->React.array}
              </Select>
            </Field>
          </Column>
          <Column>
            <Field label="Cog">
              <Select
                value={gearing.cogTeeth->Float.toString} onChange=updateCog>
                {List.map(
                   GearingValues.cogTeeth,
                   ~f=tooth => {
                     let toothString = Float.toString(tooth);
                     <option value=toothString key=toothString>
                       toothString->React.string
                     </option>;
                   },
                 )
                 ->List.toArray
                 ->React.array}
              </Select>
            </Field>
          </Column>
          <Column>
            <Field label="Wheel size">
              <Select
                value={gearing.wheelSize->Js.Float.toString}
                onChange=updateWheelSize>
                {List.map(GearingValues.wheelSizes, ~f=wheel =>
                   <option
                     value={Float.toString(wheel.value)} key={wheel.key}>
                     wheel.name->React.string
                   </option>
                 )
                 ->List.toArray
                 ->React.array}
              </Select>
            </Field>
          </Column>
          <Column>
            <Field label="Crank length">
              <Select
                value={gearing.crankLength->Float.toString}
                onChange=updateCrankLength>
                {List.map(
                   GearingValues.crankLengths,
                   ~f=crank => {
                     let crankString = crank->Float.toString;
                     <option value=crankString key=crankString>
                       crankString->React.string
                     </option>;
                   },
                 )
                 ->List.toArray
                 ->React.array}
              </Select>
            </Field>
          </Column>
        </Columns>
      </Content>
      <hr />
      <Content>
        <Columns>
          <Column>
            <Field label="Gear inches">
              {Js.Float.toFixedWithPrecision(details.gearInches, ~digits=1)
               ->React.string}
            </Field>
          </Column>
          <Column>
            <Field label="Development">
              {Js.Float.toFixedWithPrecision(details.development, ~digits=1)
               ->React.string}
            </Field>
          </Column>
          <Column>
            <Field label="Gain ratio">
              {Js.Float.toFixedWithPrecision(details.gainRatio, ~digits=1)
               ->React.string}
            </Field>
          </Column>
        </Columns>
      </Content>
      <hr />
      <Content>
        <Columns>
          <Column is6=true>
            <Label> {React.string("Cadences")} </Label>
            <Table>
              <thead>
                <tr>
                  <td> {React.string("Cadence")} </td>
                  <td> {React.string("Kmph")} </td>
                  <td> {React.string("Mph")} </td>
                </tr>
              </thead>
              <tbody>
                {List.map(details.cadences, ~f=({rpm, mph, kmph}) =>
                   <tr>
                     <td>
                       {Float.round(rpm)->Float.toString->React.string}
                     </td>
                     <td>
                       {Js.Float.toFixedWithPrecision(kmph, ~digits=2)
                        ->React.string}
                     </td>
                     <td>
                       {Js.Float.toFixedWithPrecision(mph, ~digits=2)
                        ->React.string}
                     </td>
                   </tr>
                 )
                 ->List.toArray
                 ->React.array}
              </tbody>
            </Table>
          </Column>
          <Column is6=true>
            <Label> {React.string("Equivalent Gears")} </Label>
          </Column>
        </Columns>
      </Content>
    </Card>
  </section>;
};
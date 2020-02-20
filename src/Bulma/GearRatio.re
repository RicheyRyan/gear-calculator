[@react.component]
let make = (~chainringTeeth, ~cogTeeth) => {
  <Tags hasAddons=true>
    <Tag isLarge=true isInfo=true>
      {chainringTeeth->Js.Float.toString->React.string}
    </Tag>
    <Tag isLarge=true> {React.string("x")} </Tag>
    <Tag isLarge=true isInfo=true>
      {cogTeeth->Js.Float.toString->React.string}
    </Tag>
  </Tags>;
};
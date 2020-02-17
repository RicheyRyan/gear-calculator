module Styles = {
  open Css;

  let viewButton = style([marginRight(px(10))]);
  let listItem = style([paddingBottom(rem(0.6))]);
};

[@react.component]
let make =
    (
      ~isActive=false,
      ~gearing: Gearing.t,
      ~handleView,
      ~handleRemove,
      ~isOnlyItem,
    ) => {
  <li className=Styles.listItem>
    <Columns>
      <Column isNarrow=true>
        <Tags hasAddons=true>
          <Tag isLarge=true isInfo=true>
            {gearing.chainringTeeth->Js.Float.toString->React.string}
          </Tag>
          <Tag isLarge=true> {React.string("x")} </Tag>
          <Tag isLarge=true isInfo=true>
            {gearing.cogTeeth->Js.Float.toString->React.string}
          </Tag>
        </Tags>
      </Column>
      <Column>
        <Button
          isSuccess=true
          className=Styles.viewButton
          onClick={_ => handleView()}>
          {React.string("View")}
        </Button>
        {isOnlyItem
           ? React.null
           : <Button isDanger=true onClick={_ => handleRemove()}>
               {React.string("Remove")}
             </Button>}
      </Column>
    </Columns>
  </li>;
};
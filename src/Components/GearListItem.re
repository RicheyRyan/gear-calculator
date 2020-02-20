module Styles = {
  open Css;

  let viewButton = style([marginRight(px(10))]);
  let listItem = style([paddingBottom(rem(0.6))]);
  let buttons = style([display(`flex), alignItems(`center)]);
  let selectionColumn =
    style([
      color(hex("3ec46d")),
      alignSelf(`center),
      maxWidth(px(30)),
      fontWeight(`bold),
      fontSize(em(2.)),
    ]);
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
      <Column className=Styles.selectionColumn>
        {isActive ? React.string("*") : React.null}
      </Column>
      <Column isNarrow=true>
        <GearRatio
          chainringTeeth={gearing.chainringTeeth}
          cogTeeth={gearing.cogTeeth}
        />
      </Column>
      <Column className=Styles.buttons>
        <Button
          isSuccess=true
          className=Styles.viewButton
          onClick={_ => handleView()}>
          {React.string("View")}
        </Button>
        {isOnlyItem
           ? React.null
           : <Button
               isDelete=true
               isLarge=true
               onClick={_ => handleRemove()}
             />}
      </Column>
    </Columns>
  </li>;
};
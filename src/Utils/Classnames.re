let make = cns => cns->List.filter(~f=x => x !== "")->List.join(~sep=" ");

let ifTrue = (cn, x) => x ? cn : "";

let ifSome = (cn, x) =>
  switch (x) {
  | Some(_) => cn
  | None => ""
  };

let mapSome = (x, fn) =>
  switch (x) {
  | Some(x) => x->fn
  | None => ""
  };

let unpack =
  fun
  | Some(x) => x
  | None => "";
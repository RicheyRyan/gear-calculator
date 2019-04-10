let formatFloat = str => {
  let len = String.length(str);
  let lastChar = str.[len - 1];
  if (lastChar === '.') {
    String.sub(str, 0, len - 1);
  } else {
    str;
  };
};

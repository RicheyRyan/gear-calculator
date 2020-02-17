[%raw "require('bulma')"];

Css.(global("html, body", [overflow(hidden)]));

ReactDOMRe.renderToElementWithId(<App />, "app");
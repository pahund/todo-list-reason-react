open Utils;

open Types;

let component = ReasonReact.statelessComponent("TodoItem");

type style = {
  root: ReactDOMRe.style,
  completed: ReactDOMRe.style
};

let styles = {
  root: ReactDOMRe.Style.make(), /* add root styles here */
  completed: ReactDOMRe.Style.make(~opacity="0.666", ~textDecoration="line-through", ())
};

let make = (~item: item, ~onToggle, ~onEditStart, ~onEditDone, _) => {
  ...component,
  render: (_) => {
    let style = styles.root;
    let style = item.completed ? ReactDOMRe.Style.combine(style, styles.completed) : style;
    <div style>
      <input
        _type="checkbox"
        onChange=((_) => onToggle())
        checked=(Js.Boolean.to_js_boolean(item.completed))
      />
      (
        item.editing ?
          <EditTodoField initialText=item.title onSubmit=((text) => onEditDone(text)) /> :
          <label onClick=((_) => onEditStart())> (str(item.title)) </label>
      )
    </div>
  }
};
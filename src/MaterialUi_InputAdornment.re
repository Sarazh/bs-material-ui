[@bs.deriving jsConverter]
type position = [ | [@bs.as "start"] `Start | [@bs.as "end"] `End];

module Classes = {
  type classesType =
    | Root(string)
    | PositionStart(string)
    | PositionEnd(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | PositionStart(_) => "positionStart"
    | PositionEnd(_) => "positionEnd";
  let to_obj = listOfClasses =>
    listOfClasses
    |> StdLabels.List.fold_left(
         ~f=
           (obj, classType) => {
             switch (classType) {
             | Root(className)
             | PositionStart(className)
             | PositionEnd(className) =>
               Js.Dict.set(obj, to_string(classType), className)
             };
             obj;
           },
         ~init=Js.Dict.empty(),
       );
};

[@bs.obj]
external makeProps :
  (
    ~className: string=?,
    ~component: 'union_r2hz=?,
    ~disableTypography: bool=?,
    ~position: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/InputAdornment/InputAdornment"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~className: option(string)=?,
      ~component: option([ | `String(string) | `Callback('genericCallback)])=?,
      ~disableTypography: option(bool)=?,
      ~position: option(position)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~className?,
        ~component=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            component,
          ),
        ~disableTypography?,
        ~position=?Js.Option.map((. v) => positionToJs(v), position),
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );

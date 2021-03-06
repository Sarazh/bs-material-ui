[@bs.deriving jsConverter]
type color = [
  | [@bs.as "inherit"] `Inherit
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
  | [@bs.as "default"] `Default
];

[@bs.deriving jsConverter]
type position = [
  | [@bs.as "fixed"] `Fixed
  | [@bs.as "absolute"] `Absolute
  | [@bs.as "sticky"] `Sticky
  | [@bs.as "static"] `Static
];

module Classes = {
  type classesType =
    | Root(string)
    | PositionFixed(string)
    | PositionAbsolute(string)
    | PositionSticky(string)
    | PositionStatic(string)
    | ColorDefault(string)
    | ColorPrimary(string)
    | ColorSecondary(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | PositionFixed(_) => "positionFixed"
    | PositionAbsolute(_) => "positionAbsolute"
    | PositionSticky(_) => "positionSticky"
    | PositionStatic(_) => "positionStatic"
    | ColorDefault(_) => "colorDefault"
    | ColorPrimary(_) => "colorPrimary"
    | ColorSecondary(_) => "colorSecondary";
  let to_obj = listOfClasses =>
    listOfClasses
    |> StdLabels.List.fold_left(
         ~f=
           (obj, classType) => {
             switch (classType) {
             | Root(className)
             | PositionFixed(className)
             | PositionAbsolute(className)
             | PositionSticky(className)
             | PositionStatic(className)
             | ColorDefault(className)
             | ColorPrimary(className)
             | ColorSecondary(className) =>
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
    ~color: string=?,
    ~position: string=?,
    ~component: 'union_rw1q=?,
    ~elevation: 'number_a=?,
    ~square: bool=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/AppBar/AppBar"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~position: option(position)=?,
      ~component: option([ | `String(string) | `Callback('genericCallback)])=?,
      ~elevation: option([ | `Int(int) | `Float(float)])=?,
      ~square: option(bool)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~className?,
        ~color=?Js.Option.map((. v) => colorToJs(v), color),
        ~position=?Js.Option.map((. v) => positionToJs(v), position),
        ~component=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            component,
          ),
        ~elevation=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            elevation,
          ),
        ~square?,
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );

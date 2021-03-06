[@bs.deriving jsConverter]
type color = [
  | [@bs.as "default"] `Default
  | [@bs.as "inherit"] `Inherit
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
];

[@bs.deriving jsConverter]
type size = [
  | [@bs.as "small"] `Small
  | [@bs.as "medium"] `Medium
  | [@bs.as "large"] `Large
];

[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "flat"] `Flat
  | [@bs.as "outlined"] `Outlined
  | [@bs.as "raised"] `Raised
  | [@bs.as "fab"] `Fab
];

module Classes = {
  type classesType =
    | Root(string)
    | Label(string)
    | FlatPrimary(string)
    | FlatSecondary(string)
    | Outlined(string)
    | ColorInherit(string)
    | Raised(string)
    | RaisedPrimary(string)
    | RaisedSecondary(string)
    | FocusVisible(string)
    | Disabled(string)
    | Fab(string)
    | Mini(string)
    | SizeSmall(string)
    | SizeLarge(string)
    | FullWidth(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Label(_) => "label"
    | FlatPrimary(_) => "flatPrimary"
    | FlatSecondary(_) => "flatSecondary"
    | Outlined(_) => "outlined"
    | ColorInherit(_) => "colorInherit"
    | Raised(_) => "raised"
    | RaisedPrimary(_) => "raisedPrimary"
    | RaisedSecondary(_) => "raisedSecondary"
    | FocusVisible(_) => "focusVisible"
    | Disabled(_) => "disabled"
    | Fab(_) => "fab"
    | Mini(_) => "mini"
    | SizeSmall(_) => "sizeSmall"
    | SizeLarge(_) => "sizeLarge"
    | FullWidth(_) => "fullWidth";
  let to_obj = listOfClasses =>
    listOfClasses
    |> StdLabels.List.fold_left(
         ~f=
           (obj, classType) => {
             switch (classType) {
             | Root(className)
             | Label(className)
             | FlatPrimary(className)
             | FlatSecondary(className)
             | Outlined(className)
             | ColorInherit(className)
             | Raised(className)
             | RaisedPrimary(className)
             | RaisedSecondary(className)
             | FocusVisible(className)
             | Disabled(className)
             | Fab(className)
             | Mini(className)
             | SizeSmall(className)
             | SizeLarge(className)
             | FullWidth(className) =>
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
    ~component: 'union_ri3k=?,
    ~disabled: bool=?,
    ~disableFocusRipple: bool=?,
    ~disableRipple: bool=?,
    ~focusVisibleClassName: string=?,
    ~fullWidth: bool=?,
    ~href: string=?,
    ~mini: bool=?,
    ~size: string=?,
    ~type_: string=?,
    ~variant: string=?,
    ~action: 'any_rg17=?,
    ~buttonRef: 'union_r5b6=?,
    ~centerRipple: bool=?,
    ~focusRipple: bool=?,
    ~onBlur: ReactEventRe.Focus.t => unit=?,
    ~onClick: ReactEventRe.Mouse.t => unit=?,
    ~onFocus: ReactEventRe.Focus.t => unit=?,
    ~onFocusVisible: 'genericCallback=?,
    ~onKeyDown: ReactEventRe.Keyboard.t => unit=?,
    ~onKeyUp: ReactEventRe.Keyboard.t => unit=?,
    ~onMouseDown: ReactEventRe.Mouse.t => unit=?,
    ~onMouseLeave: ReactEventRe.Mouse.t => unit=?,
    ~onMouseUp: ReactEventRe.Mouse.t => unit=?,
    ~onTouchEnd: ReactEventRe.Touch.t => unit=?,
    ~onTouchMove: ReactEventRe.Touch.t => unit=?,
    ~onTouchStart: ReactEventRe.Touch.t => unit=?,
    ~role: string=?,
    ~tabIndex: 'union_rtrf=?,
    ~_TouchRippleProps: Js.t({..})=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/Button/Button"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~component: option([ | `String(string) | `Callback('genericCallback)])=?,
      ~disabled: option(bool)=?,
      ~disableFocusRipple: option(bool)=?,
      ~disableRipple: option(bool)=?,
      ~focusVisibleClassName: option(string)=?,
      ~fullWidth: option(bool)=?,
      ~href: option(string)=?,
      ~mini: option(bool)=?,
      ~size: option(size)=?,
      ~type_: option(string)=?,
      ~variant: option(variant)=?,
      ~action: option(Js.t({..}) => unit)=?,
      ~buttonRef:
         option(
           [ | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))],
         )=?,
      ~centerRipple: option(bool)=?,
      ~focusRipple: option(bool)=?,
      ~onBlur: option(ReactEventRe.Focus.t => unit)=?,
      ~onClick: option(ReactEventRe.Mouse.t => unit)=?,
      ~onFocus: option(ReactEventRe.Focus.t => unit)=?,
      ~onFocusVisible: option('genericCallback)=?,
      ~onKeyDown: option(ReactEventRe.Keyboard.t => unit)=?,
      ~onKeyUp: option(ReactEventRe.Keyboard.t => unit)=?,
      ~onMouseDown: option(ReactEventRe.Mouse.t => unit)=?,
      ~onMouseLeave: option(ReactEventRe.Mouse.t => unit)=?,
      ~onMouseUp: option(ReactEventRe.Mouse.t => unit)=?,
      ~onTouchEnd: option(ReactEventRe.Touch.t => unit)=?,
      ~onTouchMove: option(ReactEventRe.Touch.t => unit)=?,
      ~onTouchStart: option(ReactEventRe.Touch.t => unit)=?,
      ~role: option(string)=?,
      ~tabIndex: option([ | `Int(int) | `Float(float) | `String(string)])=?,
      ~_TouchRippleProps: option(Js.t({..}))=?,
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
        ~component=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            component,
          ),
        ~disabled?,
        ~disableFocusRipple?,
        ~disableRipple?,
        ~focusVisibleClassName?,
        ~fullWidth?,
        ~href?,
        ~mini?,
        ~size=?Js.Option.map((. v) => sizeToJs(v), size),
        ~type_?,
        ~variant=?Js.Option.map((. v) => variantToJs(v), variant),
        ~action?,
        ~buttonRef=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            buttonRef,
          ),
        ~centerRipple?,
        ~focusRipple?,
        ~onBlur?,
        ~onClick?,
        ~onFocus?,
        ~onFocusVisible?,
        ~onKeyDown?,
        ~onKeyUp?,
        ~onMouseDown?,
        ~onMouseLeave?,
        ~onMouseUp?,
        ~onTouchEnd?,
        ~onTouchMove?,
        ~onTouchStart?,
        ~role?,
        ~tabIndex=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            tabIndex,
          ),
        ~_TouchRippleProps?,
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );

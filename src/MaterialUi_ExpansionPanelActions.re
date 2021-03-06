module Classes = {
  type classesType =
    | Root(string)
    | Action(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Action(_) => "action";
  let to_obj = listOfClasses =>
    listOfClasses
    |> StdLabels.List.fold_left(
         ~f=
           (obj, classType) => {
             switch (classType) {
             | Root(className)
             | Action(className) =>
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
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/ExpansionPanelActions/ExpansionPanelActions"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~className: option(string)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~className?,
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );

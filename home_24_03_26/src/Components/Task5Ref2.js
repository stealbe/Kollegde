import React, { useRef } from "react";

export function CustomTextInput()
 {
   const textInput = useRef(); // int & textinput  
  
   function focusTextInput() {
      textInput.current.focus();
      textInput.current.value = "value from ref";
    }
      return (
        <div>
          <input type="text" ref={textInput} />
          <input type="button"  value="Фокус на текстовом поле"  onClick={focusTextInput}
          />
        </div>
      );
  }
  
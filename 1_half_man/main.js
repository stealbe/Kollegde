"use strict";

function CaesarEncrypt(str, shift) {
  const start_t = performance.now();
  let result = "";
  for (let i = 0; i < str.length; i++) {
    let char = str[i];
    if (char.match(/[a-z]/i)) {
      let code = str.charCodeAt(i);
      let base = code >= 65 && code <= 90 ? 65 : 97;
      char = String.fromCharCode(((code - base + shift) % 26) + base);
    }
    result += char;
  }
  const end_t = performance.now();
  return { result: result, time: end_t - start_t };
}

function CaesarDecrypt(str, encryptedStr) {
  const start_t = performance.now();
  let shift = 0;
  for (; shift < 26; shift++) {
    let result = "";
    for (let i = 0; i < str.length; i++) {
      let char = str[i];
      if (char.match(/[a-z]/i)) {
        let code = str.charCodeAt(i);
        let base = code >= 65 && code <= 90 ? 65 : 97;
        char = String.fromCharCode(((code - base + shift) % 26) + base);
      }
      result += char;
    }
    if (result === encryptedStr) {
      break;
    }
  }
  const end_t = performance.now();
  return { shift: shift, time: end_t - start_t };
}

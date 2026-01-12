"use strict";

function CaesarEncrypt(str, shift) {
  const start_t = performance.now();
  let result = "";

  for (let i = 0; i < str.length; i++) {
    let char = str[i];
    if (char.match(/[a-zа-я]/i)) {
      let code = str.charCodeAt(i); // Get the Unicode of the latter
      let base = code >= 65 && code <= 90 ? 65 : 97; // Determine if it's uppercase or lowercase
      char = String.fromCharCode(((code - base + shift) % 26) + base); // Shift the letter and wrap around the alphabet
    }
    result += char;
  }
  const end_t = performance.now();
  return { result: result, time: end_t - start_t };
}

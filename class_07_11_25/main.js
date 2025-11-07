document.forms[0].first_name.addEventListener("blur", function () {
  let regex = new RegExp("^[A-ZА-Я]{1}[a-zа-я]{2,}$");
  if (this.value.length > 0 && regex.test(this.value))
    document.forms[1].small_name.value = this.value;
  else if (this.value.length > 0) {
    this.setCustomValidity(
      "Имя должно начинаться с заглавной буквы и содержать не менее 3 букв."
    );
    this.reportValidity();
  }
});

document.forms[0].email.addEventListener("blur", function () {
  let regex = new RegExp("^[\\w-\\.]+@([\\w.\\-]+\\.)+[\\w-]{2,4}$");
  if (this.value.length > 0 && regex.test(this.value))
    document.forms[1].small_email.value = this.value;
  else if (this.value.length > 0) {
    this.setCustomValidity("Введите корректный email адрес.");
    this.reportValidity();
  }
});

"use strict";

let laptops = [
  {
    id: 1,
    brand: "Apple",
    model: "MacBook Air M2 (2024)",
    description:
      "Екран 13.6” Retina (2560x1664) / Apple M2 (8-ядерний) / RAM 8 ГБ / SSD 512 ГБ / без ОД / Wi-Fi / macOS / 1.24 кг / сріблястий",
    stars: 4.2,
    cost: 1499,
    sale: 10,
    reviews_count: 256,
    preview_img:
      "https://content1.rozetka.com.ua/goods/images/big_tile/596102605.jpg",
  },
  {
    id: 2,
    brand: "ASUS",
    model: "ROG Zephyrus G14",
    description:
      "Екран 14” IPS (2560x1600) 165 Гц / AMD Ryzen 9 7940HS / RAM 16 ГБ / SSD 1 ТБ / RTX 4070, 8 ГБ / без ОС / 1.65 кг / чорний",
    stars: 4.6,
    cost: 1899,
    sale: 12,
    reviews_count: 312,
    preview_img:
      "https://content2.rozetka.com.ua/goods/images/big_tile/597709136.jpg",
  },
  {
    id: 3,
    brand: "Lenovo",
    model: "Legion 5 Pro",
    description:
      "Екран 16” IPS (2560x1600) 165 Гц / AMD Ryzen 7 7840HS / RAM 16 ГБ / SSD 1 ТБ / RTX 4070, 8 ГБ / без ОС / 2.49 кг / сірий",
    stars: 3.9,
    cost: 1599,
    sale: 15,
    reviews_count: 204,
    preview_img:
      "https://content1.rozetka.com.ua/goods/images/big_tile/582457354.jpg",
  },
  {
    id: 4,
    brand: "HP",
    model: "Spectre x360 14",
    description:
      "Екран 14” OLED (2880x1800) сенсорний / Intel Core i7-1360P / RAM 16 ГБ / SSD 1 ТБ / Intel Iris Xe / Windows 11 / 1.36 кг / темно-синій",
    stars: 4.7,
    cost: 1399,
    sale: 8,
    reviews_count: 174,
    preview_img:
      "https://content2.rozetka.com.ua/goods/images/big_tile/597709595.jpg",
  },
  {
    id: 5,
    brand: "Dell",
    model: "XPS 15 (2024)",
    description:
      "Екран 15.6” OLED (3456x2160) / Intel Core i9-14900H / RAM 32 ГБ / SSD 1 ТБ / RTX 4070, 8 ГБ / Windows 11 / 1.92 кг / сріблястий",
    stars: 4.1,
    cost: 1999,
    sale: 5,
    reviews_count: 387,
    preview_img:
      "https://content2.rozetka.com.ua/goods/images/big_tile/597709595.jpg",
  },
  {
    id: 6,
    brand: "Acer",
    model: "Nitro 5",
    description:
      "Екран 15.6” IPS (1920x1080) 144 Гц / Intel Core i5-13450HX / RAM 16 ГБ / SSD 512 ГБ / RTX 4060, 8 ГБ / без ОС / 2.5 кг / чорний",
    stars: 4.0,
    cost: 1099,
    sale: 20,
    reviews_count: 645,
    preview_img:
      "https://content2.rozetka.com.ua/goods/images/big_tile/597709595.jpg",
  },
  {
    id: 7,
    brand: "MSI",
    model: "Katana 17",
    description:
      "Екран 17.3” IPS (1920x1080) 144 Гц / Intel Core i7-13620H / RAM 16 ГБ / SSD 1 ТБ / RTX 4060, 8 ГБ / без ОС / 2.6 кг / чорний",
    stars: 4.4,
    cost: 1399,
    sale: 18,
    reviews_count: 299,
    preview_img:
      "https://content2.rozetka.com.ua/goods/images/big_tile/597709595.jpg",
  },
  {
    id: 8,
    brand: "Apple",
    model: "MacBook Pro 16 M3 Pro",
    description:
      "Екран 16.2” Liquid Retina XDR (3456x2234) / Apple M3 Pro / RAM 18 ГБ / SSD 1 ТБ / macOS / 2.14 кг / сірий космос",
    stars: 4.9,
    cost: 2999,
    sale: 7,
    reviews_count: 124,
    preview_img:
      "https://content2.rozetka.com.ua/goods/images/big_tile/597709595.jpg",
  },
  {
    id: 9,
    brand: "Lenovo",
    model: "IdeaPad 3",
    description:
      "Екран 15.6” IPS (1920x1080) / Intel Core i5-1335U / RAM 8 ГБ / SSD 512 ГБ / Intel Iris Xe / Windows 11 / 1.63 кг / сріблястий",
    stars: 3.8,
    cost: 699,
    sale: 25,
    reviews_count: 482,
    preview_img:
      "https://content2.rozetka.com.ua/goods/images/big_tile/597709595.jpg",
  },
  {
    id: 10,
    brand: "ASUS",
    model: "ZenBook 14 OLED",
    description:
      "Екран 14” OLED (2880x1800) / Intel Core i7-1360P / RAM 16 ГБ / SSD 1 ТБ / Intel Iris Xe / Windows 11 / 1.3 кг / темно-синій",
    stars: 4.8,
    cost: 1299,
    sale: 10,
    reviews_count: 215,
    preview_img:
      "https://content2.rozetka.com.ua/goods/images/big_tile/597709595.jpg",
  },
  {
    id: 11,
    brand: "Samsung",
    model: "Galaxy Book3 Pro",
    description:
      "Екран 16” AMOLED (2880x1800) / Intel Core i7-1360P / RAM 16 ГБ / SSD 1 ТБ / Intel Iris Xe / Windows 11 / 1.6 кг / сірий",
    stars: 4.3,
    cost: 1599,
    sale: 9,
    reviews_count: 167,
    preview_img:
      "https://content2.rozetka.com.ua/goods/images/big_tile/597709595.jpg",
  },
  {
    id: 12,
    brand: "HP",
    model: "Omen 16",
    description:
      "Екран 16.1” IPS (1920x1080) 165 Гц / AMD Ryzen 7 7840HS / RAM 16 ГБ / SSD 1 ТБ / RTX 4070, 8 ГБ / без ОС / 2.4 кг / чорний",
    stars: 4.5,
    cost: 1899,
    sale: 15,
    reviews_count: 278,
    preview_img:
      "https://content2.rozetka.com.ua/goods/images/big_tile/597709595.jpg",
  },
  {
    id: 13,
    brand: "Acer",
    model: "Swift 5",
    description:
      "Екран 14” IPS (2560x1600) / Intel Core i7-1360P / RAM 16 ГБ / SSD 1 ТБ / Intel Iris Xe / Windows 11 / 1.2 кг / зелений",
    stars: 4.0,
    cost: 999,
    sale: 10,
    reviews_count: 198,
    preview_img:
      "https://content2.rozetka.com.ua/goods/images/big_tile/597709595.jpg",
  },
  {
    id: 14,
    brand: "Gigabyte",
    model: "Aorus 15",
    description:
      "Екран 15.6” IPS (2560x1440) 165 Гц / Intel Core i7-13700H / RAM 16 ГБ / SSD 1 ТБ / RTX 4070, 8 ГБ / без ОС / 2.3 кг / чорний",
    stars: 3.7,
    cost: 1749,
    sale: 12,
    reviews_count: 142,
    preview_img:
      "https://content2.rozetka.com.ua/goods/images/big_tile/597709595.jpg",
  },
  {
    id: 15,
    brand: "Microsoft",
    model: "Surface Laptop 5",
    description:
      "Екран 13.5” PixelSense (2256x1504) сенсорний / Intel Core i7-1255U / RAM 16 ГБ / SSD 512 ГБ / Intel Iris Xe / Windows 11 / 1.3 кг / платиновий",
    stars: 4.4,
    cost: 1299,
    sale: 8,
    reviews_count: 230,
    preview_img:
      "https://content2.rozetka.com.ua/goods/images/big_tile/597709595.jpg",
  },
];

const template = document.querySelector("#card_temp").innerHTML;
let html = "";

laptops.forEach((product) => {
  product.has_sale = product.sale > 0;
  if (product.has_sale) {
    product.new_cost = +(product.cost * (1 - product.sale / 100)).toFixed(2);
  }
  product.bonus = (product.cost / 100).toFixed();
  product.stars_width = product.stars * 20;

  html += Mustache.render(
    document.querySelector("#card_temp").innerHTML,
    product
  );
});

document.querySelector("#prod_list").insertAdjacentHTML("beforeend", html);

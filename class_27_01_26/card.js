const styles = {
  card: {
    width: "240px",
    background: "#fff",
    padding: "8px",
    boxShadow: "0 2px 8px rgba(0,0,0,.08)",
    display: "flex",
    flexDirection: "column",
    position: "relative",
    transition: "box-shadow .2s ease, transform .2s ease",
  },

  like: {
    display: "flex",
    flexDirection: "row",
    justifyContent: "center",
    alignItems: "center",
    width: "24px",
    height: "24px",
    marginBottom: "var(--global-spacer)",
    backgroundColor: "#ffffffb3",
    padding: "0",
    border: "none",
    borderRadius: "var(--global-spacer)",
    cursor: "pointer",
    color: "var(--global-yellow)",
    position: "absolute",
    top: "var(--global-spacer)",
    right: "var(--global-spacer)",
    zIndex: "3",
    fontSize: "28px",
    fontWeight: "200",
  },

  imageWrap: {
    width: "100%",
    height: "180px",
    display: "flex",
    alignItems: "center",
    justifyContent: "center",
    marginBottom: "10px",
  },

  image: {
    maxWidth: "100%",
    maxHeight: "100%",
    objectFit: "contain",
  },

  title: {
    fontSize: "14px",
    fontWeight: "400",
    lineHeight: "1.4",
    height: "40px",
    overflow: "hidden",
    marginBottom: "8px",
    color: "var(--global-black)",
    textDecoration: "none",
    wordBreak: "break-word",
  },

  bottom: {
    marginTop: "auto",
    width: "100%",
  },

  price: {
    fontSize: "20px",
    fontWeight: "700",
    color: "var(--global-black)",
    marginBottom: "6px",
  },

  flags: {
    display: "flex",
    alignItems: "center",
    justifyContent: "space-between",
    gap: "var(--global-spacer)",
    fontSize: "14px",
    lineHeight: "15.4",
    color: "#00a046",
  },
  buySect: {
    display: "flex",
    justifyContent: "space-between",
  },
  cart: {
    width: "32px",
    height: "32px",
  },
  addToCart: {
    width: "32px",
    height: "32px",
    border: "none",
    background: "none",
  },
  smartBtn: {
    width: "max-content",
    height: "24px",
    border: "none",
    background: "none",
  },
  old_price: {
    position: "relative",
    display: "inline-block",
    lineHeight: "1",
    textDecoration: "line-through",
    color: "var(--global-black-60)",
    fontSize: "14px",
    marginBottom: "var(--global-spacer)",
  },
  sale_price: {
    lineHeight: "1",
    fontWeight: "700",
    color: "var(--global-red)",
    fontSize: "20px",
  },
};

function Card(props) {
  return (
    <div className="card" style={styles.card} id={"card_" + props.id}>
      {props.label ? (
        <span
          className="label"
          style={{
            color: props.label.color_font,
            background: props.label.color,
          }}
        >
          {props.label.text}
        </span>
      ) : props.discount ? (
        <span
          className="label"
          style={{
            color: "var(--global-black-5)",
            background: "var(--global-red)",
          }}
        >
          -{props.discount}%
        </span>
      ) : null}

      <button style={styles.like}>♡</button>

      <a href={props.href} style={styles.imageWrap}>
        <img
          src={props.previewImg || "./images/noneImg.svg"}
          alt={props.name}
          style={styles.image}
        />
      </a>

      <a href={props.href} style={styles.title}>
        {props.name}
      </a>

      <section style={styles.bottom}>
        <div style={styles.buySect}>
          {props.oldPrice ? (
            <div>
              <div style={styles.old_price}>{props.oldPrice}₴</div>
              <div style={styles.sale_price}>{props.price}₴</div>
            </div>
          ) : (
            <div style={styles.price}>{props.price}₴</div>
          )}

          <button style={styles.addToCart}>
            <svg
              style={styles.cart}
              viewBox="-2.4 -2.4 28.8 28.8"
              xmlns="http://www.w3.org/2000/svg"
              fill="none"
            >
              <circle cx="7.5" cy="18.5" r="1.5" fill="#00a046" />
              <circle cx="16.5" cy="18.5" r="1.5" fill="#00a046" />
              <path
                stroke="#00a046"
                strokeLinecap="round"
                strokeLinejoin="round"
                strokeWidth="1.5"
                d="M3 5h2l.6 3L7 15h10l2-7H5.6z"
              />
            </svg>
          </button>
        </div>

        <div style={styles.flags}>
          <span>Безкоштовна доставка</span>

          {props.smartPromo && (
            <button style={styles.smartBtn}>
              <img
                src="./images/smart_promo.png"
                alt="smart promo"
                height="16"
              />
            </button>
          )}
        </div>
      </section>
    </div>
  );
}

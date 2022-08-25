## 概要

法が固定されている場合の、いわゆる modint 構造体。法は符号付き 32 bit 整数型の範囲内の正整数である必要がある。 `std::ostream` での出力を除いて、全て `constexpr` である。

## 使い方

`static_modint<mod>` を以下 `mint` とする

### コンストラクタ

- `mint()` : 値 $0$ で初期化。計算量 $\mathrm{\Theta}(1)$ 。
- `template <typename T> mint(T n)` : 値 $n$ で初期化。 $0 \leq n < \mathrm{mod}$ を満たさない場合は適切に変換される。計算量 $\mathrm{\Theta}(1)$ 。

### static メンバ関数

- `int mod()` : 法を `int` 型で返す。計算量 $\mathrm{\Theta}(1)
- `mint raw(int n)` : 値 $n$ で初期化された `mint` を返す。ここで、 `0 \leq n < \mathrm{mod}$ を満たす必要がある。コンストラクタより高速に動くことが期待できる。

### メンバ関数

- `int val()` : 値を `int` 型で返す。計算量 $\mathrm{\Theta}(1)$ 。
- `mint pow(i64 n)` : $n$ 乗を返す。計算量 $\mathrm{\Theta}(\mathrm{mod})$ 。
- `mint inv()` : 逆元を返す。計算量 $\mathrm{\Theta}(\mathrm{mod})$ 。実装は拡張 Euclid の互除法。

### operator

```
+mint
-mint

mint + mint
mint += mint
mint - mint
mint -= mint
mint * mint
mint *= mint
mint / mint
mint /= mint

mint == mint
mint != mint

std::ostream << mint
```

計算量は割り算のみ $\mathrm{\Theta}(\log mod)$ 他は $\mathrm{\Theta}(1)$ 。
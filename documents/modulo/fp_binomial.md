## 概要

`static int mod()` メンバを持つ Modint 構造体をテンプレート引数に持ち、素数 mod 上でのある種の二項演算 (nCr, nPr, nHr 等) に必要な情報を管理する。

## 使い方

`fp_binomial<M>` の static メンバとして基本的な情報が持たれる。

### static メンバ関数

- `mint fact(int n)` : $n!$ を返す。
- `mint inv(int n)` : $n$ の逆元を返す。
- `mint inv_fact(int n)` : $n!$ の逆元を返す。

計算量は、いずれもアクセスされる最大の $n$ を $x$ として合計 $\mathrm{\Theta}(x)$ となる。

- `mint comb(int n, int r)` : $n\mathrm{C}r$ を返す。
  - 制約 : $0 \leq r \leq n$
- `mint perm(int n, int r)` : $n\mathrm{P}r$ を返す。
  - 制約 : $0 \leq r \leq n$
- `mint homo(int n, int r)` : $n\mathrm{H}r$ を返す。
  - 制約 : $n = r = 0 \lor (n > 0 \land r >= 0)$

計算量は、いずれもアクセスされる最大の $n, r$ を $x$ として合計 $\mathrm{\Theta}(x)$ となる。

### 注意
空間も $\mathrm{O}(n)$ 必要。
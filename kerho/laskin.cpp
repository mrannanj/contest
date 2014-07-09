#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

struct Frac {
  Frac(): a(0), b(0) {}
  Frac(ll num, ll den): a(num), b(den) {
    ll d = gcd(abs(a), abs(b));
    a /= d;
    b /= d;
  }
  Frac(string num, string den): a(atoll(num.c_str())), b(atoll(den.c_str()))
  {
  }
  ll a;
  ll b;
};

istream& operator>>(istream& is, Frac& m) {
  char c;
  ll a;
  ll b;

  is >> a >> c >> b;
  m.a = a;
  m.b = b;
  return is;
}

ostream& operator<<(ostream& os, const Frac& m) {
  ll a = m.a;
  ll b = m.b;
  return os << a << "/" << b;
}

Frac operator-(const Frac& m1, const Frac& m2) {
  Frac r;
  r.a = m1.a*m2.b - m2.a*m1.b;
  r.b = m1.b * m2.b;
  ll d = gcd(abs(r.a), abs(r.b));
  r.a /= d;
  r.b /= d;
  return r;
}

Frac operator+(const Frac& m1, const Frac& m2) {
  Frac r;
  r.a = m1.a*m2.b + m2.a*m1.b;
  r.b = m1.b * m2.b;
  ll d = gcd(abs(r.a), abs(r.b));
  r.a /= d;
  r.b /= d;
  return r;
}

Frac operator*(const Frac& m1, const Frac& m2) {
  Frac r;
  r.a = m1.a * m2.a;
  r.b = m1.b * m2.b;
  ll d = gcd(abs(r.a), abs(r.b));
  r.a /= d;
  r.b /= d;
  return r;
}

Frac operator/(const Frac& m1, const Frac& m2) {
  Frac r;
  r.a = m1.a * m2.b;
  r.b = m1.b * m2.a;
  ll d = gcd(abs(r.a), abs(r.b));
  r.a /= d;
  r.b /= d;
  return r;
}

Frac abs(Frac m) {
  if (m.a < 0) {
    m.a = -m.a;
  }
  if (m.b < 0) {
    m.b = -m.b;
  }
  return m;
}

bool operator<(const Frac& m1, const Frac& m2) {
  return (m1 - m2).a < 0;
}

enum class Token {
  NUMBER,
  PLUS,
  DIV,
  MUL,
  MINUS,
  LPAREN,
  RPAREN,
  END
};

enum class State {
  INIT,
  NUMBER
};

struct Terminal {
  string s;
  Token t;
};

size_t p = 0;
vector<Terminal> ts;

Frac s1();
Frac s2();
Frac s3();

Frac s2() {
  assert(p + 2 < ts.size());
  assert(ts[p].t == Token::NUMBER);
  assert(ts[p+1].t == Token::DIV);
  assert(ts[p+2].t == Token::NUMBER);
  Frac r(ts[p].s, ts[p+2].s);
  p += 3;
  return r;
}

Frac s3() {
  assert(ts[p].t == Token::LPAREN);
  ++p;
  Frac r = s1();
  assert(ts[p].t == Token::RPAREN);
  ++p;
  return r;
}

Frac s1() {
  Token op;
  Frac r;
  switch (ts[p].t) {
    case Token::NUMBER:
      r = s2();
      break;
    case Token::LPAREN:
      r = s3();
      break;
    case Token::MINUS:
      p++;
      r = Frac(-1, 1) * s1();
      break;
    default:
      cout << "fail" << endl;
      abort();
  }
  while (true) {
    switch (ts[p].t) {
      case Token::END: case Token::RPAREN:
        return r;
      case Token::PLUS:
        ++p;
        r = r + s1();
        break;
      case Token::MINUS:
        ++p;
        r = r - s1();
        break;
      case Token::MUL:
        ++p;
        r = r * s1();
        break;
      case Token::DIV:
        ++p;
        r = r / s1();
        break;
      default:
        cout << "only +-*/ operators supported" << endl;
        abort();
    }
  }
}

int main() {
  string s;
  State state = State::INIT;

  string line;
  getline(cin, line);

  for (char c : line) {
    switch (state) {
      init: state = State::INIT;
      case State::INIT:
        s.clear();
        if (c >= '0' and c <= '9') {
          s.push_back(c);
          state = State::NUMBER;
        } else if (c == '+') {
          ts.push_back({"+", Token::PLUS});
        } else if (c == '/') {
          ts.push_back({"/", Token::DIV});
        } else if (c == '*') {
          ts.push_back({"*", Token::MUL});
        } else if (c == '(') {
          ts.push_back({"(", Token::LPAREN});
        } else if (c == ')') {
          ts.push_back({")", Token::RPAREN});
        } else if (c == '-') {
          ts.push_back({"-", Token::MINUS});
        }
        break;
      case State::NUMBER:
        if (c >= '0' and c <= '9') {
          s.push_back(c);
        } else {
          ts.push_back({s, Token::NUMBER});
          goto init;
        }
        break;
    }
  }
  if (state == State::NUMBER) {
    ts.push_back({s, Token::NUMBER});
  }
  ts.push_back({"$$", Token::END});

  Frac m = s1();
  cout << m << endl;
}

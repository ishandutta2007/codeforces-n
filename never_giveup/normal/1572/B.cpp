/*
                     .:*+=%@@@@@@=-.
                 .:=@#@@@#@@#######%==*.
              .-=####@######%*-.....:%##%.
            .*@###########%+:--........-%@-
          .*@##############@+--.........-:%-
        .+##################@==%%%%=+*:----+.
      .-@####################%++%@@@@@=+**%@@*
      .%###################@%%@@@###@%+:--%@@%.
     -@###################@%%%%*::*%++:-----=@+.
    -#####################@%=++++++*:-------.-=:
   .+####################@%++*::-:::--::*:::***=:
   .@#####################%=++*::::-:::++*=##@@#@-
  ..#####################@%%=++**:::::**+%@#@%%##-..
   .%####################@@%=+++*+****::*=@######@.
  .=######################@%%==+==++**+=@%@##@###+:...
  -#######################@@@%%%===++=@@@%=++===*::--...
  -########################@@@@@@@%==%%=++==@@:::::*:--.
..:#########################@@@@@@%%======++++::-..:-.--...
%#############################@###@%%@@%==%=%*----.--.::---.
#############################################*-:*:-:---*---- .
#############################################*--*--:---*---:-.
#############################################+--::--::-*::-::.
###########################################+:*-.---.---.:---*-..
###########################################**:-----------------.
##########################################@::**:--::::::--:::::-
###########################################:--:*:::::::::**::*+*
###########################################=:::***::::::**:::*+*
############################@@@@@@#########@+****::::********+++
############################@%%%%%@@@@@@@###%+***::::::::***+==+
############################@%%%%%%%%%%%@####=+:::-::::-::*+=%%+
#############################@%%%%%%%%%%@#####=::--------:*=%@%+
%###########################@%%%%==%%%%%%@##@#=:------..-:+%@@%=
----------------------------------------------
--------------------------------------------
----------------------------------------------
--------------------------------------------
----------------------------------------------

         o###########oo
      o##"          ""##o
    o#"                "##
  o#"                    "#o
 #"  ##              ##   "##
#"                          ##
#  ###################       #
#                            #
#                            #
#                            #
#                            #
#                            #
#                            #
#o                           #
"#o                         ##
 "#o                       ##
  "#o                    o#"
   "#o                  ##
     "#o              o#"
       "#ooo      ooo#######oo
        ###############   "######o
     o###""        "###o      # ###
   o###o     oooo    ###    oo####"
 o###**#     #**#   ############"
 ""##""""""""""###########    #
    # oooooooo#"#**     ##    #
    # #       # # **    ##    #
    #o#       #o#  *****###ooo#
                        ##
                        ##   o###o
                        ## o##***##
               o########## #***#**##o
             o##"   ""###  #***##***#
 o#######o  ###   oo####   ##**####*#
o##"  ""#############""     ##****###
##"         ##              ##*##*###
##          ###              ##### ##
##           ###              # ##  #
##            ##                 #
##             ##
##             ###
##              ###oo
###              ""###
 ###
  ###
*/
#ifndef ONPC
//#pragma GCC optimize("Ofast,no-stack-protector")
#endif
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("fast-math")
//#pragma GCC target("avx2")
// if avx2 not supported, use this instead
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

// something
//#pragma GCC optimize("O3","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("avx")  //Enable AVX

#include <bits/stdc++.h>

#ifdef ONPC
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-const-variable"
#endif
#define all(x) (x).begin(), (x).end()
#define fr first
#define sc second
#define m_p make_pair
#define unique(a) a.resize(unique(a.begin(), a.end()) - a.begin())
#define low_bo(a, x) ((int)(lower_bound(a.begin(), a.end(), x) - a.begin()))
#define up_bo(a, x) ((int)(upper_bound(a.begin(), a.end(), x) - a.begin()))
#define unique(a) a.resize(unique(a.begin(), a.end()) - a.begin())
#define popcnt(x) __builtin_popcount(x)
#define shuffle(a) shuffle(a.begin(), a.end(), rnd)

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

using namespace std;

/*
const int MEMSIZE = 5e8;
char memory[MEMSIZE];
int memorypos;
inline void * operator new(size_t n){
    //assert (memorypos + n < MEMSIZE);
    if (memorypos + n >= MEMSIZE)
        memorypos = MEMSIZE / 3;
    char * ret = memory + memorypos;
    memorypos += n;
    return (void *)ret;
}
inline void operator delete(void *){}
*/

using ll = long long;

#ifndef ONPC
#define cerr cerr_maksim
struct Cerr : public ostream {
    template<typename T>
    Cerr& operator<<(T const&) {
        return *this;
    }
} cerr;
#endif

#ifdef ONPC
mt19937 rnd(223);
mt19937_64 rndll(231);
#else
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rndll(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif


template<typename T>
void setmin(T &x, T y) {
    x = min(x, y);
}

template<typename T>
void setmax(T &x, T y) {
    x = max(x, y);
}

#define TIME (clock() * 1.0 / CLOCKS_PER_SEC)

namespace Ment {
    template<typename T>
    T inverse(T a, T m) {
        T u = 0, v = 1;
        while (a != 0) {
            T t = m / a;
            m -= t * a;
            swap(a, m);
            u -= t * v;
            swap(u, v);
        }
        assert(m == 1);
        return u;
    }

    template<typename T>
    class Modular {
    public:
        using Type = typename decay<decltype(T::value)>::type;

        constexpr Modular() : value() {}

        template<typename U>
        Modular(const U &x) {
            value = normalize(x);
        }

        template<typename U>
        static Type normalize(const U &x) {
            Type v;
            if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
            else v = static_cast<Type>(x % mod());
            if (v < 0) v += mod();
            return v;
        }

        const Type &operator()() const { return value; }

        template<typename U>
        explicit operator U() const { return static_cast<U>(value); }

        constexpr static Type mod() { return T::value; }

        Modular &operator+=(const Modular &other) {
            if ((value += other.value) >= mod()) value -= mod();
            return *this;
        }

        Modular &operator-=(const Modular &other) {
            if ((value -= other.value) < 0) value += mod();
            return *this;
        }

        template<typename U>
        Modular &operator+=(const U &other) { return *this += Modular(other); }

        template<typename U>
        Modular &operator-=(const U &other) { return *this -= Modular(other); }

        Modular &operator++() { return *this += 1; }

        Modular &operator--() { return *this -= 1; }

        Modular operator++(int) {
            Modular result(*this);
            *this += 1;
            return result;
        }

        Modular operator--(int) {
            Modular result(*this);
            *this -= 1;
            return result;
        }

        Modular operator-() const { return Modular(-value); }

        template<typename U = T>
        typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type &
        operator*=(const Modular &rhs) {
#ifdef _WIN32
            uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
            uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
            asm(
            "divl %4; \n\t"
            : "=a" (d), "=d" (m)
            : "d" (xh), "a" (xl), "r" (mod())
            );
            value = m;
#else
            value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
            return *this;
        }

        template<typename U = T>
        typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type &
        operator*=(const Modular &rhs) {
            int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
            value = normalize(value * rhs.value - q * mod());
            return *this;
        }

        template<typename U = T>
        typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type &
        operator*=(const Modular &rhs) {
            value = normalize(value * rhs.value);
            return *this;
        }

        Modular &operator/=(const Modular &other) { return *this *= Modular(inverse(other.value, mod())); }

        template<typename U>
        friend bool operator==(const Modular<U> &lhs, const Modular<U> &rhs);

        template<typename U>
        friend bool operator<(const Modular<U> &lhs, const Modular<U> &rhs);

        template<typename U>
        friend std::istream &operator>>(std::istream &stream, Modular<U> &number);

    private:
        Type value;
    };

    template<typename T>
    bool operator==(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value == rhs.value; }

    template<typename T, typename U>
    bool operator==(const Modular<T> &lhs, U rhs) { return lhs == Modular<T>(rhs); }

    template<typename T, typename U>
    bool operator==(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) == rhs; }

    template<typename T>
    bool operator!=(const Modular<T> &lhs, const Modular<T> &rhs) { return !(lhs == rhs); }

    template<typename T, typename U>
    bool operator!=(const Modular<T> &lhs, U rhs) { return !(lhs == rhs); }

    template<typename T, typename U>
    bool operator!=(U lhs, const Modular<T> &rhs) { return !(lhs == rhs); }

    template<typename T>
    bool operator<(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value < rhs.value; }

    template<typename T>
    Modular<T> operator+(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) += rhs; }

    template<typename T, typename U>
    Modular<T> operator+(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) += rhs; }

    template<typename T, typename U>
    Modular<T> operator+(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) += rhs; }

    template<typename T>
    Modular<T> operator-(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) -= rhs; }

    template<typename T, typename U>
    Modular<T> operator-(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) -= rhs; }

    template<typename T, typename U>
    Modular<T> operator-(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) -= rhs; }

    template<typename T>
    Modular<T> operator*(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }

    template<typename T, typename U>
    Modular<T> operator*(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) *= rhs; }

    template<typename T, typename U>
    Modular<T> operator*(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }

    template<typename T>
    Modular<T> operator/(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }

    template<typename T, typename U>
    Modular<T> operator/(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) /= rhs; }

    template<typename T, typename U>
    Modular<T> operator/(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }

    template<typename T, typename U>
    Modular<T> power(const Modular<T> &a, const U &b) {
        assert(b >= 0);
        Modular<T> x = a, res = 1;
        U p = b;
        while (p > 0) {
            if (p & 1) res *= x;
            x *= x;
            p >>= 1;
        }
        return res;
    }

    template<typename T>
    string to_string(const Modular<T> &number) {
        return to_string(number());
    }

    template<typename T>
    std::ostream &operator<<(std::ostream &stream, const Modular<T> &number) {
        return stream << number();
    }

    template<typename T>
    std::istream &operator>>(std::istream &stream, Modular<T> &number) {
        typename common_type<typename Modular<T>::Type, int64_t>::type x;
        stream >> x;
        number.value = Modular<T>::normalize(x);
        return stream;
    }

    constexpr int md = 1e9 + 7;
    using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
}
using Ment::Mint;
//using Mint = double;

/*
using namespace Ment;
using ModType = int;
struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;
*/

// WARNING!!!!!!
// Maksim reads solution
// be careful!!!!

// solution starts here

/*

const int Mo = 1e9 + 7;

int ad(int x, int y) {
    return (x + y) % Mo;
}

int mul(int x, int y) {
    return x * (ll)y % Mo;
}

int dif(int x, int y) {
    return (x - y + Mo) % Mo;
}
 */

using ld = double;

const ll llinf = 1e18 + 100;

const int maxn = 2e5 + 100, maxw = 5e6 + 10, inf = 1e9 + 100, LG = 20, SQ = 450;

void solve() {
    int n;
    n = rnd() % 15 + 1;
    cin >> n;
    //cerr << n << '\n';
    vector<int> a(n);
    int tot = 0, sus = 0;
    for (int &i : a) {
        i = rnd() & 1;
        cin >> i;
        //cerr << i << ' ';
        tot ^= i;
        sus += i;
    }
    //cerr << '\n';
    if (tot == 1 || sus == n) {
        cout << "NO\n";
        return;
    }
    vector<int> ans;
    auto add = [&](int i) {
        assert(i >= 0 && i + 2 < n);
        int x = (a[i] ^ a[i + 1] ^ a[i + 2]);
        a[i] = a[i + 1] = a[i + 2] = x;
        ans.push_back(i);
    };
    auto kill = [&](int l, int r) -> bool {
        if (l > 0) {
            for (int t = l; t + 1 <= r; t += 2) {
                add(t - 1);
                a[t] = a[t + 1] = 0;
            }
        } else if (r + 1 < n) {
            for (int t = r - 1; t >= l; t -= 2) {
                add(t);
                a[t] = a[t + 1] = 0;
            }
        } else {
            cout << "NO\n";
            return 0;
        }
        return 1;
    };
    pair<int, int> last = {-1, -1};
    for (int i = 0; i < n; i++)
        if (a[i] == 1) {
            if (last.fr == -1) {
                last.fr = i;
                while (i < n && a[i] == 1)
                    i++;
                last.sc = i - 1;
                i--;
                if ((last.sc - last.fr + 1) % 2 == 0) {
                    if (!kill(last.fr, last.sc))
                        return;
                    last.fr = last.sc = -1;
                }
                continue;
            }
            pair<int, int> seg;
            {
                seg.fr = i;
                while (i < n && a[i] == 1)
                    i++;
                seg.sc = i - 1;
                i--;
            }
            // last.fr != -1
            if ((seg.fr - last.sc) % 2 == 0) {
                //odd 0s
                for (int t = last.sc; t + 2 != seg.fr; t += 2)
                    add(t);
                add(seg.fr - 2);
                for (int t = seg.fr - 3; t > last.fr; t -= 2)
                    add(t - 1);
                int tot = seg.sc - last.fr + 1;
                for (int t = seg.fr + 1; t + 1 <= seg.sc; t += 2)
                    add(t - 1);
                if (tot % 2 == 1)
                    last = {-1, -1};
                else
                    last = {seg.sc, seg.sc};
            } else {
                //even 0s
                for (int t = last.sc; t + 1 != seg.fr; t += 2)
                    add(t);
                last.sc = seg.sc;
                if ((last.sc - last.fr + 1) % 2 == 0) {
                    if (!kill(last.fr, last.sc))
                        return;
                    last.fr = last.sc = -1;
                }
            }
        }
    assert(last.fr == -1);
    assert(ans.size() <= n);
    for (int i = 0; i < n; i++)
        assert(a[i] == 0);
    cout << "YES\n";
    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i + 1 << ' ';
    cout << '\n';
}
// check test counter

int main() {
#ifdef ONPC
    freopen("../a.in", "r", stdin);
    freopen("../a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout.precision(20);
    //precalc();
    if (false) {
        int te = 0;
        while (1) {
            cerr << "ts " << ++te << '\n';
            solve();
        }
    }
    int ts;
    ts = 1;
    cin >> ts;
    for (int its = 1; its <= ts; its++) {
        cerr << "\nts " << its << '\n';
        //cerr << "\n\nConsumed " << TIME << '\n';
        //cout << "Case #" << its << ": ";
        solve();
    }
#ifdef ONPC
    cerr << "\n\nConsumed " << TIME << '\n';
#endif
}
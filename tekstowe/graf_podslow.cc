// Tomasz Nowak
// Graf Podsłów / Automat Suffixowy (Suffix Automaton)

// linki:
// http://codeforces.com/blog/entry/20861
// http://codeforces.com/blog/entry/22420 ( https://drive.google.com/file/d/0B0BBPCmtPbIcbVFsSG9qeTI1TjA/view )
// https://saisumit.wordpress.com/2016/01/26/suffix-automaton/
// http://e-maxx.ru/algo/suffix_automata (najlepsze, ale po rusku. Dwa powyższe linki mocno bazują na tym)


// benchmarki konstrukcji
// sprawdzane jest co należy używać jako Node
// długość słowa 10^7, sprawdzane na moim kompie (czyli na szybkim)

// wielkość alfabetu: 2
// mapa:              15.0s
// unordered_mapa:    14.4s
// std::array:         4.4s

// wielkość alfabetu: 26
// mapa:               7.0s
// unordered_mapa:    10.8s
// std::array:         4.4s

// wniosek: jak wielkość alfabetu <= 26, używaj std::array

// jakieś customowe wielkości alfabetu sami sobie sprawdzajcie, macie kod:


#include <bits/stdc++.h>
using namespace std;

struct SuffixAutomaton {
    static constexpr int sigma = 26;  // wielkość alfabetu
    using Node = array<int, sigma>;
    Node new_node;  // wskazuje na same minus jedynki (stany nieistniejące)

    vector<Node> edges;
    vector<int> link, length;
    int last = 0;   // "ostatni" stan, czyli stan reprezentujący całe słowo

    void add_letter(int c) {
        edges.emplace_back(new_node);               // dodajemy nowy stan, i na początku uznajemy, że
        length.emplace_back(length[last] + 1);      //   suffix link idzie do wierzchołka startowego 
        link.emplace_back(0);                       //   (być może potem to trzeba będzie poprawić)

        int r = int(edges.size()) - 1, p = last;    // r - właśnie dodany stan
        while(p != -1 && edges[p][c] == -1) {       // przechodzę po ścieżce suffix linków 
            edges[p][c] = r;                        //   do stanu startowego (czyli przechodzę po stanach końcowych)
            p = link[p];                            //   i, jak się da, dodaję nowe krawędzie do r
        }
        if(p != -1) {                               // doszliśmy do stanu, który ma już krawędź z literą c
            int q = edges[p][c];
            if(length[p] + 1 == length[q])          // można przyczepić suffix linka r do q (prostszy przypadek)
                link[r] = q;                        //   i nic więcej nie robimy
            else {
                edges.emplace_back(edges[q]);       // klonujemy stan, by stworzyć taki, by można było go zlinkować z r
                length.emplace_back(length[p] + 1);
                link.emplace_back(link[q]);
                int q_prim = int(edges.size()) - 1; // q' - właśnie dodany stan

                link[q] = link[r] = q_prim;         // komentarze już są bezużyteczne, jest to najtrudniejsza część,
                while(p != -1 && edges[p][c] == q) {//   trzeba to samemu zrozumieć, narysować, przemyśleć... :/
                    edges[p][c] = q_prim;
                    p = link[p];
                }
            }
        }
        last = r;
    }

    SuffixAutomaton(vector<int> &v) {
        new_node.fill(-1);     // -1 - stan nieistniejący
        edges = { new_node };  // dodajemy stan startowy, który reprezentuje puste słowo
        link = { -1 };
        length = { 0 };

        for(int c : v)
            add_letter(c);     // dodajemy kolejno literki naszego słowa do automatu
    }

    SuffixAutomaton(string) {
        // sami sobie piszcie taki durny konstruktor, lol.
        //   (w tekstówkach, zawsze zmieniam stringa od razu na vectora intów)
    }

    bool is_inside(vector<int> &s) {  // prosta, przykładowa funkcja, która sprawdza,
        int q = 0;                    // czy dane słowo jest podsłowem naszego słowa
        for(int c : s)
            if(edges[q][c] == -1)
                return false;
            else
                q = edges[q][c];
        return true;
    }
};

int main() {
    string str;
    cin >> str;

    vector<int> s(str.size());
    for(int i = 0; i != int(str.size()); ++i)
        s[i] = str[i] - 'a';

    auto start = chrono::steady_clock::now();

    SuffixAutomaton automat(s);

    auto end = chrono::steady_clock::now();
    cout << "czas wykonania: " << chrono::duration<double, milli>(end - start).count() << endl;

    for(int v = 0; v <= automat.last; ++v)
        for(int i = 0; i < automat.sigma; ++i)
            if(automat.edges[v][i] != -1)
                cout << v << " -> " << automat.edges[v][i] << " (przez krawedz " << char(i + 'a') << ")\n";
}

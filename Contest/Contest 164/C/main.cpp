//
//  main.cpp
//  Contest 164
//
//  Created by 边俊林 on 2019/11/24.
//  Copyright © 2019 边俊林. All rights reserved.
//

#include <map>
#include <set>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Node *root = new Node();
        for (auto& prod: products)
            buildTrie(root, prod, 0);
        pCurr = root;

        vector<vector<string>> res;
        for (char ch: searchWord)
            res.push_back(type(ch));
        return res;
    }

private:
    struct Node {
        int cnt = 0;
        vector<Node*> nodes = vector<Node*>(26, NULL);
    };

    Node *pCurr;
    string pres = "";

    vector<string> type(char ch) {
        if (pCurr == NULL || pCurr->nodes[ch-'a'] == NULL)
            pCurr = NULL;
        else
            pCurr = pCurr->nodes[ch-'a'];

        pres += ch;
        vector<string> recs = vector<string>();
        getRecomment(recs, pCurr, pres);
        return recs;
    }

    void getRecomment(vector<string>& res, Node* pNode, string curs) {
        if (res.size() >= 3 || pNode == NULL) return;
        if (pNode->cnt > 0) {
            for (int i = 0; i < pNode->cnt && res.size() < 3; ++i)
                res.push_back(curs);
        }

        for (int i = 0; i < 26; ++i) {
            if (pNode->nodes[i] != NULL)
                getRecomment(res, pNode->nodes[i], curs + (char)(i+'a'));
            if (res.size() >= 3) return;
        }
    }

    void buildTrie(Node* pNode, string& word, int idx) {
        if (idx == word.length()) {
            pNode->cnt++;
            return;
        }

        int dig = word[idx] - 'a';
        if (pNode->nodes[dig] == NULL)
            pNode->nodes[dig] = new Node();
        buildTrie(pNode->nodes[dig], word, idx+1);
    }
};

int main() {
    Solution sol = Solution();
    vector<string> strs = {
        "mobile","mouse","moneypot","monitor","mousepad"
//        "havana"
//        "bags","baggage","banner","box","cloths"
//        "eucgsmpsyndddijvpxfagngnjbzxuajxmrmszwtjvwswgdrojt","mervtkzsouapfbky","eucgsmpsyndddijvpxfagngnjbzxuajxnzjk","eduvadjohhskmyzipulgjeat","eucgsnatcadpbcyrxlgldpcaijmnojdkjqfwxkz","eucgsmpsynevhpeoqwbgdidv","yvu","eucgsmpsyndddijvpxfagnbjthdmywjcmbmgpfrvwhdarjske","eixctybvrnuyqibnpxpbcpcqcq","eucgsmpsyndddijvpxfagngnjrcnbbwae","lrvlimn","eucgsmpsyndddijvpxfagngnjbzgsidschcqhm","thhnadanjkbrcnofgpdfthvcodrmrezulkuytrqosqaooecqom","eucgsmpsyndddijvpxfagngwcpixbrkupusfqoyihroghoae","eucgsmpsyndddijvpxmmydswjxsdmer","fhfhindvjohibmsoipvdyedlxoinlumjlb","lsuinsmrgxxhswxshvogzxojsbvhzbcioldypag","ptbyxfktngjsofvicpvsmyqddacyahf","yjhiemwpwfpyewvcfbtljsrwlfiihwisqekfoearodlvhoejq","atoygkvdbdvmuukgfjnufsnhjcsaxk","eucgsdwqeaslgrthiruatrpulqyjgmsbdljebf","eucgsmpsyndddijvpxpcyrilzawoid","eucgsmpsyndddijvpxfagngnjbhvxvjmecfdqzpokhzpqdo","faoywdrvlgacdcfj","eucgsmpsynddwdgwnssfvds","eucgsmpsyndqgjneynofkuebob","asafyzzpxlltqyscywuahwinwijuccwnd","eucgsmpsyndddiznbxfvpqei","eucgsmpsyndddijvpximqtdtlybvziqhdvowuijbkurk","hvxmdjutynhrxyubizbyjwwxfpvblzxvfrca","eucgsu","jhckeuhdvbfdzmyjbjcfariwejezwhtzojeyhxjwegqgrl","eucgsmpsyndddijvpxfagngnjsjjbob","eucgsmpsyndddijvpxfdtbeujjoeqvezdjmopfcmzohuantaid","eucgsmpsyndddijvpxfagngnjbzxuajxmrmszloha","eucgsmpsyndddijvpxfagngnjbzxuajlkwhlwhuwmyagdvymu","jdskdhwkehgqazzweqyzmqzsikjnwgylnhgugjixyrpmyrs","eucgsmpsdney","sasmjvaqjrrovkxqccfpqyruscxgzkbeekz","eucgsmpsyndddijvpxfagngnjbzxuajxmrmszwtjjofldab","eucgsmpsyndddijvpxfagngnjbzxuajxmrmszwtjvwswgdros","ekszgjqykwcwatzrzykatpxcasaifohwrrhipm","shfcpdjhktwfcqezsabkzyzyuibxpzxggnxgcwflloucbgodpm","tpcxhiehypiqtaxzdjxhofufucblqvkoqhlgxgozolaelf","swtrepxomxqemgodrupgigvpxxgptmilfkmzhfnr","dcvzdk","eucgsmpsyndddijvpxfagngnjbzxuajxmrmssckqdpjjasnms","nknhhv","eucgsmpsyndddijvpxfagngnjbzxuajxmrmszwtjvwjyi","qrsqrmqtpajtewxiegcevy","eucgsmpsyndddijvpxfagnfqcq","eucgsmpsyndddijvpxfagngnjbzxuajxmicjxmxhnrxbbczh","eucgshcaieewetzvzwigqfrlwpy","ogubeczu","eucgsmpsyndddijvpxfagngnjbzxuavqyzgaeyi","eucgsmpsyndddijvpxfagngnjbzxuajxmonbleriwyuvlnsfzt","jhz","eucgsmpsyndddijvpxfagngnjbzxuajxmrmszwtjvwswgdroje","xasvjrkqyxory","eucgsmpsyndddijvpxfagngnjbzxuajxmrmszwtjvwsehufy","eucgsmpsyndntjxkzpjstoke","eucgsmpsyndddijvpxfagngnjbzxuajxmrmszhwsbfrppvadx","eucgsmrczev","eucgsmpsyndddijvpxfagngnjbzxuafelaasrnq","eucgsmpsyndddijvpxohsjopdnlnlhksjadjvuvroybu","gnntehraxahinoyqdrspmjaunucrzw","roqdenkakwsbkcbkijyrpfdehrfj","eucgsmpsyndddijvpxfagngnjbzxuajxmrmszwtjvwswgusf","eucgsmpsyndddijvpxfagngnjbjkffxzscalu","eugyortzihuywhfyrwubdfuomvcjudxtappednlohmxz","eucgsmpsyndddijvpxfagngnjbzxuajxmrmszwtjvwswq","eucjqsqvatpjbfvhowkaagxyidiyymapdumaxgoqgbpwsu","eucgsmpsyndddijvpxfagngnjbzxuajxmrmszwtjvwswgdrk","es","eucgsmpsyndddijvpxfagngnjbzxuajxmrmszwtjvwswgdwv","kbninamhdqpoyzznnsqxzmieqajsqrjocrqbmfhwomstdc","jbwggbwtybranddatuybnzre","ludoupnbvsxksvmtaxuuiymidzotziwbqaclvvk","eucgsmpsyndddijvpxfagngnsgpnllzgpyirgem","eucgsmpsyndddijvpxfagngnjbzxuajxmrmszwtebvruvqmpx","nwbqryotfdaopywffjbikuqzraabwngcicsufkeerbpnfyi","eucgsmpsyndddijvoaevblhxotmowpxwpuhzmemw","eucgsmpsyndddijvpxfagngnjbzxuajxmrmszwtjvwswgu","eucgsmpsyndddijvpcfjbzthtculbzszzfaroncw","grygljuxydgpoygjoemajbkaqmbwyverlruejnigqdsvdpwm","eucgsmpsyomtefhlwqluqgcckz","eucijltqylixpvjwtlhurqdseysduhivw","eucgsmpsyndddijvpxfagngnjbzxuajxmrbcm","zibchozkzyhdsmfcryjyzkzgyohjs","yiuxtmtzrnnitnpzyfgfctnlednanfwtjplvueab","eucgsmpsyndddijvpxfagngnjbzxuajxmrmszwtjvwslgknojn","eucgsmpsyndddijvpxfagngnjbxzehobuljrngufbcks","bwbbmbvwzegxmqhdmufnvwpwtykmdvwngqtdwym","eucgsmpsyndddijvpxfagnoezpyieslubwxeobrnktvnpinamb","eucgsmpslmkdakhg","eucgsmczlqunsmfbrodtrtevmuflaf","rpofbqaryrhmqzqkzrmhhsmtgfecva","pmvfbplrjqcmxlpypswxgqemjpxmwmswesrhwmicumoilapzhy","eucgsmpsyndddezzokejvhvdmsoaaoowwottmw","rmvmikeynztayityavakrt","tdeypjrxduem","fqvsmpnzkzuubhuwchdqy","eucgsmpsyoesekvyqvtmymaplhzynaupevoihscjkrjtcj","eucgsmpsyndddijvpxfagngnjbzxjh","jghjdzajfpvyesz","eucgsmpsyndddijvpxfagngnjbzxlmymsyqvaojj","eucgsmpsyndddijvpxfagngnjbzxuajxmrmszwdetn","eunahmcfpnnjavmduowjntsgo","eucgsmpsyndddijvpxfagngnjbzqinqttopi","ubgzjxnomgcnrbbhyppemgyejbycpgamympgupaetudz","mtuindengcxqg","eucgdxsvzyxpbwtnqmzundoosvddromqhydyyjich","eucgsmpsyndddijvpxfagngnjbzxuajxmrmszwtjvwswgkqoyw","eucgsmpsyndddijvpxfagngnjbzxuajxmrmszwtjvwswgdrog","eucgsmpsyndddijvpxfagnpcl","eucgsmpsyndddijvpxfagngnjbzjegcxjcrslyvgbd","nhb","eucgsmpsyndddijvpxfagngnjbzxuajxmrmszwtjvwsudaj","vnyfkvdguu","eucshaijqdl","eucgsmpsyndddijvpxfagngnjbzxuyxowpbndxvxayzxfp","fvgk","eucgsmpslzukdhnbtmsycj","wvpelpocfsodafurhbgbytnta","eucgsmpsyndddijvpxfagngnjbzzetehbbepo","eucgsmpsyndddijvpxfagngnjbzxuajxmrmszwtjvwswgdayg","eucgsmpsyndddijvpxfagngnjbzxuajxjtkkz","knhrz","eucgsmpsyndddijvpxfagngnjbzxuyretdzgzkqaep","eucgsmpsyndddijvpxfagngnjbzxuajxmgi","eucgdjnclcqogrzxi","clliyxtdxzwwz","eucgsmpsyndddijvpxfagngnjbzxuajxmrmszwtjvvev","sugaphcopoyjzoxdpznrkrgjzcfdddvcktwxukcnan","eucgsmpsyndddijvpxfagngnjbzxuajxmrmszwtjvwswgdrojp","vwavfxqerifzseyfefbchueoadvcoximlvowsndrwxspqsn","ejafexrgcikuqefkvlfe","eucgsmpsyndddijvpxfaiuejxgpzbirbus","eucgsmpsyndddijvpxfagngnjbzzdo","bgtdtziavmvfbkexrmqzojkdrapfbljxghlesmflzvgxrooc","eucgsmpsyndddijvpxfagludvrubjhfhn","jsposqsidurgsqjwkabv","eucgsmpsyndddijvpxfagnplbcjevfnfaezqcijiixrrcd","wdhaxpoe","nkj","eucgsmpsyndddijvpxfagngnjbzxuajxmweazgncksq","eucgsmpsyndddijvpxfagnyxks","bouogc","eucgabxhtbnohgmunhrospjzqozczhowc","udcilqgipfjswuscpxtbgqancfolgqbvfvrzsy","eucgsmpsyndddijvpcdswmsvlekrtarkybjwovevieve","zkwfbyawpokgpnzzikaybfosdbqjmkdthsyoojb","gabgl","bkyxlqjgdsuhzbpvtnaobudwsrjqvceliadetviiar","eucgsmpsyndddijvpxfagngnjbzxuajxqqdlwpeyxgtuvbfqj","eucgsmpsyndddijvpxfagngnjbzxuajxmrmszwtjvwswwvy","ryxcr","eucgsmpsyndddijvpxfagngnjbzvrkbgrrtcpbqvlktqwwxxn","eucgsmpsyndddijfagrxzrdg","eucgsmhsnicnajhcaca","revsyodsujynljmd","fficqqokrlkfwsbosapqvaurdk","eucgudniqtxzmtschgm","eucgsmpsyncxbvicmuafacp","eucgsmpsyndddijvpxfagngnjbzxuajxmrmszwtjvwswgjrp","qvjbtmibwikrugaeihweuumhajcffcurgn","eucgsmpsyndddijvpxfagngnjbzxuajxmrmszwtjvwswgdcum","jolquz","eucgsmpsyndddijvpxfagngnjbzxuajxmrmszwtjyfpyyv","eucgsmpsyndddijvpxfagngnjbzxubimdvzlcpv","mesisdbvntasidlsnpbyrv","aekcjkuqrjfujvztrpiksbkegngbilgshwdgmfxz","fcmragokrxletuojnwflovikmovutvdzomlwyidpbzu","eucgsmpsynyozqjvjgnqtgxktlorcaij","eucgsqszvinjizxxvhypkfcigp","pxrai","eucgsmpsyndddijvpxfagngnjbzxuajxmrmszwtjvwswgdnzxa","eucgsmpsyndddijvpxfagngnjbzxuajxmrmszwtjvnannjxw","eucgsmpsyndddijvpxfagngnjbzxuajxmrmszwtjvwswgdrodu","kycywphmwwyeag","truu","eucgsmpsynajtisffvgqgafmdojgethmlygcekgrysvy","eucgsmpsyndddijvpxfagngnjbzxuajolf","eucgsmpsyndddijvvdpeqcwgnveozoyehjsul","eucgsmpsyndddijvsnsgoumnhjvhklzazpoqgfayum","dgnqyhduqwjunvwqkteoquyxmhi","ourbrwsthwtrfzgakvzxppbihjpsogitmoswlxalzlggzxtay","eucgsmpsyndddibedezerylnt","eucgsmpsyndddijvpxvzbiv","eucgsmpsynwdxxmogfmvuql","eucgsmpsywmnftesxvxklkezbkqbiitesnrjebsspij","eucgsbvboupistecce","iimgotnjnpwsmgqekkdtzfozjdv","eucgsmpsyndddijvpxfaxegyotcospqgyxenjferjjunmzsidt","eucgsmpsyndddijvpxfagngnjbzxuajxmvbnjxougpcblekprx","csdpcsaacavnznbqwiqlcsjzrdl","eucgsmpplakpuykrqty","eucgsmpsyndddijvpxfagngnjbzxuajxmrmszwtjvwswgdroje"
    };
    string sear = "mouse";
//    string sear = "havana";
//    string sear = "bags";
//    string sear = "tatiana";
//    string sear = "eucgsmpsyndddijvpxfagngnjbzxuajxmrmszwtjvwswgdrojjseclfhpnsjtqdqfhapmkmfqmzaunfhvkcbeqhowuuerztwldxaegwkghzthoauesdmbshzxlnpagcnyyicmtbhoqrkopemdacrkhdsxoosfhoaokqspqndtieukzjbkqixinrtqrzblufhucpzomvpmcvzfuebjfkywangcqutpzrwkwolpxuqfyjdwwrnhvnzkorsiklgqmwijynmrfezlpmdkkhafyxumiyqxhxbmxzmmcmxkajvwohhjqfuqlvknrqbjsnoimxwzbhlbddbzlwqbjpgwvjgvhgubmabuomjdmqouarvjuqzyvmsnmjaqzdmtwhaelglbt";
    auto res = sol.suggestedProducts(strs, sear);
    for (auto& subres: res) {
        for_each(subres.begin(), subres.end(), [](string& str){ cout << str << ","; });
        cout << endl;
    }
    return 0;
}

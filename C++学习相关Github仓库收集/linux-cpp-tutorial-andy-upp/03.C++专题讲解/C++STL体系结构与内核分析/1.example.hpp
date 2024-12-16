// author : Hou Jie (侯捷)
// date : 2015/10/28 
// compiler : DevC++ 5.11 (MinGW with GNU 4.9.9.2)
//
// 說明：這是侯捷 E-learning video "C++標準庫" 的實例程式.
// 該課程的所有測試都出現在此.
// 每一個小測試單元都被放進一個 namespace 中, 
// 如此保持各單元間最大的獨立性.
// 每個 namespace 上方皆有該單元相應的 #include <...> 
// 因此有可能整個程式重複含入 (included) 某些 headers. 
// 這無所謂，因為每個 standard headers 都有自我防衛機制，不讓自己被 included 二次.
//
// 本文件用到若干 C++ 2.0 New Features，所以你必須在你的集成環境 (IDE) 上設定 "C++11 on". 
// 如果你的編譯器報錯，應是因為我用到 (測試) GNU 標準庫的獨特 (非標準) 組件 (特別是 allocators)，
// 將報錯語句改為註解 (comments) 即可通過編譯. 

using namespace std;
const long ASIZE  =   500000L;


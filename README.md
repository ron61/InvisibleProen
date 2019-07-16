# InvisibleProen
2019年3Sプロジェクト演習

## 仕様
- ToggleUI押すとボタンの表示非表示を切り替えられる
- マーカーが一回カメラから外れると，アニメーションが最初からになる．スタートしない時は，スタートボタンを押す．一時停止したいときは，停止ボタンを押す．
- Materialボタンを押すと，autdおよび台座のモデルのマテリアルが切り替わる．位置調整用のピンクのものと，occlusion用のshader貼ったもの．ピンクの状態で位置調整をし，現実のautdなどと位置があったら，materialを切り替えてocclusionできるようにする．

## 反省点
- occlusionするなら，6d.aiとかにするべきだった．安易にARkitにしたためにゴリ押しocclusion実装しかできなかった．まあ精度は出るけど頑張れば．．．

## Refs
透明にするシェーダー．occlusion実装するのに使用した．
http://nn-hokuson.hatenablog.com/entry/2017/06/01/220504

Animationが最初からにできない問題．結局よくわからなかった．
https://qiita.com/panti310/items/b4bae4c0c0087bd81f66

たまにxcodeからビルドしようとするとき，build only device．．．と出てビルドできなくなる．
その時は
Xcode>Open Developer Tool>Simulator
として
Hardware>iOs>対象の端末
としてからもう一度やり直すとできるようになる．

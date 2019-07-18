# InvisibleProen
2019年3Sプロジェクト演習のソースコード

## 内容
- UnityProject
- demo.cpp
  - 当日のデモで使用したatudのコード．
- leapmotion_autd.cpp
  - leapmotionでマイクロビーズを操作できるデモ用のautdのコード．

## 仕様
- ToggleUI押すとボタンの表示非表示を切り替えられる
- マーカーが一回カメラから外れると，アニメーションが最初からになる．スタートしない時は，スタートボタンを押す．一時停止したいときは，停止ボタンを押す．
- Materialボタンを押すと，autdおよび台座のモデルのマテリアルが切り替わる．位置調整用のピンクのものと，occlusion用のshader貼ったもの．ピンクの状態で位置調整をし，現実のautdなどと位置があったら，materialを切り替えてocclusionできるようにする．

## 反省点
- occlusionするなら，6d.aiとかにするべきだった．安易にARkitにしたためにゴリ押しocclusion実装しかできなかった．まあ精度は出るけど頑張れば．．．

## Refs
[【Unityシェーダ入門】オブジェクトが重なった部分をくり抜く](http://nn-hokuson.hatenablog.com/entry/2017/06/01/220504)

[Animatorの動的attachと停止、再生の制御](https://qiita.com/panti310/items/b4bae4c0c0087bd81f66)

たまにxcodeからビルドしようとするとき，build only device．．．と出てビルドできなくなる．
その時は
Xcode>Open Developer Tool>Simulator
として
Hardware>iOs>対象の端末
としてからもう一度やり直すとできるようになる．

子オブジェクトの取得
```
GameObject ChildObject;
ChildObject = transform.GetChild(0).gameObject;
```

[Blenderで人型用のアニメーションを自作して、Unity上のモデルに適用するまでの流れ](https://qiita.com/ritsuka/items/a8684c52f5320e068f32)

[Unityで始めるARkit入門](http://nn-hokuson.hatenablog.com/entry/2018/10/10/194736)

[UnityでARKITを使うとき最初にやる準備/設定](https://qiita.com/kdmyk/items/4738cba9652ddc0eb6b2)



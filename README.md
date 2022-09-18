# dwm

My build of dwm.

## Patches and features

* [**actualfullscreen-20211013-cb3f58a**](https://dwm.suckless.org/patches/actualfullscreen/dwm-actualfullscreen-20211013-cb3f58a.diff) provides true fullscreen (<kbd>super+f</kbd>) in dwm.
    * [This code](https://github.com/LukeSmithxyz/dwm/pull/186/files) makes dwm exit fullscreen if a new window is spawned.
* [**alpha/fixborders-6.2**](https://dwm.suckless.org/patches/alpha/dwm-fixborders-6.2.diff) keeps borders opaque when using terminal transparency.
* [**alwayscenter-20200625-f04cac6**](https://dwm.suckless.org/patches/alwayscenter/dwm-alwayscenter-20200625-f04cac6.diff) makes all floating windows centered.

## Installation

```
git clone https://github.com/thatguynoe/dwm
cd dwm
sudo make install
```

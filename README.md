# dwm

My build of dwm.

## Patches and features

* [**actualfullscreen-20211013-cb3f58a**](https://dwm.suckless.org/patches/actualfullscreen/dwm-actualfullscreen-20211013-cb3f58a.diff) provides true fullscreen (<kbd>super+f</kbd>) in dwm.
    * [This code](https://github.com/LukeSmithxyz/dwm/pull/186/files) makes dwm exit fullscreen if a new window is spawned.
* [**alpha/fixborders-6.2**](https://dwm.suckless.org/patches/alpha/dwm-fixborders-6.2.diff) keeps borders opaque when using terminal transparency.
* [**alwayscenter-20200625-f04cac6**](https://dwm.suckless.org/patches/alwayscenter/dwm-alwayscenter-20200625-f04cac6.diff) makes all floating windows centered.
* [**deck-6.2**](https://dwm.suckless.org/patches/deck/dwm-deck-6.2.diff) provides the deck layout and is accessible via <kbd>super+u</kbd>.
    * [**dwm-deck-tilegap-6.1**](https://dwm.suckless.org/patches/deck/dwm-deck-tilegap-6.1.diff) provides gaps functionality in the deck layout.
* [**focusmonmouse-6.2**](https://dwm.suckless.org/patches/focusmonmouse/dwm-focusmonmouse-6.2.diff) moves the mouse to the selected monitor.
* [**hide_vacant_tags-6.3**](https://dwm.suckless.org/patches/hide_vacant_tags/dwm-hide_vacant_tags-6.3.diff) hides tags which are not in use.
* [**scratchpads-20200414-728d397b**](https://dwm.suckless.org/patches/scratchpads/dwm-scratchpads-20200414-728d397b.diff) provides scratchpads.

## Installation

```
git clone https://github.com/thatguynoe/dwm
cd dwm
sudo make install
```

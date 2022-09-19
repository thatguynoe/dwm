# dwm

My build of [dwm](https://dwm.suckless.org/).

## Patches and features

* [**actualfullscreen-20211013-cb3f58a**](https://dwm.suckless.org/patches/actualfullscreen/dwm-actualfullscreen-20211013-cb3f58a.diff) provides true fullscreen (<kbd>super+f</kbd>) in dwm.
    * [This code](https://github.com/LukeSmithxyz/dwm/pull/186/files) makes dwm exit fullscreen if a new window is spawned.
* [**alpha/fixborders-6.2**](https://dwm.suckless.org/patches/alpha/dwm-fixborders-6.2.diff) keeps borders opaque when using terminal transparency.
* [**alwayscenter-20200625-f04cac6**](https://dwm.suckless.org/patches/alwayscenter/dwm-alwayscenter-20200625-f04cac6.diff) makes all floating windows centered.
* [**deck-6.2**](https://dwm.suckless.org/patches/deck/dwm-deck-6.2.diff) provides the deck layout and is accessible via <kbd>super+u</kbd>.
    * [**dwm-deck-tilegap-6.1**](https://dwm.suckless.org/patches/deck/dwm-deck-tilegap-6.1.diff) provides gaps functionality in the deck layout.
* [**focusmonmouse-6.2**](https://dwm.suckless.org/patches/focusmonmouse/dwm-focusmonmouse-6.2.diff) moves the mouse to the selected monitor.
* [**hide_vacant_tags-6.3**](https://dwm.suckless.org/patches/hide_vacant_tags/dwm-hide_vacant_tags-6.3.diff) hides tags which are not in use.
* [**sendmoncenter-20210805-138b405f**](https://dwm.suckless.org/patches/sendmoncenter/dwm-sendmoncenter-20210805-138b405f.diff) keeps centered floating windows centered when sending them to another monitor.
* [**scratchpads-20200414-728d397b**](https://dwm.suckless.org/patches/scratchpads/dwm-scratchpads-20200414-728d397b.diff) provides scratchpads.
* [**stacker-6.2**](https://dwm.suckless.org/patches/stacker/dwm-stacker-6.2.diff) can move windows up the stack with <kbd>super+K/J</kbd>.
* [**statuspadding-6.3**](https://dwm.suckless.org/patches/statuspadding/dwm-statuspadding-6.3.diff) makes the amount of horizontal and vertical padding in the status bar configurable.
* [**sticky-6.1**](https://dwm.suckless.org/patches/sticky/dwm-sticky-6.1.diff) makes windows "sticky" with <kbd>super+s</kbd>.
    * [This code](https://github.com/LukeSmithxyz/dwm/pull/181/files) makes dwm not focus sticky windows when switching tags.
    * [**stickyindicator-6.2**](https://dwm.suckless.org/patches/stickyindicator/dwm-stickyindicator-6.2.diff) displays an indicator in the bar to show when a window is sticky.
    * The `focus(NULL)` code in the `togglesticky` function in `dwm.c` switches focus to the visible window upon unstickying a window; no more accidentally killing previously-stickied windows.
* [**swallow-6.3**](https://dwm.suckless.org/patches/swallow/dwm-swallow-6.3.diff) allows for programs launched via the terminal to take its place if they would make it inoperable.
* [**vanitygaps-6.2**](https://dwm.suckless.org/patches/vanitygaps/dwm-vanitygaps-6.2.diff) provides gaps throughout all layouts.
* Autostarts [dwmblocks](http://github.com/thatguynoe/dwmblocks) through the `runAutostart` function in `dwm.c`.

## Installation

```sh
git clone https://github.com/thatguynoe/dwm
cd dwm
sudo make install
```

# Charybdis Mini (3x6) keymap

The POINTER layer is altered to meet charybdis' needs and special keys:

## Pointer (Mouse, only if enabled)
* CSC: CTL(/GUI)+Shift+Click
```
 (⌥)│vMv│SD-│DD-│DD+│SD+          │   │CSC│AGr│   │(⌥)
 ─── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
 (⌃)│Bt4│DrT│Drg│Snp│Bt5       Meh│Sft│ ⌃ │ ⌥ │ ⌘ │(⌃)
 ─── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
 (⌘)│Tb←│Cut│Cpy│Pst│^M^          │Snp│Drg│DrT│Tb→│(⌘)
              ┌───┬───┬───┐ ┌───┬───┐
              │CSC│Bt1│Bt2│ │Bt3│Bt1│
              └───┴───┴───┘ └───┴─⇧─┘
```

(all the rest is like my standard layout:)

# Base Layers
First and last column keys on base layers for 6x3 keyboards,
(X) is the corresponding key from the currently active base layer:
```
     ⌥/⌫│                                       │⌥/(X)
     ───┼─                                     ─┼─────
     ⌃/⎋│           (...other keys...)          │⌃/(X)
     ───┼─                                     ─┼─────
     ⌘/▤│                                       │⌘/ ↵
```

All base layers share the same thumb cluster:
(If the keyboard only has 2 keys on one side, the outermost key (marked with *) is missing)
```
                *                     *
                ⎋ │ ↵ │ ⇥ │ │ ⌫ │Spc│ ⌦
               ───┴─⇧─┴LOW┘ └RSE┴─⇧─┴───
```

## QWERTY (german adaption)
```
      q │ w │ e │ r │ t         z │ u │ i │ o │ p │(ü)
     ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
      a │ s │ d │ f │ g         h │ j │ k │ l │ ö │(ä)
     ─Σ─┼───┼───┼───┼───       ───┼───┼───┼───┼─Σ─ ───
      y │ x │ c │ v │ b         n │ m │ , │ . │ ß │
     ─M─┴───┴───┴───┴───       ───┴───┴───┴───┴─M─
```

## BONE
```
      j │ d │ u │ a │ x         p │ h │ l │ m │ w │(ß)
     ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
      c │ t │ i │ e │ o         b │ n │ r │ s │ g │(q)
     ─Σ─┼───┼───┼───┼───       ───┼───┼───┼───┼─Σ─ ───
      f │ v │ ü │ ä │ ö         y │ z │ , │ . │ k │
     ─M─┴───┴───┴───┴───       ───┴───┴───┴───┴─M─
```

## Colemak (Mod DH, german adaption)
```
      q │ w │ f │ p │ b         j │ l │ u │ y │ ö │(ü)
     ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
      a │ r │ s │ t │ g         m │ n │ e │ i │ o │(ä)
     ─Σ─┼───┼───┼───┼───       ───┼───┼───┼───┼─Σ─ ───
      z │ x │ c │ d │ v         k │ h │ , │ . │ ß │
     ─M─┴───┴───┴───┴───       ───┴───┴───┴───┴─M─
```

# Additional Layers

## Symbols
```
 (⌥)│ @ │ _ │ [ │ ] │ ^         ! │ < │ > │ = │ & │(⌥)
 ─── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
 (⌃)│ \ │ / │ { │ } │ *         ? │ ( │ ) │ - │ : │(⌃)
 ─── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
 (⌘)│ # │ $ │ | │ ~ │ ´         + │ % │ " │ ' │ ; │(⌘)
               ───┌───┬───┐ ┌───┬───┐───
                ° │ § │ ` │ │AGr│Spc│CWT
               ───└───┴───┘ └───┴─⇧─┘───
```
       (when dynamic tapping term is enabled, thumbs change to:)
```
               ───┌───┬───┐ ┌───┬───┐───
               PTT│ § │TT+│ │TT-│Spc│CWT
               ───└───┴───┘ └───┴─⇧─┘───
```

## Lower (Function keys and numbers)
```
 (⌥)│F1 │F2 │F3 │F4 │ £         / │ 7 │ 8 │ 9 │ - │(⌥)
 ─── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
 (⌃)│F5 │F6 │F7 │F8 │ €         + │ 4 │ 5 │ 6 │ . │(⌃)
 ─── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
 (⌘)│F9 │F10│F11│F12│ ¢         0 │ 1 │ 2 │ 3 │ , │(⌘)
               ───┌───┬───┐ ┌───┬───┐───
                ¥ │Sft│(v)│ │Bsp│Spc│ $
               ───└───┴───┘ └ATT┴─⇧─┘───
```

## Raise (Navigation and control keys)
(the home row modifiers on the right are sticky)
```
 (⌥)│PUp│BSp│ ↑ │Del│Ins       Prv│Stp│Ply│AGr│Nxt│(⌥)
 ─── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
 (⌃)│Hme│ ← │ ↓ │ → │End     * Meh│Sft│ ⌃ │ ⌥ │ ⌘ │(⌃)
 ─── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
 (⌘)│Esc│Cut│Cpy│Pst│PDn       PSc│CWT│Pse│Ejt│SLk│(⌘)
               ───┌───┬───┐ ┌───┬───┐───
               Prv│V -│V ×│ │(v)│V +│Nxt
               ───└─⇧─┴ATT┘ └───┴─⇧─┘───
```

## Pointer (Mouse)
(see above)

## Attic (Adjustments and missing stuff)
```
    │QBt│ECl│LAs│LAr│APP        ¡ │ ‹ │ « │ » │ › │(§)
 ─── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
    │LyG│Ly←│Ly→│BsL│MDX        ¿ │ • │ ‚ │ ‘ │ ’ │(…)
 ─── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
    │RGB│R_S│R_H│R_V│R_M       n-–│m-—│ „ │ “ │ ” │
               ───┌───┬───┐ ┌───┬───┐───
               LSf│Br-│(v)│ │(v)│Br+│RSf
               ───└─⇧─┴───┘ └───┴─⇧─┘───
```

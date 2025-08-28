# QMK Userspace

This is a template repository which allows for an external set of QMK keymaps to be defined and compiled. This is useful for users who want to maintain their own keymaps without having to fork the main QMK repository.

These keymaps are using keymap_german_mac_iso.
Symbols are 'translated', if a linux/windows host is detected.

# Base Layers
First and last column keys on base layers for 6x3 keyboards,
(X) is the corresponding key from the currently active base layer:
```
     ⌥/⌫│                                       │⌥/(X)
     ───┼─                                     ─┼─────
     Σ/⎋│           (...other keys...)          │Σ/(X)
     ───┼─                                     ─┼─────
     ⌘/▤│                                       │⌘/ ↵
```

All base layers share the same thumb cluster:
(If the keyboard only has 2 keys on one side, the outermost key (marked with *) is missing)
```
                *                     *
                ⎋ │ ↵ │ ⇥ │ │ ⌦ │Spc│Rpt
               ───┴─⇧─┴LOW┘ └RSE┴───┴───
```

## QWERTY (german adaption)
```
      q │ w │ e │ r │ t         z │ u │ i │ o │ p │(ü)
     ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
      a │ s │ d │ f │ g         h │ j │ k │ l │ ö │(ä)
     ─G─┼─A─┼─S─┼─C─┼(Σ)       (Σ)┼─C─┼─S─┼─A─┼─G─ ───
      y │ x │ c │ v │ b         n │ m │ , │ . │ ß │
     ─M─┴───┴───┴───┴───       ───┴───┴───┴───┴─M─
```

## BONE
```
      j │ d │ u │ a │ x         p │ h │ l │ m │ w │(ß)
     ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
      c │ t │ i │ e │ o         b │ n │ r │ s │ g │(q)
     ─G─┼─A─┼─S─┼─C─┼(Σ)       (Σ)┼─C─┼─S─┼─A─┼─G─ ───
      f │ v │ ü │ ä │ ö         y │ z │ , │ . │ k │
     ─M─┴───┴───┴───┴───       ───┴───┴───┴───┴─M─
```

## NOTED
```
      z │ y │ u │ a │ q         p │ b │ m │ l │ f │(j)
     ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
      c │ s │ i │ e │ o         d │ t │ n │ r │ h │(ß)
     ─G─┼─A─┼─S─┼─C─┼(Σ)       (Σ)┼─C─┼─S─┼─A─┼─G─ ───
      v │ x │ ü │ ä │ ö         w │ g │ , │ . │ k │
     ─M─┴───┴───┴───┴───       ───┴───┴───┴───┴─M─
```

## Colemak (Mod DH, german adaption)
```
      q │ w │ f │ p │ b         j │ l │ u │ y │ ö │(ü)
     ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
      a │ r │ s │ t │ g         m │ n │ e │ i │ o │(ä)
     ─G─┼─A─┼─S─┼─C─┼(Σ)       (Σ)┼─C─┼─S─┼─A─┼─G─ ───
      z │ x │ c │ d │ v         k │ h │ , │ . │ ß │
     ─M─┴───┴───┴───┴───       ───┴───┴───┴───┴─M─
```

# Additional Layers

## Symbols
```
    │ @ │ _ │ [ │ ] │ ^         ! │ < │ > │ = │ & │   
 ─── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
    │ \ │ / │ { │ } │ *         ? │ ( │ ) │ - │ : │ § 
 ─── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
    │ # │ $ │ | │ ~ │ ´         + │ % │ " │ ' │ ; │   
               ───┌───┬───┐ ┌───┬───┐───
                ° │ § │ ` │ │AGr│Spc│CWT
               ───└───┴───┘ └───┴─S─┘───
```
       (when dynamic tapping term is enabled, thumbs change to:)
```
               ───┌───┬───┐ ┌───┬───┐───
               PTT│ § │TT+│ │TT-│Spc│CWT
               ───└───┴───┘ └───┴─S─┘───
```

## Lower (Function keys and numbers)
```
    │F1 │F2 │F3 │F4 │ £         / │ 7 │ 8 │ 9 │ - │   
 ─── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
    │F5 │F6 │F7 │F8 │ €         + │ 4 │ 5 │ 6 │ . │   
 ─── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
    │F9 │F10│F11│F12│ ¢         0 │ 1 │ 2 │ 3 │ , │   
               ───┌───┬───┐ ┌───┬───┐───
                ¥ │Sft│(v)│ │Bsp│Spc│ $
               ───└───┴───┘ └ATT┴─S─┘───
```

## Raise (Navigation and control keys)
(the home row modifiers on the right are sticky)
```
    │PUp│BSp│ ↑ │Del│PDn       Prv│Ply│Nxt│Stp│Ejt│
 ─── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
    │Hme│ ← │ ↓ │ → │End     * Meh│ C │ S │ A │ G │
 ─── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
    │Udo│Cut│Cpy│Pst│Rdo       PSc│   │Ins│AGr│CWT│
               ───┌───┬───┐ ┌───┬───┐───
               Prv│V -│V ×│ │(v)│V +│Nxt
               ───└─S─┴ATT┘ └───┴─S─┘───
```

## Pointer (Mouse, only if enabled)
* CSC: CTL(/GUI)+Shift+Click
```
    │vMv│<M<│Ms↑│>M>│^M^          │   │   │   │   │   
 ─── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
    │Bt4│Ms←│Ms↓│Ms→│Bt5       Meh│ C │ S │ A │ G │   
 ─── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
    │Tb←│Cut│Cpy│Pst│CSC       Slo│Med│Fst│AGr│Tb→│   
               ───┌───┬───┐ ┌───┬───┐───
               CSC│Bt1│Bt2│ │Bt3│Bt1│CSC
               ───└───┴───┘ └───┴─S─┘───
```

## Attic (Adjustments and missing stuff)
```
    │QBt│ECl│LAs│LAr│APP        ¡ │ ‹ │ « │ » │ › │QBt
 ─── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
    │LyG│Ly←│Ly→│BsL│MDX        ¿ │ • │ ‚ │ ‘ │ ’ │(…)
 ─── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
    │RGB│R_S│R_H│R_V│R_M       n-–│m-—│ „ │ “ │ ” │
               ───┌───┬───┐ ┌───┬───┐───
               LSf│Br-│(v)│ │(v)│Br+│RSf
               ───└─S─┴───┘ └───┴─S─┘───
``
# Portfolio
Currently my board contains the following beauties:
1. Redox (03/2021) (ready assembled)
1. Kyria rev.2 (05/2021)
1. dracuLad w/ Pimorini (08/2022)
1. Iris rev.6 (08/2022)
1. Paintbrush (10/2022)
1. [never worked: Aurora sweep (wireless) (03/2023)]
1. Cantor (11/2023)
1. Corne (wireless) (01/2025)


# QMK Userspace

This is a template repository which allows for an external set of QMK keymaps to be defined and compiled. This is useful for users who want to maintain their own keymaps without having to fork the main QMK repository.

These keymaps are using keymap_german_mac_iso.
Symbols are 'translated', if a linux/windows host is detected.

# Base Layers
First and last column keys on base layers for 6x3 keyboards,
(X) is the corresponding key from the currently active base layer:
```
     A/⌫│                                       │A/(X)
     ───┼─                                     ─┼─────
     Σ/⎋│           (...other keys...)          │Σ/(X)
     ───┼─                                     ─┼─────
      G │                                       │ C/▤
```

All base layers share the same thumb cluster:
(If the keyboard only has 2 keys on one side, the outermost key (marked with *) is missing)
```
                *                     *
                ⎋ │ ↵ │ ⇥ │ │./,│Spc│ ⎋
               ─R─ ─G─┴LOW┘ └RSE┴─── ─L─
```

## QWERTY (german adaption)
```
      q │ w │ e │ r │ t         z │ u │ i │ o │ p │(ü)
     ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
      a │ s │ d │ f │ g         h │ j │ k │ l │ ö │(ä)
     ─G─┼─A─┼─S─┼─C─┼(Σ)       (Σ)┼─C─┼─S─┼─A─┼─G─ ───
      y │ x │ c │ v │ b         n │ m │ , │ . │ ß │
     ─M─┴───┴───┴───┴───       ───┴───┴(ä)┴(ü)┴─M─
```

## NOTED
```
      z │ y │ u │ a │ q         p │ b │ m │ l │ f │(j)
     ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
      c │ s │ i │ e │ o         d │ t │ n │ r │ h │(ß)
     ─G─┼─A─┼─S─┼─C─┼(Σ)       (Σ)┼─C─┼─S─┼─A─┼─G─ ───
      v │ x │ ü │ ä │ ö         w │ g │ , │ . │ k │
     ─M─┴───┴───┴───┴───       ───┴───┴(j)┴(ß)┴─M─
```

## BONE
```
      j │ d │ u │ a │ x         p │ h │ l │ m │ w │(ß)
     ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
      c │ t │ i │ e │ o         b │ n │ r │ s │ g │(q)
     ─G─┼─A─┼─S─┼─C─┼(Σ)       (Σ)┼─C─┼─S─┼─A─┼─G─ ───
      f │ v │ ü │ ä │ ö         y │ z │ , │ . │ k │
     ─M─┴───┴───┴───┴───       ───┴───┴(q)┴(ß)┴─M─
```

## NEO2
```
      x │ v │ l │ c │ w         k │ h │ g │ f │ q │(ß)
     ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
      u │ i │ a │ e │ o         s │ n │ r │ t │ d │(y)
     ─G─┼─A─┼─S─┼─C─┼(Σ)       (Σ)┼─C─┼─S─┼─A─┼─G─ ───
      ü │ ö │ ä │ p │ z         b │ m │ , │ . │ j │
     ─M─┴───┴───┴───┴───       ───┴───┴(y)┴(ß)┴─M─
```

## Colemak (Mod DH, german adaption)
```
      q │ w │ f │ p │ b         j │ l │ u │ y │ ö │(ü)
     ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
      a │ r │ s │ t │ g         m │ n │ e │ i │ o │(ä)
     ─G─┼─A─┼─S─┼─C─┼(Σ)       (Σ)┼─C─┼─S─┼─A─┼─G─ ───
      z │ x │ c │ d │ v         k │ h │ , │ . │ ß │
     ─M─┴───┴───┴───┴───       ───┴───┴(ä)┴(ü)┴─M─
```

## DVORADVORAKgerman adaption)
```
      q │ w │ e │ r │ t         z │ u │ i │ o │ p │(ü)
     ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
      a │ s │ d │ f │ g         h │ j │ k │ l │ ö │(ä)
     ─G─┼─A─┼─S─┼─C─┼(Σ)       (Σ)┼─C─┼─S─┼─A─┼─G─ ───
      y │ x │ c │ v │ b         n │ m │ , │ . │ ß │
     ─M─┴───┴───┴───┴───       ───┴───┴(ä)┴(ü)┴─M─
```


# Additional Layers

## Symbols
```
 Bsp│ @ │ _ │ [ │ ] │ ^         ! │ < │ > │ = │ & │ ſ
 ─── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
    │ \ │ / │ { │ } │ *         ? │ ( │ ) │ - │ : │ §
 ─── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
    │ # │ $ │ | │ ~ │ ´         + │ % │ " │ ' │ ; │ …
               ───┌───┬───┐ ┌───┬───┐───
                ° │ § │G+ˇ│ │ … │Spc│ ſ
               ───└───┴───┘ └───┴───┘───
```

## Lower (Function keys and numbers)
```
 Bsp│F1 │F2 │F3 │F4 │ £         / │ 7 │ 8 │ 9 │ + │ $
 ─── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
  ¥ │F5 │F6 │F7 │F8 │ €         . │ 4 │ 5 │ 6 │ - │ #
 ─── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
  ( │F9 │F10│F11│F12│ ¢         0 │ 1 │ 2 │ 3 │ , │ )
               ───┌───┬───┐ ┌───┬───┐───
                ¥ │Sft│(v)│ │App│Spc│ $
               ───└───┴───┘ └ATT┴─S─┘───
```

## Raise (Navigation and control keys)
(the home row modifiers on the right are sticky)
```
 Bsp│PUp│BSp│ ↑ │Del│PDn       Prv│Ply│Nxt│Stp│Ejt│ Ps
 ─── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
 Ins│Hme│ ← │ ↓ │ → │End     * Meh│ C │ S │ A │ G │ SL
 ─── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
    │Udo│Cut│Cpy│Pst│All       PSc│MDX│CpW│AGr│Rdo│
               ───┌───┬───┐ ┌───┬───┐───
               Prv│V -│V ×│ │(v)│V +│Nxt
               ───└─S─┴ATT┘ └───┴─S─┘───
```

## Pointer (Mouse, only if enabled)
```
    │vMv│<M<│Ms↑│>M>│^M^          │   │   │   │   │
 ─── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
    │Bt4│Ms←│Ms↓│Ms→│Bt5       Meh│ C │ S │ A │ G │
 ─── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
    │Tb←│Cut│Cpy│Pst│All       Slo│Med│Fst│AGr│Tb→│
               ───┌───┬───┐ ┌───┬───┐───
               CSC│Bt1│Bt2│ │Bt3│Bt1│CSC
               ───└───┴───┘ └───┴─S─┘───
```

## Attic (Adjustments and missing stuff)
```
    │QBt│ECl│LAs│LAr│Ins        ¡ │ ‹ │ « │ » │ › │QBt
 ─── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
    │M/A│Ly←│Ly→│BsL│MDX        ¿ │ • │ ‚ │ ‘ │ ’ │Pwr
 ─── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
    │RGB│R_S│R_H│R_V│R_M       n-–│m-—│ „ │ “ │ ” │ECl
               ───┌───┬───┐ ┌───┬───┐───
               LSf│Br-│(v)│ │(v)│Br+│RSf
               ───└─S─┴───┘ └───┴─S─┘───
```

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


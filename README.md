# QMK Userspace

This is a template repository which allows for an external set of QMK keymaps to be defined and compiled. This is useful for users who want to maintain their own keymaps without having to fork the main QMK repository.

These keymaps are using keymap_german_iso with some extensions for Linux systems.
Symbols are 'translated', if a mac host is detected.

## Base Layers

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

The dot and comma key is mainly used for 5 column keyboards where I replaced dot and comma by some of the "umlauts".
The selected base layer is still active after a power cut or reset.

### QWERTY (German adaption)

```
      q  │  w  │  e  │  r  │  t          z  │  u  │  i  │  o  │  p  │ (ü)
    ─────┼─────┼─────┼─────┼─────      ─────┼─────┼─────┼─────┼───── ─────
      a  │  s  │  d  │  f  │  g          h  │  j  │  k  │  l  │  ö  │ (ä)
    ──G──┼──A──┼──S──┼──C──┼─(Σ)─      ─(Σ)─┼──C──┼──S──┼──A──┼──G── ─────
      y  │  x  │  c  │  v  │  b          n  │  m  │  ,  │  .  │  ß  │
    ──M──┴─────┴─────┴─────┴─────      ─────┴─────┴─(ä)─┴─(ü)─┴──M── ─────
```

### NOTED

```
      z  │  y  │  u  │  a  │  q          p  │  b  │  m  │  l  │  f  │ (j)
    ─────┼─────┼─────┼─────┼─────      ─────┼─────┼─────┼─────┼───── ─────
      c  │  s  │  i  │  e  │  o          d  │  t  │  n  │  r  │  h  │ (ß)
    ──G──┼──A──┼──S──┼──C──┼─(Σ)─      ─(Σ)─┼──C──┼──S──┼──A──┼──G── ─────
      v  │  x  │  ü  │  ä  │  ö          w  │  g  │  ,  │  .  │  k  │
    ──M──┴─────┴─────┴─────┴─────      ─────┴─────┴─(j)─┴─(ß)─┴──M── ─────
```

### BONE

```
      j  │  d  │  u  │  a  │  x          p  │  h  │  l  │  m  │  w  │ (ß)
    ─────┼─────┼─────┼─────┼─────      ─────┼─────┼─────┼─────┼───── ─────
      c  │  t  │  i  │  e  │  o          b  │  n  │  r  │  s  │  g  │ (q)
    ──G──┼──A──┼──S──┼──C──┼─(Σ)─      ─(Σ)─┼──C──┼──S──┼──A──┼──G── ─────
      f  │  v  │  ü  │  ä  │  ö          y  │  z  │  ,  │  .  │  k  │
    ──M──┴─────┴─────┴─────┴─────      ─────┴─────┴─(q)─┴─(ß)─┴──M── ─────
```

### NEO2

```
      x  │  v  │  l  │  c  │  w          k  │  h  │  g  │  f  │  q  │ (ß)
    ─────┼─────┼─────┼─────┼─────      ─────┼─────┼─────┼─────┼───── ─────
      u  │  i  │  a  │  e  │  o          s  │  n  │  r  │  t  │  d  │ (y)
    ──G──┼──A──┼──S──┼──C──┼─(Σ)─      ─(Σ)─┼──C──┼──S──┼──A──┼──G── ─────
      ü  │  ö  │  ä  │  p  │  z          b  │  m  │  ,  │  .  │  j  │
    ──M──┴─────┴─────┴─────┴─────      ─────┴─────┴─(y)─┴─(ß)─┴──M── ─────
```

### Colemak (Mod DH, German adaption)

```
      q  │  w  │  f  │  p  │  b          j  │  l  │  u  │  y  │  ö  │ (ü)
    ─────┼─────┼─────┼─────┼─────      ─────┼─────┼─────┼─────┼───── ─────
      a  │  r  │  s  │  t  │ g           m  │  n  │  e  │  i  │  o  │ (ä)
    ──G──┼──A──┼──S──┼──C──┼─(Σ)─      ─(Σ)─┼──C──┼──S──┼──A──┼──G── ─────
      z  │  x  │  c  │  d  │  v          k  │  h  │  ,  │  .  │  ß  │
    ──M──┴─────┴─────┴─────┴─────      ─────┴─────┴─(ä)─┴─(ü)─┴──M── ─────
```

### DVORAK (German adaption)

```
      ü  │  ,  │  .  │  p  │  y          f  │  g  │  c  │  t  │  z  │ (ß)
    ─────┼─(ß)─┼─(l)─┼─────┼─────      ─────┼─────┼─────┼─────┼───── ─────
      a  │  o  │  e  │  i  │  u          h  │  d  │  r  │  n  │  s  │ (l)
    ──G──┼──A──┼──S──┼──C──┼─(Σ)─      ─(Σ)─┼──C──┼──S──┼──A──┼──G── ─────
(ä)│  ö  │  q  │  j  │  k  │  x          b  │  m  │  w  │  v  │  ä  │
    ──M──┴─────┴─────┴─────┴─────      ─────┴─────┴─────┴─────┴──M── ─────
```

## Special Layers (not very useful perhaps?)

These are not used for normal writing. They are not persisted and gone after a restart.

### Game Layer

(You have to reset the keyboard to return to normal behaviour)

```
(TAB)  q │ w │ e │ r │ t         6 │ 7 │ 8 │ 9 │Esc (Bsp)
───── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ─────
(Ctl)  a │ s │ d │ f │ g         ← │ ↓ │ ↑ │ → │ 5  (Ent)
───── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ─────
(Sft)  y │ x │ c │ v │ b         0 │ 1 │ 2 │ 3 │ 4  (Sft)
              ┌───┬───┬───┐ ┌───┬───┬───┐
              │Ctl│Ent│Tab│ │Sft│Spc│Alt│
              └───┴───┴───┘ └───┴───┴───┘
```

### ASETNIOP Layer

```
        │   │   │   │             │   │   │   │
     ───┼───┼───┼───┼───       ───┼───┼───┼───┼───
        │   │   │   │    [TBD]    │   │   │   │
     ───┼───┼───┼───┼───       ───┼───┼───┼───┼───
        │   │   │   │             │   │   │   │
              ┌───┬───┬───┐ ┌───┬───┬───┐
              │   │   │   │ │   │   │   │
              └───┴───┴───┘ └───┴───┴───┘
```

### ARTSEN.IO Layer

```
        │   │   │   │             │   │   │   │
     ───┼───┼───┼───┼───       ───┼───┼───┼───┼───
        │   │   │   │    [TBD]    │   │   │   │
     ───┼───┼───┼───┼───       ───┼───┼───┼───┼───
        │   │   │   │             │   │   │   │
              ┌───┬───┬───┐ ┌───┬───┬───┐
              │   │   │   │ │   │   │   │
              └───┴───┴───┘ └───┴───┴───┘
```

## Additional Layers

### Raise (Navigation, edit and media control keys)

(the home row modifiers on the right are sticky)

```
 Bsp │ PUp │ BSp │  ↑  │ Del │ PDn         Prv │ Ply │ Nxt │ Stp │ Ejt │ Pse
───── ─────┼─────┼─────┼─────┼─────       ─────┼─────┼─────┼─────┼───── ─────
 Ins │ Hme │  ←  │  ↓  │  →  │ End       * Meh │  C  │  S  │  A  │  G  │ SLk
───── ─────┼─────┼─────┼─────┼─────       ─────┼─────┼─────┼─────┼───── ─────
 Rdo │ Udo │ Cut │ Cpy │ Pst │ All         PSc │ Ins │ CpW │ AGr │ APP │
                    ─────┌─────┬─────┐ ┌─────┬─────┐─────
                     Prv │ V - │ V × │ │ (v) │ V + │ Nxt
                    ─────└──S──┴─ATT─┘ └─────┴──S──┘─────
```

### Lower (Function keys and numbers)

```
 Bsp │ F1  │  F2 │ F3  │ F4  │  £           /  │  7  │  8  │  9  │  +  │  $
───── ─────┼─────┼─────┼─────┼─────       ─────┼─────┼─────┼─────┼───── ─────
  ¥  │ F5  │ F6  │ F7  │ F8  │  €           :  │  4  │  5  │  6  │  -  │  #
───── ──G──┼──A──┼──S──┼──C──┼─────       ─────┼──C──┼──S──┼──A──┼──G── ─────
     │ F9  │ F10 │ F11 │ F12 │  ¢           0  │  1  │  2  │  3  │  ,  │
                    ─────┌─────┬─────┐ ┌─────┬─────┐─────
                      $  │  ¥  │ (v) │ │  .  │ Spc │  $
                    ─────└─────┴─────┘ └─ATT─┴─────┘─────
```

### Symbols

```
     │  @  │  _  │  [  │  ]  │  ^           !  │  <  │  >  │  =  │  &  │  ſ
───── ─────┼─────┼─────┼─────┼─────       ─────┼─────┼─────┼─────┼───── ─────
     │  \  │  /  │  {  │  }  │  *           ?  │  (  │  )  │  -  │  :  │  §
───── ─────┼─────┼─────┼─────┼─────       ─────┼─────┼─────┼─────┼───── ─────
     │  #  │  $  │  |  │  ~  │  ´           +  │  %  │  "  │  '  │  ;  │  …
                    ─────┌─────┬─────┐ ┌─────┬─────┐─────
                      °  │  §  │ G+ˇ │ │  …  │ Spc │  ſ
                    ─────└─────┴─────┘ └─────┴─────┘─────
```

### Pointer (Mouse, only if enabled)

```
     │ MW↓ │ MW← │ Ms↑ │ MW→ │ MW↑             │     │     │     │     │
───── ─────┼─────┼─────┼─────┼─────       ─────┼─────┼─────┼─────┼───── ─────
     │ Bt4 │ Ms← │ Ms↓ │ Ms→ │ Bt5         Meh │  C  │  S  │  A  │  G  │
───── ─────┼─────┼─────┼─────┼─────       ─────┼─────┼─────┼─────┼───── ─────
     │ Tb← │ Cut │ Cpy │ Pst │ All         Slo │ Med │ Fst │ AGr │ Tb→ │
                    ─────┌─────┬─────┐ ┌─────┬─────┐─────
                         │ Bt1 │ Bt2 │ │ Bt3 │ Bt1 │
                    ─────└─────┴─────┘ └─────┴─────┘─────
```

### attic (adjustments and missing stuff)

```
 QBt │ QBt │LARTS│LASET│LGAME│ MDX          ¡  │  ‹  │  «  │  »  │  ›  │ QBt
───── ─────┼─────┼─────┼─────┼─────       ─────┼─────┼─────┼─────┼───── ─────
 ECl │ ECl │ Ly↓ │ Ly↑ │ BsL │ UGl          ¿  │  •  │  ‚  │  ‘  │  ’  │ ECl
───── ─────┼─────┼─────┼─────┼─────       ─────┼─────┼─────┼─────┼───── ─────
 Rst │U_Spd│U_Sat│U_Hue│U_Val│U_Mod        n-– │ m-— │  „  │  “  │  ”  │ Pwr
                    ─────┌─────┬─────┐ ┌─────┬─────┐─────
                         │ Br- │ (v) │ │ (v) │ Br+ │ RSf
                    ─────└──S──┴─────┘ └─────┴──S──┘─────
```

## Portfolio

Currently my board contains the following beauties:

1. Redox (03/2021) (ready assembled)
2. Kyria rev.2 (05/2021)
3. dracuLad w/ Pimorini (08/2022)
4. Iris rev.6 (08/2022)
5. Paintbrush (10/2022)
6. [never worked: Aurora sweep (wireless) (03/2023)]
7. Cantor (11/2023)
8. Bastard Keyboards Charybdis mini (10/2024)
9. Corne (wireless) (01/2025)

#ifdef KEY_OVERRIDE_ENABLE
#    ifdef DPI_MOD
const key_override_t point_dpi_override = ko_make_basic(MOD_MASK_SHIFT, DPI_MOD, DPI_RMOD);
#    endif
#    ifdef S_D_MOD
const key_override_t point_sniper_dpi_override = ko_make_basic(MOD_MASK_SHIFT, S_D_MOD, S_D_RMOD);
#    endif
const key_override_t  key_sz_override  = ko_make_basic(MOD_MASK_SHIFT, DE_SS, DE_UCSZ);
const key_override_t  key_dot_override = ko_make_basic(MOD_MASK_SHIFT, RSE_DOT, DE_COMM);
const key_override_t *key_overrides[]  = {
#    ifdef DPI_MOD
    &point_dpi_override,
#    endif
#    ifdef S_D_MOD
    &point_sniper_dpi_override,
#    endif
    &key_sz_override, &key_dot_override};
#endif // KEY_OVERRIDE_ENABLE

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _BASE_L_2_:
#    if defined(QWERTY_ENABLE) || defined (COLEMAK_DH_ENABLE)
        case _BASE_R_2_(DE_ADIA):
#    endif
#    ifdef NOTED_ENABLE
        case _BASE_R_2_(DE_SS):
#    endif
#    ifdef BONE_ENABLE
        case _BASE_R_2_(DE_Q):
#    endif
#    ifdef NEO2_ENABLE
        case _BASE_R_2_(DE_Y):
#    endif
#    ifdef DVORAK_DE_ENABLE
        case _BASE_R_2_(DE_L):
#    endif
            return 150;
        default:
            return TAPPING_TERM;
    }
}
#endif // TAPPING_TERM_PER_KEY

#ifdef KEY_OVERRIDE_ENABLE

#    ifdef DPI_MOD
const key_override_t point_dpi_override = ko_make_basic(MOD_MASK_SHIFT, DPI_MOD, DPI_RMOD);
#    endif
#    ifdef S_D_MOD
const key_override_t point_sniper_dpi_override = ko_make_basic(MOD_MASK_SHIFT, S_D_MOD, S_D_RMOD);
#    endif
const key_override_t key_sz_override  = ko_make_basic(MOD_MASK_SHIFT, DE_SS, DE_UCSZ);
const key_override_t key_dot_override = ko_make_basic(MOD_MASK_SHIFT, RSE_DOT, DE_COMM);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
#    ifdef DPI_MOD
    &point_dpi_override,
#    endif
#    ifdef S_D_MOD
    &point_sniper_dpi_override,
#    endif
    &key_sz_override, &key_dot_override};
#endif // KEY_OVERRIDE_ENABLE

#ifdef KEY_OVERRIDE_ENABLE
const key_override_t key_sz_override = ko_make_basic(MOD_MASK_SHIFT, DE_SS, DE_UCSZ);
const key_override_t key_dot_override = ko_make_basic(MOD_MASK_SHIFT, RSE_DOT, DE_COMM);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&key_sz_override,
	&key_dot_override
};
#endif     // KEY_OVERRIDE_ENABLE

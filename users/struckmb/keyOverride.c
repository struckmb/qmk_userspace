#ifdef KEY_OVERRIDE_ENABLE
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, DE_SS, DE_UCSZ);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&delete_key_override
};
#endif     // KEY_OVERRIDE_ENABLE

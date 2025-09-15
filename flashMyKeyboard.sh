#! /bin/bash

KEYBOARD=splitkb/kyria/rev1
KEYMAP=struckmb
SIDE=left

while getopts 'bcdk:m:s:' opt; do
    case "$opt" in
    b)
        KEYBOARD=bastardkb/charybdis/3x6/elitec
        ;;
    c)
        KEYBOARD=cantor
        ;;
    d)
        KEYBOARD=draculad
        ;;
    k)
        KEYBOARD=${OPTARG}
        ;;
    m)
        KEYMAP=${OPTARG}
        ;;
    s)
        SIDE=${OPTARG}
        ;;
    esac
done

if [ "$KEYBOARD" = "cantor" ]; then
    echo "keyboard: ${KEYBOARD}, keymap: ${KEYMAP}, side: ${SIDE}"
    qmk flash -kb $KEYBOARD -km ${KEYMAP} -bl "dfu-util-split-${SIDE}"
else
    echo "keyboard: ${KEYBOARD}, keymap: ${KEYMAP}"
    qmk flash -kb $KEYBOARD -km ${KEYMAP}
fi

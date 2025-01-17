#!/usr/bin/env python

def is_opcode(line):
    return line.startswith('#define') and 'OPCODE' not in line

opcode_map = {}
with open('opcodes.h') as f:
    for line in f:
        if is_opcode(line):
            _, op, code = line.strip().split()
            opcode_map[code] = op

block = '''
// AUTOGENERATED BY generate_debug_names.py, DO NOT MODIFY

#ifndef __6502_DEBUG_NAMES__
#define __6502_DEBUG_NAMES__

#include <stdint.h>

char *inst_names[0x100];
char names_initialized = 0;

void init_names() {
    if (names_initialized) {
        return;
    }
    names_initialized = 1;

    for (int i = 0; i < 0xFF; i++) {
        inst_names[i] = "unknown";
    }
%s
}

#endif
'''

bb = block % '\n'.join('    inst_names[%s] = "%s";' % (code, op)
        for code, op in opcode_map.items())

print(bb)

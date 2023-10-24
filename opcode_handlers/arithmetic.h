case ADC_AB:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    add(m, m->read_cb(m, mem_abs(arg1, arg2, 0), NULL));
    break;

case ADC_ABX:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    add(m, m->read_cb(m, mem_abs(arg1, arg2, m->x), NULL));
    break;

case ADC_ABY:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    add(m, m->read_cb(m, mem_abs(arg1, arg2, m->y), NULL));
    break;

case ADC_IMM:
    add(m, NEXT_BYTE(m));
    break;

case ADC_INX:
    add(m, m->read_cb(m, mem_indexed_indirect(m, NEXT_BYTE(m), m->x), NULL));
    break;

case ADC_INY:
    add(m, m->read_cb(m, mem_indirect_index(m, NEXT_BYTE(m), m->y), NULL));
    break;

case ADC_ZP:
    add(m, m->read_cb(m, NEXT_BYTE(m), NULL));
    break;

case ADC_ZPX:
    add(m, m->read_cb(m, ZP(NEXT_BYTE(m) + m->x), NULL));
    break;

case SBC_AB:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    sub(m, m->read_cb(m, mem_abs(arg1, arg2, 0), NULL));
    break;

case SBC_ABX:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    sub(m, m->read_cb(m, mem_abs(arg1, arg2, m->x), NULL));
    break;

case SBC_ABY:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    sub(m, m->read_cb(m, mem_abs(arg1, arg2, m->y), NULL));
    break;

case SBC_IMM:
    sub(m, NEXT_BYTE(m));
    break;

case SBC_INX:
    sub(m, m->read_cb(m, mem_indexed_indirect(m, NEXT_BYTE(m), m->x), NULL));
    break;

case SBC_INY:
    sub(m, m->read_cb(m, mem_indirect_index(m, NEXT_BYTE(m), m->y), NULL));
    break;

case SBC_ZP:
    sub(m, m->read_cb(m, NEXT_BYTE(m), NULL));
    break;

case SBC_ZPX:
    sub(m, m->read_cb(m, ZP(NEXT_BYTE(m) + m->x), NULL));
    break;

case LDA_AB:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    m->ac = m->read_cb(m, mem_abs(arg1, arg2, 0), NULL);
    set_flags(m, m->ac);
    break;

case LDA_ABX:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    m->ac = m->read_cb(m, mem_abs(arg1, arg2, m->x), NULL);
    set_flags(m, m->ac);
    break;

case LDA_ABY:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    m->ac = m->read_cb(m, mem_abs(arg1, arg2, m->y), NULL);
    set_flags(m, m->ac);
    break;

case LDA_IMM:
    m->ac = NEXT_BYTE(m);
    set_flags(m, m->ac);
    break;

case LDA_INX:
    m->ac = m->read_cb(m, mem_indexed_indirect(m, NEXT_BYTE(m), m->x), NULL);
    set_flags(m, m->ac);
    break;

case LDA_INY:
    m->ac = m->read_cb(m, mem_indirect_index(m, NEXT_BYTE(m), m->y), NULL);
    set_flags(m, m->ac);
    break;

case LDA_ZP:
    m->ac = m->read_cb(m, NEXT_BYTE(m), NULL);
    set_flags(m, m->ac);
    break;

case LDA_ZPX:
    m->ac = m->read_cb(m, NEXT_BYTE(m) + m->x, NULL);
    set_flags(m, m->ac);
    break;

case LDX_AB:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    m->x = m->read_cb(m, mem_abs(arg1, arg2, 0), NULL);
    set_flags(m, m->x);
    break;

case LDX_ABY:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    m->x = m->read_cb(m, mem_abs(arg1, arg2, m->y), NULL);
    set_flags(m, m->x);
    break;

case LDX_IMM:
    m->x = NEXT_BYTE(m);
    set_flags(m, m->x);
    break;

case LDX_ZP:
    m->x = m->read_cb(m, NEXT_BYTE(m), NULL);
    set_flags(m, m->x);
    break;

case LDX_ZPY:
    m->x = m->read_cb(m, NEXT_BYTE(m) + m->y, NULL);
    set_flags(m, m->x);
    break;

case LDY_AB:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    m->y = m->read_cb(m, mem_abs(arg1, arg2, 0), NULL);
    set_flags(m, m->y);
    break;

case LDY_ABX:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    m->y = m->read_cb(m, mem_abs(arg1, arg2, m->x), NULL);
    set_flags(m, m->y);
    break;

case LDY_IMM:
    m->y = NEXT_BYTE(m);
    set_flags(m, m->y);
    break;

case LDY_ZP:
    m->y = m->read_cb(m, NEXT_BYTE(m), NULL);
    set_flags(m, m->y);
    break;

case LDY_ZPX:
    m->y = m->read_cb(m, NEXT_BYTE(m) + m->x, NULL);
    set_flags(m, m->y);
    break;

case CMP_AB:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    cmp(m, m->read_cb(m, mem_abs(arg1, arg2, 0), NULL), m->ac);
    break;

case CMP_ABX:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    cmp(m, m->read_cb(m, mem_abs(arg1, arg2, m->x), NULL), m->ac);
    break;

case CMP_ABY:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    cmp(m, m->read_cb(m, mem_abs(arg1, arg2, m->y), NULL), m->ac);
    break;

case CMP_IMM:
    cmp(m, NEXT_BYTE(m), m->ac);
    break;

case CMP_INX:
    cmp(m, m->read_cb(m, mem_indexed_indirect(m, NEXT_BYTE(m), m->x), NULL), m->ac);
    break;

case CMP_INY:
    cmp(m, m->read_cb(m, mem_indirect_index(m, NEXT_BYTE(m), m->y), NULL), m->ac);
    break;

case CMP_ZP:
    cmp(m, m->read_cb(m, NEXT_BYTE(m), NULL), m->ac);
    break;

case CMP_ZPX:
    cmp(m, m->read_cb(m, ZP(NEXT_BYTE(m) + m->x), NULL), m->ac);
    break;

case CPX_AB:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    cmp(m, m->read_cb(m, mem_abs(arg1, arg2, 0), NULL), m->x);
    break;

case CPX_IMM:
    cmp(m, NEXT_BYTE(m), m->x);
    break;

case CPX_ZP:
    cmp(m, m->read_cb(m, NEXT_BYTE(m), NULL), m->x);
    break;

case CPY_AB:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    cmp(m, m->read_cb(m, mem_abs(arg1, arg2, 0), NULL), m->y);
    break;

case CPY_IMM:
    cmp(m, NEXT_BYTE(m), m->y);
    break;

case CPY_ZP:
    cmp(m, m->read_cb(m, NEXT_BYTE(m), NULL), m->y);
    break;

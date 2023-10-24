case STA_AB:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    r1 = mem_abs(arg1, arg2, 0);
    m->write_cb(m, r1, m->ac, NULL);
    mark_dirty(m, r1);
    break;

case STA_ABX:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    r1 = mem_abs(arg1, arg2, m->x);
    m->write_cb(m, r1, m->ac, NULL);
    mark_dirty(m, r1);
    break;

case STA_ABY:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    r1 = mem_abs(arg1, arg2, m->y);
    m->write_cb(m, r1, m->ac, NULL);
    mark_dirty(m, r1);
    break;

case STA_INX:
    r1 = mem_indexed_indirect(m, NEXT_BYTE(m), m->x);
    m->write_cb(m, r1, m->ac, NULL);
    mark_dirty(m, r1);
    break;

case STA_INY:
    r1 = mem_indirect_index(m, NEXT_BYTE(m), m->y);
    m->write_cb(m, r1, m->ac, NULL);
    mark_dirty(m, r1);
    break;

case STA_ZP:
    r1 = ZP(NEXT_BYTE(m));
    m->write_cb(m, r1, m->ac, NULL);
    mark_dirty(m, r1);
    break;

case STA_ZPX:
    r1 = ZP(NEXT_BYTE(m) + m->x);
    m->write_cb(m, r1, m->ac, NULL);
    mark_dirty(m, r1);
    break;

case STX_ZP:
    r1 = ZP(NEXT_BYTE(m));
    m->write_cb(m, r1, m->x, NULL);
    mark_dirty(m, r1);
    break;

case STX_ZPY:
    r1 = ZP(NEXT_BYTE(m) + m->y);
    m->write_cb(m, r1, m->x, NULL);
    mark_dirty(m, r1);
    break;

case STX_AB:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    r1 = mem_abs(arg1, arg2, 0);
    m->write_cb(m, r1, m->x, NULL);
    mark_dirty(m, r1);
    break;

case STY_ZP:
    r1 = ZP(NEXT_BYTE(m));
    m->write_cb(m, r1, m->y, NULL);
    mark_dirty(m, r1);
    break;

case STY_ZPX:
    r1 = ZP(NEXT_BYTE(m) + m->x);
    m->write_cb(m, r1, m->y, NULL);
    mark_dirty(m, r1);
    break;

case STY_AB:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    r1 = mem_abs(arg1, arg2, 0);
    m->write_cb(m, r1, m->y, NULL);
    mark_dirty(m, r1);
    break;

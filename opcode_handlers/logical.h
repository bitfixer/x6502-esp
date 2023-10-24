case AND_IMM:
    m->ac &= NEXT_BYTE(m);
    set_flags(m, m->ac);
    break;

case AND_ZP:
    m->ac &= m->read_cb(m, NEXT_BYTE(m), NULL);
    set_flags(m, m->ac);
    break;

case AND_ZPX:
    m->ac &= m->read_cb(m, ZP(NEXT_BYTE(m) + m->x), NULL);
    set_flags(m, m->ac);
    break;

case AND_AB:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    m->ac &= m->read_cb(m, mem_abs(arg1, arg2, 0), NULL);
    set_flags(m, m->ac);
    break;

case AND_ABX:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    m->ac &= m->read_cb(m, mem_abs(arg1, arg2, m->x), NULL);
    set_flags(m, m->ac);
    break;

case AND_ABY:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    m->ac &= m->read_cb(m, mem_abs(arg1, arg2, m->y), NULL);
    set_flags(m, m->ac);
    break;

case AND_INX:
    m->ac &= m->read_cb(m, mem_indexed_indirect(m, NEXT_BYTE(m), m->x), NULL);
    set_flags(m, m->ac);
    break;

case AND_INY:
    m->ac &= m->read_cb(m, mem_indirect_index(m, NEXT_BYTE(m), m->y), NULL);
    set_flags(m, m->ac);
    break;

case EOR_IMM:
    m->ac ^= NEXT_BYTE(m);
    set_flags(m, m->ac);
    break;

case EOR_ZP:
    m->ac ^= m->read_cb(m, NEXT_BYTE(m), NULL);
    set_flags(m, m->ac);
    break;

case EOR_ZPX:
    m->ac ^= m->read_cb(m, ZP(NEXT_BYTE(m) + m->x), NULL);
    set_flags(m, m->ac);
    break;

case EOR_AB:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    m->ac ^= m->read_cb(m, mem_abs(arg1, arg2, 0), NULL);
    set_flags(m, m->ac);
    break;

case EOR_ABX:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    m->ac ^= m->read_cb(m, mem_abs(arg1, arg2, m->x), NULL);
    set_flags(m, m->ac);
    break;

case EOR_ABY:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    m->ac ^= m->read_cb(m, mem_abs(arg1, arg2, m->y), NULL);
    set_flags(m, m->ac);
    break;

case EOR_INX:
    m->ac ^= m->read_cb(m, mem_indexed_indirect(m, NEXT_BYTE(m), m->x), NULL);
    set_flags(m, m->ac);
    break;

case EOR_INY:
    m->ac ^= m->read_cb(m, mem_indirect_index(m, NEXT_BYTE(m), m->y), NULL);
    set_flags(m, m->ac);
    break;

case ORA_IMM:
    m->ac |= NEXT_BYTE(m);
    set_flags(m, m->ac);
    break;

case ORA_ZP:
    m->ac |= m->read_cb(m, NEXT_BYTE(m), NULL);
    set_flags(m, m->ac);
    break;

case ORA_ZPX:
    m->ac |= m->read_cb(m, ZP(NEXT_BYTE(m) + m->x), NULL);
    set_flags(m, m->ac);
    break;

case ORA_AB:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    m->ac |= m->read_cb(m, mem_abs(arg1, arg2, 0), NULL);
    set_flags(m, m->ac);
    break;

case ORA_ABX:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    m->ac |= m->read_cb(m, mem_abs(arg1, arg2, m->x), NULL);
    set_flags(m, m->ac);
    break;

case ORA_ABY:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    m->ac |= m->read_cb(m, mem_abs(arg1, arg2, m->y), NULL);
    set_flags(m, m->ac);
    break;

case ORA_INX:
    m->ac |= m->read_cb(m, mem_indexed_indirect(m, NEXT_BYTE(m), m->x), NULL);
    set_flags(m, m->ac);
    break;

case ORA_INY:
    m->ac |= m->read_cb(m, mem_indirect_index(m, NEXT_BYTE(m), m->y), NULL);
    set_flags(m, m->ac);
    break;

case BIT_AB:
    arg1 = NEXT_BYTE(m);
    arg2 = NEXT_BYTE(m);
    t1 = m->read_cb(m, mem_abs(arg1, arg2, 0), NULL);
    set_flag(m, FLAG_ZERO, !(t1 & m->ac));
    set_flag(m, FLAG_OVERFLOW, t1 & 0x40);
    set_flag(m, FLAG_NEGATIVE, t1 & 0x80);
    break;

case BIT_ZP:
    t1 = m->read_cb(m, NEXT_BYTE(m), NULL);
    set_flag(m, FLAG_ZERO, !(t1 & m->ac));
    set_flag(m, FLAG_OVERFLOW, t1 & 0x40);
    set_flag(m, FLAG_NEGATIVE, t1 & 0x80);
    break;

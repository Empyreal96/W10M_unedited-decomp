// EtwTraceContextSwap 
 
int (*__fastcall EtwTraceContextSwap(int (*result)(), int a2))()
{
  int (*v3)(); // r9
  unsigned int v4; // r5
  int v5; // r8
  unsigned int v6; // r4
  _DWORD *v7; // r2
  unsigned int v8; // r3
  int v9; // r4
  int v10; // r6
  int v11; // r2
  int v12; // r3
  unsigned int v13; // r2
  int v14; // r3
  int v15; // r1
  unsigned int v16; // r3
  int v17; // r0
  int v18; // r0
  unsigned int v19; // r3
  char v20; // r3
  unsigned __int64 *v21; // lr
  unsigned int v22; // r1
  unsigned int v23; // r6
  unsigned __int64 v24; // kr08_8
  unsigned int v25; // r3
  int v26; // r3
  unsigned int v27; // r3
  int v28; // r2
  unsigned int *v29; // lr
  unsigned int *v30; // t2
  unsigned int v31; // r0
  unsigned int v32; // r6
  unsigned int v33; // r1
  unsigned int *v34; // r2
  unsigned int v35; // r1
  unsigned int v36; // [sp+8h] [bp-40h]
  __int64 v37; // [sp+10h] [bp-38h] BYREF
  __int64 v38; // [sp+18h] [bp-30h] BYREF
  unsigned int v39; // [sp+20h] [bp-28h] BYREF
  unsigned int *v40; // [sp+24h] [bp-24h]

  v3 = result;
  v4 = EtwpActiveSystemLoggers;
  v5 = 0;
  v6 = __clz(__rbit(EtwpActiveSystemLoggers));
  v36 = v6;
  if ( 1 != (unsigned __int8)(v6 >> 5) )
  {
    result = EtwpGetPerfCounter;
    while ( 1 )
    {
      v4 &= v4 - 1;
      v7 = &EtwpGroupMasks[8 * v6];
      if ( !v7 || (v7[1] & 4) == 0 )
        goto LABEL_5;
      v8 = (unsigned __int16)EtwpSystemLogger[2 * v6];
      v9 = v8 >= 0x40 ? 1 : WmipLoggerContext[v8];
      if ( (v9 & 1) != 0 )
        goto LABEL_5;
      if ( (v7[1] & 0x100) == 0 )
        break;
      v10 = 1 << *(_DWORD *)(v9 + 124);
      if ( (v10 & ~v5) == 0 )
        goto LABEL_16;
      if ( *(int (**)())(v9 + 32) != EtwpGetPerfCounter )
        return (int (*)())sub_51B5C4(EtwpGetPerfCounter, WmipLoggerContext);
      KeQueryPerformanceCounter(&v38, 0);
      v37 = v38;
      EtwpCCSwapTrace(v3, a2, *(_DWORD *)(v9 + 124), &v37);
      v5 |= v10;
LABEL_15:
      result = EtwpGetPerfCounter;
LABEL_16:
      v11 = *(_DWORD *)(v9 + 608);
      if ( (v11 & 0x80) == 0 || (*(_BYTE *)(*(_DWORD *)(v9 + 620) + 164) & 0x10) == 0 )
        goto LABEL_5;
      EtwpStackTraceDispatcher(v11 & 0xFFFF0000 | *(_DWORD *)v9, &v37, a2, 3168770);
LABEL_54:
      result = EtwpGetPerfCounter;
LABEL_5:
      v6 = __clz(__rbit(v4));
      v36 = v6;
      if ( 1 == (unsigned __int8)(v6 >> 5) )
        return result;
    }
    v12 = *(_DWORD *)(v9 + 608);
    if ( (v12 & 0xC00) != 0
      && (v12 & 0x800) != 0
      && (v13 = 0, v14 = *(_DWORD *)(*(_DWORD *)(v9 + 628) + 16), __dmb(0xBu), v14) )
    {
      while ( 1 )
      {
        v15 = *(_DWORD *)(v9 + 628);
        if ( *(_WORD *)(v15 + 2 * v13 + 20) == 1316 )
          break;
        v16 = *(_DWORD *)(v15 + 16);
        ++v13;
        __dmb(0xBu);
        if ( v13 >= v16 )
          goto LABEL_26;
      }
      v17 = EtwpReserveWithPmcCounters(v9, 1316, 24, &v39, &v37, 3168770, v36);
    }
    else
    {
LABEL_26:
      v18 = EtwpReserveTraceBuffer((_DWORD *)v9, 0x28u, &v39, &v37, 3168770);
      if ( !v18 )
        goto LABEL_54;
      v19 = v37;
      *(_WORD *)(v18 + 6) = 1316;
      *(_QWORD *)(v18 + 8) = __PAIR64__(HIDWORD(v37), v19);
      *(_DWORD *)v18 = -1072693246;
      *(_WORD *)(v18 + 4) = 40;
      v17 = v18 + 16;
    }
    if ( !v17 )
      goto LABEL_54;
    *(_DWORD *)v17 = *(_DWORD *)(a2 + 880);
    *(_DWORD *)(v17 + 4) = *((_DWORD *)v3 + 220);
    *(_BYTE *)(v17 + 8) = *(_BYTE *)(a2 + 123);
    *(_BYTE *)(v17 + 9) = *((_BYTE *)v3 + 123);
    *(_BYTE *)(v17 + 11) = *(_BYTE *)(a2 + 348);
    *(_BYTE *)(v17 + 12) = *((_BYTE *)v3 + 395);
    *(_BYTE *)(v17 + 13) = *((_BYTE *)v3 + 135);
    v20 = *((_BYTE *)v3 + 132);
    __dmb(0xBu);
    v21 = (unsigned __int64 *)((char *)v3 + 48);
    *(_BYTE *)(v17 + 14) = v20;
    *(_BYTE *)(v17 + 15) = *((_DWORD *)v3 + 91);
    *(_DWORD *)(v17 + 16) = KeTickCount - *(_DWORD *)(a2 + 304);
    while ( 1 )
    {
      v23 = *((_DWORD *)v3 + 13);
      v22 = *(_DWORD *)v21;
      do
        v24 = __ldrexd(v21);
      while ( __PAIR64__(v24, HIDWORD(v24)) == __PAIR64__(v22, v23) && __strexd(__PAIR64__(v23, v22), v21) );
      if ( __PAIR64__(v22, v23) == __PAIR64__(v24, HIDWORD(v24)) )
        break;
      __dmb(0xAu);
      __yield();
    }
    *(_DWORD *)(v17 + 20) = (__int64)(*((_QWORD *)v3 + 3) - __PAIR64__(v23, v22)) >> 10;
    v25 = (unsigned int)KeGetPcr();
    if ( v3 == *(int (**)())((v25 & 0xFFFFF000) + 0x58C) )
    {
      *(_BYTE *)(v17 + 10) = 0;
      v26 = *(_DWORD *)((v25 & 0xFFFFF000) + 0x1100);
      if ( !v26 )
        goto LABEL_43;
      v27 = *(_DWORD *)(v26 + 16);
    }
    else
    {
      v28 = *((_DWORD *)v3 + 17);
      __dmb(0xBu);
      if ( v28 )
      {
        v27 = *(_DWORD *)(*(_DWORD *)((v25 & 0xFFFFF000) + 0xEB0) + v28 + 96);
        if ( v27 > 0xFF )
          LOBYTE(v27) = -1;
      }
      else
      {
        LOBYTE(v27) = 0;
      }
    }
    *(_BYTE *)(v17 + 10) = v27;
LABEL_43:
    v29 = v40;
    v30 = v40;
    __pld(v40);
    v31 = *v30;
    v32 = v39;
    if ( (*v30 ^ v39) >= 7 )
    {
LABEL_49:
      __dmb(0xBu);
      v34 = (unsigned int *)(v32 + 12);
      do
        v35 = __ldrex(v34);
      while ( __strex(v35 - 1, v34) );
      __dmb(0xBu);
    }
    else
    {
      while ( 1 )
      {
        __dmb(0xBu);
        do
          v33 = __ldrex(v29);
        while ( v33 == v31 && __strex(v31 + 1, v29) );
        if ( v33 == v31 )
          break;
        v31 = v33;
        if ( (v33 ^ v32) >= 7 )
          goto LABEL_49;
      }
    }
    goto LABEL_15;
  }
  return result;
}

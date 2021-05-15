// MiDbgTranslatePhysicalAddress 
 
int __fastcall MiDbgTranslatePhysicalAddress(unsigned int a1, int a2, int a3, int a4)
{
  char v5; // r5
  unsigned int v6; // r8
  int v7; // r1
  int v9; // r6
  int v10; // r4
  unsigned __int8 *v11; // r3
  unsigned int v12; // r1
  int v13; // r0
  unsigned int v14; // r0
  unsigned int *v15; // r2
  unsigned int v16; // r1
  int v17; // r3
  char v18; // r0
  unsigned __int8 *v19; // r1
  unsigned int v20; // r2
  int v21; // r3
  _DWORD *v22; // r1
  _DWORD *v23; // r4
  int v24; // r8
  int v25; // r0
  unsigned __int16 v26; // r3
  int v27; // r3
  _DWORD *v28; // r4
  int v29; // r0
  unsigned __int16 v30; // r3
  int v31; // r3
  char v32; // r3
  unsigned int v33; // [sp+4h] [bp-24h]
  int v34; // [sp+8h] [bp-20h]
  unsigned int varg_r0; // [sp+30h] [bp+8h]
  int varg_r3; // [sp+3Ch] [bp+14h]

  varg_r3 = a4;
  v5 = a3;
  varg_r0 = a1;
  v34 = dword_634584;
  v6 = a1;
  if ( !dword_634584 || !MiCheckPhysicalAddressRange(a1, a2) )
    return 0;
  v33 = (v7 << 20) | (v6 >> 12);
  if ( (v5 & 1) != 0 )
    return sub_555088();
  v9 = 1;
  *(_DWORD *)a4 = 0;
  if ( (v5 & 4) != 0 )
  {
    *(_BYTE *)(a4 + 4) = 17;
  }
  else
  {
    v18 = KfRaiseIrql(2);
    v6 = varg_r0;
    v7 = a2;
    *(_BYTE *)(a4 + 4) = v18;
  }
  if ( (BYTE2(MiFlags) & 3) == 3 && (v6 & 0x400) != 0 )
  {
    varg_r0 = v6 & 0xFFFFFBFF;
    v33 = (v7 << 20) | ((v6 & 0xFFFFFBFF) >> 12);
    if ( !MI_IS_PFN(v33) )
      return 0;
    v9 = 3;
  }
  if ( MI_IS_PFN(v33) )
  {
    v10 = MmPfnDatabase + 24 * v33;
    if ( (v5 & 4) != 0 )
    {
      *(_DWORD *)a4 = 1;
      v11 = (unsigned __int8 *)(v10 + 15);
      do
        v12 = __ldrex(v11);
      while ( __strex(v12 | 0x80, v11) );
      __dmb(0xBu);
      if ( v12 >> 7 )
      {
        if ( (v5 & 0x41) != 0 || (KiBugCheckActive & 3) == 0 )
          return 0;
        ++dword_634588;
        *(_DWORD *)a4 = 4;
      }
    }
    else
    {
      *(_DWORD *)a4 = 2;
      v19 = (unsigned __int8 *)(v10 + 15);
      do
        v20 = __ldrex(v19);
      while ( __strex(v20 | 0x80, v19) );
      while ( 1 )
      {
        __dmb(0xBu);
        if ( !(v20 >> 7) )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
          v21 = *(_DWORD *)(v10 + 12);
          __dmb(0xBu);
        }
        while ( v21 < 0 );
        do
          v20 = __ldrex(v19);
        while ( __strex(v20 | 0x80, v19) );
      }
    }
    *(_DWORD *)(a4 + 8) = v10;
    v13 = MiMakeProtectionPfnCompatible(v9, v10);
    v9 = v13;
    if ( (*(_BYTE *)(v10 + 18) & 0xC0) == 192 )
      v9 = v13 | 8;
    goto LABEL_15;
  }
  v22 = (_DWORD *)(a4 + 12);
  if ( (v5 & 4) == 0 )
  {
    *(_DWORD *)a4 = 16;
    KeAcquireInStackQueuedSpinLockAtDpcLevel((unsigned int *)&dword_634880, v22);
    goto LABEL_44;
  }
  *(_DWORD *)a4 = 8;
  if ( !KeTryToAcquireInStackQueuedSpinLockAtDpcLevel((unsigned int *)&dword_634880, v22) )
    return 0;
LABEL_44:
  v23 = (_DWORD *)dword_634888;
  v24 = 3;
  if ( !dword_634888 )
    goto LABEL_55;
  do
  {
    v25 = MiIoPfnCompare(v33, (int)v23);
    if ( v25 >= 0 )
    {
      if ( v25 <= 0 )
        break;
      v23 = (_DWORD *)v23[1];
    }
    else
    {
      v23 = (_DWORD *)*v23;
    }
  }
  while ( v23 );
  if ( !v23
    || ((v26 = *(_WORD *)(v23[6] + 2 * (v33 - v23[5])), __dmb(0xBu), v27 = v26 >> 14, v27 == 3) ? (v23 = 0) : (v24 = v27),
        !v23) )
  {
LABEL_55:
    v28 = (_DWORD *)dword_63488C;
    if ( dword_63488C )
    {
      do
      {
        v29 = MiIoPfnCompare(v33, (int)v28);
        if ( v29 >= 0 )
        {
          if ( v29 <= 0 )
            break;
          v28 = (_DWORD *)v28[1];
        }
        else
        {
          v28 = (_DWORD *)*v28;
        }
      }
      while ( v28 );
      if ( v28 )
      {
        v30 = *(_WORD *)(v28[6] + 2 * (v33 - v28[5]));
        __dmb(0xBu);
        v31 = v30 >> 14;
        if ( v31 != 3 )
          v24 = v31;
      }
    }
  }
  if ( v24 == 3 )
  {
    if ( (v5 & 4) != 0 )
      v24 = 0;
    if ( (v5 & 0x28) != 0 )
      v5 = v5 & 0xC7 | 0x10;
  }
  else
  {
    v32 = v5 & 0xC7;
    if ( v24 )
    {
      if ( v24 == 2 )
        v5 = v32 | 0x20;
      else
        v5 = v32 | 8;
    }
    else
    {
      v5 = v32 | 0x10;
    }
  }
  if ( (v5 & 8) == 0 )
  {
    if ( (v5 & 0x10) != 0 )
    {
      __dsb(0xFu);
      __mcr(15, 0, 0, 8, 7, 0);
      __dsb(0xFu);
      __isb(0xFu);
      v9 |= 0x28u;
    }
    else
    {
      if ( (v5 & 0x20) == 0 )
      {
LABEL_82:
        MiDbgUnTranslatePhysicalAddress(a4);
        return 0;
      }
      __dsb(0xFu);
      __mcr(15, 0, 0, 8, 7, 0);
      __dsb(0xFu);
      __isb(0xFu);
      v9 |= 0x38u;
    }
  }
  if ( v24 == 3 )
    ++dword_634588;
LABEL_15:
  v14 = (MmProtectToPteMask[v9] & 0x3ED | MiDetermineUserGlobalPteMask(dword_634584) | (v33 << 12)) & 0xFFFFF3FF | 0x12;
  if ( (v9 & 4) != 0 )
    v14 &= 0xFFFFFDFF;
  if ( (v5 & 0x41) != 0 )
    byte_634580 = 1;
  __dmb(0xBu);
  v15 = (unsigned int *)dword_634584;
  do
    v16 = __ldrex(v15);
  while ( !v16 && __strex(v14, v15) );
  __dmb(0xBu);
  if ( v16 )
    goto LABEL_82;
  v17 = *(_DWORD *)a4 | 0x20;
  *(_DWORD *)a4 = v17;
  if ( (v17 & 0x12) != 0 )
    KeFlushSingleTb(v34 << 10, 1);
  else
    KeFlushSingleCurrentTb(v34 << 10, 0, (int)v15, v17);
  return (varg_r0 & 0xFFF) + (v34 << 10);
}

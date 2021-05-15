// MiCountSharedPages 
 
int __fastcall MiCountSharedPages(_DWORD *a1, unsigned int a2, unsigned int a3)
{
  _DWORD *v3; // r6
  int v6; // r8
  unsigned int *v7; // r9
  int v8; // r10
  unsigned __int8 *v10; // r3
  unsigned int v11; // r1
  unsigned int v12; // r0
  unsigned int v13; // r5
  int v14; // r2
  unsigned int v15; // r6
  unsigned int v16; // r5
  unsigned int v17; // t1
  int v18; // r5
  unsigned int v19; // r1
  unsigned int *v21; // [sp+10h] [bp-28h] BYREF
  unsigned int *v22; // [sp+14h] [bp-24h]

  v3 = a1;
  v6 = 0;
  v7 = (unsigned int *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 492);
  v22 = v7;
  v8 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_53DA64();
  v10 = (unsigned __int8 *)v7 + 3;
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 | 0x80, v10) );
  __dmb(0xBu);
  if ( v11 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(v7);
  while ( 1 )
  {
    v12 = *v7;
    if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v12 & 0x40000000) == 0 )
    {
      do
        v19 = __ldrex(v7);
      while ( v19 == v12 && __strex(v12 | 0x40000000, v7) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  if ( a2 > a3 )
    goto LABEL_23;
  while ( 2 )
  {
    v13 = MiGetNextPageTable(a2, a3, 0, v8, 1, &v21);
    if ( !v13 )
      v13 = a3 + 4;
    v14 = v3[7];
    if ( (v14 & 7) != 2 || (v14 & 0xF8) == 8 )
    {
      if ( (v14 & 0x28) != 40 )
        v6 += (int)(v13 - a2) >> 2;
      a2 = v13;
    }
    else
    {
      for ( ; a2 < v13; a2 += 4 )
      {
        if ( MiPteNeedsCommitCharge(v3, a2) == 1 )
          ++v6;
      }
    }
    if ( a2 == a3 + 4 )
      break;
    v15 = a2 << 10;
    while ( 1 )
    {
      v17 = *(_DWORD *)a2;
      a2 += 4;
      v16 = v17;
      if ( !v17 )
      {
        if ( MiPteNeedsCommitCharge(a1, a2 - 4) != 1 )
          goto LABEL_20;
LABEL_25:
        ++v6;
        goto LABEL_20;
      }
      if ( (v16 & 2) != 0 )
      {
        if ( (v16 & 0x100) == 0 )
        {
          v18 = MmPfnDatabase + 24 * (v16 >> 12);
          if ( (*(_DWORD *)(v18 + 20) & 0x8000000) != 0
            && (*(_DWORD *)(v18 + 4) | 0x80000000) == MiGetProtoPteAddress(a1, v15 >> 12, 1, &v21) )
          {
            goto LABEL_25;
          }
        }
      }
      else if ( (v16 & 0x400) != 0 )
      {
        if ( (v16 & 0xFFFFE000) == -8192 )
        {
          if ( (v16 & 0xA0) != 160 )
            goto LABEL_25;
        }
        else if ( (v16 & 0x1FC | (v16 >> 2) & 0x3FFFFE00) - 0x40000000 == MiGetProtoPteAddress(a1, v15 >> 12, 1, &v21)
               && ((a1[7] & 7) != 2 || MiPteNeedsCommitCharge(a1, a2 - 4) == 1) )
        {
          goto LABEL_25;
        }
      }
LABEL_20:
      v15 += 4096;
      if ( (a2 & 0xFFF) == 0 )
        break;
      if ( a2 > a3 )
        goto LABEL_22;
    }
    v3 = a1;
    if ( a2 <= a3 )
      continue;
    break;
  }
LABEL_22:
  v7 = v22;
LABEL_23:
  MiUnlockWorkingSetExclusive(v7, v8);
  return v6;
}

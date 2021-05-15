// KiInsertQueueDpc 
 
int __fastcall KiInsertQueueDpc(int a1, int a2, int a3, unsigned int *a4, unsigned __int8 a5)
{
  unsigned int v5; // r5
  int v7; // r10
  unsigned int v9; // r3
  unsigned int v10; // r9
  unsigned int v11; // r1
  unsigned int v12; // r7
  _DWORD *v13; // r6
  unsigned int *v14; // r5
  unsigned int v15; // r2
  unsigned int v16; // r0
  unsigned int *v17; // r2
  unsigned int v18; // r1
  int v19; // r3
  __int16 v20; // r0
  int v21; // r5
  unsigned __int16 *v22; // r2
  unsigned int v23; // r4
  unsigned __int16 *v24; // r2
  unsigned int v25; // r0
  int v26; // r3
  unsigned int *v27; // r1
  unsigned int v28; // r4
  unsigned int v29; // r3
  unsigned int v30; // r4
  int v31; // r2
  int v32; // r0
  unsigned __int8 *v33; // r3
  unsigned int v34; // r2
  int v35; // r2
  _DWORD *v36; // r3
  unsigned __int16 *v37; // r2
  unsigned int v38; // r0
  unsigned int v39; // [sp+8h] [bp-40h]
  int v43; // [sp+24h] [bp-24h]

  v5 = *(unsigned __int16 *)(a1 + 2);
  v7 = 0;
  if ( (dword_682604 & 0x40000) != 0 )
    return sub_54120C();
  v43 = KfRaiseIrql(15);
  v9 = (unsigned int)KeGetPcr();
  v10 = (v9 & 0xFFFFF000) + 1408;
  if ( v5 >= 0x20 )
  {
    v39 = v5 - 32;
    v12 = (unsigned int)*(&KiProcessorBlock + v5 - 32);
  }
  else
  {
    v11 = *(_DWORD *)((v9 & 0xFFFFF000) + 0x594);
    v39 = v11;
    if ( v5 != (unsigned __int16)v11 )
      *(_WORD *)(a1 + 2) = v11;
    v12 = (v9 & 0xFFFFF000) + 1408;
  }
  if ( (*(_DWORD *)(v12 + 1048) & *(_DWORD *)(a1 + 8)) == 0 )
  {
    v31 = *(unsigned __int8 *)(v12 + 1053);
    __dmb(0xBu);
    v32 = 1 << (v31 & 7);
    v33 = (unsigned __int8 *)(a1 + (v31 >> 3) + 8);
    do
      v34 = __ldrex(v33);
    while ( __strex(v34 | v32, v33) );
    __dmb(0xBu);
  }
  if ( *(_BYTE *)a1 == 26 && *(_BYTE *)(v12 + 1752) )
    v13 = (_DWORD *)(v12 + 1704);
  else
    v13 = (_DWORD *)(v12 + 1680);
  v14 = v13 + 2;
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(v13 + 2);
  }
  else
  {
    do
      v15 = __ldrex(v14);
    while ( __strex(1u, v14) );
    __dmb(0xBu);
    if ( v15 )
      KxWaitForSpinLockAndAcquire(v13 + 2);
  }
  v16 = *(_DWORD *)(v10 + 3276);
  if ( v39 != *(_DWORD *)(v10 + 20) )
    v16 = 1;
  __dmb(0xBu);
  v17 = (unsigned int *)(a1 + 28);
  do
    v18 = __ldrex(v17);
  while ( !v18 && __strex(v16, v17) );
  __dmb(0xBu);
  if ( !v18 )
  {
    ++v13[3];
    ++v13[4];
    *(_DWORD *)(a1 + 20) = a2;
    *(_DWORD *)(a1 + 24) = a3;
    v7 = 1;
    if ( *(_BYTE *)(a1 + 1) == 2 )
    {
      v35 = *v13;
      v36 = (_DWORD *)(a1 + 4);
      if ( !*v13 )
        v13[1] = v36;
      *v36 = v35;
      *v13 = v36;
    }
    else
    {
      *(_DWORD *)(a1 + 4) = 0;
      *(_DWORD *)v13[1] = a1 + 4;
      v13[1] = a1 + 4;
    }
  }
  if ( a4 )
  {
    __dmb(0xBu);
    do
      v30 = __ldrex(a4);
    while ( __strex(v30 & ~((a5 << 24) | 0x80), a4) );
    __dmb(0xBu);
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v13 + 2);
  }
  else
  {
    __dmb(0xBu);
    *v14 = 0;
  }
  if ( v7 )
  {
    if ( v13 == (_DWORD *)(v12 + 1704) )
    {
      __dmb(0xBu);
      v37 = (unsigned __int16 *)(v12 + 1758);
      do
        v38 = __ldrex(v37);
      while ( __strex(v38 | 2, v37) );
      __dmb(0xBu);
      if ( (v38 & 0x2F) != 0 )
        goto LABEL_38;
      v20 = 4;
LABEL_31:
      v21 = 47;
      if ( v12 == v10 )
      {
        v21 = 41;
        v20 |= 0x20u;
      }
      __dmb(0xBu);
      v22 = (unsigned __int16 *)(v12 + 1756);
      do
        v23 = __ldrex(v22);
      while ( __strex(v23 | v20, v22) );
      __dmb(0xBu);
      if ( (v21 & v23) == 0 )
      {
        if ( v12 == v10 )
        {
          HalRequestSoftwareInterrupt(2);
        }
        else
        {
          v26 = (int)*(&KiProcessorBlock + v39);
          __dmb(0xBu);
          v27 = (unsigned int *)(v26 + 1676);
          do
            v28 = __ldrex(v27);
          while ( __strex(v28 | 2, v27) );
          __dmb(0xBu);
          v29 = (unsigned int)KeGetPcr();
          ++*(_DWORD *)((v29 & 0xFFFFF000) + 0x1414);
          HalSendSoftwareInterrupt(v39, 2);
        }
      }
      goto LABEL_38;
    }
    if ( v13[3] < *(_DWORD *)(v12 + 1736) )
    {
      v19 = *(unsigned __int8 *)(a1 + 1);
      if ( v10 == v12 )
      {
        if ( !*(_BYTE *)(a1 + 1) && *(_DWORD *)(v12 + 1740) >= *(_DWORD *)(v12 + 1744) )
          goto LABEL_42;
      }
      else if ( v19 != 3 && v19 != 2 )
      {
LABEL_42:
        __dmb(0xBu);
        v24 = (unsigned __int16 *)(v12 + 1756);
        do
          v25 = __ldrex(v24);
        while ( __strex(v25 | 0x10, v24) );
        __dmb(0xBu);
        if ( (v25 & 0x2F) != 0 || (*(_DWORD *)(*(_DWORD *)(v12 + 2360) + 128) & *(_DWORD *)(v12 + 1048)) == 0 )
          goto LABEL_38;
        goto LABEL_30;
      }
    }
LABEL_30:
    v20 = 2;
    goto LABEL_31;
  }
LABEL_38:
  KfLowerIrql(v43);
  return v7;
}

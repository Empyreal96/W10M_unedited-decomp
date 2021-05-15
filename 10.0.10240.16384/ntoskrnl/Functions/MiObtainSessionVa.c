// MiObtainSessionVa 
 
int __fastcall MiObtainSessionVa(int a1)
{
  _DWORD *v2; // r3
  int v3; // r6
  int v4; // r9
  int v5; // r5
  int v6; // r0
  int v8; // r0
  char *v9; // r8
  unsigned int v10; // r6
  int v11; // r2
  int v12; // t1
  unsigned int v13; // r1
  unsigned int v14; // r2
  unsigned int v15; // r1
  int v16; // r7
  int *v17; // r7
  int v18; // r4
  int v19; // r1
  unsigned int v20; // r0
  int v21; // r0
  _DWORD *i; // [sp+0h] [bp-30h]
  char var28[44]; // [sp+8h] [bp-28h] BYREF

  v2 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324) + 0x2000);
  for ( i = v2; ; v2 = i )
  {
    v3 = *v2;
    v4 = 0;
    v5 = 0;
    v6 = KeAcquireInStackQueuedSpinLock(&dword_6342BC, var28);
    if ( dword_63529C )
      return sub_50FF88(v6);
    v8 = 512 - dword_633884;
    v9 = &byte_63505C[dword_633884];
    v10 = v3 + 4 * dword_633884;
    if ( dword_633884 != 512 )
    {
      while ( 1 )
      {
        v12 = (unsigned __int8)*v9++;
        v11 = v12;
        if ( v12 == 1 && !*(_DWORD *)v10 )
          break;
        if ( !v11 )
          break;
        v4 = 0;
        v5 = 0;
LABEL_8:
        v10 += 4;
        if ( !--v8 )
          goto LABEL_37;
      }
      if ( !v11 )
        ++v5;
      if ( ++v4 != a1 )
        goto LABEL_8;
      if ( v8 )
        break;
    }
LABEL_37:
    if ( dword_633884 )
    {
      dword_633884 = 0;
      KeReleaseInStackQueuedSpinLock(var28);
    }
    else
    {
      KeReleaseInStackQueuedSpinLock(var28);
      if ( CcUnmapInactiveViews(16 * a1, 1, 0) != 1 )
      {
        ++dword_635260;
        JUMPOUT(0x50FFA2);
      }
    }
  }
  v13 = dword_635310 - (v5 << 22);
  dword_635310 = v13;
  if ( v9 > &byte_63505C[(int)(3072 - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2] )
    dword_633890 -= v5 << 22;
  v14 = dword_635024 + v5;
  dword_635024 += v5;
  if ( v13 < dword_633888 )
    dword_633888 = v13;
  if ( v14 > dword_6352D8 )
    dword_6352D8 = v14;
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&dword_6342C0);
  }
  else
  {
    do
      v15 = __ldrex((unsigned __int8 *)&dword_6342C0 + 3);
    while ( __strex(v15 | 0x80, (unsigned __int8 *)&dword_6342C0 + 3) );
    __dmb(0xBu);
    if ( v15 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(&dword_6342C0);
    while ( 1 )
    {
      v16 = dword_6342C0;
      if ( (dword_6342C0 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (dword_6342C0 & 0x40000000) == 0 )
      {
        v19 = dword_6342C0 | 0x40000000;
        do
          v20 = __ldrex((unsigned int *)&dword_6342C0);
        while ( v20 == v16 && __strex(v19, (unsigned int *)&dword_6342C0) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  if ( v4 )
  {
    v17 = &MiState[v9 - byte_63505C];
    v18 = v4;
    do
    {
      --v9;
      --v17;
      if ( *v9 != 1 )
        *v9 = 1;
      ++v17[319];
      if ( v10 < 0xC0000000 || v10 > 0xC03FFFFF )
      {
        *(_DWORD *)v10 = 768;
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)v10 = 768;
        if ( v10 + 1070596096 <= 0xFFF )
        {
          v21 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v21, v21 + 4 * (v10 & 0xFFF), 768);
        }
      }
      v10 -= 4;
      --v18;
    }
    while ( v18 );
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_6342C0);
  }
  else
  {
    __dmb(0xBu);
    dword_6342C0 = 0;
  }
  KeReleaseInStackQueuedSpinLock(var28);
  MiReclaimSystemVa(0);
  return dword_63389C + ((v9 - byte_63505C) << 22);
}

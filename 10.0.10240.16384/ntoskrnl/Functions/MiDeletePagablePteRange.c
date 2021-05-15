// MiDeletePagablePteRange 
 
int __fastcall MiDeletePagablePteRange(int a1)
{
  int v1; // r4
  unsigned int *v2; // r5
  int v3; // r6
  unsigned __int8 *v5; // r3
  unsigned int v6; // r1
  unsigned int v7; // r0
  int v8; // r0
  int v9; // r7
  unsigned int v10; // r8
  unsigned int v11; // r10
  unsigned int v12; // r4
  unsigned int v13; // r9
  unsigned int v14; // r6
  unsigned int v15; // r2
  int v16; // r10
  unsigned int v17; // r8
  unsigned int *v18; // r4
  unsigned int v19; // r6
  unsigned int v20; // r1
  int v21; // r0
  int v22; // r0
  unsigned int v23; // r2
  int v24; // r0
  int v25; // [sp+8h] [bp-E0h] BYREF
  unsigned int v26; // [sp+Ch] [bp-DCh]
  int v27; // [sp+10h] [bp-D8h]
  int v28; // [sp+14h] [bp-D4h]
  int v29; // [sp+18h] [bp-D0h]
  int v30; // [sp+20h] [bp-C8h] BYREF
  int v31; // [sp+24h] [bp-C4h]
  int v32; // [sp+28h] [bp-C0h]
  int v33; // [sp+2Ch] [bp-BCh]
  int v34; // [sp+30h] [bp-B8h] BYREF
  char v35; // [sp+34h] [bp-B4h]
  char v36; // [sp+35h] [bp-B3h]
  int v37; // [sp+38h] [bp-B0h]
  int v38; // [sp+3Ch] [bp-ACh]
  int v39; // [sp+40h] [bp-A8h]
  int v40; // [sp+44h] [bp-A4h]

  v1 = -1070592000;
  v30 = 0;
  v31 = 0;
  v32 = 0;
  v33 = 0;
  v28 = a1;
  __mrc(15, 0, 13, 0, 3);
  v2 = (unsigned int *)(a1 + 492);
  v3 = KfRaiseIrql(2);
  v27 = v3;
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_520D8C();
  v5 = (unsigned __int8 *)v2 + 3;
  do
    v6 = __ldrex(v5);
  while ( __strex(v6 | 0x80, v5) );
  __dmb(0xBu);
  if ( v6 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(v2);
  while ( 1 )
  {
    v7 = *v2;
    if ( (*v2 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v7 & 0x40000000) == 0 )
    {
      do
        v20 = __ldrex(v2);
      while ( v20 == v7 && __strex(v7 | 0x40000000, v2) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  v26 = 0x3FFFFF;
  do
  {
    v8 = MiGetNextPageTable(v1, -1070591996, 0, v3, 1, &v25);
    v25 = v8;
    if ( !v8 )
      break;
    v34 = 1;
    v35 = 0;
    v36 = 0;
    v38 = 0;
    v39 = 0;
    v37 = 33;
    v29 = v8 << 10;
    v9 = v8 << 10;
    v10 = v26;
    v40 = 0;
    v11 = 0;
    v12 = v8;
    v13 = v8;
    do
    {
      v14 = *(_DWORD *)v12;
      if ( *(_DWORD *)v12 )
      {
        if ( (v14 & 2) != 0 )
        {
          MiTerminateWsle(v9, v2, *(_DWORD *)(MmPfnDatabase + 24 * (v14 >> 12)));
          MiInsertTbFlushEntry(&v34, v9 & 0xFFFFF000, 1);
          v15 = v14 & 0xFFFFFFFC | 0x400;
          if ( v12 + 0x40000000 > v10 )
          {
            *(_DWORD *)v12 = v15;
          }
          else
          {
            __dmb(0xBu);
            *(_DWORD *)v12 = v15;
            if ( v12 + 1070596096 <= 0xFFF )
            {
              v21 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v21, v21 + 4 * (v12 & 0xFFF), v15);
            }
          }
          v13 = v12;
        }
        else if ( (v14 & 0x400) != 0 || (v14 & 0x800) != 0 || (v14 & 0x10) != 0 )
        {
          v13 = v12;
        }
        else
        {
          MiReleasePageFileSpace(MiSystemPartition, *(_DWORD *)v12, 1);
          if ( v12 + 0x40000000 > v10 )
          {
            *(_DWORD *)v12 = 0;
          }
          else
          {
            __dmb(0xBu);
            *(_DWORD *)v12 = 0;
            if ( v12 + 1070596096 <= 0xFFF )
            {
              v22 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v22, v22 + 4 * (v12 & 0xFFF), 0);
            }
          }
        }
      }
      v12 += 4;
      v9 += 4096;
      if ( v12 > 0xC0301004 )
        break;
      if ( (v12 & 0xFFF) == 0 )
        break;
      ++v11;
    }
    while ( v11 < 0x400 );
    MiFlushTbList(&v34);
    v16 = v28;
    v17 = v25;
    MiDeletePteRun(v25, v13, v28, 0, &v30);
    v18 = (unsigned int *)(((v17 >> 10) & 0x3FFFFC) - 0x40000000);
    v19 = *v18;
    if ( (*(_DWORD *)(MmPfnDatabase + 24 * (*v18 >> 12) + 12) & 0x3FFFFFFF) == 1 )
    {
      MiTerminateWsle(v17, v2, *(_DWORD *)(MmPfnDatabase + 24 * (v19 >> 12)));
      MiInsertTbFlushEntry(&v34, v17 & 0xFFFFF000, 1);
      v23 = v19 & 0xFFFFFFFC | 0x400;
      if ( ((v17 >> 10) & 0x3FFFFC) > v26 )
      {
        *v18 = v23;
      }
      else
      {
        __dmb(0xBu);
        *v18 = v23;
        if ( ((v17 >> 10) & 0x3FFFFC) - 3145728 <= 0xFFF )
        {
          v24 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v24, v24 + 4 * ((v17 >> 10) & 0xFFC), v23);
        }
      }
      MiFlushTbList(&v34);
      MiDeletePteRun(((v17 >> 10) & 0x3FFFFC) - 0x40000000, ((v17 >> 10) & 0x3FFFFC) - 0x40000000, v16, 0, &v30);
    }
    v1 = v17 + 4096;
    v3 = v27;
  }
  while ( v17 + 4096 <= 0xC0301004 );
  MiUnlockWorkingSetExclusive(v2, v3);
  return v31;
}

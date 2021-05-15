// MiExpandSpecialPool 
 
int *__fastcall MiExpandSpecialPool(char a1)
{
  int v1; // r4
  unsigned int *v2; // r6
  unsigned int v3; // r0
  unsigned int v4; // r7
  int v5; // r3
  unsigned int v6; // r9
  int *v7; // r4
  unsigned int v9; // r1
  int v10; // r4
  int v11; // r7
  int v12; // r3
  int v13; // r10
  int v14; // r0
  unsigned int v15; // r7
  int v16; // r10
  int v17; // [sp+0h] [bp-30h]
  char v18[40]; // [sp+8h] [bp-28h] BYREF

  if ( (unsigned int)dword_635310 <= 0x4000000 || dword_632D50 >= dword_632AF0 )
    return 0;
  v1 = (a1 & 1) != 0 ? 7 : 13;
  v17 = a1 & 1;
  if ( (a1 & 0x20) != 0 )
  {
    v2 = (unsigned int *)dword_63501C;
    v3 = MiObtainSessionVa(1);
  }
  else
  {
    v2 = (unsigned int *)&unk_634D00;
    v3 = MiObtainSystemVa(1, v1);
  }
  v4 = v3;
  if ( !v3 )
    return 0;
  v5 = (v3 >> 10) & 0x3FFFFC;
  v6 = v5 - 0x40000000;
  if ( !MiMakeZeroedPageTables(v5 - 0x40000000, v5 - 1073737732, 0) )
  {
    if ( v2 != (unsigned int *)&unk_634D00 )
      v1 = 1;
    MiReturnSystemVa(v4, v4 + 4096, v1, 0);
    return 0;
  }
  do
    v9 = __ldrex((unsigned int *)&dword_632D50);
  while ( __strex(v9 + 1, (unsigned int *)&dword_632D50) );
  v10 = MmPfnDatabase + 24 * (*(_DWORD *)(((v6 >> 10) & 0x3FFFFC) - 0x40000000) >> 12) + 8;
  v11 = *(_DWORD *)v10 & 0x1FFF | 0x2000;
  if ( (unsigned int)(MmPfnDatabase + 24 * (*(_DWORD *)(((v6 >> 10) & 0x3FFFFC) - 0x40000000) >> 12) + 1073741832) > 0x3FFFFF )
  {
    *(_DWORD *)v10 = v11;
  }
  else
  {
    v12 = *(_DWORD *)v10;
    v13 = 0;
    __dmb(0xBu);
    *(_DWORD *)v10 = v11;
    if ( (v12 & 2) == 0 && (v11 & 2) != 0 )
      v13 = 1;
    if ( (unsigned int)(v10 + 1070596096) <= 0xFFF )
    {
      v14 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v14, (_DWORD *)(v14 + 4 * (v10 & 0xFFF)), v11);
    }
    if ( v13 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  if ( v17 )
    v15 = (unsigned int)(v2 + 1);
  else
    v15 = (unsigned int)(v2 + 4);
  v7 = (int *)v6;
  KeAcquireInStackQueuedSpinLock(v2, (unsigned int)v18);
  v16 = 511;
  do
  {
    InsertTailListPte(v15, v7);
    v7 += 2;
    --v16;
  }
  while ( v16 );
  if ( v2 != (unsigned int *)&unk_634D00 )
    MiVaRegionSessionSpecialPool(v6 << 10, 1);
  KeReleaseInStackQueuedSpinLock((int)v18);
  return v7;
}

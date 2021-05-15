// MiInitializeSystemPageTable 
 
int __fastcall MiInitializeSystemPageTable(unsigned int a1, _DWORD *a2)
{
  char v2; // r7
  unsigned int v4; // r0
  unsigned int v5; // r3
  unsigned int v6; // r1
  int v7; // r4
  int v8; // r9
  unsigned int i; // r1
  int v10; // r3
  unsigned int v11; // r10
  unsigned int v12; // r6
  unsigned int v13; // r4
  unsigned int v14; // r2
  int result; // r0
  int v16; // r6
  int v17; // r0
  int v18; // r4
  unsigned int v19; // r2
  char v20[4]; // [sp+0h] [bp-D0h] BYREF
  _DWORD *v21; // [sp+4h] [bp-CCh]
  int v22; // [sp+8h] [bp-C8h]
  int v23; // [sp+Ch] [bp-C4h]
  unsigned int v24; // [sp+10h] [bp-C0h]
  BOOL v25; // [sp+18h] [bp-B8h] BYREF
  char v26; // [sp+1Ch] [bp-B4h]
  char v27; // [sp+1Dh] [bp-B3h]
  int v28; // [sp+20h] [bp-B0h]
  int v29; // [sp+24h] [bp-ACh]
  int v30; // [sp+28h] [bp-A8h]
  int v31; // [sp+2Ch] [bp-A4h]

  v2 = 0;
  v4 = *(_DWORD *)a1;
  v21 = a2;
  v5 = (int)((unsigned __int64)(715827883i64 * ((int)a2 - MmPfnDatabase)) >> 32) >> 2;
  v6 = a1 << 10;
  v7 = v5 + (v5 >> 31);
  v24 = 0x3FFFFF;
  v22 = v7;
  if ( (a1 << 10) + 0x40000000 > 0x3FFFFF )
  {
    if ( (v4 & 2) != 0 )
    {
      if ( v4 >> 12 == dword_63490C )
        goto LABEL_42;
      if ( v4 >> 12 == dword_634914 )
        return sub_5106AC();
    }
    if ( v6 >= (MmPfnDatabase & 0xFFFFF000) && v6 < MmPfnDatabase + 24 * (dword_633850 + 1) )
      return sub_5106AC();
LABEL_42:
    if ( *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1384) )
    {
      v18 = MiMapPageInHyperSpaceWorker(v7, v20, 0x80000000);
      RtlFillMemoryUlong(v18, 4096, -1);
      MiUnmapPageInHyperSpaceWorker(v18, (unsigned __int8)v20[0], 0x80000000);
      v7 = v22;
    }
    else
    {
      MxFillPhysicalPage(v7, -1);
    }
    v8 = 4;
    goto LABEL_3;
  }
  v8 = 6;
LABEL_3:
  for ( i = a1; i >= 0xC0000000; i <<= 10 )
  {
    if ( i > 0xC03FFFFF )
      break;
  }
  if ( i >= dword_63389C
    && ((v10 = *((unsigned __int8 *)&MiState[2423]
               + ((int)(((i >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
         v10 == 11)
     || v10 == 1) )
  {
    v2 = 1;
    MiObtainSessionVaCharges();
  }
  else if ( i <= MmHighestUserAddress || i >= 0xC0000000 && i <= dword_633894 )
  {
    v2 = 4;
  }
  *v21 = 0;
  v11 = *(_DWORD *)(((a1 >> 10) & 0x3FFFFC) - 0x40000000);
  v23 = v2 & 1;
  v12 = v11 >> 12;
  if ( (v2 & 1) != 0 )
  {
    v13 = (MmProtectToPteMask[v8] & 0x7ED | (v7 << 12) | MiDetermineUserGlobalPteMask(a1) | 0x812) & 0xFFFFF9FF;
  }
  else
  {
    v13 = (MmProtectToPteMask[v8] & 0x1ED | (v7 << 12) | MiDetermineUserGlobalPteMask(a1)) & 0xFFFFF1FF | 0x12;
    if ( (v2 & 4) != 0 )
      v13 |= 0x800u;
  }
  if ( v8 == 6 )
    v13 |= 1u;
  if ( ((a1 >> 10) & 0x3FFFFC) == 3148800 && (MiFlags & 0x30) != 0 )
  {
    if ( v23 )
    {
      v12 = MiUpdateSessionPdeMaster(a1 << 20, v13);
    }
    else if ( (v2 & 4) != 0 )
    {
      v12 = v11 >> 12;
    }
    else
    {
      v12 = *(_DWORD *)(PsInitialSystemProcess + 24) >> 12;
    }
  }
  MiInitializePfnForOtherProcess(v22, a1, v12, 0);
  MiMarkPageActive(v21);
  v14 = *(_DWORD *)a1;
  result = 2;
  if ( (*(_DWORD *)a1 & 2) != 0 )
    v2 |= 8u;
  if ( (v2 & 8) != 0 )
  {
    __dmb(0xBu);
    do
      v19 = __ldrex((unsigned int *)a1);
    while ( __strex(v13, (unsigned int *)a1) );
    __dmb(0xBu);
    v25 = (v2 & 4) != 0;
    v26 = 0;
    v27 = 0;
    v30 = 0;
    v28 = 33;
    v29 = 0;
    v31 = 0;
    MiInsertTbFlushEntry(&v25, a1 << 10, 1);
    result = MiFlushTbList(&v25);
  }
  else if ( a1 + 0x40000000 > v24 )
  {
    *(_DWORD *)a1 = v13;
  }
  else
  {
    v16 = 0;
    __dmb(0xBu);
    *(_DWORD *)a1 = v13;
    if ( (v14 & 2) == 0 && (v13 & 2) != 0 )
      v16 = 1;
    if ( a1 + 1070596096 <= 0xFFF )
    {
      v17 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      result = MiArmWriteConvertedHardwarePde(v17, v17 + 4 * (a1 & 0xFFF), v13);
    }
    if ( v16 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  return result;
}

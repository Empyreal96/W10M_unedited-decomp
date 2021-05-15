// CmDumpKey 
 
int __fastcall CmDumpKey(_DWORD *a1, int a2)
{
  _DWORD *v2; // r8
  int v5; // r6
  int v6; // r3
  unsigned int v7; // r0
  unsigned int v8; // r2
  unsigned int v9; // r1
  int v10; // r7
  unsigned int v11; // r1
  __int16 v12; // r3
  int v13; // r2
  int v14; // r3
  int v15; // r0
  unsigned int v16; // r4
  unsigned int v17; // r1
  bool v18; // zf
  int v19; // r0
  unsigned int v20; // r1
  unsigned int v21; // r1
  __int16 v22; // r3
  unsigned int v24; // [sp+8h] [bp-28h] BYREF
  unsigned int v25; // [sp+Ch] [bp-24h] BYREF
  unsigned int v26[8]; // [sp+10h] [bp-20h] BYREF

  v24 = 0;
  v25 = 0;
  v26[0] = 0;
  v2 = (_DWORD *)a1[5];
  if ( v2 == CmpMasterHive )
    return -1073741790;
  CmpLockRegistry();
  v6 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v6 & 0xFFFFFFC0) + 0x134);
  __pld(&CmpShutdownRundown);
  v7 = CmpShutdownRundown & 0xFFFFFFFE;
  v8 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v9 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v9 == v7 && __strex(v8, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v9 == v7 )
  {
    v10 = 1;
  }
  else
  {
    v10 = ExfAcquireRundownProtection(&CmpShutdownRundown);
    if ( !v10 )
    {
      v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v12 = *(_WORD *)(v11 + 0x134) + 1;
      *(_WORD *)(v11 + 308) = v12;
      if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
        KiCheckForKernelApcDelivery(0);
      v5 = -1073741491;
      goto LABEL_19;
    }
  }
  CmpLockKcbShared(a1);
  if ( (a1[1] & 0x20000) != 0 )
  {
    v5 = -1073741444;
LABEL_18:
    CmpUnlockKcb(a1);
LABEL_19:
    CmpUnlockRegistry();
    if ( !v10 )
      return v5;
    __pld(&CmpShutdownRundown);
    v16 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v17 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v17 == v16 && __strex(v16 - 2, (unsigned int *)&CmpShutdownRundown) );
    v18 = v17 == v16;
    goto LABEL_30;
  }
  v13 = a1[6];
  v14 = *(_DWORD *)(v2[8] + 36);
  if ( v13 != v14 )
  {
    v5 = -1073741811;
    goto LABEL_18;
  }
  ExAcquireResourceExclusiveLite(v2[468], 1, v13, v14);
  v5 = CmpSnapshotHiveToOffsetArray((int)v2, (int *)&v25, &v24, v26);
  ExReleaseResourceLite(v2[468]);
  CmpUnlockKcb(a1);
  CmpUnlockRegistry();
  if ( v5 >= 0 )
  {
    v5 = CmpWriteOffsetArrayToFile(v19, v25, v24, v26[0], a2);
    CmpFreeOffsetArray(v25, v24);
  }
  __pld(&CmpShutdownRundown);
  v15 = CmpShutdownRundown & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v20 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v20 == v15 && __strex(v15 - 2, (unsigned int *)&CmpShutdownRundown) );
  v18 = v20 == v15;
LABEL_30:
  if ( !v18 )
    v15 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
  v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v22 = *(_WORD *)(v21 + 0x134) + 1;
  *(_WORD *)(v21 + 308) = v22;
  if ( !v22 && *(_DWORD *)(v21 + 100) != v21 + 100 && !*(_WORD *)(v21 + 310) )
    KiCheckForKernelApcDelivery(v15);
  return v5;
}

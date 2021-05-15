// MiResolveProtoCombine 
 
int __fastcall MiResolveProtoCombine(unsigned int a1, int a2, unsigned int a3)
{
  unsigned int v3; // r5
  int v5; // r7
  int v6; // r8
  int v7; // r0
  int v8; // r5
  unsigned int v9; // r6
  unsigned int *v10; // r2
  unsigned int v11; // r5
  unsigned int v12; // r7
  unsigned int v13; // r8
  int v14; // r5
  unsigned int v15; // r4
  int v16; // r6
  unsigned __int8 *v17; // r1
  unsigned int v18; // r2
  unsigned int *v19; // r2
  unsigned int v20; // r0
  int v21; // r3
  unsigned int v22; // r4
  unsigned int v23; // r10
  unsigned int v24; // r9
  unsigned int v25; // r1
  int v26; // r4
  int v27; // r3
  bool v28; // cf
  int v29; // r9
  unsigned int v30; // r3
  int result; // r0
  unsigned int *v32; // r2
  unsigned int v33; // r1
  unsigned int v34; // r3
  unsigned int v35; // r3
  unsigned int *v36; // r2
  unsigned int v37; // r0
  unsigned int v38; // r3
  int v39; // r9
  int v40; // r0
  int v41; // r3
  char v42; // r7
  int v43; // r0
  int v44; // r3
  unsigned int v46; // [sp+Ch] [bp-2Ch]
  unsigned int v47; // [sp+10h] [bp-28h] BYREF
  int v48; // [sp+14h] [bp-24h]

  v48 = a2;
  v3 = a1;
  v47 = 0;
  if ( !MiLockProtoPoolPage(a3, 0) )
LABEL_69:
    JUMPOUT(0x54F4CC);
  v5 = 3 * (*(_DWORD *)(((a3 >> 10) & 0x3FFFFC) - 0x40000000) >> 12);
  v6 = MmPfnDatabase;
  v46 = v3 << 10;
  v7 = MiLockLeafPage((unsigned int *)a3, 0);
  v8 = v7;
  if ( !v7 )
  {
LABEL_42:
    MiUnlockProtoPoolPage(v6 + 8 * v5, 17);
    goto LABEL_69;
  }
  v9 = *(_DWORD *)a3;
  if ( (*(_DWORD *)a3 & 2) != 0 )
    goto LABEL_4;
  if ( (v9 & 0x400) != 0 || (v9 & 0x800) == 0 || (*(_BYTE *)(v7 + 18) & 0x20) != 0 )
  {
LABEL_40:
    __dmb(0xBu);
    v36 = (unsigned int *)(v8 + 12);
    do
      v37 = __ldrex(v36);
    while ( __strex(v37 & 0x7FFFFFFF, v36) );
    goto LABEL_42;
  }
  if ( !MiUnlinkPageFromList(v7, 0) )
  {
    MiDiscardTransitionPte(v8);
    goto LABEL_40;
  }
  v32 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 2960);
  do
    v33 = __ldrex(v32);
  while ( __strex(v33 + 1, v32) );
  *(_DWORD *)(v8 + 12) &= 0xC0000000;
  ++*(_WORD *)(v8 + 16);
  *(_BYTE *)(v8 + 18) = *(_BYTE *)(v8 + 18) & 0xF8 | 6;
  v9 = (MmProtectToPteMask[(*(_DWORD *)a3 >> 5) & 0x1F] ^ *(_DWORD *)a3) & 0xFED ^ *(_DWORD *)a3 | MiDetermineUserGlobalPteMask(a3) | 0x12;
  v34 = *(_DWORD *)(v8 + 8);
  if ( (v34 & 0x400) == 0 && (v34 & 0x10) != 0 && ((v34 >> 2) & 1) == dword_63F99C )
    v47 = MiCaptureDirtyBitToPfn(v8);
  if ( a3 + 0x40000000 <= 0x3FFFFF )
  {
    v38 = *(_DWORD *)a3;
    v39 = 0;
    __dmb(0xBu);
    *(_DWORD *)a3 = v9;
    if ( (v38 & 2) == 0 )
      v39 = 1;
    if ( a3 + 1070596096 <= 0xFFF )
    {
      v40 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v40, (_DWORD *)(v40 + 4 * (a3 & 0xFFF)), v9);
    }
    if ( v39 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  else
  {
    *(_DWORD *)a3 = v9;
  }
LABEL_4:
  *(_DWORD *)(v8 + 12) = *(_DWORD *)(v8 + 12) & 0xC0000000 | (*(_DWORD *)(v8 + 12) + 1) & 0x3FFFFFFF;
  __dmb(0xBu);
  v10 = (unsigned int *)(v8 + 12);
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 & 0x7FFFFFFF, v10) );
  MiUnlockProtoPoolPage(v6 + 8 * v5, 17);
  if ( v47 )
    MiReleasePageFileInfo((int)MiSystemPartition, v47, 1, v47);
  v12 = a1;
  v13 = v9 >> 12;
  v14 = MmPfnDatabase + 24 * (v9 >> 12);
  v15 = *(_DWORD *)(v14 + 8);
  v16 = MmPfnDatabase + 24 * (*(_DWORD *)(((a1 >> 10) & 0x3FFFFC) - 0x40000000) >> 12);
  v17 = (unsigned __int8 *)(v16 + 15);
  do
    v18 = __ldrex(v17);
  while ( __strex(v18 | 0x80, v17) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v18 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v41 = *(_DWORD *)(v16 + 12);
      __dmb(0xBu);
    }
    while ( v41 < 0 );
    do
      v18 = __ldrex(v17);
    while ( __strex(v18 | 0x80, v17) );
  }
  *(_DWORD *)(v16 + 12) = *(_DWORD *)(v16 + 12) & 0xC0000000 | (*(_DWORD *)(v16 + 12) + 1) & 0x3FFFFFFF;
  __dmb(0xBu);
  v19 = (unsigned int *)(v16 + 12);
  do
    v20 = __ldrex(v19);
  while ( __strex(v20 & 0x7FFFFFFF, v19) );
  if ( (v15 & 0x400) != 0 )
    v21 = (*(unsigned __int16 *)((v15 & 0xFFFFF800 | (2 * (v15 & 0x3FC))) + 0x10) >> 1) & 0x1F;
  else
    v21 = (v15 >> 5) & 0x1F;
  v22 = 16 * (v21 & 0x1F);
  v23 = BYTE2(MiFlags) & 3;
  v24 = dword_63389C;
  if ( v23 )
  {
    v25 = a1 << 10;
    if ( a1 << 10 >= dword_63389C )
    {
      v42 = v21 & 0x1F;
      if ( (v21 & 2) != 0 )
      {
        v43 = MiIsStrongCodeImagePage(v14, &v47, 1024);
        v25 = v46;
        if ( v43 )
        {
          v12 = a1;
          v22 = v22 & 0xFFFFFE0F | 0x30;
        }
        else
        {
          v44 = v42 & 0x1F;
          v12 = a1;
          if ( v44 == 2 )
            v22 = v22 & 0xFFFFFE0F | 0x10;
          else
            v22 &= 0xFFFFFFDF;
        }
      }
      else
      {
        v12 = a1;
      }
    }
  }
  else
  {
    v25 = a1 << 10;
  }
  v26 = (v22 >> 4) & 7;
  v27 = *(unsigned __int8 *)(v14 + 18) >> 6;
  if ( v27 != 1 )
  {
    if ( v27 )
    {
      if ( v27 == 2 )
        v26 |= 0x18u;
    }
    else
    {
      v26 |= 8u;
    }
  }
  v28 = v25 >= v24;
  v29 = v48;
  if ( v28 )
  {
    if ( (*(_BYTE *)(v48 + 112) & 7u) < 2 )
    {
      v35 = MmProtectToPteMask[v26] & 0xFED | (v13 << 12) | MiDetermineUserGlobalPteMask(v12);
    }
    else
    {
      if ( v23 >= 3 && (*(_BYTE *)(v14 + 23) & 7) != 3 )
        v26 &= 0xFFFFFFFD;
      v35 = (MmProtectToPteMask[v26] & 0x3ED | (v13 << 12) | MiDetermineUserGlobalPteMask(v12)) & 0xFFFFF3FF;
    }
    v30 = v35 | 0x12;
  }
  else
  {
    v30 = (MmProtectToPteMask[v26] | (v13 << 12)) & 0xFFFFFBFF | 0x832;
  }
  if ( MiAllocateWsle(v29, v12, v14, 0, v30, 0) )
    result = 1;
  else
    result = sub_54F4BC();
  return result;
}

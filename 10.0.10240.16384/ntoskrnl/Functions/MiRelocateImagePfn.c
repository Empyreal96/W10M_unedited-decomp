// MiRelocateImagePfn 
 
int __fastcall MiRelocateImagePfn(int a1, unsigned int a2, unsigned int a3, int a4, int a5)
{
  _DWORD *v9; // r6
  int v10; // r1
  _DWORD *v11; // r2
  unsigned int v13; // r10
  int v14; // r9
  int v15; // r3
  unsigned int v16; // r4
  int v18; // r0
  int v19; // r3
  int v20; // r4
  unsigned int v21; // r1
  int v22; // r3
  int v23; // r4
  int v24; // r1
  unsigned int *v25; // r0
  unsigned int v26; // r2
  unsigned int *v27; // r5
  unsigned int v28; // r2
  int v29; // [sp+8h] [bp-28h]
  int v30; // [sp+8h] [bp-28h]
  unsigned int v31; // [sp+Ch] [bp-24h]
  int v32; // [sp+10h] [bp-20h]

  v9 = **(_DWORD ***)(a1 + 56);
  if ( a3 >= v9[6] )
    return 0;
  v10 = 0;
  v11 = (_DWORD *)(*v9 + 4 * a3);
  while ( !*v11++ )
  {
    if ( ++v10 )
    {
      if ( v10 != 5 )
        return 0;
      break;
    }
  }
  if ( a2 && (a2 < 0xC0000000 || a2 > 0xC03FFFFF) )
  {
    v31 = 0;
    v13 = 0;
  }
  else
  {
    v30 = MmPfnDatabase;
    v31 = a2;
    v13 = MiReservePtes(&dword_634D58, 1u);
    if ( !v13 )
      return sub_801660();
    a2 = v13 << 10;
    v20 = MiMakeProtectionPfnCompatible(4, v30 + 24 * a4);
    v21 = (MiDetermineUserGlobalPteMask(v13) | MmProtectToPteMask[v20] & 0x1ED | (a4 << 12)) & 0xFFFFF1FF | 0x12;
    if ( v13 < 0xC0000000 || v13 > 0xC03FFFFF )
    {
      *(_DWORD *)v13 = v21;
    }
    else
    {
      v22 = *(_DWORD *)v13;
      v23 = 0;
      __dmb(0xBu);
      *(_DWORD *)v13 = v21;
      if ( (v22 & 2) == 0 )
        v23 = 1;
      if ( v13 + 1070596096 <= 0xFFF )
        MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v21, v13);
      if ( v23 == 1 )
      {
        __dsb(0xFu);
        __isb(0xFu);
      }
    }
  }
  v14 = a5;
  if ( a5 )
  {
    v15 = v9[5];
  }
  else
  {
    v14 = v9[5];
    v15 = 0;
  }
  v29 = v15;
  v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( v9[1] == v16 )
  {
    v16 = 0;
  }
  else
  {
    --*(_WORD *)(v16 + 310);
    v24 = KeAbPreAcquire((unsigned int)(v9 + 3), 0, 0);
    v32 = v24;
    v25 = v9 + 3;
    do
      v26 = __ldrex(v25);
    while ( !v26 && __strex(0x11u, v25) );
    __dmb(0xBu);
    if ( v26 )
    {
      ExfAcquirePushLockSharedEx(v25, v24, (unsigned int)(v9 + 3));
      v24 = v32;
    }
    if ( v24 )
      *(_BYTE *)(v24 + 14) |= 1u;
  }
  MiPerformFixups(a2, a1, a3, v14, v29, 1);
  if ( v16 )
  {
    v27 = v9 + 3;
    __dmb(0xBu);
    do
      v28 = __ldrex(v27);
    while ( v28 == 17 && __strex(0, v27) );
    if ( v28 != 17 )
      ExfReleasePushLockShared(v9 + 3);
    v18 = KeAbPostRelease((unsigned int)(v9 + 3));
    v19 = (__int16)(*(_WORD *)(v16 + 310) + 1);
    *(_WORD *)(v16 + 310) = v19;
    if ( !v19 && *(_DWORD *)(v16 + 100) != v16 + 100 )
      KiCheckForKernelApcDelivery(v18);
  }
  if ( !v13 )
    return 0;
  if ( v13 == v31 )
  {
    if ( v13 + 0x40000000 > 0x3FFFFF )
    {
      *(_DWORD *)v13 = 0;
    }
    else
    {
      __dmb(0xBu);
      *(_DWORD *)v13 = 0;
      if ( v13 + 1070596096 <= 0xFFF )
        MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), 0, v13);
    }
    KeFlushSingleTb(a2, 1);
    return 0;
  }
  MiReleasePtes(&dword_634D58, v13, 1u);
  return 0;
}

// MiValidateImagePfn 
 
int __fastcall MiValidateImagePfn(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v9; // r9
  int v11; // r7
  unsigned int v12; // r5
  int v13; // r4
  unsigned int v14; // r1
  unsigned int v15; // r6
  int v16; // r4
  int v17; // r0
  int v18; // r3
  int v19; // r4
  unsigned int v20; // r1
  int v21[4]; // [sp+10h] [bp-30h] BYREF
  int v22; // [sp+20h] [bp-20h]

  v21[2] = a3;
  v21[3] = a4;
  v9 = MmPfnDatabase + 24 * a8;
  if ( (BYTE2(MiFlags) & 3u) > 1 )
    return sub_7E62BC(a1);
  v11 = *(_DWORD *)(a1 + 56);
  v22 = *(_DWORD *)(v11 + 4);
  if ( (v22 & 0xFFFFFFF8) == 8 )
    JUMPOUT(0x7E62F2);
  if ( (*(_DWORD *)(a1 + 52) & 0xC000000) != 0 && !*(_DWORD *)(v11 + 8) )
  {
    v16 = SeGetStrongImageReference(v22 & 0xFFFFFFF8, v21, v22);
    if ( v16 < 0 )
      return v16;
    *(_DWORD *)(v11 + 8) = v21[0];
  }
  v12 = MiReservePtes(&dword_634D58, 1u);
  if ( v12 )
  {
    v13 = MiMakeProtectionPfnCompatible(1, v9);
    v14 = (MmProtectToPteMask[v13] & 0x3ED | (a8 << 12) | MiDetermineUserGlobalPteMask(v12)) & 0xFFFFF3FF | 0x12;
    if ( v12 < 0xC0000000 || v12 > 0xC03FFFFF )
    {
      *(_DWORD *)v12 = v14;
    }
    else
    {
      v18 = *(_DWORD *)v12;
      v19 = 0;
      __dmb(0xBu);
      *(_DWORD *)v12 = v14;
      if ( (v18 & 2) == 0 )
        v19 = 1;
      if ( v12 + 1070596096 <= 0xFFF )
        MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v14, v12);
      if ( v19 == 1 )
      {
        __dsb(0xFu);
        __isb(0xFu);
      }
    }
    v15 = 0;
    if ( (MiFlags & 0x100000) != 0 && (*(_DWORD *)(a1 + 52) & 0xC000000) != 0 || a6 == -1 )
      goto LABEL_10;
    v17 = MiRevertRelocatedImagePfn(v12 << 10, a1);
    v15 = v17;
    if ( v17 == -1 )
    {
      v15 = 0;
      goto LABEL_10;
    }
    if ( v17 )
    {
      v21[1] = v17;
LABEL_10:
      v16 = SeValidateImageData(v22 & 0xFFFFFFF8);
      if ( v16 < 0 )
      {
        do
          v20 = __ldrex((unsigned int *)algn_632EF4);
        while ( __strex(v20 + 1, (unsigned int *)algn_632EF4) );
      }
      else
      {
        MiMarkPfnVerified(v9, 0);
      }
      MiReleasePtes(&dword_634D58, v12, 1u);
      if ( v15 )
        ExFreePoolWithTag(v15);
      return v16;
    }
    MiReleasePtes(&dword_634D58, v12, 1u);
  }
  return -1073741670;
}

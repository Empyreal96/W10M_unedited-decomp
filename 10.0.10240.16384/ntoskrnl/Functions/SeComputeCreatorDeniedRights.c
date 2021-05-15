// SeComputeCreatorDeniedRights 
 
int __fastcall SeComputeCreatorDeniedRights(int *a1, int a2, int a3, int a4)
{
  int v4; // r7
  int v8; // r8
  __int16 v9; // r5
  int v10; // r3
  int v11; // r1
  int v12; // r0
  int v13; // r3
  int v14; // r3
  int v15; // r0
  int v16; // r0
  _DWORD *v17; // r3
  void *v18; // [sp+20h] [bp-28h] BYREF
  int v19; // [sp+24h] [bp-24h] BYREF
  int v20[8]; // [sp+28h] [bp-20h] BYREF

  v4 = 0;
  v19 = 0;
  if ( (a3 & 0xC0000) == 0 )
    return 0;
  v8 = *(_DWORD *)(*(_DWORD *)(a2 + 48) + 44);
  if ( !v8 )
  {
    v8 = a4;
    if ( !a4 )
    {
      v8 = *(_DWORD *)(a2 + 44);
      if ( !v8 )
        return 0;
    }
  }
  v9 = *(_WORD *)(v8 + 2);
  if ( (v9 & 4) != 0 )
  {
    if ( (*(_WORD *)(v8 + 2) & 0x8000) != 0 )
    {
      v10 = *(_DWORD *)(v8 + 16);
      if ( !v10 )
        return sub_52F494();
      v11 = v10 + v8;
    }
    else
    {
      v11 = *(_DWORD *)(v8 + 16);
    }
  }
  else
  {
    v11 = 0;
  }
  if ( !RtlpOwnerAcesPresent(0, v11) )
  {
    if ( (v9 & 0x10) != 0 )
    {
      if ( (v9 & 0x8000) != 0 )
      {
        v14 = *(_DWORD *)(v8 + 12);
        v12 = v14 ? v14 + v8 : 0;
      }
      else
      {
        v12 = *(_DWORD *)(v8 + 12);
      }
    }
    else
    {
      v12 = 0;
    }
    v18 = 0;
    v13 = (unsigned __int8)SepRmEnforceCap;
    __dmb(0xBu);
    if ( !v13 )
      return 0;
    if ( !v12 )
      return 0;
    v16 = SepGetScopedPolicySid();
    if ( !v16 )
      return 0;
    v17 = SepRmReferenceFindCap(v16, &v18) >= 0 ? v18 : SepRmDefaultCap;
    if ( (v17[7] & 1) == 0 )
      return 0;
  }
  v15 = *a1;
  if ( !*a1 )
    v15 = a1[2];
  if ( !SepTokenIsOwner(v15, v8) )
    return 0;
  if ( (a3 & 0x40000) != 0
    && !SeAccessCheckWithHint(
          v8,
          0,
          a1,
          1,
          0x40000u,
          0,
          0,
          (int)StandardBitMapping,
          *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A),
          &v19,
          v20) )
  {
    v4 = 0x40000;
  }
  if ( (a3 & 0x80000) != 0
    && !SeAccessCheckWithHint(
          v8,
          0,
          a1,
          1,
          0x80000u,
          0,
          0,
          (int)StandardBitMapping,
          *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A),
          &v19,
          v20) )
  {
    v4 |= 0x80000u;
  }
  return v4;
}

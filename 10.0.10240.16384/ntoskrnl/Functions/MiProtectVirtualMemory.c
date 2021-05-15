// MiProtectVirtualMemory 
 
int __fastcall MiProtectVirtualMemory(int a1, int a2, int *a3, int *a4, int a5, int *a6)
{
  unsigned int v6; // r4
  int v7; // r7
  int v9; // r1
  int v10; // r9
  int v11; // r8
  unsigned int v12; // r10
  int v13; // r0
  int v14; // r5
  int v15; // r6
  int v16; // r2
  int v17; // r3
  int v18; // r3
  unsigned int v19; // r4
  int v20; // r6
  unsigned int *v21; // r3
  int v22; // r0
  int v23; // r4
  __int16 v24; // r2
  int v25; // r4
  int v26; // r3
  int v27; // [sp+10h] [bp-50h]
  int v30[2]; // [sp+1Ch] [bp-44h] BYREF
  int v31; // [sp+24h] [bp-3Ch]
  unsigned int v32; // [sp+28h] [bp-38h] BYREF
  int v33; // [sp+2Ch] [bp-34h]
  int v34; // [sp+30h] [bp-30h] BYREF
  int v35[10]; // [sp+38h] [bp-28h] BYREF

  v33 = a2;
  v35[0] = a1;
  *a6 = 1;
  v30[0] = 0;
  v27 = 0;
  v6 = *a3;
  v7 = a5;
  v30[1] = 1;
  v31 = *a4;
  v32 = v6;
  if ( a5 < 0 )
  {
    v27 = 1;
    v7 = a5 & 0x7FFFFFFF;
  }
  if ( (v7 & 0x40000000) != 0 )
    return sub_800F88();
  v10 = MiMakeProtectionMask(v7);
  if ( v10 == -1 )
    return -1073741755;
  v11 = v6 & 0xFFFFF000;
  v12 = (v9 + v6 - 1) | 0xFFF;
  v13 = MiObtainReferencedVad(v6 & 0xFFFFF000, &v34);
  v14 = v13;
  if ( !v13 )
  {
    v23 = v34;
    if ( v34 == -1073741664 )
      v23 = -1073741800;
    return v23;
  }
  if ( v12 >> 12 > *(_DWORD *)(v13 + 16) )
    goto LABEL_45;
  v15 = 0;
  if ( (v10 & 2) != 0 )
  {
    v23 = MiAllowProtectionChange(v33, v35[0], v13, v10, v11, v12);
    if ( v23 < 0 )
      goto LABEL_41;
    if ( (*(_DWORD *)(v14 + 28) & 0x10) == 0 && MiIsProcessCfgEnabled() )
    {
      if ( (v24 & 0x4000) != 0 )
      {
        v23 = MiCheckSecuredVad((_DWORD *)v14, v32, v31, v10);
        if ( v23 < 0 )
          goto LABEL_41;
        v15 = 1;
      }
      v35[0] = v11;
      v35[1] = v12;
      v23 = MiCommitVadCfgBits(v14, v35, 0);
      if ( v23 < 0 )
        goto LABEL_41;
    }
  }
  v16 = *(_DWORD *)(v14 + 28);
  v17 = v16 & 7;
  switch ( v17 )
  {
    case 5:
      goto LABEL_51;
    case 3:
      if ( v10 == 24 || v10 == 1 || v10 == 4 )
      {
        v25 = MiProtectAweRegion(v11, v12, v10);
        MiUnlockAndDereferenceVad(v14);
        *a4 = v12 - v11 + 1;
        *a3 = v11;
        *a6 = v25;
        return 0;
      }
      goto LABEL_45;
    case 1:
LABEL_45:
      v23 = -1073741800;
      goto LABEL_41;
  }
  v18 = v27;
  if ( v27 == 1 )
  {
    if ( (v16 & 0x8000) != 0 || (*(_DWORD *)(**(_DWORD **)(v14 + 44) + 28) & 0x20) != 0 )
      goto LABEL_40;
    v18 = 1;
  }
  if ( (v16 & 0x4000) != 0 && !v15 )
  {
    v23 = MiCheckSecuredVad((_DWORD *)v14, v32, v31, v10);
    if ( v23 < 0 )
      goto LABEL_41;
    v18 = v27;
  }
  v16 = *(_DWORD *)(v14 + 28);
  if ( (v16 & 0x8000) != 0 )
  {
    if ( (v7 & 0x88) == 0 && v18 != 1 )
    {
      if ( (*(_DWORD *)(v14 + 28) & 7) == 6 )
      {
        if ( (v7 & 0xFFFFF9F9) != 0 )
        {
          v23 = -1073741755;
          goto LABEL_41;
        }
        v26 = (unsigned __int8)v16 >> 6;
        v7 &= 0xFFFFF9FF;
        if ( v26 == 3 && (v16 & 0x38) != 0 )
        {
          v7 |= 0x400u;
        }
        else if ( v26 == 1 )
        {
          v7 |= 0x200u;
        }
        v10 = MiMakeProtectionMask(v7);
      }
      v22 = MiProtectPrivateMemory(v14, v11, v12, v10, v7, (int)&v32, v30);
LABEL_23:
      v23 = v22;
      if ( v22 >= 0 )
      {
        MiUnlockAndDereferenceVad(v14);
        *a4 = v12 - v11 + 1;
        *a3 = v11;
        *a6 = v32;
        if ( v30[0] == 1 )
          return 1073741847;
        return 0;
      }
LABEL_41:
      MiUnlockAndDereferenceVad(v14);
      return v23;
    }
LABEL_40:
    v23 = -1073741582;
    goto LABEL_41;
  }
  if ( (*(_DWORD *)(v14 + 28) & 7) == 7 )
  {
LABEL_51:
    if ( v10 == (unsigned __int8)v16 >> 3 )
      goto LABEL_52;
    goto LABEL_45;
  }
  if ( (v7 & 0x600) != 0 )
    goto LABEL_40;
  v19 = *(_DWORD *)(**(_DWORD **)(v14 + 44) + 28);
  v20 = (v19 >> 5) & 1;
  if ( !v20 && !MiIsPteProtectionCompatible((unsigned __int8)v16 >> 3, v7) )
    goto LABEL_62;
  if ( (v19 & 0x80) != 0 && !v20 )
    goto LABEL_22;
  if ( !MiVadMapsLargeImage(v14) )
  {
    if ( !MiIsRangeFullyCommitted(v14, v11, (unsigned int *)v12, v21) )
    {
      v23 = -1073741779;
      goto LABEL_41;
    }
LABEL_22:
    v22 = MiSetProtectionOnSection(v33, (_DWORD *)v14, v11, v12, v7, v27, &v32, v30);
    goto LABEL_23;
  }
  if ( v7 != 64 && v7 != 4 )
  {
LABEL_62:
    v23 = -1073741746;
    goto LABEL_41;
  }
LABEL_52:
  MiUnlockAndDereferenceVad(v14);
  *a4 = v12 - v11 + 1;
  *a3 = v11;
  *a6 = MmProtectToValue[v10];
  return 0;
}

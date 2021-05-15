// MiMapViewOfPhysicalSection 
 
int __fastcall MiMapViewOfPhysicalSection(int a1, unsigned int *a2, __int64 *a3, _DWORD *a4, unsigned int a5, int a6, int a7, unsigned __int8 *a8)
{
  int v10; // r4
  unsigned int v11; // r10
  int v12; // r4
  _BYTE *v13; // r0
  _DWORD *v14; // r5
  unsigned int v15; // r7
  __int64 *v16; // r6
  unsigned int v17; // r4
  int v18; // r3
  unsigned int v19; // r6
  unsigned int v20; // r1
  int v21; // r2
  int v22; // r10
  unsigned int v23; // r4
  bool v24; // cc
  int v25; // r0
  unsigned int v26; // r9
  int v27; // r8
  int v28; // r6
  int v29; // r0
  int v30; // r9
  int v31; // r0
  int v33; // [sp+10h] [bp-48h] BYREF
  _DWORD *v34; // [sp+14h] [bp-44h]
  int v35; // [sp+18h] [bp-40h]
  unsigned int v36; // [sp+1Ch] [bp-3Ch] BYREF
  __int64 *v37; // [sp+20h] [bp-38h]
  unsigned int v38; // [sp+24h] [bp-34h]
  unsigned int v39; // [sp+28h] [bp-30h]
  int v40; // [sp+2Ch] [bp-2Ch]
  unsigned int *v41; // [sp+30h] [bp-28h]
  int v42; // [sp+34h] [bp-24h]
  unsigned int v43; // [sp+38h] [bp-20h]

  v34 = a4;
  v37 = a3;
  v41 = a2;
  if ( (a7 & 0x20002000) != 0 )
    return -1073741577;
  v11 = a5 >> 3;
  if ( a5 >> 3 == 2 || (a5 & 5) == 5 || a5 == 24 )
    return -1073741755;
  v39 = 0;
  v36 = 0;
  v12 = __mrc(15, 0, 13, 0, 3);
  v35 = v12;
  v13 = (_BYTE *)ExAllocatePoolWithTag(512, 76, 1818517846);
  v14 = v13;
  if ( !v13 )
    return -1073741670;
  memset(v13, 0, 76);
  v14[2] = -2;
  v14[11] = &dword_632E24;
  v14[10] &= 0xFBFFFFFF;
  v14[7] = v14[7] & 0xFFFFFF01 | (8 * (a5 & 0x1F)) | 1;
  v14[6] = 0;
  v15 = *a3 >> 12;
  v33 = 0;
  v38 = -1;
  v14[12] = v15;
  v14[13] = v15;
  LOCK_ADDRESS_SPACE(v12 & 0xFFFFFFC0, a1);
  if ( (*(_DWORD *)(a1 + 192) & 0x20) == 0 )
  {
    if ( *v41 )
    {
      v19 = *v41 & 0xFFFF0000 | (unsigned __int16)*(_DWORD *)v37;
      v17 = (*v34 + v19 - 1) | 0xFFF;
      v40 = v17;
      if ( v19 < 0x10000 && !*(_DWORD *)(a1 + 780) || MiCheckForConflictingVadExistence() )
      {
        v10 = -1073741800;
        goto LABEL_36;
      }
    }
    else
    {
      v16 = v37;
      v40 = *v34 + (unsigned __int16)*(_DWORD *)v37;
      v10 = MiSelectUserAddress(a7, a6, v40, 0x10000, a5, &v36, &v33);
      if ( v10 < 0 )
        goto LABEL_36;
      v17 = (v40 + v33 - 1) | 0xFFF;
      v18 = *(_DWORD *)v16;
      v40 = v17;
      v19 = v33 + (unsigned __int16)v18;
      v39 = v36;
    }
    v14[3] = v19 >> 12;
    v14[4] = v17 >> 12;
    v20 = (v17 >> 12) - (v19 >> 12) + v15;
    v43 = v17 >> 12;
    v21 = 1;
    v36 = v20;
    if ( v11 == 3 && (a5 & 7) != 0 )
    {
      v21 = 2;
    }
    else if ( v11 == 1 )
    {
      v21 = 0;
    }
    v22 = 0;
    v23 = v15;
    v24 = v15 > v20;
    v42 = MiPlatformCacheAttributes[v21 + 6];
    v33 = -1;
    while ( 1 )
    {
      v37 = (__int64 *)v23;
      if ( v24 )
        break;
      v25 = MI_IS_PFN(v23);
      if ( !v25 )
      {
        if ( !v22 )
          v33 = v23;
        ++v22;
      }
      if ( (v25 == 1 || v23 == v36) && v22 )
      {
        v10 = MiReferenceIoPages(1, v33, v22, v42, 0, 0);
        if ( v10 < 0 )
          goto LABEL_36;
        v23 = (unsigned int)v37;
        v38 = v33 + v22 - 1;
        v33 = -1;
        v22 = 0;
      }
      v24 = ++v23 > v36;
    }
    v10 = MiInsertVadCharges((int)v14, a1);
    if ( v10 >= 0 )
    {
      MiInsertViewOfPhysicalSection(a1, (int)v14);
      if ( v39 == 1 )
        MiAdvanceVadHint(v19 >> 12, v43);
      *v34 = v40 - v19 + 1;
      if ( (a5 & 2) != 0 && MiIsProcessCfgEnabled() )
      {
        v30 = v35;
        MiLockVad(v35 & 0xFFFFFFC0, (int)v14);
        UNLOCK_ADDRESS_SPACE_UNORDERED(v30 & 0xFFFFFFC0, a1);
        v10 = MiCommitVadCfgBits((int)v14, 0, a8);
        if ( v10 < 0 )
        {
          v31 = MiReferenceVad((int)v14);
          MiDeleteVad(v31, 0);
          return v10;
        }
        MiUnlockVad(v30 & 0xFFFFFFC0, (int)v14);
      }
      else
      {
        UNLOCK_ADDRESS_SPACE(v35 & 0xFFFFFFC0, a1);
      }
      v10 = 0;
      *v41 = v19;
      return v10;
    }
    goto LABEL_36;
  }
  v10 = -1073741558;
LABEL_36:
  UNLOCK_ADDRESS_SPACE(v35 & 0xFFFFFFC0, a1);
  v26 = v38;
  if ( v38 != -1 )
  {
    v27 = -1;
    v28 = 0;
    while ( v15 <= v26 )
    {
      v29 = MI_IS_PFN(v15);
      if ( !v29 )
      {
        if ( !v28 )
          v27 = v15;
        ++v28;
      }
      if ( v29 == 1 || v15 == v26 )
      {
        if ( v28 )
        {
          MiDereferenceIoPages(1, v27, v28);
          v27 = -1;
          v28 = 0;
        }
      }
      ++v15;
    }
  }
  ExFreePoolWithTag((unsigned int)v14);
  return v10;
}

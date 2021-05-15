// CmpValidateHiveSecurityDescriptors 
 
int __fastcall CmpValidateHiveSecurityDescriptors(int a1, int a2, _BYTE *a3, int a4)
{
  int v4; // r4
  int v6; // r6
  _DWORD *v7; // r7
  BOOL v8; // r9
  int v10; // r0
  int v11; // r8
  int v12; // r4
  int v13; // r3
  int v14; // r10
  int v15; // r0
  unsigned int v16; // r2
  unsigned int v17; // r1
  unsigned int v18; // r3
  void (__fastcall *v19)(int, int *); // r3
  int v20; // r4
  int v21; // r4
  int v22; // r3
  int v23; // r3
  int v24; // r0
  int v25; // r3
  unsigned int v26; // r3
  int v27; // r3
  int v28; // [sp+8h] [bp-38h] BYREF
  int v29; // [sp+Ch] [bp-34h] BYREF
  int v30; // [sp+10h] [bp-30h] BYREF
  int v31; // [sp+14h] [bp-2Ch]
  int v32; // [sp+18h] [bp-28h]
  _BYTE *v33; // [sp+1Ch] [bp-24h]

  v4 = *(_DWORD *)(a1 + 1992);
  v31 = a4;
  v32 = a2;
  v6 = *(_DWORD *)(a1 + 28);
  v7 = 0;
  v33 = a3;
  v30 = -1;
  v28 = -1;
  v8 = v4 == 0;
  if ( !HvIsCellAllocated(a1, *(_DWORD *)(*(_DWORD *)(a1 + 32) + 36), 0, -1) )
    return sub_8057DC();
  v10 = (*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, *(_DWORD *)(*(_DWORD *)(a1 + 32) + 36), &v30);
  v11 = v10;
  if ( !v10 )
    JUMPOUT(0x8057E6);
  v12 = *(_DWORD *)(v10 + 44);
  v13 = 0;
  v29 = 0;
  v14 = v12;
  while ( HvIsCellAllocated(a1, v12, v31, v13) )
  {
    v15 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v12, &v28);
    v7 = (_DWORD *)v15;
    if ( !v15 )
    {
      v22 = 144;
      goto LABEL_52;
    }
    v16 = -4 - *(_DWORD *)(v15 - 4);
    if ( v16 < 0x14 )
      goto LABEL_33;
    v17 = *(_DWORD *)(v15 + 16);
    v18 = v17 + 20;
    if ( v17 + 20 < v17 || v18 > v16 )
      goto LABEL_33;
    if ( v12 != v14 )
    {
      v18 = *(_DWORD *)(v15 + 8);
      if ( v18 != v29 )
      {
        v22 = 160;
        goto LABEL_52;
      }
    }
    if ( !RtlValidRelativeSecurityDescriptor(v15 + 20, v17, 0, v18) )
    {
LABEL_33:
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v28);
      v7 = 0;
      goto LABEL_34;
    }
    if ( v8 )
    {
      if ( CmpAddSecurityCellToCache(a1, v12, 1) < 0 )
      {
        v22 = 176;
        goto LABEL_52;
      }
    }
    else if ( !CmpFindSecurityCellCacheIndex((_DWORD *)a1, v12, &v29) )
    {
      v22 = 192;
      goto LABEL_52;
    }
    v19 = *(void (__fastcall **)(int, int *))(a1 + 8);
    v29 = v12;
    v12 = v7[1];
    v19(a1, &v28);
    v7 = 0;
    if ( v12 == v14 )
    {
      if ( v8 )
        CmpAdjustSecurityCacheSize((_DWORD *)a1);
      if ( (v32 & 0x2000000) == 0 || *(_DWORD *)(a1 + 1992) <= 1u )
      {
LABEL_20:
        v20 = 0;
        goto LABEL_21;
      }
      v21 = 0;
      while ( CmpCheckSecurityCellAccess(a1, *(_DWORD *)(*(_DWORD *)(a1 + 2004) + 8 * v21), 1, 131097) >= 0 )
      {
        if ( (unsigned int)++v21 >= *(_DWORD *)(a1 + 1992) )
          goto LABEL_20;
      }
      v22 = 208;
      goto LABEL_52;
    }
  }
  if ( v14 == v12 )
  {
    v22 = 128;
    goto LABEL_52;
  }
LABEL_34:
  v23 = (unsigned __int8)CmpSelfHeal;
  if ( CmpSelfHeal || (v23 = CmpBootType, (CmpBootType & 6) != 0) )
  {
    if ( HvIsCellAllocated(a1, *(_DWORD *)(v11 + 44), 0, v23) )
    {
      v24 = (*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, *(_DWORD *)(v11 + 44), &v28);
      v7 = (_DWORD *)v24;
      if ( v24 )
      {
        if ( RtlValidRelativeSecurityDescriptor(v24 + 20, *(_DWORD *)(v24 + 16), 0, v25) )
        {
          v26 = v7[4];
          if ( v26 + 20 < v26 || v26 + 20 > -4 - *(v7 - 1) )
          {
            v22 = 80;
          }
          else
          {
            if ( HvpMarkCellDirty(a1, *(_DWORD *)(v11 + 44), 0, 0) )
            {
              v27 = *(_DWORD *)(v11 + 44);
              v7[1] = v27;
              v7[2] = v27;
              CmpDestroySecurityCache((_DWORD *)a1);
              CmpInitSecurityCache((_DWORD *)a1);
              *(_DWORD *)(*(_DWORD *)(a1 + 32) + 4088) |= 4u;
              v20 = 2;
              *v33 = 1;
              goto LABEL_21;
            }
            v22 = 96;
          }
        }
        else
        {
          v22 = 64;
        }
      }
      else
      {
        v22 = 48;
      }
    }
    else
    {
      v22 = 32;
    }
  }
  else
  {
    v22 = 112;
  }
LABEL_52:
  SetFailureLocation(v6, 0, 9, -1073741492, v22);
  v20 = 1;
LABEL_21:
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v30);
  if ( v7 )
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v28);
  return v20;
}

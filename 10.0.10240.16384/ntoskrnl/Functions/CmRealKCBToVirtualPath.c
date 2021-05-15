// CmRealKCBToVirtualPath 
 
int __fastcall CmRealKCBToVirtualPath(int a1, _DWORD *a2, int a3)
{
  int v3; // r7
  int v7; // r4
  int *v8; // r5
  unsigned __int16 *v9; // r0
  unsigned __int16 *v10; // r4
  int v11; // r2
  int v12; // r10
  __int16 v13; // r1
  __int16 v14; // r3
  int v15; // r7
  int v16; // r0
  int v17; // r0
  unsigned __int16 v18; // r1
  unsigned int v19; // r1
  int v20; // r2
  int v21; // r0
  int v22; // r7
  unsigned __int16 v23; // r3
  int v24; // r4
  _WORD *v25; // r3
  int v26; // r2
  int v27; // r0
  int v28; // r2
  int v29; // r2
  int v30; // r3
  int v31; // r2
  int v32; // r3
  int v34[2]; // [sp+0h] [bp-38h] BYREF
  __int64 v35; // [sp+8h] [bp-30h] BYREF
  unsigned __int16 v36; // [sp+10h] [bp-28h] BYREF
  int v37; // [sp+12h] [bp-26h]
  __int16 v38; // [sp+16h] [bp-22h]

  v36 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0i64;
  v3 = 0;
  if ( !CmpVEEnabled )
    return -1073741811;
  v8 = (int *)CmpConstructName(a1);
  if ( !v8 )
  {
    v9 = (unsigned __int16 *)CmpConstructName(*(_DWORD *)(a1 + 40));
    v10 = v9;
    if ( !v9 )
      return -1073741670;
    v11 = *(_DWORD *)(a1 + 44);
    v12 = 0;
    v13 = *v9 + 10;
    v34[0] = 0;
    v14 = *(_WORD *)(v11 + 12);
    if ( (*(_DWORD *)v11 & 1) != 0 )
    {
      v15 = (unsigned __int16)(v13 + 2 * v14);
      v12 = v11 + 14;
    }
    else
    {
      v15 = (unsigned __int16)(v14 + v13);
      v34[0] = v11 + 14;
    }
    v16 = ExAllocatePoolWithTag(1, v15, 1649298755);
    v8 = (int *)v16;
    if ( v16 )
    {
      *(_DWORD *)(v16 + 4) = v16 + 8;
      *(_WORD *)v16 = v15 - 8;
      *(_WORD *)(v16 + 2) = v15 - 8;
      v17 = 0;
      if ( (*v10 & 0xFFFE) != 0 )
      {
        v18 = 0;
        do
        {
          *(_WORD *)(v8[1] + 2 * v17) = *(_WORD *)(*((_DWORD *)v10 + 1) + 2 * v17);
          v17 = ++v18;
        }
        while ( v18 < (unsigned int)(*v10 >> 1) );
      }
      v19 = 0;
      *(_WORD *)(v8[1] + 2 * v17) = 92;
      v20 = *(_DWORD *)(a1 + 44);
      v21 = (unsigned __int16)(v17 + 1);
      if ( *(_WORD *)(v20 + 12) )
      {
        v22 = v34[0];
        do
        {
          if ( (*(_DWORD *)v20 & 1) != 0 )
          {
            *(_WORD *)(v8[1] + 2 * v21) = *(unsigned __int8 *)(v19 + v12);
            v23 = v19 + 1;
          }
          else
          {
            *(_WORD *)(v8[1] + 2 * v21) = *(_WORD *)(v22 + 2 * (v19 >> 1));
            v23 = v19 + 2;
          }
          v20 = *(_DWORD *)(a1 + 44);
          v19 = v23;
          v21 = (unsigned __int16)(v21 + 1);
        }
        while ( v23 < (unsigned int)*(unsigned __int16 *)(v20 + 12) );
      }
    }
    ExFreePoolWithTag((unsigned int)v10);
    if ( !v8 )
      return -1073741670;
    v3 = 0;
  }
  v7 = CmpGetVirtualizationID(&v36);
  if ( v7 >= 0 )
  {
    v24 = v36 + *(unsigned __int16 *)v8 + 38;
    if ( a2 )
    {
      LODWORD(v35) = *a2;
      v25 = (_WORD *)a2[1];
      HIDWORD(v35) = v25;
      if ( v25 )
      {
        v26 = (unsigned __int16)v35;
        if ( (_WORD)v35 )
        {
          if ( *v25 )
          {
            if ( *v25 == 92 )
            {
              HIDWORD(v35) = v25 + 1;
              v26 = (unsigned __int16)(v35 - 2);
              LOWORD(v35) = v35 - 2;
            }
            if ( v26 )
            {
              v3 = 1;
              v24 += v26 + 2;
            }
          }
        }
      }
    }
    v27 = ExAllocatePoolWithTag(1, v24, 1649298755);
    *(_DWORD *)(a3 + 4) = v27;
    if ( v27 )
    {
      *(_WORD *)(a3 + 2) = v24;
      *(_WORD *)a3 = 0;
      v7 = RtlAppendUnicodeToString((unsigned __int16 *)a3, (int)L"\\Registry\\User\\", v28, 0);
      if ( v7 < 0 )
        goto LABEL_39;
      v7 = RtlAppendUnicodeStringToString((unsigned __int16 *)a3, &v36);
      if ( v7 < 0
        || (v7 = RtlAppendUnicodeToString((unsigned __int16 *)a3, (int)L"\\VirtualStore", v29, v30), v7 < 0)
        || (v34[0] = *v8,
            v34[1] = v8[1] + 18,
            LOWORD(v34[0]) -= 18,
            v7 = RtlAppendUnicodeStringToString((unsigned __int16 *)a3, (unsigned __int16 *)v34),
            v7 < 0)
        || v3
        && ((v7 = RtlAppendUnicodeToString((unsigned __int16 *)a3, (int)L"\\", v31, v32), v7 < 0)
         || (v7 = RtlAppendUnicodeStringToString((unsigned __int16 *)a3, (unsigned __int16 *)&v35), v7 < 0)) )
      {
LABEL_39:
        RtlFreeAnsiString((_DWORD *)a3);
      }
    }
    else
    {
      v7 = -1073741670;
    }
  }
  ExFreePoolWithTag((unsigned int)v8);
  RtlFreeAnsiString(&v36);
  return v7;
}

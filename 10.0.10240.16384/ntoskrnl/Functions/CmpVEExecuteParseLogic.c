// CmpVEExecuteParseLogic 
 
int __fastcall CmpVEExecuteParseLogic(int a1, int *a2, int *a3, _DWORD *a4)
{
  int v5; // r8
  __int16 v6; // r3
  int *v7; // r4
  int *v8; // r7
  int v10; // r9
  int v11; // r4
  int (__fastcall **v12)(void *); // r8
  int v13; // r0
  int v14; // r2
  unsigned int v15; // r0
  int v16; // r3
  int v17; // r4
  int v18; // r7
  int v19; // r2
  int v20; // r3
  unsigned int v21; // r0
  int v22; // r2
  int v23; // r2
  int v24; // r3
  unsigned int v25; // r0
  char v27[4]; // [sp+8h] [bp-50h] BYREF
  int (__fastcall **v28)(void *); // [sp+Ch] [bp-4Ch] BYREF
  int v29; // [sp+10h] [bp-48h] BYREF
  int v30; // [sp+14h] [bp-44h] BYREF
  int *v31; // [sp+18h] [bp-40h] BYREF
  int v32; // [sp+20h] [bp-38h] BYREF
  int v33; // [sp+24h] [bp-34h]
  int v34; // [sp+28h] [bp-30h] BYREF
  int v35; // [sp+2Ch] [bp-2Ch]
  unsigned __int16 v36; // [sp+30h] [bp-28h] BYREF
  int v37; // [sp+32h] [bp-26h]
  __int16 v38; // [sp+36h] [bp-22h]

  v32 = 0;
  v5 = 0;
  v33 = 0;
  v34 = 0;
  v35 = 0;
  v36 = 0;
  v37 = 0;
  v38 = 0;
  v30 = -1;
  v6 = *(_WORD *)(a1 + 106);
  v7 = a3;
  v31 = a3;
  v8 = a2;
  v10 = 0;
  if ( (v6 & 0x200) != 0 )
  {
    v10 = a1;
LABEL_14:
    *v7 |= 8u;
    if ( CmpVirtualBranchIsReplicated(v10, a2, v27) )
      goto LABEL_15;
    if ( (*v7 & 1) != 0 && v27[0] )
    {
      v16 = *(unsigned __int16 *)(a1 + 106);
      if ( (v16 & 0x200) == 0 )
      {
        if ( (*(_DWORD *)(a1 + 4) & 0x10) != 0 )
          goto LABEL_15;
        if ( !*(_WORD *)v8 )
        {
          v18 = 0;
          goto LABEL_36;
        }
        v11 = CmpBlockHiveWrites(*(int **)(a1 + 20), 0, 0);
        if ( v11 < 0 )
          goto LABEL_48;
        v17 = CmpFindPathByName(a1, v8, 0, &v29, &v28);
        CmpUnblockHiveWrites(*(int **)(a1 + 20), 0, 0);
        v18 = 0;
LABEL_33:
        if ( v17 )
        {
LABEL_36:
          if ( (*(_WORD *)(a1 + 106) & 0x200) != 0 )
          {
            v21 = a4[1];
            if ( v21 )
              ExFreePoolWithTag(v21);
            *a4 = v34;
            a4[1] = v18;
            v35 = 0;
            goto LABEL_20;
          }
          goto LABEL_47;
        }
LABEL_15:
        if ( !v10 )
        {
          v15 = a4[1];
          if ( v15 )
            ExFreePoolWithTag(v15);
          *a4 = v32;
          a4[1] = v5;
LABEL_19:
          v33 = 0;
LABEL_20:
          v11 = 260;
LABEL_48:
          RtlFreeAnsiString(&v36);
          RtlFreeAnsiString(&v34);
          RtlFreeAnsiString(&v32);
          return v11;
        }
LABEL_47:
        v11 = -1073741199;
        goto LABEL_48;
      }
      v11 = CmVirtualKCBToRealPath(a1, (int)&v36, v14, v16);
      if ( v11 < 0 )
        goto LABEL_48;
      HIWORD(v34) = v36 + *(_WORD *)v8 + 2;
      v35 = ExAllocatePoolWithTag(1, HIWORD(v34), 1649298755);
      if ( v35 )
      {
        RtlCopyUnicodeString((unsigned __int16 *)&v34, &v36);
        RtlAppendUnicodeToString((unsigned __int16 *)&v34, (int)L"\\", v19, v20);
        RtlAppendUnicodeStringToString((unsigned __int16 *)&v34, (unsigned __int16 *)v8);
        v11 = CmpBlockHiveWrites(0, 16, &v31);
        if ( v11 < 0 )
          goto LABEL_48;
        v17 = CmpFindPathByName(0, &v34, 0, &v29, &v28);
        CmpUnblockHiveWrites(0, 16, v31);
        v18 = v35;
        goto LABEL_33;
      }
    }
    else
    {
      if ( (*(_WORD *)(a1 + 106) & 0x200) == 0 )
        goto LABEL_47;
      v22 = *(_DWORD *)(a1 + 4);
      if ( (v22 & 0x7FE00000u) <= 0xA00000 )
        goto LABEL_47;
      v11 = CmVirtualKCBToRealPath(a1, (int)&v36, v22, v22 & 0x7FE00000);
      if ( v11 < 0 )
        goto LABEL_48;
      RtlFreeAnsiString(&v32);
      HIWORD(v32) = v36 + *(_WORD *)v8 + 2;
      v33 = ExAllocatePoolWithTag(1, HIWORD(v32), 1649298755);
      if ( v33 )
      {
        RtlCopyUnicodeString((unsigned __int16 *)&v32, &v36);
        RtlAppendUnicodeToString((unsigned __int16 *)&v32, (int)L"\\", v23, v24);
        RtlAppendUnicodeStringToString((unsigned __int16 *)&v32, (unsigned __int16 *)v8);
        v25 = a4[1];
        if ( v25 )
          ExFreePoolWithTag(v25);
        *a4 = v32;
        a4[1] = v33;
        goto LABEL_19;
      }
    }
    v11 = -1073741670;
    goto LABEL_48;
  }
  if ( (*(_DWORD *)(a1 + 4) & 0x10) != 0 )
    goto LABEL_52;
  v11 = CmpBlockHiveWrites(*(int **)(a1 + 20), 0, 0);
  if ( v11 >= 0 )
  {
    if ( CmpFindPathByName(a1, v8, 0, &v29, &v28) )
    {
      v12 = v28;
      v13 = ((int (__fastcall *)(int (__fastcall **)(void *), int, int *))v28[1])(v28, v29, &v30);
      if ( v13 )
      {
        if ( (*(_DWORD *)(v13 + 52) & 0x200000) != 0 )
          v11 = -1073741199;
      }
      else
      {
        v11 = -1073741670;
      }
      ((void (__fastcall *)(int (__fastcall **)(void *), int *))v12[2])(v12, &v30);
    }
    CmpUnblockHiveWrites(*(int **)(a1 + 20), 0, 0);
    if ( !v11 )
    {
LABEL_52:
      v11 = CmRealKCBToVirtualPath(a1, v8, (int)&v32);
      if ( v11 >= 0 )
      {
        v5 = v33;
        v7 = v31;
        a2 = &v32;
        goto LABEL_14;
      }
    }
  }
  return v11;
}

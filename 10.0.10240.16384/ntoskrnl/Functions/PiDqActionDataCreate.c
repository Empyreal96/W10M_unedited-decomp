// PiDqActionDataCreate 
 
int __fastcall PiDqActionDataCreate(int a1, int a2, _DWORD *a3, _DWORD *a4)
{
  _DWORD *v5; // r7
  int v8; // r5
  _BYTE *v9; // r0
  _DWORD *v10; // r4
  unsigned int v12; // r8
  int v13; // r0
  int v14; // r2
  int v15; // r1
  int v16; // r7
  bool v17; // zf
  int v18; // r2
  int v19; // r0
  int v20; // r0
  _DWORD v22[9]; // [sp+1Ch] [bp-24h] BYREF

  v5 = a4;
  v22[0] = 0;
  v8 = 0;
  *a4 = 0;
  v9 = (_BYTE *)ExAllocatePoolWithTag(1, 20, 1483763280);
  v10 = v9;
  if ( !v9 )
    return sub_7C6CF4();
  memset(v9, 0, 20);
  if ( !a3[2] )
  {
    *v10 = 0;
    v10[1] = 1;
    goto LABEL_12;
  }
  *v10 = a3[4];
  v10[1] = *(_DWORD *)(a1 + 16);
  v8 = PnpAllocatePWSTR(*(unsigned __int16 **)(a3[2] + 12), 0x7FFFFFFFu, 1483763280, v10 + 2);
  if ( v8 < 0 )
    goto LABEL_22;
  v12 = *(_DWORD *)(a1 + 44);
  if ( (v12 || (*(_DWORD *)(a1 + 32) & 2) != 0) && (*v10 == 1 || *v10 == 2) )
  {
    v13 = PiDqGetPnpObjectType(*(_DWORD *)(a1 + 16));
    v15 = *(_DWORD *)(a1 + 32);
    v16 = v13;
    if ( (v15 & 2) == 0 )
    {
      v17 = v14 == 1;
      v18 = v10[2];
      if ( v17 )
        v19 = PiDqActionDataGetRequestedProperties(
                a2,
                v13,
                v18,
                *(_DWORD *)(a1 + 32) & 4,
                *(_DWORD *)(a1 + 40),
                *(_DWORD **)(a1 + 48),
                v12,
                v10 + 4,
                v10 + 3);
      else
        v19 = PiDqActionDataGetChangedProperties(
                a2,
                v13,
                v18,
                *(_DWORD *)(a1 + 32) & 4,
                *(_DWORD *)(a1 + 40),
                *(_DWORD *)(a1 + 48),
                v12,
                a3[3],
                v10 + 4,
                v10 + 3);
      goto LABEL_11;
    }
    if ( v14 != 1 )
    {
      v19 = PiDqActionDataGetChangedProperties(
              a2,
              v13,
              v10[2],
              *(_DWORD *)(a1 + 32) & 4,
              *(_DWORD *)(a1 + 40),
              0,
              0,
              a3[3],
              v10 + 4,
              v10 + 3);
LABEL_11:
      v5 = a4;
      v8 = v19;
      goto LABEL_12;
    }
    if ( (v15 & 4) != 0 )
    {
      v8 = PiDqActionDataGetAllPropertiesInBestLanguage(a2, 0, v13, v10[2], *(_DWORD *)(a1 + 40), v10 + 4, v10 + 3, v22);
      if ( v8 >= 0 )
      {
        v20 = PiDqActionDataGetAllPropertiesInBestLanguage(
                a2,
                1,
                v16,
                v10[2],
                *(_DWORD *)(a1 + 40),
                v10 + 4,
                v10 + 3,
                v22);
        goto LABEL_29;
      }
    }
    else
    {
      v8 = PiDqActionDataGetAllPropertiesInAllLanguages(a2, 0, v13, v10[2], v10 + 4, v10 + 3, v22);
      if ( v8 >= 0 )
      {
        v20 = PiDqActionDataGetAllPropertiesInAllLanguages(a2, 1, v16, v10[2], v10 + 4, v10 + 3, v22);
LABEL_29:
        v8 = v20;
        v5 = a4;
        if ( v20 == -1073741772 )
          v8 = 0;
        goto LABEL_12;
      }
    }
LABEL_22:
    PiDqActionDataFree(v10);
    return v8;
  }
LABEL_12:
  if ( v8 < 0 || *v10 == 2 && !v10[3] )
    goto LABEL_22;
  *v5 = v10;
  return v8;
}

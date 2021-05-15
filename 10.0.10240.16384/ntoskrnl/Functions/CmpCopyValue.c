// CmpCopyValue 
 
int __fastcall CmpCopyValue(int a1, int a2, int a3, int a4)
{
  int (__fastcall *v4)(int, int, int *); // r4
  int v6; // r5
  int v8; // r0
  int v9; // r10
  int v10; // r4
  unsigned int v11; // r7
  int v12; // r9
  bool v13; // zf
  int v14; // r0
  int v15; // r9
  int v16; // r0
  int v17; // r9
  int *v18; // r0
  int v19; // r0
  char v21[4]; // [sp+10h] [bp-38h] BYREF
  int v22; // [sp+14h] [bp-34h] BYREF
  unsigned int v23; // [sp+18h] [bp-30h] BYREF
  unsigned int v24; // [sp+1Ch] [bp-2Ch] BYREF
  int v25; // [sp+20h] [bp-28h] BYREF
  int v26; // [sp+24h] [bp-24h]
  int v27[8]; // [sp+28h] [bp-20h] BYREF

  v4 = *(int (__fastcall **)(int, int, int *))(a1 + 4);
  v6 = -1;
  v26 = a4;
  v27[0] = a2;
  v22 = -1;
  v8 = v4(a1, a2, &v22);
  v9 = v8;
  if ( !v8 )
    return -1;
  v11 = *(_DWORD *)(v8 + 4);
  if ( v11 < 0x80000000 )
  {
    v12 = 0;
  }
  else
  {
    v11 += 0x80000000;
    v12 = 1;
  }
  v25 = *(_DWORD *)(v8 + 8);
  v23 = v11;
  v10 = CmpCopyCell(a1, v27[0], a3);
  if ( v10 == -1 || !v11 )
  {
LABEL_37:
    if ( v9 )
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v22);
    return v10;
  }
  if ( v11 <= 4 )
  {
    if ( v12 )
    {
      v17 = *(_DWORD *)(v9 + 8);
    }
    else
    {
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v22);
      v18 = (int *)(*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, MEMORY[8], &v22);
      if ( !v18 )
        goto LABEL_33;
      v17 = *v18;
    }
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v22);
    v19 = (*(int (__fastcall **)(int, int, int *))(a3 + 4))(a3, v10, &v22);
    if ( v19 )
    {
      *(_DWORD *)(v19 + 4) = v11 + 0x80000000;
      *(_DWORD *)(v19 + 8) = v17;
      (*(void (__fastcall **)(int, int *))(a3 + 8))(a3, &v22);
      v9 = 0;
      goto LABEL_37;
    }
LABEL_33:
    HvFreeCell(a3, v10);
    return v6;
  }
  if ( (*(_DWORD *)(a1 + 148) < 4u || v11 - 16345 > 0x7FFFC026)
    && (*(_DWORD *)(a3 + 148) < 4u || v11 - 16345 > 0x7FFFC026) )
  {
    v15 = CmpCopyCell(a1, v25, a3);
  }
  else
  {
    v25 = -1;
    v13 = CmpGetValueData(a1, v27[0], v9, &v23, (int *)&v24, v21, (int)&v25) == 0;
    v14 = a3;
    if ( v13 )
    {
LABEL_15:
      HvFreeCell(v14, v10);
      v10 = -1;
      goto LABEL_37;
    }
    v11 = v23;
    if ( CmpSetValueDataNew(a3, v24, v23, v26, v27) < 0 )
    {
      if ( v21[0] == 1 )
        ExFreePoolWithTag(v24);
      else
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v25);
      goto LABEL_20;
    }
    if ( v21[0] == 1 )
      ExFreePoolWithTag(v24);
    else
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v25);
    v15 = v27[0];
  }
  if ( v15 == -1 )
  {
LABEL_20:
    v14 = a3;
    goto LABEL_15;
  }
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v22);
  v16 = (*(int (__fastcall **)(int, int, int *))(a3 + 4))(a3, v10, &v22);
  if ( v16 )
  {
    *(_DWORD *)(v16 + 4) = v11;
    *(_DWORD *)(v16 + 8) = v15;
    (*(void (__fastcall **)(int, int *))(a3 + 8))(a3, &v22);
    return v10;
  }
  HvFreeCell(a3, v10);
  CmpFreeValueData(a3, v15, v11);
  return v6;
}

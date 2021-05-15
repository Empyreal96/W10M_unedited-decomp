// CmpSetValueKeyExisting 
 
int __fastcall CmpSetValueKeyExisting(int a1, int a2, _DWORD *a3, int a4, int a5, unsigned int a6, int a7)
{
  int v9; // r4
  unsigned int v11; // r8
  int v12; // r10
  int v13; // r7
  unsigned int v14; // r7
  int v15; // r0
  int v16; // r4
  int v17; // r3
  int v18; // r0
  int v19; // [sp+8h] [bp-28h] BYREF
  int v20; // [sp+Ch] [bp-24h] BYREF
  int v21; // [sp+10h] [bp-20h]

  v21 = a4;
  v19 = -1;
  v9 = 0;
  if ( !HvpMarkCellDirty(a1, a2, 0, 0) )
    return sub_805F34();
  v11 = a3[1];
  if ( v11 < 0x80000000 )
  {
    v12 = *(_DWORD *)(a1 + 148) >= 4u && v11 - 16345 <= 0x7FFFC026 ? 2 : 1;
  }
  else
  {
    v11 += 0x80000000;
    v12 = 0;
  }
  if ( a6 > 4 )
    v13 = *(_DWORD *)(a1 + 148) >= 4u && a6 - 16345 <= 0x7FFFC026 ? 2 : 1;
  else
    v13 = 0;
  v20 = v13;
  if ( !CmpMarkValueDataDirty(a1, a3) )
    return sub_805F34();
  if ( v13 )
  {
    v14 = a3[2];
    if ( v20 != 1 )
    {
      if ( v20 != 2 )
        return v9;
      if ( v12 == 2 )
      {
        v9 = CmpSetValueDataExisting(a1, a5, a6, a7, a3[2]);
        if ( v9 < 0 )
          return v9;
      }
      else
      {
        v9 = CmpSetValueDataNew(a1, a5, a6, a7, &v20);
        if ( v9 < 0 )
          return v9;
        if ( v12 && v11 )
          HvFreeCell(a1, a3[2]);
        v14 = v20;
      }
      a3[1] = a6;
      a3[2] = v14;
      goto LABEL_12;
    }
    if ( v12 == 1 && v11 )
    {
      v15 = (*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, a3[2], &v19);
      if ( v15 )
      {
        if ( a6 <= -4 - *(_DWORD *)(v15 - 4) )
        {
          v16 = v14;
          goto LABEL_24;
        }
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v19);
        v20 = 0;
        v18 = HvReallocateCell(a1, v14, a6, 1, &v20, &v19);
        v16 = v18;
        if ( v18 != -1 )
        {
          a3[2] = v18;
LABEL_31:
          v15 = v20;
LABEL_24:
          memmove(v15, a5, a6);
          (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v19);
          v17 = v21;
          a3[2] = v16;
          a3[3] = v17;
          a3[1] = a6;
          if ( v12 == 2 )
            CmpFreeValueData(a1, v14, v11);
          return 0;
        }
      }
    }
    else
    {
      v16 = HvAllocateCell(a1, a6);
      if ( v16 != -1 )
        goto LABEL_31;
    }
    return -1073741670;
  }
  if ( v12 == 1 && v11 || v12 == 2 )
    CmpFreeValueData(a1, a3[2], v11);
  a3[1] = a6 + 0x80000000;
  a3[2] = 0;
  memmove((int)(a3 + 2), a5, a6);
LABEL_12:
  a3[3] = v21;
  return 0;
}

// CmpMarkValueDataDirty 
 
BOOL __fastcall CmpMarkValueDataDirty(int a1, int a2, int a3, int a4)
{
  unsigned int v6; // r2
  int v7; // r4
  int (__fastcall *v9)(int); // r3
  int v10; // r7
  int v11; // r0
  int v12; // r6
  int v13; // r1
  unsigned int i; // r4
  int v15; // r1
  int v16; // [sp+0h] [bp-20h] BYREF
  int v17[7]; // [sp+4h] [bp-1Ch] BYREF

  v16 = a3;
  v17[0] = a4;
  if ( *(_DWORD *)(a2 + 8) == -1 )
    return 1;
  v6 = *(_DWORD *)(a2 + 4);
  if ( v6 >= 0x80000000 )
    return 1;
  if ( *(_DWORD *)(a1 + 148) >= 4u && v6 - 16345 <= 0x7FFFC026 )
  {
    v9 = *(int (__fastcall **)(int))(a1 + 4);
    v16 = -1;
    v17[0] = -1;
    v10 = 0;
    v11 = v9(a1);
    v12 = v11;
    if ( !v11 )
      return 0;
    v13 = *(_DWORD *)(v11 + 4);
    if ( v13 != -1 )
    {
      v10 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v13, &v16);
      if ( !v10 )
      {
        v7 = 0;
        goto LABEL_19;
      }
      for ( i = 0; i < *(unsigned __int16 *)(v12 + 2); i = (unsigned __int16)(i + 1) )
      {
        v15 = *(_DWORD *)(v10 + 4 * i);
        if ( v15 != -1 && !HvpMarkCellDirty(a1, v15, 0, 0) )
          goto LABEL_23;
      }
      if ( !HvpMarkCellDirty(a1, *(_DWORD *)(v12 + 4), 0, 0) )
      {
LABEL_23:
        v7 = 0;
LABEL_17:
        if ( v10 )
          (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v16);
LABEL_19:
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, v17);
        if ( !v7 )
          return v7;
        return HvpMarkCellDirty(a1, *(_DWORD *)(a2 + 8), 0, 0) != 0;
      }
    }
    v7 = 1;
    goto LABEL_17;
  }
  return HvpMarkCellDirty(a1, *(_DWORD *)(a2 + 8), 0, 0) != 0;
}

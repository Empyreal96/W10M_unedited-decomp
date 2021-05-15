// sub_7EB2D8 
 
void __fastcall sub_7EB2D8(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // r5
  int *v8; // r7
  int v9; // r8
  int v10; // r10
  int v11; // r9
  int *v12; // r6
  int v13; // r0
  _DWORD *v14; // r4
  unsigned int v15; // r2

  v10 = *(_DWORD *)(v7 + 44);
  v11 = 0;
  v12 = v8;
  while ( 1 )
  {
    v13 = (*(int (__fastcall **)(int, int, int *))(v7 + 4))(v7, *v12, &a5);
    v14 = (_DWORD *)v13;
    if ( !v13 )
      goto LABEL_16;
    if ( *(_DWORD *)(v13 + 12) )
    {
      if ( !HvpMarkCellDirty(v7, *v12, 0, 0) )
        goto LABEL_15;
      v14[3] = 0;
      ++v11;
    }
    v15 = v12[1];
    if ( v15 >= v14[5] || v9 == 511 )
    {
      if ( !v9 )
      {
        CmpLogClearAccessBitsEvent(a7, v11, (unsigned int)(*(_DWORD *)(v7 + 44) - v10) >> 3);
LABEL_15:
        (*(void (__fastcall **)(int, int *))(v7 + 8))(v7, &a5);
LABEL_16:
        JUMPOUT(0x7080D2);
      }
      --v9;
      v12 -= 2;
    }
    else
    {
      if ( CmpFindSubKeyByNumber(v7, v14, v15, &a6) < 0 )
        goto LABEL_15;
      ++v9;
      ++v12[1];
      v12[2] = a6;
      v12 += 2;
      v12[1] = 0;
    }
    (*(void (__fastcall **)(int, int *))(v7 + 8))(v7, &a5);
  }
}

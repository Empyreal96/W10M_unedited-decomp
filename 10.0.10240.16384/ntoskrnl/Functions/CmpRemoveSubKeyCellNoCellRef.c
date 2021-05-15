// CmpRemoveSubKeyCellNoCellRef 
 
int __fastcall CmpRemoveSubKeyCellNoCellRef(int a1, int a2, int a3)
{
  int (__fastcall *v4)(int, int, int *); // r3
  int v7; // r5
  unsigned __int16 *v8; // r9
  int v9; // r7
  unsigned int v10; // r10
  int (__fastcall *v11)(int, unsigned int, int *); // r3
  unsigned __int16 *v12; // r0
  unsigned __int16 *v13; // r6
  unsigned int v14; // r10
  int v15; // r8
  int i; // r9
  int (__fastcall *v17)(int, unsigned int, int *); // r3
  unsigned __int16 *v18; // r0
  unsigned int v19; // r0
  unsigned int v20; // r3
  BOOL v21; // r8
  unsigned int v22; // r8
  int v23; // r0
  int v24; // r8
  int v25; // r3
  int v27; // [sp+0h] [bp-40h] BYREF
  int v28; // [sp+4h] [bp-3Ch] BYREF
  unsigned int v29; // [sp+8h] [bp-38h]
  unsigned int v30; // [sp+Ch] [bp-34h]
  int v31; // [sp+10h] [bp-30h] BYREF
  int v32; // [sp+14h] [bp-2Ch]
  int v33; // [sp+18h] [bp-28h]
  int v34; // [sp+1Ch] [bp-24h]

  v31 = -1;
  v27 = -1;
  v28 = -1;
  v4 = *(int (__fastcall **)(int, int, int *))(a1 + 4);
  v33 = a3;
  v7 = 1;
  v8 = 0;
  v9 = v4(a1, a2, &v31);
  if ( v9 )
  {
    if ( !HvpMarkCellDirty(a1, a2, 0, 0)
      || (v10 = *(_DWORD *)(v9 + 28),
          v11 = *(int (__fastcall **)(int, unsigned int, int *))(a1 + 4),
          v29 = v10,
          v12 = (unsigned __int16 *)v11(a1, v10, &v28),
          (v13 = v12) == 0) )
    {
      v7 = 0;
LABEL_33:
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v31);
      return v7;
    }
    if ( *v12 == 26994 )
    {
      v14 = v12[1];
      v15 = 0;
      if ( v12[1] )
      {
        for ( i = (int)v12; ; i = v32 )
        {
          if ( v15 )
            (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v27);
          v30 = *(_DWORD *)(i + 4);
          v17 = *(int (__fastcall **)(int, unsigned int, int *))(a1 + 4);
          v32 = i + 4;
          v18 = (unsigned __int16 *)v17(a1, v30, &v27);
          v8 = v18;
          if ( !v18 )
            break;
          v19 = CmpFindCellInIndex(v18, v33);
          v20 = v8[1];
          v34 = v19;
          if ( v19 < v20 )
          {
            v21 = v8[1] == 1;
            if ( !HvpMarkCellDirty(a1, v30, 0, 0) || (v10 = v29, v21) && !HvpMarkCellDirty(a1, v29, 0, 0) )
            {
              v7 = 0;
              goto LABEL_29;
            }
            CmpRemoveCellFromIndex(v8, v34);
            if ( v21 )
            {
              v22 = v30;
              v23 = CmpFindCellInIndex(v13, v30);
              CmpRemoveCellFromIndex(v13, v23);
              (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v27);
              v8 = 0;
              HvFreeCell(a1, v22);
              goto LABEL_25;
            }
            goto LABEL_27;
          }
          if ( ++v15 >= v14 )
            goto LABEL_27;
        }
        goto LABEL_22;
      }
    }
    else
    {
      v24 = CmpFindCellInIndex(v12, a3);
      if ( !HvpMarkCellDirty(a1, v10, 0, 0) )
      {
LABEL_22:
        v7 = 0;
LABEL_31:
        if ( v13 )
          (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v28);
        goto LABEL_33;
      }
      CmpRemoveCellFromIndex(v13, v24);
LABEL_25:
      if ( !v13[1] )
      {
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v28);
        v13 = 0;
        HvFreeCell(a1, v10);
      }
    }
LABEL_27:
    v25 = *(_DWORD *)(v9 + 20) - 1;
    *(_DWORD *)(v9 + 20) = v25;
    if ( !v25 )
    {
      *(_DWORD *)(v9 + 28) = -1;
      *(_WORD *)(v9 + 52) = 0;
      *(_DWORD *)(v9 + 56) = 0;
    }
LABEL_29:
    if ( v8 )
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v27);
    goto LABEL_31;
  }
  return 0;
}

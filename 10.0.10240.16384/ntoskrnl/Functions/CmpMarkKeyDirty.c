// CmpMarkKeyDirty 
 
int __fastcall CmpMarkKeyDirty(int a1, int a2, int a3)
{
  int (__fastcall *v4)(int, int, _DWORD *); // r3
  int v7; // r8
  int v8; // r0
  int v9; // r4
  int v11; // r1
  int v12; // r1
  int v13; // r0
  int v14; // r6
  int v15; // r0
  int v16; // r6
  int *v17; // r7
  int v18; // t1
  int v19; // r0
  int v20; // r0
  void (__fastcall *v21)(int, int *); // r3
  int v22; // r4
  int v23; // [sp+0h] [bp-30h] BYREF
  int v24; // [sp+4h] [bp-2Ch] BYREF
  int v25; // [sp+8h] [bp-28h] BYREF
  _DWORD v26[9]; // [sp+Ch] [bp-24h] BYREF

  v4 = *(int (__fastcall **)(int, int, _DWORD *))(a1 + 4);
  v25 = -1;
  v26[0] = -1;
  v23 = -1;
  v24 = -1;
  v7 = 0;
  v8 = v4(a1, a2, v26);
  v9 = v8;
  if ( !v8 )
    return sub_805F04();
  if ( (*(_WORD *)(v8 + 2) & 2) == 0 )
  {
    if ( HvpMarkCellDirty(a1, a2, 0, 0) )
    {
      v11 = *(_DWORD *)(v9 + 48);
      if ( v11 == -1 || HvpMarkCellDirty(a1, v11, 0, 0) )
      {
        v12 = *(_DWORD *)(v9 + 44);
        if ( v12 == -1 )
          goto LABEL_12;
        if ( HvpMarkCellDirty(a1, v12, 0, 0) )
        {
          v13 = (*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, *(_DWORD *)(v9 + 44), &v23);
          v14 = v13;
          if ( v13 )
          {
            if ( HvpMarkCellDirty(a1, *(_DWORD *)(v13 + 4), 0, 0) && HvpMarkCellDirty(a1, *(_DWORD *)(v14 + 8), 0, 0) )
            {
              (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v23);
LABEL_12:
              if ( (*(_WORD *)(v9 + 2) & 0x40) != 0 || !*(_DWORD *)(v9 + 36) )
                goto LABEL_22;
              if ( HvpMarkCellDirty(a1, *(_DWORD *)(v9 + 40), 0, 0) )
              {
                v15 = (*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, *(_DWORD *)(v9 + 40), &v25);
                v7 = v15;
                if ( v15 )
                {
                  v16 = 0;
                  if ( *(_DWORD *)(v9 + 36) )
                  {
                    v17 = (int *)v15;
                    while ( HvpMarkCellDirty(a1, *v17, 0, 0) )
                    {
                      v18 = *v17++;
                      v19 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v18, &v24);
                      if ( !v19 )
                        break;
                      v20 = CmpMarkValueDataDirty(a1, v19);
                      v21 = *(void (__fastcall **)(int, int *))(a1 + 8);
                      if ( !v20 )
                      {
                        v21(a1, &v24);
                        goto LABEL_31;
                      }
                      v21(a1, &v24);
                      if ( (unsigned int)++v16 >= *(_DWORD *)(v9 + 36) )
                        goto LABEL_22;
                    }
                    goto LABEL_31;
                  }
LABEL_22:
                  if ( (*(_WORD *)(v9 + 2) & 4) != 0
                    || !a3
                    || CmpMarkIndexDirty(a1, *(_DWORD *)(v9 + 16), a2)
                    && HvpMarkCellDirty(a1, *(_DWORD *)(v9 + 16), 0, 0) )
                  {
                    v22 = 1;
                    goto LABEL_27;
                  }
LABEL_31:
                  v22 = 0;
LABEL_27:
                  if ( v7 )
                    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v25);
                  goto LABEL_30;
                }
              }
              goto LABEL_33;
            }
            (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v23);
          }
        }
      }
    }
LABEL_33:
    v22 = 0;
    goto LABEL_30;
  }
  v22 = 1;
LABEL_30:
  (*(void (__fastcall **)(int, _DWORD *))(a1 + 8))(a1, v26);
  return v22;
}

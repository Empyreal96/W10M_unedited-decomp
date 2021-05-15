// CmpDuplicateIndex 
 
int __fastcall CmpDuplicateIndex(int a1, int a2, int a3, int a4)
{
  int (*v5)(void); // r3
  int v7; // r6
  _DWORD *v9; // r5
  _WORD *v10; // r0
  _WORD *v11; // r8
  unsigned int v12; // r9
  int v13; // r0
  _DWORD *v14; // r0
  unsigned int v15; // r7
  int v16; // r0
  unsigned int v17; // r7
  _DWORD *v18; // r8
  unsigned int v19; // t1
  int v21; // [sp+0h] [bp-28h] BYREF
  _DWORD v22[9]; // [sp+4h] [bp-24h] BYREF

  v21 = a2;
  v22[0] = a3;
  v22[1] = a4;
  v5 = *(int (**)(void))(a1 + 4);
  v7 = -1;
  v21 = -1;
  v22[0] = -1;
  v9 = 0;
  v10 = (_WORD *)v5();
  v11 = v10;
  if ( v10 )
  {
    if ( *v10 == 26994 )
    {
      v12 = HvDuplicateCell(a1, a2, a3, 0);
      v13 = a1;
      if ( v12 == -1 )
      {
LABEL_5:
        (*(void (__fastcall **)(int, int *))(a1 + 8))(v13, &v21);
        return v7;
      }
      v14 = (_DWORD *)(*(int (__fastcall **)(int, unsigned int, _DWORD *))(a1 + 4))(a1, v12, v22);
      v9 = v14;
      if ( !v14 )
      {
LABEL_15:
        HvFreeCell(a1, v12);
        v13 = a1;
        goto LABEL_5;
      }
      *v14 = 26994;
      v15 = 0;
      if ( v11[1] )
      {
        while ( 1 )
        {
          v16 = HvDuplicateCell(a1, *(_DWORD *)&v11[2 * v15 + 2], a3, 1);
          if ( v16 == -1 )
            break;
          v9[++v15] = v16;
          ++*((_WORD *)v9 + 1);
          if ( v15 >= (unsigned __int16)v11[1] )
            goto LABEL_17;
        }
        v17 = 0;
        if ( *((_WORD *)v9 + 1) )
        {
          v18 = v9;
          do
          {
            v19 = v18[1];
            ++v18;
            HvFreeCell(a1, v19);
            ++v17;
          }
          while ( v17 < *((unsigned __int16 *)v9 + 1) );
        }
        (*(void (__fastcall **)(int, _DWORD *))(a1 + 8))(a1, v22);
        goto LABEL_15;
      }
    }
    else
    {
      v12 = HvDuplicateCell(a1, a2, a3, 1);
    }
LABEL_17:
    if ( v9 )
      (*(void (__fastcall **)(int, _DWORD *))(a1 + 8))(a1, v22);
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v21);
    v7 = v12;
  }
  return v7;
}

// CmpRemoveValueFromList 
 
int __fastcall CmpRemoveValueFromList(int a1, unsigned int a2, unsigned int *a3, int a4)
{
  unsigned int v6; // r1
  unsigned int v7; // r6
  int v9; // r0
  _DWORD *v10; // r2
  unsigned int v11; // r1
  int v12; // r4
  int v14; // [sp+8h] [bp-18h] BYREF
  int v15[5]; // [sp+Ch] [bp-14h] BYREF

  v14 = (int)a3;
  v15[0] = a4;
  v6 = a3[1];
  v7 = *a3 - 1;
  if ( *a3 == 1 )
  {
    HvFreeCell(a1, v6);
    a3[1] = -1;
LABEL_7:
    *a3 = v7;
    return 0;
  }
  v14 = -1;
  v9 = (*(int (__fastcall **)(int, unsigned int, int *))(a1 + 4))(a1, v6, &v14);
  if ( v9 )
  {
    if ( a2 < v7 )
    {
      v10 = (_DWORD *)(v9 + 4 * a2);
      v11 = v7 - a2;
      do
      {
        --v11;
        *v10 = v10[1];
        ++v10;
      }
      while ( v11 );
    }
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v14);
    v15[0] = 0;
    v12 = HvReallocateCell(a1, a3[1], 4 * v7, 1, v15, &v14);
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v14);
    a3[1] = v12;
    goto LABEL_7;
  }
  return -1073741670;
}

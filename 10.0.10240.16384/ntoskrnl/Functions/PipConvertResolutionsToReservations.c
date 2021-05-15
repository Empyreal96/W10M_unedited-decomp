// PipConvertResolutionsToReservations 
 
int __fastcall PipConvertResolutionsToReservations(int a1, int a2, int a3, int a4)
{
  int v5; // r7
  int v6; // r8
  int *v7; // r4
  int *v8; // r6
  int v9; // r3
  int *v10; // r5
  int *v11; // r2
  int v12; // r3
  int v14; // [sp+0h] [bp-20h] BYREF
  int v15; // [sp+4h] [bp-1Ch]

  v14 = a3;
  v15 = a4;
  if ( !a1 )
    return -1073741811;
  v5 = 0;
  PipDeleteBindingIds(a1);
  v6 = a1 + 16;
  v7 = *(int **)(a1 + 16);
  while ( v7 != (int *)v6 )
  {
    v8 = v7 - 2;
    v9 = *((unsigned __int8 *)v7 + 28);
    v7 = (int *)*v7;
    if ( !v9 )
    {
      v10 = (int *)v8[7];
      while ( v10 != v8 + 7 )
      {
        v11 = v10;
        v12 = v10[2];
        v10 = (int *)*v10;
        if ( v12 == 1 )
        {
          v14 = 0;
          v15 = *(_DWORD *)(v8[5] + 24);
          v5 = PipSetDependency((int)&v14, (int)(v11 + 2));
        }
      }
      *((_BYTE *)v8 + 36) = 1;
    }
  }
  return v5;
}

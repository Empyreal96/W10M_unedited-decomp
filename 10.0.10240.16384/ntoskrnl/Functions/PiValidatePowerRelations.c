// PiValidatePowerRelations 
 
int __fastcall PiValidatePowerRelations(int a1)
{
  int **v2; // r4
  int *v3; // r1
  __int64 v4; // r2
  int **v5; // r0
  int i; // r3
  int *v7; // r1
  int v8; // r3
  int v9; // r5
  int **v10; // r4
  int *v11; // r0
  __int64 v12; // r2
  int **v13; // r7
  __int64 v14; // r2
  int v15; // r2
  int **v16; // r0
  int v18; // [sp+0h] [bp-20h]
  int *v19; // [sp+8h] [bp-18h] BYREF
  int **v20; // [sp+Ch] [bp-14h]

  v18 = a1;
  v20 = &v19;
  v19 = (int *)&v19;
  v2 = (int **)(a1 + 100);
  while ( *v2 != (int *)v2 )
  {
    v3 = *v2;
    v4 = *(_QWORD *)*v2;
    if ( (int **)HIDWORD(v4) != v2 || *(int **)(v4 + 4) != v3 )
      __fastfail(3u);
    *v2 = (int *)v4;
    *(_DWORD *)(v4 + 4) = v2;
    v5 = v20;
    *v3 = (int)&v19;
    v3[1] = (int)v5;
    if ( *v5 != (int *)&v19 )
      sub_81181C();
    *v5 = v3;
    v20 = (int **)v3;
  }
  v7 = v19;
  if ( v19 != (int *)&v19 )
  {
    do
    {
      v8 = v7[5];
      v9 = v8 - 84;
      v10 = (int **)(v8 + 16);
      while ( *v10 != (int *)v10 )
      {
        v11 = *v10;
        v12 = *(_QWORD *)*v10;
        if ( (int **)HIDWORD(v12) != v10 || *(int **)(v12 + 4) != v11 )
          __fastfail(3u);
        *v10 = (int *)v12;
        *(_DWORD *)(v12 + 4) = v10;
        v13 = v20;
        *v11 = (int)&v19;
        v11[1] = (int)v13;
        if ( *v13 != (int *)&v19 )
          __fastfail(3u);
        *v13 = v11;
        v20 = (int **)v11;
      }
      for ( i = v9; i; i = *(_DWORD *)(i + 8) )
      {
        if ( i == a1 )
          KeBugCheckEx(202, 12, *(_DWORD *)(a1 + 16), *(_DWORD *)(v9 + 16), 0);
      }
      v7 = (int *)*v7;
    }
    while ( v7 != (int *)&v19 );
    v7 = v19;
  }
  while ( v7 != (int *)&v19 )
  {
    v14 = *(_QWORD *)v7;
    if ( (int **)v7[1] != &v19 || *(int **)(v14 + 4) != v7 )
      __fastfail(3u);
    v19 = (int *)*v7;
    *(_DWORD *)(v14 + 4) = &v19;
    v15 = v7[2] + 16;
    v16 = *(int ***)(v7[2] + 20);
    *v7 = v15;
    v7[1] = (int)v16;
    if ( *v16 != (int *)v15 )
      __fastfail(3u);
    *v16 = v7;
    *(_DWORD *)(v15 + 4) = v7;
    v7 = v19;
  }
  return v18;
}

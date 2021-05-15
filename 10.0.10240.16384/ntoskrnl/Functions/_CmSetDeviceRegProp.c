// _CmSetDeviceRegProp 
 
int __fastcall CmSetDeviceRegProp(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v9; // r7
  int (__fastcall *v13)(int, int, int, int, int, int *); // r5
  int v14; // r3
  int v15; // r2
  int v16; // r1
  int v17; // r0
  int v18; // r4
  int v20; // r0
  int v21; // [sp+10h] [bp-50h] BYREF
  int v22[10]; // [sp+14h] [bp-4Ch] BYREF

  v9 = a6;
  v21 = 0;
  memset(v22, 0, sizeof(v22));
  v13 = *(int (__fastcall **)(int, int, int, int, int, int *))(a1 + 160);
  v14 = a5;
  v15 = a7;
  v16 = a8;
  v22[2] = a4;
  v22[3] = a5;
  v22[5] = a7;
  v22[6] = a8;
  v22[1] = a3;
  v22[4] = a6;
  if ( v13 )
  {
    v17 = v13(a1, a2, 1, 10, 1, &v21);
    if ( v17 == -1073741822 )
    {
      v13 = 0;
    }
    else
    {
      if ( v17 == -1073741536 )
        return v21;
      if ( v17 )
        return -1073741595;
    }
    a3 = v22[1];
    a4 = v22[2];
    v14 = v22[3];
    v9 = v22[4];
    v15 = v22[5];
    v16 = v22[6];
  }
  v18 = CmSetDeviceRegPropWorker(a1, a2, a3, a4, v14, v9, v15, v16);
  if ( v13 )
  {
    v21 = v18;
    v20 = v13(a1, a2, 1, 10, 2, &v21);
    if ( v20 != -1073741822 )
    {
      if ( v20 == -1073741536 )
        return v21;
      if ( !v20 )
        return v18;
      return -1073741595;
    }
  }
  return v18;
}

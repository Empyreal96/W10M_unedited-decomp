// _CmSetInstallerClassRegProp 
 
int __fastcall CmSetInstallerClassRegProp(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v8; // r7
  int (__fastcall *v12)(int, int, int, int, int, int *); // r5
  int v13; // r3
  int v14; // r2
  int v15; // r1
  int v16; // r0
  int v17; // r4
  int v18; // r0
  int v20; // [sp+10h] [bp-50h] BYREF
  int v21[10]; // [sp+14h] [bp-4Ch] BYREF

  v8 = a6;
  v20 = 0;
  memset(v21, 0, sizeof(v21));
  v12 = *(int (__fastcall **)(int, int, int, int, int, int *))(a1 + 160);
  v13 = a5;
  v14 = a7;
  v15 = 0;
  v21[2] = a4;
  v21[3] = a5;
  v21[4] = a6;
  v21[5] = a7;
  v21[1] = a3;
  v21[6] = 0;
  if ( v12 )
  {
    v16 = v12(a1, a2, 2, 10, 1, &v20);
    if ( v16 == -1073741822 )
    {
      v12 = 0;
    }
    else
    {
      if ( v16 == -1073741536 )
        return v20;
      if ( v16 )
        return -1073741595;
    }
    a3 = v21[1];
    a4 = v21[2];
    v13 = v21[3];
    v8 = v21[4];
    v14 = v21[5];
    v15 = v21[6];
  }
  v17 = CmSetInstallerClassRegPropWorker(a1, a2, a3, a4, v13, v8, v14, v15);
  if ( !v12 )
    return v17;
  v20 = v17;
  v18 = v12(a1, a2, 2, 10, 2, &v20);
  if ( v18 == -1073741822 )
    return v17;
  if ( v18 == -1073741536 )
    return v20;
  if ( v18 )
    return -1073741595;
  return v17;
}

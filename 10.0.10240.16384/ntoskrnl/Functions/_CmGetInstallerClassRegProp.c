// _CmGetInstallerClassRegProp 
 
int __fastcall CmGetInstallerClassRegProp(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v8; // r7
  int v9; // r8
  int v10; // r9
  int (__fastcall *v13)(int, int, int, int, int, int *); // r5
  int v14; // r3
  int v15; // r0
  int v16; // r4
  int v17; // r0
  int v20; // [sp+18h] [bp-50h] BYREF
  _DWORD v21[10]; // [sp+1Ch] [bp-4Ch] BYREF

  v8 = a5;
  v9 = a6;
  v10 = a7;
  v20 = 0;
  memset(v21, 0, sizeof(v21));
  v13 = *(int (__fastcall **)(int, int, int, int, int, int *))(a1 + 160);
  v14 = 0;
  v21[1] = a3;
  v21[2] = a4;
  v21[3] = a5;
  v21[4] = a6;
  v21[5] = a7;
  v21[6] = 0;
  if ( v13 )
  {
    v15 = v13(a1, a2, 2, 9, 1, &v20);
    if ( v15 == -1073741822 )
    {
      v13 = 0;
    }
    else
    {
      if ( v15 == -1073741536 )
        return v20;
      if ( v15 )
        return -1073741595;
    }
    a3 = v21[1];
    a4 = v21[2];
    v8 = v21[3];
    v9 = v21[4];
    v10 = v21[5];
    v14 = v21[6];
  }
  v16 = CmGetInstallerClassRegPropWorker(a1, a2, a3, a4, v8, v9, v10, v14);
  if ( v13 )
  {
    v20 = v16;
    v17 = v13(a1, a2, 2, 9, 2, &v20);
    if ( v17 != -1073741822 )
    {
      if ( v17 != -1073741536 )
      {
        if ( !v17 )
          return v16;
        return -1073741595;
      }
      return v20;
    }
  }
  return v16;
}

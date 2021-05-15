// _CmDeleteInterfaceClass 
 
int __fastcall CmDeleteInterfaceClass(int a1, int a2, int a3)
{
  int (__fastcall *v6)(int, int, int, int, int, int *); // r5
  int v7; // r0
  int v8; // r4
  int v9; // r0
  int v11; // [sp+8h] [bp-48h] BYREF
  int v12[10]; // [sp+Ch] [bp-44h] BYREF

  v11 = 0;
  memset(v12, 0, sizeof(v12));
  v6 = *(int (__fastcall **)(int, int, int, int, int, int *))(a1 + 160);
  v12[1] = a3;
  if ( v6 )
  {
    v7 = v6(a1, a2, 4, 3, 1, &v11);
    if ( v7 == -1073741822 )
    {
      v6 = 0;
    }
    else
    {
      if ( v7 == -1073741536 )
        return v11;
      if ( v7 )
        return -1073741595;
    }
    a3 = v12[1];
  }
  v8 = CmDeleteInterfaceClassWorker(a1, a2, a3);
  if ( !v6 )
    return v8;
  v11 = v8;
  v9 = v6(a1, a2, 4, 3, 2, &v11);
  if ( v9 == -1073741822 )
    return v8;
  if ( v9 == -1073741536 )
    return v11;
  if ( v9 )
    return -1073741595;
  return v8;
}

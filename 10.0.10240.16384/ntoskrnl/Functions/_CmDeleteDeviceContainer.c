// _CmDeleteDeviceContainer 
 
int __fastcall CmDeleteDeviceContainer(int a1, int a2)
{
  int (__fastcall *v4)(int, int, int, int, int, int *); // r5
  int v5; // r0
  int v6; // r4
  int v7; // r0
  int v9; // [sp+8h] [bp-48h] BYREF
  int v10[10]; // [sp+Ch] [bp-44h] BYREF

  v9 = 0;
  memset(v10, 0, sizeof(v10));
  v4 = *(int (__fastcall **)(int, int, int, int, int, int *))(a1 + 160);
  v10[1] = 0;
  if ( v4 )
  {
    v5 = v4(a1, a2, 5, 3, 1, &v9);
    if ( v5 == -1073741822 )
    {
      v4 = 0;
    }
    else
    {
      if ( v5 == -1073741536 )
        return v9;
      if ( v5 )
        return -1073741595;
    }
  }
  v6 = CmDeleteDeviceContainerWorker(a1, a2);
  if ( !v4 )
    return v6;
  v9 = v6;
  v7 = v4(a1, a2, 5, 3, 2, &v9);
  if ( v7 == -1073741822 )
    return v6;
  if ( v7 == -1073741536 )
    return v9;
  if ( v7 )
    return -1073741595;
  return v6;
}

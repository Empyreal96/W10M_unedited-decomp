// DrvDbOpenContext 
 
int __fastcall DrvDbOpenContext(int **a1)
{
  int v2; // r5
  _BYTE *v3; // r0
  unsigned int v4; // r4
  int v5; // r0
  int v7; // r5
  int *v8; // r6
  unsigned int v9; // r6
  int *v10; // [sp+10h] [bp-20h] BYREF

  PiDrvDbCtx = 0;
  v2 = **a1;
  v10 = 0;
  v3 = (_BYTE *)ExAllocatePoolWithTag(1, 32, 1111770192);
  v4 = (unsigned int)v3;
  if ( !v3 )
    return -1073741801;
  memset(v3, 0, 32);
  *(_DWORD *)(v4 + 4) = v2;
  *(_DWORD *)(v4 + 8) = -805306368;
  *(_DWORD *)v4 = a1;
  *(_DWORD *)(v4 + 12) = v4 + 12;
  *(_DWORD *)(v4 + 16) = v4 + 12;
  v5 = ExAllocatePoolWithTag(512, 56, 1111770192);
  *(_DWORD *)(v4 + 28) = v5;
  if ( !v5 )
    JUMPOUT(0x81930E);
  if ( ExInitializeResourceLite(v5) < 0 )
    return sub_819300();
  v7 = DrvDbCreateDatabaseNode(v4, L"SYSTEM", 1, L"DriverDatabase", 3, 0, 0, &v10);
  v8 = v10;
  if ( v7 >= 0 )
  {
    v7 = DrvDbLoadDatabaseNode((int **)v4, v10);
    if ( v7 >= 0 )
    {
      v7 = DrvDbRegisterObjects(a1, v4);
      if ( v7 >= 0 )
      {
        PiDrvDbCtx = v4;
        v4 = 0;
      }
    }
  }
  if ( v4 )
  {
    if ( v8 )
      DrvDbDestroyDatabaseNode(v4, v8);
    v9 = *(_DWORD *)(v4 + 28);
    if ( v9 )
    {
      ExDeleteResourceLite(*(_DWORD **)(v4 + 28));
      ExFreePoolWithTag(v9);
    }
    ExFreePoolWithTag(v4);
  }
  return v7;
}

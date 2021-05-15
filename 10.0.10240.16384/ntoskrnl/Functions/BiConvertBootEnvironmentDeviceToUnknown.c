// BiConvertBootEnvironmentDeviceToUnknown 
 
int __fastcall BiConvertBootEnvironmentDeviceToUnknown(int a1, _DWORD *a2, int *a3)
{
  unsigned int v4; // r3
  int v7; // r4
  _BYTE *v8; // r0
  _DWORD *v9; // r5

  v4 = *(_DWORD *)(a1 + 8);
  v7 = v4 + 20;
  if ( v4 >= 0xFFFFFFEC )
    return -1073741675;
  v8 = (_BYTE *)ExAllocatePoolWithTag(1, v4 + 20, 1262764866);
  v9 = v8;
  if ( !v8 )
    return -1073741670;
  memset(v8, 0, v7);
  *v9 = 5;
  memmove((int)(v9 + 5), a1, *(_DWORD *)(a1 + 8));
  *a2 = v9;
  *a3 = v7;
  return 0;
}

// _PnpCtxOpenMachine 
 
int __fastcall PnpCtxOpenMachine(int a1, int a2, int a3, int a4, int a5, int a6, unsigned int *a7)
{
  _BYTE *v7; // r0
  unsigned int v8; // r4
  _BYTE *v9; // r0
  _BYTE *v10; // r0
  int v11; // r5
  int v12; // r2

  *a7 = 0;
  v7 = (_BYTE *)ExAllocatePoolWithTag(1, 172, 1380994640);
  v8 = (unsigned int)v7;
  if ( !v7 )
    return -1073741801;
  v9 = memset(v7, 0, 172);
  v10 = (_BYTE *)SysCtxOpenMachine(v9);
  v11 = (int)v10;
  v12 = 0;
  if ( (int)v10 >= 0 )
  {
    v10 = (_BYTE *)SysCtxIsVersionAvailable(0);
    if ( v10 )
    {
      *(_DWORD *)v8 = v12;
      *(_DWORD *)(v8 + 4) = 0;
      *(_DWORD *)(v8 + 8) = 0;
      *(_DWORD *)(v8 + 12) = 0;
      *(_DWORD *)(v8 + 16) = 0;
      *(_DWORD *)(v8 + 20) = 0;
      *(_DWORD *)(v8 + 24) = 0;
      *(_DWORD *)(v8 + 28) = 0;
      *(_DWORD *)(v8 + 32) = 0;
      *(_DWORD *)(v8 + 36) = 0;
      memset((_BYTE *)(v8 + 40), 0, 24);
      memset((_BYTE *)(v8 + 64), 0, 44);
      *(_DWORD *)(v8 + 68) = PnpDispatchDevice;
      *(_DWORD *)(v8 + 72) = PnpDispatchInstallerClass;
      *(_DWORD *)(v8 + 76) = PnpDispatchDeviceInterface;
      *(_DWORD *)(v8 + 80) = PnpDispatchInterfaceClass;
      *(_DWORD *)(v8 + 84) = PnpDispatchDeviceContainer;
      v10 = memset((_BYTE *)(v8 + 108), 0, 44);
      *(_DWORD *)(v8 + 152) = 0;
      *(_DWORD *)(v8 + 156) = 0;
      *(_DWORD *)(v8 + 160) = 0;
      *(_DWORD *)(v8 + 164) = 0;
      *(_DWORD *)(v8 + 168) = 0;
      *a7 = v8;
      v8 = 0;
      v12 = 0;
    }
    else
    {
      v11 = -1073741637;
    }
  }
  if ( v12 )
    return sub_818EA4(v10);
  if ( v8 )
    ExFreePoolWithTag(v8);
  return v11;
}

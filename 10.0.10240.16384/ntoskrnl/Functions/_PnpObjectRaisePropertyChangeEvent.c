// _PnpObjectRaisePropertyChangeEvent 
 
int __fastcall PnpObjectRaisePropertyChangeEvent(int result, int a2, int a3, int a4, int a5, int a6)
{
  int (__fastcall *v6)(int, int, int, int, _DWORD *); // r4
  _DWORD v7[6]; // [sp+8h] [bp-18h] BYREF

  v6 = *(int (__fastcall **)(int, int, int, int, _DWORD *))(result + 156);
  if ( v6 )
  {
    switch ( a3 )
    {
      case 1:
        result = PnpDeviceRaisePropertyChangeEventWorker(result, a2);
        break;
      case 3:
        result = PnpInterfaceRaisePropertyChangeEventWorker(result, a2);
        break;
      case 2:
        result = PnpInstallerClassRaisePropertyChangeEventWorker(result, a2);
        break;
      case 4:
        result = sub_7C8CD8();
        break;
      default:
        v7[0] = a4;
        v7[1] = a5;
        v7[2] = a6;
        result = v6(result, a2, a3, 4, v7);
        break;
    }
  }
  return result;
}

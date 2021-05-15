// IovpUtilMarkDeviceObject 
 
int __fastcall IovpUtilMarkDeviceObject(int result, int a2)
{
  int v2; // r2
  int v3; // r3

  v2 = *(_DWORD *)(result + 176);
  if ( a2 )
  {
    switch ( a2 )
    {
      case 1:
        v3 = *(_DWORD *)(v2 + 16) | 0x10000000;
        break;
      case 2:
        v3 = *(_DWORD *)(v2 + 16) | 0x20000000;
        break;
      case 3:
        v3 = *(_DWORD *)(v2 + 16) | 0x8000000;
        break;
      case 4:
        v3 = *(_DWORD *)(v2 + 16) | 0x2000000;
        break;
      case 5:
        v3 = *(_DWORD *)(v2 + 16) | 0x1000000;
        break;
      default:
        return result;
    }
  }
  else
  {
    v3 = *(_DWORD *)(v2 + 16) | 0x4000000;
  }
  *(_DWORD *)(v2 + 16) = v3;
  return result;
}

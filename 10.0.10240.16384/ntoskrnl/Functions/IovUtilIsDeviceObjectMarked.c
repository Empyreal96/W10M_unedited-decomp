// IovUtilIsDeviceObjectMarked 
 
BOOL __fastcall IovUtilIsDeviceObjectMarked(int a1, int a2)
{
  int v2; // r3
  bool v3; // zf

  v2 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 16);
  if ( a2 )
  {
    switch ( a2 )
    {
      case 1:
        v3 = (v2 & 0x10000000) == 0;
        break;
      case 2:
        v3 = (v2 & 0x20000000) == 0;
        break;
      case 3:
        v3 = (v2 & 0x8000000) == 0;
        break;
      case 4:
        v3 = (v2 & 0x2000000) == 0;
        break;
      case 5:
        v3 = (v2 & 0x1000000) == 0;
        break;
      default:
        return 0;
    }
  }
  else
  {
    v3 = (v2 & 0x4000000) == 0;
  }
  return !v3;
}

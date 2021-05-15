// PiRestartDevice 
 
int __fastcall PiRestartDevice(int a1)
{
  int *v2; // r4
  int v3; // r2
  int v5; // [sp+10h] [bp-10h] BYREF
  char v6; // [sp+14h] [bp-Ch]

  v2 = *(int **)(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 176) + 20);
  v3 = v2[43];
  if ( v3 == 787 || v3 == 788 )
    return -1073741738;
  if ( (v2[67] & 0x6000) != 0 )
    return -1073741823;
  switch ( v3 )
  {
    case 769:
    case 771:
    case 772:
    case 774:
    case 775:
    case 781:
      goto LABEL_8;
    case 770:
    case 786:
      PnpRestartDeviceNode(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 176) + 20));
LABEL_8:
      if ( *(_DWORD *)(a1 + 12) == 16 )
      {
        v5 = 3;
        v6 = PnPBootDriversInitialized;
        ObfReferenceObject(v2[4]);
        PipProcessDevNodeTree((int)v2, a1, (int)&v5, 0, 0, 0, 0);
      }
      break;
    case 773:
    case 776:
    case 777:
    case 778:
    case 779:
    case 780:
      return 0;
    default:
      return -1073741823;
  }
  return 0;
}

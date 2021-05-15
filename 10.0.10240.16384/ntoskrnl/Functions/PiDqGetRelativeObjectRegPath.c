// PiDqGetRelativeObjectRegPath 
 
int __fastcall PiDqGetRelativeObjectRegPath(unsigned __int16 *a1, int a2, unsigned __int16 **a3)
{
  unsigned __int16 *v6; // r0
  int result; // r0
  int v8; // [sp+0h] [bp-20h]

  v8 = (int)a1;
  v6 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 2048, 1483763280);
  *a3 = v6;
  if ( !v6 )
    return sub_7C90B8();
  switch ( a2 )
  {
    case 1:
      result = CmGetDeviceRegKeyPath(PiPnpRtlCtx, (int)a1, 16, 0, 0, (int)v6, 1024, 0);
      break;
    case 5:
      result = CmGetDeviceContainerRegKeyPath(v6, a1, 80, 1024);
      break;
    case 2:
      result = CmGetCommonClassRegKeyPath((int)v6, a1, 32, 0, v8, (int)v6, 0x400u, 0);
      break;
    case 3:
      result = CmGetDeviceInterfaceRegKeyPath((int)v6, a1, 48, 0, v8, v6, 0x400u, 0);
      break;
    case 4:
      result = CmGetCommonClassRegKeyPath((int)v6, a1, 64, 0, v8, (int)v6, 0x400u, 0);
      break;
    default:
LABEL_15:
      JUMPOUT(0x7C90BA);
  }
  if ( result < 0 )
    goto LABEL_15;
  return result;
}

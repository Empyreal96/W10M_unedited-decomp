// PnpQueryRemoveLockedDeviceNode 
 
int __fastcall PnpQueryRemoveLockedDeviceNode(int a1, int a2, _DWORD *a3, unsigned __int16 *a4)
{
  int v8; // r8
  int v9; // r0
  int v10; // r4
  int v11; // r0
  int result; // r0
  int v13[8]; // [sp+0h] [bp-20h] BYREF

  v13[0] = (int)a3;
  v13[1] = (int)a4;
  switch ( *(_DWORD *)(a1 + 172) )
  {
    case 0x303:
    case 0x304:
    case 0x306:
    case 0x307:
    case 0x308:
      v8 = *(_DWORD *)(a1 + 16);
      v13[0] = 0;
      v9 = PiIrpQueryRemoveDevice(v8, v13);
      v10 = v9;
      if ( v9 < 0 )
      {
        if ( a2 == 54 && v9 == -1073740537 )
        {
          PipSetDevNodeState((_DWORD *)a1, 784);
          *(_DWORD *)(a1 + 456) |= 2u;
        }
        else
        {
          IopRemoveDevice(v8, 3);
          *a3 = 6;
          RtlCopyUnicodeString(a4, (unsigned __int16 *)(a1 + 20));
          if ( v13[0] )
          {
            if ( a4[1] - *a4 >= *(unsigned __int16 *)(v13[0] + 28) + 4 )
              RtlAppendUnicodeStringToString(a4, (unsigned __int16 *)(v13[0] + 28));
          }
        }
        goto LABEL_5;
      }
      v11 = PipSetDevNodeState((_DWORD *)a1, 784);
      if ( a2 != 54 )
        goto LABEL_5;
      result = sub_7DE6D0(v11);
      break;
    default:
      v10 = 0;
LABEL_5:
      result = v10;
      break;
  }
  return result;
}

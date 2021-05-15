// VfPnpIsSystemRestrictedIrp 
 
int __fastcall VfPnpIsSystemRestrictedIrp(int a1)
{
  int v1; // r3
  int result; // r0
  int v3; // r3

  switch ( *(_BYTE *)(a1 + 1) )
  {
    case 7:
      v1 = *(_DWORD *)(a1 + 8);
      if ( v1 && (v1 == 1 || v1 != 2 && v1 > 2 && v1 <= 4) )
        goto LABEL_12;
      goto LABEL_7;
    case 8:
    case 9:
    case 0xF:
    case 0x10:
    case 0x16:
      goto LABEL_12;
    case 0x13:
      v3 = *(_DWORD *)(a1 + 8);
      if ( v3 && (v3 <= 0 || v3 <= 2 || v3 != 3) )
        goto LABEL_7;
LABEL_12:
      result = 0;
      break;
    default:
LABEL_7:
      result = 1;
      break;
  }
  return result;
}

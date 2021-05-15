// MiAllowGuardFault 
 
int __fastcall MiAllowGuardFault(char a1)
{
  int result; // r0

  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) == 1 )
    goto LABEL_7;
  if ( (a1 & 1) != 0 )
    return sub_514734();
  if ( KeInvalidAccessAllowed(a1) == 1 || (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x4C) & 0x20) != 0 )
LABEL_7:
    result = 0;
  else
    result = 1;
  return result;
}

// MiValidateReservedMapping 
 
unsigned int __fastcall __spoils<R0,R2,R3,R12> MiValidateReservedMapping(unsigned int a1, int a2)
{
  int v3; // r0
  unsigned int result; // r0

  v3 = ((a1 >> 10) & 0x3FFFFC) - 0x40000000;
  if ( *(_DWORD *)(v3 - 4) != (a2 & 0xFFFFF01C) )
    sub_553594();
  result = *(_DWORD *)(v3 - 8) >> 12;
  if ( result <= 2 )
    KeBugCheckEx(218, 258, a1);
  return result;
}

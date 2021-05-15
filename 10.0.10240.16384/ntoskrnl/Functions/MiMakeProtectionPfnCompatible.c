// MiMakeProtectionPfnCompatible 
 
int __fastcall MiMakeProtectionPfnCompatible(char a1, int a2)
{
  int result; // r0
  int v3; // r3

  result = a1 & 7;
  v3 = *(unsigned __int8 *)(a2 + 18) >> 6;
  if ( !v3 )
    return result | 8;
  if ( v3 == 2 )
    result |= 0x18u;
  return result;
}

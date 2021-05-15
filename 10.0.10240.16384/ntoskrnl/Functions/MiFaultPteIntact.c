// MiFaultPteIntact 
 
int __fastcall MiFaultPteIntact(__int16 a1)
{
  int result; // r0

  if ( (a1 & 0x400) != 0 )
    result = 1;
  else
    result = sub_511940();
  return result;
}

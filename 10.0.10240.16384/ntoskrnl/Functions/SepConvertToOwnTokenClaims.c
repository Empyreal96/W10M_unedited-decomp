// SepConvertToOwnTokenClaims 
 
int __fastcall SepConvertToOwnTokenClaims(int a1)
{
  int result; // r0

  if ( (*(_DWORD *)(a1 + 176) & 0x8000) != 0 || !*(_DWORD *)(a1 + 636) )
    result = 0;
  else
    result = sub_51D4E4();
  return result;
}

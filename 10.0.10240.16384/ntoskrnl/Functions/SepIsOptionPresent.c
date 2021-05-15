// SepIsOptionPresent 
 
int __fastcall SepIsOptionPresent(_BYTE *a1, _BYTE *a2)
{
  int result; // r0

  if ( strstr(a1, a2) )
    result = sub_811478();
  else
    result = 0;
  return result;
}

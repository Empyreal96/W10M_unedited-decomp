// SepTrustToDiscretionary 
 
int __fastcall SepTrustToDiscretionary(_DWORD *a1, int a2)
{
  int result; // r0

  if ( (*a1 & a2 & 0xFDFFFFFF) == (a2 & 0xFDFFFFFF) )
    result = 0;
  else
    result = -1073741790;
  return result;
}

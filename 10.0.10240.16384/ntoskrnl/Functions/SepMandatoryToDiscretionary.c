// SepMandatoryToDiscretionary 
 
int __fastcall SepMandatoryToDiscretionary(_DWORD *a1, int a2)
{
  int result; // r0

  if ( a1[2] && (*a1 & a2 & 0xFDFFFFFF) != (a2 & 0xFDFFFFFF) )
    result = -1073741790;
  else
    result = 0;
  return result;
}

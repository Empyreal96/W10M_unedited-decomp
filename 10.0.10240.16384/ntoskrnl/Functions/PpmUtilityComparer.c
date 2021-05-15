// PpmUtilityComparer 
 
int __fastcall PpmUtilityComparer(_DWORD *a1, _DWORD *a2)
{
  int result; // r0

  if ( *a1 <= *a2 )
    result = *a1 < *a2;
  else
    result = -1;
  return result;
}

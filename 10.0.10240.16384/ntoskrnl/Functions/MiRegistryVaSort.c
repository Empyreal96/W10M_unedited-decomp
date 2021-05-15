// MiRegistryVaSort 
 
int __fastcall MiRegistryVaSort(_DWORD *a1, _DWORD *a2)
{
  int result; // r0

  if ( *a1 < *a2 )
    result = -1;
  else
    result = *a1 > *a2;
  return result;
}

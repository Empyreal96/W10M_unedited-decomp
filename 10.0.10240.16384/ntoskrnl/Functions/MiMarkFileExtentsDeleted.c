// MiMarkFileExtentsDeleted 
 
int __fastcall MiMarkFileExtentsDeleted(int a1)
{
  int result; // r0

  result = *(_DWORD *)(a1 + 12);
  if ( result )
    *(_DWORD *)(a1 + 12) = 0;
  return result;
}

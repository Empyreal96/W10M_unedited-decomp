// MiImageSuitableForSystem 
 
int __fastcall MiImageSuitableForSystem(int a1, _DWORD *a2)
{
  int result; // r0

  if ( !**(_DWORD **)(a1 + 56) )
    return sub_7CDE60();
  *a2 = 1;
  if ( (*(_DWORD *)(a1 + 28) & 0x10000000) != 0 )
    result = *(_DWORD *)(*(_DWORD *)a1 + 24);
  else
    result = 0;
  return result;
}

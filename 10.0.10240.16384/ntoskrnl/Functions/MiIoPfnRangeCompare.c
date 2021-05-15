// MiIoPfnRangeCompare 
 
int __fastcall MiIoPfnRangeCompare(_DWORD *a1, int a2)
{
  unsigned int v2; // r2
  int result; // r0

  v2 = *(_DWORD *)(a2 + 20);
  if ( a1[1] >= v2 )
    result = *a1 > v2 + 512;
  else
    result = -1;
  return result;
}

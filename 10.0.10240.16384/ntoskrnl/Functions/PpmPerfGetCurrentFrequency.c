// PpmPerfGetCurrentFrequency 
 
unsigned int __fastcall PpmPerfGetCurrentFrequency(int a1)
{
  int v1; // r2
  int v2; // r3
  unsigned int result; // r0

  v1 = *(_DWORD *)(a1 + 3200);
  v2 = *(_DWORD *)(a1 + 3204);
  if ( !v1 || !v2 )
    return 100;
  result = *(_DWORD *)(v2 + 44);
  if ( result >= *(_DWORD *)(v1 + 148) )
    result = *(_DWORD *)(v1 + 148);
  return result;
}

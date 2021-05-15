// KiEntropyDpcRoutine 
 
int __fastcall KiEntropyDpcRoutine(int a1, _DWORD *a2)
{
  int v3; // r5
  int result; // r0

  v3 = ((unsigned __int8)(*a2 >> 10) - 1) & 1;
  if ( v3 != a2[73] )
  {
    result = KiEntropyTimingRoutine(&a2[32 * v3 + 1], 128);
    a2[73] = v3;
  }
  return result;
}

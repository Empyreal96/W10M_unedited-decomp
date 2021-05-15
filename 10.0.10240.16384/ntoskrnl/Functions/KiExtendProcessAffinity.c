// KiExtendProcessAffinity 
 
int __fastcall KiExtendProcessAffinity(int result, int a2)
{
  int v2; // r2
  char v3; // r5
  int v4; // r4
  int v5; // r3
  int v6; // r6
  int v7; // r3
  unsigned int *v8; // r2

  v2 = result + 4 * a2;
  v3 = a2;
  v4 = dword_681D78[a2];
  v5 = *(_DWORD *)(v2 + 72);
  v6 = result;
  if ( v5 )
  {
    *(_DWORD *)(v2 + 72) = v5 | v4;
  }
  else
  {
    v7 = *(_DWORD *)(result + 72) | v4;
    *(_DWORD *)(result + 72) = v7;
    KiSetIdealNodeProcessByGroup(result, 0, a2, v7);
    __dmb(0xBu);
    v8 = (unsigned int *)(v6 + 100);
    do
      result = __ldrex(v8);
    while ( __strex(result | (1 << (v3 + 8)), v8) );
    __dmb(0xBu);
  }
  return result;
}

// MiSubsectionCompare 
 
int __fastcall MiSubsectionCompare(int a1, int a2)
{
  unsigned int v2; // r7
  unsigned int v3; // r5
  unsigned int v4; // r6
  int result; // r0
  unsigned int v6; // lr
  unsigned int v7; // r2
  unsigned int v8; // r4

  v2 = *(_DWORD *)(a2 - 20);
  v3 = *(_DWORD *)(a1 + 20);
  v4 = *(unsigned __int16 *)(a1 + 16) >> 6;
  result = -1;
  v6 = *(unsigned __int16 *)(a2 - 24) >> 6;
  v7 = (__PAIR64__(v6, *(_DWORD *)(a2 - 16)) + v2 - 1) >> 32;
  v8 = *(_DWORD *)(a2 - 16) + v2 - 1;
  if ( (*(_WORD *)(a2 - 22) & 0xFFF0) != 0 )
  {
    v7 = (__PAIR64__(v7, v8) + 1) >> 32;
    v8 = *(_DWORD *)(a2 - 16) + v2;
  }
  if ( v4 >= v7 && (v4 > v7 || v3 > v8) )
    return 1;
  if ( v4 > v6 || v4 >= v6 && v3 >= v2 )
    result = 0;
  return result;
}

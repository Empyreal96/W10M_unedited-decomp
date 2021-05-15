// EtwpApplyScopeFilters 
 
int __fastcall EtwpApplyScopeFilters(int result, int a2, int a3, _BYTE *a4, int a5, int a6, int a7)
{
  int v9; // r1
  char v10; // r6
  unsigned int v11; // r5
  int v12; // r4
  int v13; // r3

  if ( (*(_BYTE *)(result + 50) & 1) == 0 )
  {
    *a4 = 0;
    if ( a3 )
      v9 = *(_DWORD *)(result + 20);
    else
      v9 = *(_DWORD *)(result + 16);
    result = 1;
    v10 = 0;
    v11 = 0;
    v12 = v9;
    do
    {
      if ( *(_DWORD *)(v12 + 88) && (!a2 || *(unsigned __int16 *)(v12 + 94) == *(unsigned __int16 *)(v9 + 48)) )
      {
        v13 = *(_DWORD *)(v9 + 344);
        result = 1;
        if ( v13 )
          return sub_7C4F48(1, v9, -2147483640, v13, a5, a6, a7);
        *a4 |= 1 << v10;
        if ( a2 )
          return result;
      }
      v11 += 36;
      ++v10;
      v12 += 32;
    }
    while ( v11 < 0x120 );
  }
  return result;
}

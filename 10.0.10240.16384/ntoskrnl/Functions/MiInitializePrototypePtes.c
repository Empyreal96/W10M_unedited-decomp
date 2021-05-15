// MiInitializePrototypePtes 
 
_DWORD *__fastcall MiInitializePrototypePtes(_DWORD *result, int a2, unsigned int a3)
{
  unsigned int v3; // r1
  int v4; // r4

  v3 = 4 * a2;
  if ( *(_DWORD *)(*(_DWORD *)a3 + 32) )
  {
    v4 = a3 & 0xFFFFFC00 | ((a3 & 0x7F8 | 0x800) >> 1);
  }
  else
  {
    v4 = 0;
    if ( (*(_DWORD *)(*(_DWORD *)a3 + 28) & 0x1000) == 0 )
      v4 = 16 * (*(_WORD *)(a3 + 16) & 0x3E);
  }
  if ( v3 )
    result = RtlFillMemoryUlong(result, 4 * (v3 >> 2), v4);
  return result;
}

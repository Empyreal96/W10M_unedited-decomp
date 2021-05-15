// MmGetSessionPoolTracking 
 
_DWORD *__fastcall MmGetSessionPoolTracking(_DWORD *result, _DWORD *a2)
{
  int v2; // r2

  v2 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
  *result = *(_DWORD *)(v2 + 8372);
  *a2 = *(_DWORD *)(v2 + 8376);
  return result;
}

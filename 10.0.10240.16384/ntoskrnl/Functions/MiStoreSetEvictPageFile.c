// MiStoreSetEvictPageFile 
 
_DWORD *__fastcall MiStoreSetEvictPageFile(_DWORD *result, unsigned int a2)
{
  int v2; // r6
  int v3; // r3

  v2 = result[32];
  *(_BYTE *)((a2 >> 3) + *(_DWORD *)(result[16] + 16)) &= ~(unsigned __int8)(1 << (a2 & 7));
  v3 = result[23] + 1;
  result[23] = v3;
  if ( v3 == 256 || *(_DWORD *)(v2 + 3712) < 0x80u )
    result = (_DWORD *)KeSetEvent(v2 + 696, 0, 0);
  return result;
}

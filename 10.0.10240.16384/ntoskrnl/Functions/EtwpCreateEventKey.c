// EtwpCreateEventKey 
 
_DWORD *__fastcall EtwpCreateEventKey(_DWORD *result)
{
  _DWORD *v1; // r2
  unsigned __int64 *v2; // r3
  unsigned __int64 v3; // kr00_8
  unsigned __int64 v4; // kr08_8
  int v5; // r2

  v1 = *(_DWORD **)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x138C);
  __dmb(0xBu);
  v2 = (unsigned __int64 *)(v1 + 226);
  do
  {
    v3 = __ldrexd(v2);
    v4 = v3 + 1;
  }
  while ( __strexd(v3 + 1, v2) );
  __dmb(0xBu);
  v5 = *v1;
  *result = v4;
  result[1] = WORD2(v4) | (v5 << 16);
  return result;
}

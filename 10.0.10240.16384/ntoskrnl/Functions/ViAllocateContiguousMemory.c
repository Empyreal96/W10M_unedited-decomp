// ViAllocateContiguousMemory 
 
_BYTE *__fastcall ViAllocateContiguousMemory(int a1)
{
  __int64 v2; // r6
  _BYTE *result; // r0
  unsigned int i; // r5
  unsigned int *v5; // r2
  unsigned int v6; // r1
  unsigned int *v7; // r2
  unsigned int v8; // r1

  v2 = 0xFFFFi64;
  if ( *(_BYTE *)(a1 + 131) )
  {
    v2 = -1i64;
  }
  else if ( *(_BYTE *)(a1 + 128) )
  {
    LODWORD(v2) = -1;
  }
  else if ( *(_DWORD *)(a1 + 140) == 1 )
  {
    LODWORD(v2) = 0xFFFFFF;
  }
  *(_DWORD *)(a1 + 208) = 32;
  *(_DWORD *)(a1 + 212) = a1 + 204;
  RtlClearAllBits(a1 + 208);
  result = (_BYTE *)ExAllocatePoolWithTag(512, 128, 1449943368);
  *(_DWORD *)(a1 + 188) = result;
  if ( result )
  {
    for ( i = 0; i < 0x20; ++i )
    {
      result = (_BYTE *)MmAllocateContiguousNodeMemory(12288, 0i64, v2, 0, 0, 4);
      *(_DWORD *)(*(_DWORD *)(a1 + 188) + 4 * i) = result;
      if ( *(_DWORD *)(*(_DWORD *)(a1 + 188) + 4 * i) )
      {
        __dmb(0xBu);
        v7 = (unsigned int *)(a1 + 192);
        do
          v8 = __ldrex(v7);
        while ( __strex(v8 + 1, v7) );
      }
      else
      {
        result = RtlSetBits((_BYTE *)(a1 + 208), i, 1u);
        __dmb(0xBu);
        v5 = (unsigned int *)(a1 + 196);
        do
          v6 = __ldrex(v5);
        while ( __strex(v6 + 1, v5) );
      }
      __dmb(0xBu);
    }
  }
  return result;
}

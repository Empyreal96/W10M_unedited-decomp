// EtwpDereferenceStackEntry 
 
int __fastcall EtwpDereferenceStackEntry(_DWORD *a1, int a2)
{
  _DWORD *v3; // r5
  unsigned int *v4; // r2
  unsigned int v5; // r0
  int result; // r0
  _DWORD *v7; // r4

  v3 = a1;
  __dmb(0xBu);
  v4 = a1 + 3;
  do
  {
    v5 = __ldrex(v4);
    result = v5 - 1;
  }
  while ( __strex(result, v4) );
  __dmb(0xBu);
  if ( !result )
  {
    EtwpTraceCachedStack(*(_DWORD *)a2, 6179, v3);
    do
    {
      v7 = (_DWORD *)v3[2];
      result = RtlpInterlockedPushEntrySList((unsigned __int64 *)(a2 + 8), v3);
      v3 = v7;
    }
    while ( v7 );
  }
  return result;
}

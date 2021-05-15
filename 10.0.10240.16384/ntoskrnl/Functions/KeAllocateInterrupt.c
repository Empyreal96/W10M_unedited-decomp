// KeAllocateInterrupt 
 
int __fastcall KeAllocateInterrupt(int a1)
{
  int v2; // r7
  int result; // r0
  _DWORD *v4; // r5
  int v5; // r6

  v2 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 2360) + 266);
  while ( 1 )
  {
    result = RtlpInterlockedPopEntrySList((unsigned __int64 *)(a1 + 3368));
    if ( result )
    {
      *(_DWORD *)(result + 176) = a1;
      return result;
    }
    v4 = (_DWORD *)MmAllocateIndependentPages(4096, v2);
    if ( !v4 )
      break;
    v5 = 16;
    do
    {
      RtlpInterlockedPushEntrySList((unsigned __int64 *)(a1 + 3368), v4);
      v4 += 64;
      --v5;
    }
    while ( v5 );
  }
  return 0;
}

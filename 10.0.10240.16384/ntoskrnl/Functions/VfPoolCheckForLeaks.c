// VfPoolCheckForLeaks 
 
int __fastcall VfPoolCheckForLeaks(int a1, int a2)
{
  int v3; // r3
  int v4; // r3
  int v5; // r2
  int v6; // r3
  int result; // r0

  v3 = *(_DWORD *)(a1 + 56);
  __dmb(0xBu);
  if ( v3 || (v4 = *(_DWORD *)(a1 + 60), __dmb(0xBu), v4) )
  {
    ViBadDriver = a2 + 44;
    v5 = *(_DWORD *)(a1 + 40);
    __dmb(0xBu);
    v6 = *(_DWORD *)(a1 + 44);
    __dmb(0xBu);
    VerifierBugCheckIfAppropriate(196, 98, *(_DWORD *)(a2 + 48), a1, v6 + v5);
  }
  while ( 1 )
  {
    result = RtlpInterlockedPopEntrySList((unsigned __int64 *)(a1 + 24));
    if ( !result )
      break;
    ExFreePoolWithTag(result);
  }
  return result;
}

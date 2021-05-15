// VfIoCompletionCheckState 
 
int __fastcall VfIoCompletionCheckState(_DWORD *a1, int a2)
{
  int v4; // r0

  v4 = KeGetCurrentIrql(a1);
  if ( *(unsigned __int8 *)a1 != v4 )
  {
    KeGetCurrentIrql(v4);
    VerifierBugCheckIfAppropriate(196, 250, a2);
  }
  if ( a1[1] != *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x134) )
  {
    __mrc(15, 0, 13, 0, 3);
    VerifierBugCheckIfAppropriate(196, 251, a2);
  }
  return ExFreeToNPagedLookasideList((int)&ViIoCallbackStateLookaside, a1);
}

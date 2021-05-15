// VfFastIoCheckState 
 
int __fastcall VfFastIoCheckState(_DWORD *a1, int a2)
{
  int v4; // r0
  int v5; // r1
  int v6; // r0

  v4 = KeAreInterruptsEnabled();
  if ( !v4 )
    v4 = VerifierBugCheckIfAppropriate(196, 195, v5);
  v6 = KeGetCurrentIrql(v4);
  if ( *(unsigned __int8 *)a1 != v6 )
  {
    KeGetCurrentIrql(v6);
    VerifierBugCheckIfAppropriate(201, 17, a2);
  }
  if ( a1[1] != *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x134) )
  {
    __mrc(15, 0, 13, 0, 3);
    VerifierBugCheckIfAppropriate(196, 198, a2);
  }
  return ExFreeToNPagedLookasideList((int)&ViIoCallbackStateLookaside, a1);
}

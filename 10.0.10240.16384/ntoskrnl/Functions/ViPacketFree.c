// ViPacketFree 
 
int __fastcall ViPacketFree(_DWORD *a1)
{
  unsigned int v2; // r0

  v2 = a1[33];
  if ( v2 )
    ExFreePoolWithTag(v2);
  return ExFreeToNPagedLookasideList((int)&ViPacketLookaside, a1);
}

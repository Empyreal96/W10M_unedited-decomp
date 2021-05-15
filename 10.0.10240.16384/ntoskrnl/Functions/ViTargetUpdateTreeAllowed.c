// ViTargetUpdateTreeAllowed 
 
int __fastcall ViTargetUpdateTreeAllowed(int a1)
{
  int v1; // r4
  int v2; // r3

  v1 = 0;
  if ( (unsigned int)KeGetCurrentIrql(a1) <= 2 )
  {
    v2 = ViTargetInitialized;
    __dmb(0xBu);
    if ( v2 )
      v1 = 1;
  }
  return v1;
}

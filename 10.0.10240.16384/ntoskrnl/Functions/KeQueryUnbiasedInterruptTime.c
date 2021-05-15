// KeQueryUnbiasedInterruptTime 
 
int KeQueryUnbiasedInterruptTime()
{
  __int64 v0; // r0
  int v1; // r5
  int v2; // r6

  do
  {
    v0 = MEMORY[0xFFFF93B0];
    v1 = MEMORY[0xFFFF900C];
    __dmb(0xBu);
    v2 = MEMORY[0xFFFF9008];
    __dmb(0xBu);
    if ( v1 != MEMORY[0xFFFF9010] )
      return sub_50BC50(v0, HIDWORD(v0), -27728);
  }
  while ( v0 != MEMORY[0xFFFF93B0] );
  return v2 - v0;
}

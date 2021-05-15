// VfPendingCheckForChanges 
 
int __fastcall VfPendingCheckForChanges(int result)
{
  unsigned int v1; // r3
  int v2; // r6

  if ( (result & 0x200) != 0 && !VfForcedPendingLog )
  {
    v1 = VfForcedPendingLogLength;
    __dmb(0xBu);
    if ( v1 > 0x100000 )
    {
      __dmb(0xBu);
      VfForcedPendingLogLength = 0x100000;
    }
    v2 = VfForcedPendingLogLength;
    __dmb(0xBu);
    result = ExAllocatePoolWithTagPriority(512, v2 << 8, 1346790998, 32);
    VfForcedPendingLog = result;
    if ( result )
      result = (int)memset((_BYTE *)result, 0, v2 << 8);
  }
  return result;
}

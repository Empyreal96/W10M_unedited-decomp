// SmKmAllocateMdlForLock 
 
int __fastcall SmKmAllocateMdlForLock(unsigned int a1)
{
  int v2; // r7
  int v3; // r6
  unsigned int v4; // r8
  int v5; // r0
  int v6; // r4

  v2 = 0;
  v3 = SmAcquireReleaseCharges(a1, 3, 0);
  if ( v3 )
  {
    v4 = 4 * (((a1 + 4095) >> 12) + 7);
    v5 = ExAllocatePoolWithTag(512, v4);
    v6 = v5;
    if ( v5 )
    {
      *(_DWORD *)v5 = 0;
      *(_WORD *)(v5 + 6) = 0;
      *(_DWORD *)(v5 + 16) = 0;
      *(_DWORD *)(v5 + 20) = a1;
      *(_DWORD *)(v5 + 24) = 0;
      v6 = 0;
      v3 = 0;
      *(_WORD *)(v5 + 4) = v4;
      v2 = v5;
    }
    if ( v3 )
      return sub_551E94();
    if ( v6 )
      ExFreePoolWithTag(v6, 0);
  }
  return v2;
}

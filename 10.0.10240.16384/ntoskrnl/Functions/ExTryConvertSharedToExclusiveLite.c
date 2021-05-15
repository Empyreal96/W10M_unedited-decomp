// ExTryConvertSharedToExclusiveLite 
 
int ExTryConvertSharedToExclusiveLite()
{
  int v0; // r5
  int *v1; // r0
  int v2; // r3
  int v3; // r4
  char v5[24]; // [sp+8h] [bp-18h] BYREF

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  KeAcquireInStackQueuedSpinLock((unsigned int *)&algn_6830A4[16], (unsigned int)v5);
  if ( dword_6830A0 == 1 )
  {
    v1 = ExpFindCurrentThread((int)&CmpRegistryLock, v0, (int)v5, 0, 0);
    word_68308E |= 0x80u;
    if ( v1 != &dword_683098 )
    {
      dword_683098 = v0;
      dword_68309C = dword_68309C & 3 | 4;
      v2 = v1[1];
      *v1 = 0;
      v1[1] = v2 & 3;
    }
    v3 = 1;
  }
  else
  {
    v3 = 0;
  }
  KeReleaseInStackQueuedSpinLock((int)v5);
  return v3;
}

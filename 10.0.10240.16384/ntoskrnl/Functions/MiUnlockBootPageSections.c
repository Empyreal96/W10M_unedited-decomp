// MiUnlockBootPageSections 
 
int __fastcall MiUnlockBootPageSections(int a1, int a2, int a3)
{
  unsigned int v3; // r4
  int v4; // r3
  int v5; // r0
  int *i; // r5
  int v8; // r3

  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = *(__int16 *)(v3 + 0x134) - 1;
  *(_WORD *)(v3 + 308) = v4;
  v5 = ExAcquireResourceExclusiveLite((int)&PsLoadedModuleResource, 1, a3, v4);
  for ( i = (int *)PsLoadedModuleList; i != &PsLoadedModuleList; i = (int *)*i )
  {
    v8 = i[13];
    if ( (v8 & 0x400000) != 0 )
    {
      i[13] = v8 & 0xFFBFFFFF;
      v5 = MiLockPagableSections(i, 0);
    }
  }
  return sub_96A86C(v5);
}

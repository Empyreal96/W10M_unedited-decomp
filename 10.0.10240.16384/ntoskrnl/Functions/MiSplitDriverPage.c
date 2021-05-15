// MiSplitDriverPage 
 
int __fastcall MiSplitDriverPage(unsigned int a1, int a2, int a3, int a4)
{
  int *v6; // r5
  int result; // r0
  int v8[4]; // [sp+8h] [bp-10h] BYREF

  v8[0] = a4;
  MmLockLoadedModuleListShared(v8);
  v6 = MiLookupDataTableEntry(a1 << 10, 1);
  MmUnlockLoadedModuleListShared(LOBYTE(v8[0]));
  if ( v6 )
    result = MiMakeDriverPagesPrivate((int)v6, a1, a1, a2, 0);
  else
    result = -1073741799;
  return result;
}

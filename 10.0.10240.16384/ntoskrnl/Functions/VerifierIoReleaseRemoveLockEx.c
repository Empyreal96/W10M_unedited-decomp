// VerifierIoReleaseRemoveLockEx 
 
int __fastcall VerifierIoReleaseRemoveLockEx(int a1, int a2, int a3)
{
  int v5; // r3
  int v7; // r0
  int v8; // r2
  int v9; // r0

  v5 = ViRemLockInitialized;
  __dmb(0xBu);
  if ( v5 && a3 != 88 && (v7 = ViRemLockFindSurrogate(a1)) != 0 )
  {
    v8 = 88;
    v9 = v7 + 8;
  }
  else
  {
    v8 = a3;
    v9 = a1;
  }
  return pXdvIoReleaseRemoveLockEx(v9, a2, v8);
}

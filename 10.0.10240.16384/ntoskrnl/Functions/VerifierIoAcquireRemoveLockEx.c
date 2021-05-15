// VerifierIoAcquireRemoveLockEx 
 
int __fastcall VerifierIoAcquireRemoveLockEx(int a1, int a2, int a3, int a4, int a5)
{
  int v7; // r4
  int v10; // r0
  int v11; // r0

  v7 = ViRemLockInitialized;
  __dmb(0xBu);
  if ( v7 && a5 != 88 && (v10 = ViRemLockFindSurrogate(a1)) != 0 )
    v11 = v10 + 8;
  else
    v11 = a1;
  return pXdvIoAcquireRemoveLockEx(v11, a2, a3, a4);
}

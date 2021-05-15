// VerifierExAcquireResourceSharedLite 
 
int __fastcall VerifierExAcquireResourceSharedLite(int a1, int a2)
{
  int v4; // r5

  ViResourceAcquireSanityChecks(a1);
  v4 = pXdvExAcquireResourceSharedLite(a1, a2);
  if ( v4 )
    VfDeadlockAcquireResource(a1, 8, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, a2 == 0);
  return v4;
}

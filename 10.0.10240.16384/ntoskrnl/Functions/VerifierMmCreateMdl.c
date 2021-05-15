// VerifierMmCreateMdl 
 
int __fastcall VerifierMmCreateMdl(int a1, int a2, int a3, int a4)
{
  int v7; // r4
  int v8; // r1

  if ( !a1 && VfFaultsInjectResourceFailure(0, a2, a3, a4) )
    return 0;
  v7 = pXdvMmCreateMdl(a1, a2, a3);
  if ( (unsigned int)KeGetCurrentIrql(v7) <= 2 )
  {
    if ( v7 )
      v8 = *(__int16 *)(v7 + 4);
    else
      v8 = 28;
    if ( VfPoolTraces )
      ViPoolLogStackTrace(v7, v8);
  }
  return v7;
}

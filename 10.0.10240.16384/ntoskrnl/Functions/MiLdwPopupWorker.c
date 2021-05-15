// MiLdwPopupWorker 
 
int __fastcall MiLdwPopupWorker(unsigned int a1)
{
  __int64 v1; // r6
  unsigned int *v2; // r2
  int v3; // r3
  unsigned int v4; // r5

  v1 = *(_QWORD *)(a1 + 16);
  if ( *(_BYTE *)(a1 + 28) == 1 )
  {
    ExFreePoolWithTag(a1);
  }
  else
  {
    __dmb(0xBu);
    v2 = (unsigned int *)(a1 + 24);
    do
    {
      v4 = __ldrex(v2);
      v3 = __strex(0, v2);
    }
    while ( v3 );
  }
  CcMmLogLostDelayedWriteError(v1, SHIDWORD(v1), (int)v2, v3);
  return ObfDereferenceObject(v1);
}

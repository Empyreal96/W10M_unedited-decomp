// ViHalTrackDomainCommonBuffer 
 
__int64 __fastcall ViHalTrackDomainCommonBuffer(_DWORD *a1)
{
  int v2; // r6
  unsigned int v3; // r1
  int v4; // r2
  int vars4; // [sp+14h] [bp+4h]

  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&dword_908C48);
  }
  else
  {
    do
      v3 = __ldrex((unsigned int *)&dword_908C48);
    while ( __strex(1u, (unsigned int *)&dword_908C48) );
    __dmb(0xBu);
    if ( v3 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&dword_908C48);
  }
  v4 = ViDomainCommonBufferList;
  *a1 = ViDomainCommonBufferList;
  a1[1] = &ViDomainCommonBufferList;
  if ( *(int **)(v4 + 4) != &ViDomainCommonBufferList )
    __fastfail(3u);
  *(_DWORD *)(v4 + 4) = a1;
  ViDomainCommonBufferList = (int)a1;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&dword_908C48, vars4);
  }
  else
  {
    __dmb(0xBu);
    dword_908C48 = 0;
  }
  return KfLowerIrql(v2);
}

// ViHalFreeDomainCommonBuffer 
 
int __fastcall ViHalFreeDomainCommonBuffer(_QWORD *a1)
{
  int v2; // r6
  unsigned int v3; // r8
  int v4; // r10
  unsigned int v5; // r1
  int v6; // r2
  __int64 v7; // r0
  int vars4; // [sp+24h] [bp+4h]

  v2 = 0;
  v3 = 0;
  v4 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&dword_908C48);
  }
  else
  {
    do
      v5 = __ldrex((unsigned int *)&dword_908C48);
    while ( __strex(1u, (unsigned int *)&dword_908C48) );
    __dmb(0xBu);
    if ( v5 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&dword_908C48);
  }
  v6 = ViDomainCommonBufferList;
  if ( (int *)ViDomainCommonBufferList != &ViDomainCommonBufferList )
  {
    while ( 1 )
    {
      v3 = v6;
      if ( *(_QWORD *)(v6 + 8) == *a1 )
        break;
      v6 = *(_DWORD *)v6;
      if ( (int *)v6 == &ViDomainCommonBufferList )
        goto LABEL_9;
    }
    v7 = *(_QWORD *)v6;
    v2 = 1;
    if ( *(_DWORD *)(*(_DWORD *)v6 + 4) != v6 || *(_DWORD *)HIDWORD(v7) != v6 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v7) = v7;
    *(_DWORD *)(v7 + 4) = HIDWORD(v7);
  }
LABEL_9:
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&dword_908C48, vars4);
  }
  else
  {
    __dmb(0xBu);
    dword_908C48 = 0;
  }
  KfLowerIrql(v4);
  if ( v2 )
    ExFreePoolWithTag(v3);
  return v2;
}

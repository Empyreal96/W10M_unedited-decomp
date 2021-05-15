// EtwpReleaseProviderTraitsReference 
 
int __fastcall EtwpReleaseProviderTraitsReference(int a1)
{
  unsigned int *v1; // r2
  _DWORD *v2; // r4
  unsigned __int8 *v4; // r5
  int *v5; // r7
  int v6; // r6
  int v7; // r8
  unsigned int v8; // r2
  int v9; // r3
  int v10; // r6
  unsigned int v11; // r1

  __dmb(0xBu);
  v1 = (unsigned int *)(a1 + 56);
  do
    v2 = (_DWORD *)__ldrex(v1);
  while ( __strex(0, v1) );
  __dmb(0xBu);
  if ( !v2 )
    return 0;
  if ( (*(_BYTE *)(a1 + 50) & 1) != 0 )
  {
    v4 = (unsigned __int8 *)&EtwpProviderTraitsKmMutex;
    v5 = (int *)&EtwpProviderTraitsKmTree;
  }
  else
  {
    v4 = (unsigned __int8 *)&EtwpProviderTraitsUmMutex;
    v5 = (int *)&EtwpProviderTraitsUmTree;
  }
  v6 = KeAbPreAcquire((unsigned int)v4, 0, 0);
  v7 = KfRaiseIrql(1);
  do
    v8 = __ldrex(v4);
  while ( __strex(v8 & 0xFE, v4) );
  __dmb(0xBu);
  if ( (v8 & 1) == 0 )
    ExpAcquireFastMutexContended((int)v4, v6);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  *((_DWORD *)v4 + 1) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *((_DWORD *)v4 + 7) = v7;
  v9 = v2[3] - 1;
  v2[3] = v9;
  if ( v9 )
    v2 = 0;
  else
    RtlRbRemoveNode(v5, v2);
  v10 = *((_DWORD *)v4 + 7);
  *((_DWORD *)v4 + 1) = 0;
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)v4);
  while ( !v11 && __strex(1u, (unsigned int *)v4) );
  if ( !v11 )
  {
    KfLowerIrql((unsigned __int8)v10);
    KeAbPostRelease((unsigned int)v4);
    if ( v2 )
      ExFreePoolWithTag((unsigned int)v2);
    return 0;
  }
  return sub_7D6C38();
}

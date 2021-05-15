// PsTransferProcessQuotaToSharedQuota 
 
int __fastcall PsTransferProcessQuotaToSharedQuota(int a1, int a2)
{
  int result; // r0
  unsigned int *v4; // r2
  unsigned int v5; // r5
  unsigned int *v6; // r2
  unsigned int v7; // r1

  if ( a1 == PsInitialSystemProcess )
    return 1;
  result = *(_DWORD *)(a1 + 332);
  if ( a2 )
  {
    __dmb(0xBu);
    v4 = (unsigned int *)(a1 + 212);
    do
      v5 = __ldrex(v4);
    while ( __strex(v5 - a2, v4) );
    __dmb(0xBu);
  }
  __dmb(0xBu);
  v6 = (unsigned int *)(result + 1024);
  do
    v7 = __ldrex(v6);
  while ( __strex(v7 + 1, v6) );
  __dmb(0xBu);
  return result;
}

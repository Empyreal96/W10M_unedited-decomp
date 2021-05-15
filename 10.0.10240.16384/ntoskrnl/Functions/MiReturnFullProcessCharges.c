// MiReturnFullProcessCharges 
 
int __fastcall MiReturnFullProcessCharges(int a1, int a2, int a3, int a4)
{
  unsigned int *v6; // r2
  unsigned int v7; // r6

  if ( (*(_DWORD *)(a1 + 188) & 0x10) != 0 )
    PspChangeJobMemoryUsageByProcess(16, -a2, a1, 0);
  v6 = (unsigned int *)(a1 + 484);
  do
    v7 = __ldrex(v6);
  while ( __strex(v7 - a2, v6) );
  return PsReturnProcessPageFileQuota(a1, a2, v6, a4);
}

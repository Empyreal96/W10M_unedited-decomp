// PspFreeRateControl 
 
unsigned int __fastcall PspFreeRateControl(_DWORD *a1, int a2)
{
  int v3; // r0
  unsigned int v4; // r0

  v3 = PspGetRateControlSize(a2);
  PsReturnSharedPoolQuota(*a1, v3, 0);
  v4 = a1[3];
  if ( v4 )
    ExFreePoolWithTag(v4);
  return ExFreePoolWithTag((unsigned int)a1);
}

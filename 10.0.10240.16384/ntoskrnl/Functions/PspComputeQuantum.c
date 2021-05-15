// PspComputeQuantum 
 
int __fastcall PspComputeQuantum(int a1, int a2)
{
  int v2; // r0
  int v3; // r3

  if ( *(_BYTE *)(a1 + 375) == 1 )
    return 6;
  v2 = *(_DWORD *)(a1 + 288);
  __dmb(0xBu);
  if ( v2 && PspUseJobSchedulingClasses )
    return sub_7F6734();
  if ( a2 )
    v3 = PsPrioritySeparation;
  else
    v3 = 0;
  return *((char *)&PspForegroundQuantum + v3);
}

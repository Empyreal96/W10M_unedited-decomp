// KeQueryEffectiveBasePriorityThread 
 
int __fastcall KeQueryEffectiveBasePriorityThread(int a1)
{
  int v2; // r5
  unsigned int v3; // r0
  int v4; // r2
  unsigned int v5; // r3
  int v6; // r3
  int result; // r0

  if ( *(char *)(a1 + 123) >= 16 || !*(_DWORD *)(a1 + 68) )
    goto LABEL_10;
  v2 = 0;
  v3 = KfRaiseIrql(2);
  v4 = *(_DWORD *)(a1 + 68);
  v5 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  if ( v4 )
  {
    v6 = *(_DWORD *)(v5 + 3760) + v4;
    if ( v6 )
      v2 = (*(unsigned __int8 *)(v6 + 92) >> 3) & 1;
  }
  if ( v3 < 2 )
    KfLowerIrql(v3);
  if ( v2 )
    result = 1;
  else
LABEL_10:
    result = *(char *)(a1 + 347);
  return result;
}

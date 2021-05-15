// PspUnlockQuotaExpansion 
 
int __fastcall PspUnlockQuotaExpansion(_DWORD *a1, int a2)
{
  int result; // r0
  unsigned int v3; // r4
  unsigned int *v4; // r5
  unsigned int v5; // r1
  int v6; // r3

  if ( *a1 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      result = sub_5250F4();
    }
    else
    {
      __dmb(0xBu);
      a1[2] = 0;
      result = KfLowerIrql(a2);
    }
  }
  else
  {
    v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v4 = a1 + 2;
    __dmb(0xBu);
    do
      v5 = __ldrex(v4);
    while ( __strex(v5 - 1, v4) );
    if ( (v5 & 2) != 0 && (v5 & 4) == 0 )
      ExfTryToWakePushLock(a1 + 2);
    result = KeAbPostRelease(v4);
    v6 = (__int16)(*(_WORD *)(v3 + 310) + 1);
    *(_WORD *)(v3 + 310) = v6;
    if ( !v6 && *(_DWORD *)(v3 + 100) != v3 + 100 )
      result = KiCheckForKernelApcDelivery(result);
  }
  return result;
}

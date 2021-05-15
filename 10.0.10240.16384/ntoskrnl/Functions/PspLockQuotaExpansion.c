// PspLockQuotaExpansion 
 
int __fastcall PspLockQuotaExpansion(_DWORD *a1, _BYTE *a2)
{
  unsigned int *v3; // r4
  int result; // r0
  char v5; // r6
  unsigned int v6; // r2
  unsigned int v7; // r2
  unsigned __int8 *v8; // r5
  int v9; // r4
  unsigned int v10; // r2

  if ( *a1 )
  {
    v3 = a1 + 2;
    result = KfRaiseIrql(2);
    v5 = result;
    if ( (dword_682604 & 0x210000) != 0 )
    {
      result = sub_525114();
    }
    else
    {
      do
        v6 = __ldrex(v3);
      while ( __strex(1u, v3) );
      __dmb(0xBu);
      if ( v6 )
        result = KxWaitForSpinLockAndAcquire(v3);
      *a2 = v5;
    }
  }
  else
  {
    *a2 = 0;
    v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v7 + 310);
    v8 = (unsigned __int8 *)(a1 + 2);
    result = KeAbPreAcquire(a1 + 2, 0, 0);
    v9 = result;
    do
      v10 = __ldrex(v8);
    while ( __strex(v10 | 1, v8) );
    __dmb(0xBu);
    if ( (v10 & 1) != 0 )
      result = ExfAcquirePushLockExclusiveEx(v8, result, v8);
    if ( v9 )
      *(_BYTE *)(v9 + 14) |= 1u;
  }
  return result;
}

// PnpBusTypeGuidGetIndex 
 
int __fastcall PnpBusTypeGuidGetIndex(int a1)
{
  int v1; // r4
  int v2; // r0
  unsigned int v3; // r2
  unsigned int v5; // r3
  unsigned int v6; // r6
  int v7; // r8
  unsigned int v8; // r5
  int v9; // r4
  unsigned __int8 v10; // r4
  unsigned int v11; // r1
  _DWORD *v12; // r4
  int v13; // r1
  int v14; // r2
  int v15; // r3
  int v16; // r0
  unsigned int v18; // [sp+4h] [bp-24h]

  v1 = KeAbPreAcquire((unsigned int)&PnpBusTypeGuidLock, 0, 0);
  v2 = KfRaiseIrql(1);
  do
    v3 = __ldrex((unsigned __int8 *)&PnpBusTypeGuidLock);
  while ( __strex(v3 & 0xFE, (unsigned __int8 *)&PnpBusTypeGuidLock) );
  __dmb(0xBu);
  if ( (v3 & 1) == 0 )
    return sub_7EF4AC(v2);
  if ( v1 )
    *(_BYTE *)(v1 + 14) |= 1u;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = PnpBusTypeGuidCount;
  dword_630C64 = v5;
  dword_630C7C = v2;
  v7 = PnpBusTypeGuidArray;
  v8 = 0;
  if ( PnpBusTypeGuidCount )
  {
    v9 = PnpBusTypeGuidArray;
    do
    {
      if ( a1 == v9 )
        break;
      if ( RtlCompareMemory((unsigned __int8 *)a1, v9, 16) == 16 )
        break;
      ++v8;
      v9 += 16;
    }
    while ( v8 < v6 );
  }
  if ( v8 == v6 )
  {
    if ( v8 == PnpBusTypeGuidCountMax )
    {
      v16 = ExAllocatePoolWithTag(1, 16 * (v8 + 1), 1970499664);
      v6 = PnpBusTypeGuidCount;
      v7 = v16;
      if ( v16 )
      {
        v18 = PnpBusTypeGuidArray;
        memmove(v16, PnpBusTypeGuidArray, 16 * PnpBusTypeGuidCount);
        ++PnpBusTypeGuidCountMax;
        if ( v18 )
        {
          ExFreePoolWithTag(v18);
          v6 = PnpBusTypeGuidCount;
        }
        PnpBusTypeGuidArray = v7;
      }
      else
      {
        v7 = PnpBusTypeGuidArray;
        v8 = -1;
      }
    }
    if ( v8 != -1 )
    {
      v12 = (_DWORD *)(v7 + 16 * v6);
      v13 = *(_DWORD *)(a1 + 4);
      v14 = *(_DWORD *)(a1 + 8);
      v15 = *(_DWORD *)(a1 + 12);
      *v12 = *(_DWORD *)a1;
      v12[1] = v13;
      v12[2] = v14;
      v12[3] = v15;
      PnpBusTypeGuidCount = v6 + 1;
    }
  }
  dword_630C64 = 0;
  v10 = dword_630C7C;
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)&PnpBusTypeGuidLock);
  while ( !v11 && __strex(1u, (unsigned int *)&PnpBusTypeGuidLock) );
  if ( v11 )
    ExpReleaseFastMutexContended((unsigned int *)&PnpBusTypeGuidLock, v11);
  KfLowerIrql(v10);
  KeAbPostRelease((unsigned int)&PnpBusTypeGuidLock);
  return (unsigned __int16)v8;
}

// KiForceSymbolReferences 
 
int __fastcall KiForceSymbolReferences(int a1, int a2, unsigned int a3, unsigned int a4)
{
  int v4; // r0
  unsigned int v5; // r1
  int v6; // r4
  unsigned __int8 v8[4]; // [sp+0h] [bp-10h] BYREF
  unsigned int v9[3]; // [sp+4h] [bp-Ch] BYREF

  v9[0] = a3;
  v9[1] = a4;
  if ( !*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594) )
  {
    v4 = KeAbPreAcquire((unsigned int)v8, 0, 1);
    do
      v5 = __ldrex(v8);
    while ( __strex(v5 | 1, v8) );
    __dmb(0xBu);
    if ( (v5 & 1) != 0 )
    {
      if ( v4 )
        KeAbPostReleaseEx((int)v8, v4);
    }
    else if ( v4 )
    {
      *(_BYTE *)(v4 + 14) |= 1u;
    }
  }
  v6 = KfRaiseIrql(2);
  ExTryAcquireSpinLockExclusiveAtDpcLevel(v9);
  return KfLowerIrql(v6);
}

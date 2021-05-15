// IopLiveDumpCorralProcessors 
 
int __fastcall IopLiveDumpCorralProcessors(int a1)
{
  unsigned int *v2; // r6
  unsigned int v3; // r4
  unsigned int v4; // r2
  unsigned int v5; // r2
  unsigned int v6; // r7
  unsigned int v7; // r3
  unsigned int v8; // r3
  int result; // r0
  int v10[8]; // [sp+8h] [bp-20h] BYREF

  *(_DWORD *)(a1 + 4) = 0;
  __dmb(0xBu);
  *(_DWORD *)(a1 + 8) = 0;
  v2 = (unsigned int *)(a1 + 12);
  __dmb(0xBu);
  *(_DWORD *)(a1 + 12) = 0;
  __dmb(0xBu);
  *(_DWORD *)(a1 + 16) = 0;
  *(_DWORD *)(a1 + 68) = 0;
  *(_DWORD *)(a1 + 72) = 0;
  *(_DWORD *)(a1 + 76) = 0;
  IopLiveDumpLockPages();
  v10[1] = 0;
  v10[2] = 0;
  v10[0] = 1;
  KeSetSystemGroupAffinityThread((int)v10, (_DWORD *)(a1 + 56));
  *(_DWORD *)(a1 + 68) = 0;
  *(_DWORD *)(a1 + 72) = 0;
  __dmb(0xBu);
  *(_DWORD *)(a1 + 8) = 1;
  IopLiveDumpTraceSystemQuiesceStart();
  *(_BYTE *)(a1 + 52) = KfRaiseIrql(2);
  KeInitializeDpc(a1 + 20, (int)IopLiveDumpCorralDpc, a1);
  *(_BYTE *)(a1 + 21) = 2;
  v3 = dword_681D78[0];
  while ( v3 )
  {
    v4 = __clz(__rbit(v3));
    v3 &= ~(1 << v4);
    if ( v4 == *(_DWORD *)(a1 + 68) )
    {
      __dmb(0xBu);
      do
        v5 = __ldrex(v2);
      while ( __strex(v5 + 1, v2) );
      __dmb(0xBu);
    }
    else
    {
      v6 = *v2;
      *(_WORD *)(a1 + 22) = (char)v4 + 32;
      KeInsertQueueDpc(a1 + 20);
      while ( 1 )
      {
        v7 = *v2;
        __dmb(0xBu);
        if ( v6 != v7 )
          break;
        __dmb(0xAu);
        __yield();
      }
    }
  }
  v8 = *v2;
  __dmb(0xBu);
  *(_DWORD *)(a1 + 16) = v8;
  IopLiveDumpInitiateCorralStateChange(a1, 2);
  PoAllProcIntrDisabled = 1;
  result = IopLiveDumpInitiateCorralStateChange(a1, 3);
  *(_DWORD *)(a1 + 4) |= 1u;
  return result;
}

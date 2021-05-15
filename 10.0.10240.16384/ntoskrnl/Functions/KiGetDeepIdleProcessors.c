// KiGetDeepIdleProcessors 
 
int __fastcall KiGetDeepIdleProcessors(int a1, int a2)
{
  int v4; // r0
  int v5; // r1
  void **v6; // r4
  int v7; // t1
  int result; // r0
  int v9; // r2
  int v10; // r3

  __dmb(0xFu);
  v4 = KfRaiseIrql(2);
  v5 = (unsigned __int16)KeNumberNodes;
  *(_WORD *)a1 = 1;
  *(_WORD *)(a1 + 2) = 1;
  *(_DWORD *)(a1 + 4) = 0;
  *(_DWORD *)(a1 + 8) = 0;
  if ( v5 )
  {
    v6 = &KeNodeBlock;
    do
    {
      v7 = (int)*v6++;
      *(_DWORD *)(a1 + 8) |= *(_DWORD *)(v7 + 128);
      --v5;
    }
    while ( v5 );
  }
  result = KfLowerIrql(v4);
  *(_WORD *)(a2 + 2) = 1;
  *(_WORD *)a2 = 1;
  *(_DWORD *)(a2 + 4) = 0;
  v9 = ~*(_DWORD *)(a1 + 8);
  *(_DWORD *)(a2 + 8) = v9;
  v10 = dword_681D78[0];
  *(_WORD *)(a2 + 2) = 1;
  *(_WORD *)a2 = 1;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = v10 & v9;
  return result;
}

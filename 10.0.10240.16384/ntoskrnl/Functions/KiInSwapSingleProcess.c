// KiInSwapSingleProcess 
 
int __fastcall KiInSwapSingleProcess(int a1, int a2, int a3)
{
  int v6; // r7
  unsigned int v7; // r4
  unsigned int v9; // r2
  unsigned int v10; // r1

  v6 = 1;
  do
    v7 = __ldrex((unsigned __int8 *)a2);
  while ( __strex(v7 | 0x80, (unsigned __int8 *)a2) );
  __dmb(0xBu);
  if ( v7 >> 7 )
    return sub_50ED74();
  if ( (*(_DWORD *)(a2 + 116) & 7) == 0 )
  {
    __dmb(0xBu);
    do
      v10 = __ldrex((unsigned int *)a2);
    while ( __strex(v10 & 0xFFFFFF7F, (unsigned int *)a2) );
    v6 = 0;
    goto LABEL_9;
  }
  KiRequestProcessInSwap(a1, a2);
  v9 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  if ( a1 != *(_DWORD *)(v9 + 1412) )
  {
LABEL_9:
    KfLowerIrql(a3);
    return v6;
  }
  *(_BYTE *)(a1 + 395) = 23;
  *(_BYTE *)(a1 + 134) = a3;
  KiSwapThread(a1, v9 + 1408);
  return 1;
}

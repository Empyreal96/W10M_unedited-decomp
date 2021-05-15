// KeSuspendThread 
 
int __fastcall KeSuspendThread(int a1)
{
  int v2; // r0
  int v3; // r8
  unsigned int v4; // r7
  unsigned __int8 *v5; // r6
  unsigned int v6; // r2
  int v8; // r5
  unsigned int v9; // r1
  unsigned int v10; // r1

  v2 = KfRaiseIrql(2);
  v3 = v2;
  v4 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v5 = (unsigned __int8 *)(a1 + 452);
  do
    v6 = __ldrex(v5);
  while ( __strex(v6 | 0x80, v5) );
  __dmb(0xBu);
  if ( v6 >> 7 )
    return sub_521720();
  v8 = *(char *)(a1 + 396);
  if ( v8 == 127 )
  {
    __dmb(0xBu);
    do
      v10 = __ldrex((unsigned int *)v5);
    while ( __strex(v10 & 0xFFFFFF7F, (unsigned int *)v5) );
    KfLowerIrql(v2);
    RtlRaiseStatus(-1073741750);
  }
  *(_BYTE *)(a1 + 396) = v8 + 1;
  if ( !KiSuspendThread(a1, v4 + 1408) )
    --*(_BYTE *)(a1 + 396);
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)v5);
  while ( __strex(v9 & 0xFFFFFF7F, (unsigned int *)v5) );
  KiExitDispatcher(v4 + 1408, 0, 1, 0, v3);
  return v8;
}

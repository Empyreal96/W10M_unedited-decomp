// KeSetTimer 
 
int __fastcall KeSetTimer(unsigned int *a1, int a2, int a3, int a4, int a5)
{
  int v6; // r4
  int v7; // r8
  unsigned int v8; // r6
  __int64 v9; // r0
  int v10; // r9
  bool v11; // zf
  unsigned int v12; // r0
  unsigned int *v13; // r1
  unsigned int v15; // r1
  unsigned int *varg_r0; // [sp+30h] [bp+8h]
  int varg_r3; // [sp+3Ch] [bp+14h]

  varg_r0 = a1;
  varg_r3 = a4;
  v6 = __ROR4__(bswap32(KiWaitAlways ^ a5) ^ (unsigned int)a1, KiWaitNever) ^ KiWaitNever;
  v7 = KfRaiseIrql(2);
  v8 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v9 = KiCancelTimer(a1, 0);
  a1[8] = v6;
  v10 = v9;
  a1[10] = 0;
  v11 = KiComputeDueTime(a1, HIDWORD(v9), a3, varg_r3, 0) == 0;
  v12 = v8 + 1408;
  v13 = a1;
  if ( v11 )
    goto LABEL_9;
  a1[1] = 0;
  if ( !KiInsertTimerTable(v12, a1, a5, a4, 0) )
  {
    v13 = a1;
    v12 = v8 + 1408;
LABEL_9:
    KiTimerWaitTest(v12, v13, 0);
    goto LABEL_7;
  }
  if ( (dword_682608 & 0x20000) != 0 )
    return sub_50AAA4();
  __dmb(0xBu);
  do
    v15 = __ldrex(a1);
  while ( __strex(v15 & 0xFFFFFF7F, a1) );
LABEL_7:
  KiExitDispatcher(v8 + 1408, 0, 1, 0, v7);
  return v10;
}

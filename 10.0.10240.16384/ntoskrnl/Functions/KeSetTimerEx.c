// KeSetTimerEx 
 
int __fastcall KeSetTimerEx(unsigned int *a1, int a2, int a3, int a4, unsigned int a5, int a6)
{
  int v7; // r4
  int v8; // r8
  unsigned int v9; // r6
  __int64 v10; // r0
  int v11; // r9
  bool v12; // zf
  unsigned int v13; // r0
  unsigned int *v14; // r1
  unsigned int v16; // r1
  unsigned int *varg_r0; // [sp+30h] [bp+8h]
  int varg_r3; // [sp+3Ch] [bp+14h]

  varg_r0 = a1;
  varg_r3 = a4;
  v7 = __ROR4__(bswap32(KiWaitAlways ^ a6) ^ (unsigned int)a1, KiWaitNever) ^ KiWaitNever;
  v8 = KfRaiseIrql(2);
  v9 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v10 = KiCancelTimer(a1, 0);
  a1[10] = a5;
  a1[8] = v7;
  v11 = v10;
  v12 = KiComputeDueTime(a1, HIDWORD(v10), a3, varg_r3, 0) == 0;
  v13 = v9 + 1408;
  v14 = a1;
  if ( v12 )
    goto LABEL_9;
  a1[1] = 0;
  if ( !KiInsertTimerTable(v13, a1, a6, a4) )
  {
    v14 = a1;
    v13 = v9 + 1408;
LABEL_9:
    KiTimerWaitTest(v13, v14, 0);
    goto LABEL_7;
  }
  if ( (dword_682608 & 0x20000) != 0 )
    return sub_50C854();
  __dmb(0xBu);
  do
    v16 = __ldrex(a1);
  while ( __strex(v16 & 0xFFFFFF7F, a1) );
LABEL_7:
  KiExitDispatcher(v9 + 1408, 0, 1, 0, v8);
  return v11;
}

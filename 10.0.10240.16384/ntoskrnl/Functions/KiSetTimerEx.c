// KiSetTimerEx 
 
int __fastcall KiSetTimerEx(int a1, unsigned int a2, __int64 a3, int a4, unsigned __int8 a5, int a6)
{
  int v7; // r4
  unsigned __int8 v8; // r8
  unsigned int v9; // r6
  int v10; // r0
  __int64 v11; // r2
  int v12; // r9
  bool v13; // zf
  int v14; // r0
  unsigned int v15; // r1
  unsigned int v17; // r1
  unsigned int var20[12]; // [sp+8h] [bp-20h] BYREF
  __int64 varg_r2; // [sp+38h] [bp+10h]

  var20[10] = a1;
  var20[11] = a2;
  varg_r2 = a3;
  var20[0] = HIDWORD(a3);
  v7 = __ROR4__(bswap32(KiWaitAlways ^ a6) ^ a1, KiWaitNever) ^ KiWaitNever;
  v8 = KfRaiseIrql(2);
  v9 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v10 = KiCancelTimer(a1, 0);
  *(_DWORD *)(a1 + 40) = a4;
  v11 = varg_r2;
  v12 = v10;
  *(_DWORD *)(a1 + 32) = v7;
  v13 = KiComputeDueTime((_DWORD *)a1, v11, a5, var20) == 0;
  v14 = v9 + 1408;
  v15 = a1;
  if ( v13 )
    goto LABEL_9;
  *(_DWORD *)(a1 + 4) = 0;
  if ( !KiInsertTimerTable(v14, (_DWORD *)a1, a6, var20[0], 0) )
  {
    v15 = a1;
    v14 = v9 + 1408;
LABEL_9:
    KiTimerWaitTest(v14, v15, 0);
    goto LABEL_7;
  }
  if ( (dword_682608 & 0x20000) != 0 )
    return sub_50E188();
  __dmb(0xBu);
  do
    v17 = __ldrex((unsigned int *)a1);
  while ( __strex(v17 & 0xFFFFFF7F, (unsigned int *)a1) );
LABEL_7:
  KiExitDispatcher(v9 + 1408, 0, 1, 0, v8);
  return v12;
}

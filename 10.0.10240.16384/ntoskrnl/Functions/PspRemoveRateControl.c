// PspRemoveRateControl 
 
unsigned int __fastcall PspRemoveRateControl(int a1, int a2, int a3, int a4, int a5)
{
  int v7; // r8
  int v8; // r0
  int v9; // r3
  unsigned int *v10; // r4
  unsigned int v11; // r7
  _DWORD **v12; // r4
  int v13; // r1
  unsigned int result; // r0
  int v15[5]; // [sp+8h] [bp-38h] BYREF
  char v16; // [sp+1Ch] [bp-24h]

  v7 = PspGetRateControlJobFlag(a2, 0);
  v8 = PspGetRateControlJobFlag(a2, 1);
  __dmb(0xBu);
  v10 = (unsigned int *)(a1 + 744);
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 & ~v8, v10) );
  __dmb(0xBu);
  v15[1] = v9;
  v15[0] = 0;
  v15[2] = a5;
  v15[4] = a2;
  v15[3] = 0;
  v16 = 0;
  PspEnumJobsAndProcessesInJobHierarchy(
    a1,
    (int)PspSetRateControlJobPreCallback,
    0,
    (int)PspSetRateControlProcessCallback,
    (int)v15,
    5u);
  PspModifyAncestorBits(a1, v7, 0);
  v12 = (_DWORD **)PspGetRateControlHeaderPtr(a1, a2);
  result = PspFreeRateControl(*v12, v13);
  *v12 = 0;
  return result;
}

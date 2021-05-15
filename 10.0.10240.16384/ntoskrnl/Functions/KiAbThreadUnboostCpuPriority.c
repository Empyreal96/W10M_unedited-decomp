// KiAbThreadUnboostCpuPriority 
 
int __fastcall KiAbThreadUnboostCpuPriority(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v6; // r0
  unsigned int v7; // r2
  int v8; // r5
  int v10; // [sp+0h] [bp-18h] BYREF
  unsigned int i; // [sp+4h] [bp-14h]

  v10 = a3;
  i = a4;
  v5 = *(unsigned __int16 *)(a2 + 44) >> 1;
  v10 = 0;
  v6 = KfRaiseIrql(2);
  v7 = __clz(__rbit(v5));
  v8 = v6;
  for ( i = v7; 1 != (unsigned __int8)(v7 >> 5); i = v7 )
  {
    KiClearPriorityFloor(a1, &v10, v7 + 1);
    v5 &= v5 - 1;
    v7 = __clz(__rbit(v5));
  }
  return KiProcessDeferredReadyList(((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408, &v10, v8);
}

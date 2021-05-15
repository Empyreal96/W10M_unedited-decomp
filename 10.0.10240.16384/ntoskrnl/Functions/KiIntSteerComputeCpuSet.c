// KiIntSteerComputeCpuSet 
 
int __fastcall KiIntSteerComputeCpuSet(int a1, int a2, int a3, int a4)
{
  int v5; // r5
  int v6; // r0
  int v7; // r6
  __int16 v8; // r3
  int v10; // [sp+0h] [bp-18h] BYREF
  int v11; // [sp+4h] [bp-14h]
  int v12; // [sp+8h] [bp-10h]

  v10 = a2;
  v11 = a3;
  v12 = a4;
  v5 = 0;
  v6 = KiComputeCpuSetAffinityMask(0, (int *)(a1 + 116), a3, *(_DWORD *)(a1 + 104));
  if ( v6 && (v11 = 0, v12 = 0, v7 = 1 << __clz(__rbit(v6)), v10 = v7, KiIntSteerVerifyDestination(a1, (int)&v10) >= 0) )
  {
    v8 = v11;
    *(_DWORD *)(a1 + 132) = v7;
    *(_WORD *)(a1 + 136) = v8;
  }
  else
  {
    v5 = -1073741823;
    *(_DWORD *)(a1 + 132) = 0;
  }
  return v5;
}

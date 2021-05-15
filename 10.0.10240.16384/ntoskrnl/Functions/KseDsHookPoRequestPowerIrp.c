// KseDsHookPoRequestPowerIrp 
 
int __fastcall KseDsHookPoRequestPowerIrp(int a1, int a2, int a3, int a4, int a5, _DWORD *a6)
{
  int v8; // r4
  int varg_r0; // [sp+20h] [bp+8h]
  int varg_r1; // [sp+24h] [bp+Ch]
  int varg_r3; // [sp+2Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r3 = a4;
  v8 = off_617D9C(a1, a2);
  KsepDsEventRequestPowerIrp(*(_DWORD *)(a1 + 8), a1, a4, a2);
  if ( a6 )
    *a6 = a4;
  return v8;
}

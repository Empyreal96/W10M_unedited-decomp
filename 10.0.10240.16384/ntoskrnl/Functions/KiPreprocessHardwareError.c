// KiPreprocessHardwareError 
 
int __fastcall KiPreprocessHardwareError(_DWORD *a1, int a2, int a3, int a4)
{
  _DWORD *v6; // r5
  int v7; // r6
  int v8; // r4
  unsigned int v9; // r0
  unsigned __int16 *v10; // r3
  unsigned int v11; // r3
  unsigned int v12; // r0
  unsigned __int16 *v13; // r3
  int varg_r1; // [sp+34h] [bp+Ch]
  int varg_r2; // [sp+38h] [bp+10h]

  varg_r1 = a2;
  varg_r2 = a3;
  v6 = a1;
  v7 = KeGetCurrentIrql(a1);
  if ( !v7 )
    KfRaiseIrql(1);
  v6[4] = 0;
  *v6 = -1073740023;
  v8 = *(_DWORD *)(a3 + 64);
  if ( (v8 & 1) != 0 && (v8 & 0xFFFFFFFE) != *(_DWORD *)(a2 + 8) )
  {
    if ( (*(_DWORD *)(a3 + 68) & 0x1F) == 19 )
    {
      v9 = *(unsigned __int16 *)(v8 - 1);
      if ( v9 >= 0xE800 )
        v9 = *(unsigned __int16 *)(v8 + 1) | (v9 << 16);
    }
    else
    {
      v10 = (unsigned __int16 *)(v8 - 1);
      if ( v8 - 1 >= (unsigned int)MmUserProbeAddress )
        v10 = (unsigned __int16 *)MmUserProbeAddress;
      v11 = *v10;
      v9 = v11;
      if ( v11 >= 0xE800 )
      {
        v12 = v11 << 16;
        v13 = (unsigned __int16 *)(*(_DWORD *)(a3 + 64) + 1);
        if ( (unsigned int)v13 >= MmUserProbeAddress )
          v13 = (unsigned __int16 *)MmUserProbeAddress;
        v9 = v12 | *v13;
      }
    }
    if ( KiIsExclusiveInstruction(v9) )
      *v6 = -1073741795;
  }
  if ( !v7 )
    KfLowerIrql(0);
  return 0;
}

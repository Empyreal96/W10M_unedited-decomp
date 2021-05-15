// KeDispatchSecondaryInterrupt 
 
int __fastcall KeDispatchSecondaryInterrupt(int a1, int a2, int a3)
{
  BOOL v5; // r5
  int v6; // r6
  int *v7; // r4
  int result; // r0
  int v9[8]; // [sp+8h] [bp-20h] BYREF

  v9[1] = (int)v9;
  v9[0] = (int)v9;
  v5 = (a2 & 0x100000) != 0;
  v6 = KeGetCurrentIrql(a1);
  if ( v6 )
    v7 = v9;
  else
    v7 = 0;
  result = ((int (__fastcall *)(int, int, BOOL, int *, int))KiInterruptDispatchCommon)(1, a1, v5, v7, a3);
  if ( v6 )
  {
    if ( (int *)*v7 != v7 )
      result = sub_5539B0(result);
  }
  return result;
}

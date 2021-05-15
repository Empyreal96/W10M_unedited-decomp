// KeAdjustInterruptTime 
 
int __fastcall KeAdjustInterruptTime(int a1, int a2, int a3)
{
  char v4[4]; // [sp+0h] [bp-30h] BYREF
  int v5; // [sp+4h] [bp-2Ch]
  int v6; // [sp+8h] [bp-28h]
  int v7; // [sp+Ch] [bp-24h]
  int v8; // [sp+18h] [bp-18h]
  int v9; // [sp+1Ch] [bp-14h]

  if ( a2 <= 0 && a2 < 0 )
    return 0;
  v5 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
  v6 = a1;
  v7 = a2;
  v4[0] = a3;
  v8 = KeNumberProcessors_0;
  v9 = 1;
  KeIpiGenericCall((int (__fastcall *)(int))KiCalibrateTimeAdjustment, (int)v4, a3, 1);
  return 1;
}

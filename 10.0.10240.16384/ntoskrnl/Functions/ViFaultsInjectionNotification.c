// ViFaultsInjectionNotification 
 
int __fastcall ViFaultsInjectionNotification(int a1, int a2, int a3, int a4)
{
  int *v4; // r2
  int v6; // r3
  unsigned int vars4; // [sp+Ch] [bp+4h]

  v4 = &MmVerifierData;
  v6 = dword_620DAC + 1;
  __dmb(0xBu);
  dword_620DAC = v6;
  if ( (MmVerifierData & 0x1000) != 0 )
    ViTargetIncrementCounter(vars4, 92, (int)&MmVerifierData, MmVerifierData);
  return ViFaultsTracesLog(a1 + 1, a2, v4, a4);
}

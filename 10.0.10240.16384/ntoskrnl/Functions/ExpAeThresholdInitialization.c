// ExpAeThresholdInitialization 
 
int ExpAeThresholdInitialization()
{
  int v0; // r0
  _BYTE v2[273]; // [sp-101h] [bp-139h] BYREF
  int v3; // [sp+10h] [bp-28h]

  memset((_BYTE *)((unsigned int)v2 & 0xFFFFFF80), 0, 256);
  v0 = KfRaiseIrql(2);
  *(_DWORD *)&v2[257] = 1024;
  v3 = v0;
  return sub_96C3E0();
}

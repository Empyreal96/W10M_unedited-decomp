// PopDeviceConstraintsEnforced 
 
int PopDeviceConstraintsEnforced()
{
  int v0; // r4
  int v1; // r0
  _BYTE *v2; // r3

  v0 = 0;
  v1 = KfRaiseIrql(2);
  v2 = *(_BYTE **)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1100);
  if ( v2 && *v2 == 1 && PpmPlatformStates )
    v0 = 1;
  KfLowerIrql(v1);
  return v0;
}

// MiComputeCommitThresholds 
 
int __fastcall MiComputeCommitThresholds(_DWORD *a1)
{
  unsigned int v1; // r1
  unsigned int v2; // r3
  int v3; // r3

  v1 = a1[1029];
  v2 = v1 / 0xA;
  if ( v1 / 0xA > 0x10000 )
    v2 = 0x10000;
  a1[805] = v1 - v2;
  v3 = v1 >> 2;
  if ( v1 >> 2 > 0x100000 )
    v3 = 0x100000;
  a1[804] = v1 - v3;
  return MiSyncCommitSignals(a1, 1);
}

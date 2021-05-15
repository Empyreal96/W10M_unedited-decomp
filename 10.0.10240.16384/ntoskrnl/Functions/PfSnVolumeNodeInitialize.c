// PfSnVolumeNodeInitialize 
 
int __fastcall PfSnVolumeNodeInitialize(int a1)
{
  memset((_BYTE *)a1, 0, 68);
  *(_DWORD *)a1 = a1;
  *(_DWORD *)(a1 + 4) = a1;
  PfpOpenHandleInitialize(a1 + 16);
  return PfpOpenHandleInitialize(a1 + 36);
}

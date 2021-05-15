// IopGetBootDiskInformationLite 
 
// positive sp value has been detected, the output may be wrong!
int IopGetBootDiskInformationLite()
{
  _DWORD *v0; // r4
  _DWORD *v1; // r8
  unsigned int v2; // r0
  _DWORD *v3; // r2
  int v4; // r1
  int v6; // [sp-A4h] [bp-1A4h] BYREF
  int v7; // [sp-9Ch] [bp-19Ch] BYREF

  v0 = KeLoaderBlock_0;
  v1 = (_DWORD *)*((_DWORD *)KeLoaderBlock_0 + 32);
  RtlInitAnsiString((unsigned int)&v6, *((_DWORD *)KeLoaderBlock_0 + 26));
  v2 = RtlInitAnsiString((unsigned int)&v7, v0[27]);
  v3 = (_DWORD *)*v1;
  v4 = 2;
  while ( v1 != v3 )
  {
    if ( v3[10] )
      ++v4;
    v3 = (_DWORD *)*v3;
  }
  return ((int (__fastcall *)(unsigned int, int))sub_96E6DC)(v2, v4);
}

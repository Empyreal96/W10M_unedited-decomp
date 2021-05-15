// PiSwDeviceCompareObjects 
 
int __fastcall PiSwDeviceCompareObjects(int a1, int *a2, int *a3)
{
  int v3; // r4
  int v4; // r5
  int v5; // r0
  bool v6; // nf

  v3 = *a2;
  v4 = *a3;
  v5 = wcsicmp(*(_DWORD *)(*a2 + 12), *(unsigned __int16 **)(*a3 + 12));
  v6 = v5 < 0;
  if ( !v5 )
  {
    v5 = wcsicmp(*(_DWORD *)(v3 + 8), *(unsigned __int16 **)(v4 + 8));
    v6 = v5 < 0;
  }
  if ( v6 )
    return 0;
  if ( v5 <= 0 )
    return 2;
  return 1;
}

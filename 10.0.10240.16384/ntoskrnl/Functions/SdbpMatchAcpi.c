// SdbpMatchAcpi 
 
int __fastcall SdbpMatchAcpi(int a1, int a2, _DWORD *a3)
{
  int v5; // r4
  int v6; // r0
  int v7; // r6

  v5 = 0;
  v6 = SdbFindFirstTag(a1, a2, 28703);
  v7 = v6;
  if ( !v6
    || SdbpMatchDeviceString(a1, *a3, v6, 24613)
    && SdbpMatchDeviceString(a1, a3[1], v7, 24614)
    && SdbpMatchDeviceDWORD(a1, a3[7], v7, 16436)
    && SdbpMatchDeviceDWORD(a1, a3[8], v7, 16448) )
  {
    v5 = 1;
  }
  return v5;
}

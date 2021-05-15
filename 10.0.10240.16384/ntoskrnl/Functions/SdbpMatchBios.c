// SdbpMatchBios 
 
int __fastcall SdbpMatchBios(int a1, int a2, _DWORD *a3)
{
  int v5; // r4
  int v6; // r0
  int v7; // r6

  v5 = 0;
  v6 = SdbFindFirstTag(a1, a2, 28704);
  v7 = v6;
  if ( !v6 || SdbpMatchDeviceString(a1, *a3, v6, 24613) && SdbpMatchDeviceDWORD(a1, a3[6], v7, 16439) )
    v5 = 1;
  return v5;
}

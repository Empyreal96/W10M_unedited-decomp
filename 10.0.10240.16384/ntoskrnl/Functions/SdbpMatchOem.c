// SdbpMatchOem 
 
int __fastcall SdbpMatchOem(int a1, int a2, int a3)
{
  int v5; // r4
  int v6; // r0
  int v7; // r6

  v5 = 0;
  v6 = SdbFindFirstTag(a1, a2, 28706);
  v7 = v6;
  if ( !v6
    || SdbpMatchDeviceString(a1, *(unsigned __int16 **)a3, v6, 24613)
    && SdbpMatchDeviceString(a1, *(unsigned __int16 **)(a3 + 4), v7, 24614)
    && SdbpMatchDeviceDWORD(a1, *(_DWORD *)(a3 + 28), v7, 16436, 0x4035u, 0x4036u) )
  {
    v5 = 1;
  }
  return v5;
}

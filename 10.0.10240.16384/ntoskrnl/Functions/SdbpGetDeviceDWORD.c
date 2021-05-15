// SdbpGetDeviceDWORD 
 
int __fastcall SdbpGetDeviceDWORD(int a1, int a2, int a3)
{
  int v5; // r4
  int v6; // r0

  v5 = -1;
  v6 = SdbFindFirstTag(a1, a2, a3);
  if ( v6 )
    v5 = SdbReadDWORDTag(a1, v6, a3);
  return v5;
}

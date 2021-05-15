// SdbpMatchDeviceDWORD 
 
int __fastcall SdbpMatchDeviceDWORD(int a1, unsigned int a2, int a3, int a4, unsigned __int16 a5, unsigned __int16 a6)
{
  int v9; // r4
  int v10; // r0
  unsigned int v11; // r0
  unsigned int v12; // r0

  v9 = 0;
  v10 = SdbpGetDeviceDWORD(a1, a3, a4);
  if ( v10 == -1 )
  {
    v11 = SdbpGetDeviceDWORD(a1, a3, a5);
    if ( v11 == -1 || v11 >= a2 )
    {
      v12 = SdbpGetDeviceDWORD(a1, a3, a6);
      if ( v12 == -1 || v12 <= a2 )
        return 1;
    }
  }
  else if ( v10 == a2 )
  {
    return 1;
  }
  return v9;
}

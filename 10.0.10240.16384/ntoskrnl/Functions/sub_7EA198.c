// sub_7EA198 
 
void __fastcall sub_7EA198(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, char a11, int a12, int a13, int a14, int a15, int a16, char *a17, bool a18, int a19, int a20, int a21, int a22)
{
  _DWORD *v22; // r5
  unsigned __int16 *v23; // r1

  v23 = (unsigned __int16 *)v22[2];
  if ( v23 )
  {
    if ( RtlInitUnicodeStringEx((int)&a11, v23) >= 0 )
    {
      memset(&a17, 0, 24);
      a17 = &a11;
      a18 = (v22[3] & 0x100) != 0;
      a19 = 0;
      a20 = 0;
      a21 = v22[4];
      a22 = v22[5];
      PiDmGetCmObjectListFromCache(1, (int)PiPnpRtlServiceFilterCallback, (int)&a17);
      if ( a19 )
        JUMPOUT(0x704714);
    }
    JUMPOUT(0x704622);
  }
  JUMPOUT(0x70471A);
}

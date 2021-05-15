// AdtpGetCapID 
 
int __fastcall AdtpGetCapID(int a1, _DWORD *a2, int a3, int a4)
{
  int v5; // r5
  unsigned __int8 *v6; // r0
  int v8; // [sp+0h] [bp-18h] BYREF
  unsigned int v9; // [sp+4h] [bp-14h] BYREF
  int v10[4]; // [sp+8h] [bp-10h] BYREF

  v8 = a1;
  v10[0] = a3;
  v10[1] = a4;
  v9 = 0;
  v5 = RtlGetSaclSecurityDescriptor(a1, &v8, v10, (char *)&v8 + 1);
  if ( v5 >= 0 )
  {
    *a2 = 0;
    if ( (_BYTE)v8 )
    {
      while ( 1 )
      {
        v6 = RtlFindAceByType(v10[0], 19, &v9);
        if ( v6 )
        {
          if ( (v6[1] & 8) == 0 )
            break;
        }
        ++v9;
        if ( !v6 )
          return v5;
      }
      *a2 = v6 + 8;
    }
  }
  return v5;
}

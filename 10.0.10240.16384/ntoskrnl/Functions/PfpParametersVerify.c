// PfpParametersVerify 
 
int __fastcall PfpParametersVerify(int *a1)
{
  int v1; // r3
  int v2; // r2
  bool v3; // zf
  unsigned int v4; // r3
  unsigned int v5; // r5
  unsigned int v6; // r3

  v1 = *a1;
  v2 = -1073741811;
  if ( *a1 >= 0 )
    v3 = (v1 & 0xFFFFFFFC) == 0;
  else
    v3 = v1 == 0x80000000;
  if ( v3 && (unsigned int)a1[2] <= 0x10000 && (unsigned int)a1[3] <= 0x10000 )
  {
    v4 = a1[4];
    if ( v4 <= 0xEA60 && v4 >= 0x9C4 )
    {
      v5 = a1[5];
      if ( v5 <= 0xEA60 && v5 >= 0x1388 )
      {
        v6 = a1[6];
        if ( v6 <= 0xEA60 && v6 >= 0x9C4 )
          v2 = 0;
      }
    }
  }
  return v2;
}

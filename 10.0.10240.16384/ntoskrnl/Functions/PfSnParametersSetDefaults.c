// PfSnParametersSetDefaults 
 
int __fastcall PfSnParametersSetDefaults(_DWORD *a1)
{
  int v1; // r2
  _DWORD *v2; // r4
  _DWORD *v3; // r3
  int result; // r0

  v1 = 0;
  v2 = a1 + 16;
  do
  {
    v2[v1] = 0;
    v3 = &v2[4 * v1];
    if ( v1 )
    {
      if ( v1 == 1 )
      {
        v3[4] = -10000000;
        v3[5] = -1;
        v3[2] = 20000;
        v3[3] = 500;
        a1[121] = L"Activity";
      }
    }
    else
    {
      v3[4] = -10000000;
      v3[5] = -1;
      *((_QWORD *)v3 + 1) = 0x15400007D00i64;
      a1[120] = L"AppLaunch";
    }
    ++v1;
  }
  while ( v1 < 2 );
  a1[26] = 8;
  a1[27] = 16;
  a1[116] = 0;
  RtlStringCbCopyW((int)(a1 + 28), 0x60u);
  *((_WORD *)v2 + 71) = 0;
  result = RtlStringCbCopyW((int)(v2 + 36), 0x100u);
  *((_WORD *)v2 + 199) = 0;
  v2[101] = 10;
  return result;
}

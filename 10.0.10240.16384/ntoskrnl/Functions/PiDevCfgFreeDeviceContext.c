// PiDevCfgFreeDeviceContext 
 
unsigned int __fastcall PiDevCfgFreeDeviceContext(int *a1)
{
  unsigned int result; // r0
  _DWORD *v2; // r4
  int v3; // r5

  if ( *a1 < 0 )
    return sub_7E35B8();
  v2 = a1 + 3;
  v3 = 3;
  do
  {
    result = RtlFreeAnsiString(v2);
    v2 += 2;
    --v3;
  }
  while ( v3 );
  return result;
}

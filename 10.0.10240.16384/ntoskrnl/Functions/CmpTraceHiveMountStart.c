// CmpTraceHiveMountStart 
 
int CmpTraceHiveMountStart()
{
  int result; // r0
  int v1; // r1
  char v2; // r2
  _DWORD v3[8]; // [sp+4h] [bp-20h] BYREF

  v3[0] = 285212688;
  v3[1] = 65796;
  v3[2] = 0;
  v3[3] = 0x40000000;
  result = EtwEventEnabled(EtwpRegTraceHandle, unk_92026C, (int)v3);
  if ( result )
    result = sub_7D2B14(result, v1, v2);
  return result;
}

// CmpTraceHiveMountBaseFileMounted 
 
int __fastcall CmpTraceHiveMountBaseFileMounted(int a1, int a2)
{
  int result; // r0
  _DWORD var58[26]; // [sp+14h] [bp-58h] BYREF

  var58[24] = a1;
  var58[25] = a2;
  var58[0] = 285212689;
  var58[1] = 68100;
  var58[2] = 0;
  var58[3] = 0x40000000;
  result = EtwEventEnabled(EtwpRegTraceHandle, dword_92026C, (int)var58);
  if ( result )
    result = sub_7F3CBC();
  return result;
}

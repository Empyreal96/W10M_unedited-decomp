// CmpTraceHiveLoadStop 
 
int __fastcall CmpTraceHiveLoadStop(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, char a17)
{
  int result; // r0
  int v18; // r1
  char v19; // r2
  int v20; // r3
  _DWORD var30[16]; // [sp+4h] [bp-30h] BYREF

  var30[14] = a1;
  var30[15] = a2;
  var30[0] = 285212710;
  var30[1] = 328196;
  var30[2] = 0;
  var30[3] = 0x40000000;
  result = EtwEventEnabled(EtwpRegTraceHandle, unk_92026C, (int)var30);
  if ( result )
    result = sub_7C2E9C(result, v18, v19, v20, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17);
  return result;
}

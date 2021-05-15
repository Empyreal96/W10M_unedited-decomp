// CmpTraceHiveRestoreStop 
 
int __fastcall CmpTraceHiveRestoreStop(int a1, int a2)
{
  __int64 v2; // kr00_8
  int result; // r0
  _DWORD var30[13]; // [sp+8h] [bp-30h] BYREF
  _DWORD vars8[2]; // [sp+40h] [bp+8h] BYREF

  vars8[0] = a1;
  vars8[1] = a2;
  var30[0] = 285212712;
  var30[1] = 393732;
  var30[2] = 0;
  var30[3] = 0x40000000;
  v2 = *(_QWORD *)&EtwpRegTraceHandle;
  result = EtwEventEnabled(EtwpRegTraceHandle, dword_92026C, (int)var30);
  if ( result )
  {
    var30[4] = vars8;
    var30[5] = 0;
    var30[6] = 4;
    var30[7] = 0;
    result = EtwWrite(v2, SHIDWORD(v2), (int)var30, 0);
  }
  return result;
}

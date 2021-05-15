// CmpTraceHiveMountLogEntryApplied 
 
int __fastcall CmpTraceHiveMountLogEntryApplied(int a1, int a2)
{
  __int64 v2; // kr00_8
  int result; // r0
  _DWORD var40[17]; // [sp+8h] [bp-40h] BYREF
  int vars8; // [sp+50h] [bp+8h] BYREF
  int varsC; // [sp+54h] [bp+Ch] BYREF

  vars8 = a1;
  varsC = a2;
  var40[0] = 285212690;
  var40[1] = 68356;
  var40[2] = 0;
  var40[3] = 0x40000000;
  v2 = *(_QWORD *)&EtwpRegTraceHandle;
  result = EtwEventEnabled(EtwpRegTraceHandle, unk_92026C, (int)var40);
  if ( result )
  {
    var40[4] = &vars8;
    var40[5] = 0;
    var40[6] = 4;
    var40[7] = 0;
    var40[8] = &varsC;
    var40[9] = 0;
    var40[10] = 4;
    var40[11] = 0;
    result = EtwWrite(v2, SHIDWORD(v2), (int)var40, 0);
  }
  return result;
}

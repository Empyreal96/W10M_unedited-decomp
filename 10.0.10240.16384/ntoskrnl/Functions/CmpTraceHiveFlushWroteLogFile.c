// CmpTraceHiveFlushWroteLogFile 
 
int __fastcall CmpTraceHiveFlushWroteLogFile(int a1, int a2)
{
  int result; // r0
  _DWORD var40[20]; // [sp+Ch] [bp-40h] BYREF

  var40[18] = a1;
  var40[19] = a2;
  var40[0] = 285212698;
  var40[1] = 199940;
  var40[2] = 0;
  var40[3] = 0x40000000;
  result = EtwEventEnabled(EtwpRegTraceHandle, unk_92026C, (int)var40);
  if ( result )
    result = sub_7F3E0C();
  return result;
}

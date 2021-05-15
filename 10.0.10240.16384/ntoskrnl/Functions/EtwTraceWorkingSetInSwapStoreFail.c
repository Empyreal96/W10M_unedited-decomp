// EtwTraceWorkingSetInSwapStoreFail 
 
int __fastcall EtwTraceWorkingSetInSwapStoreFail(int a1, int a2)
{
  __int64 v3; // kr00_8
  int result; // r0
  int var38[17]; // [sp+8h] [bp-38h] BYREF
  int varsC; // [sp+4Ch] [bp+Ch] BYREF

  var38[16] = a1;
  varsC = a2;
  v3 = *(_QWORD *)&EtwpMemoryProvRegHandle;
  result = EtwProviderEnabled(EtwpMemoryProvRegHandle, unk_61A944, 0, (int)&EtwpMemoryProvRegHandle, 128i64);
  if ( result )
  {
    var38[2] = (int)var38;
    var38[3] = 0;
    var38[4] = 4;
    var38[5] = 0;
    var38[6] = (int)&varsC;
    var38[7] = 0;
    var38[8] = 4;
    var38[9] = 0;
    var38[0] = PsGetProcessId(a1);
    result = EtwWrite(v3, SHIDWORD(v3), (int)KERNEL_MEM_EVENT_WS_INSWAP_STORE_FAIL, 0);
  }
  return result;
}

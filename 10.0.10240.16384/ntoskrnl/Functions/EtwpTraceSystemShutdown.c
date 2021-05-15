// EtwpTraceSystemShutdown 
 
int EtwpTraceSystemShutdown()
{
  int result; // r0
  int v1; // [sp+8h] [bp-70h] BYREF
  __int64 v2; // [sp+10h] [bp-68h] BYREF
  __int64 v3; // [sp+18h] [bp-60h] BYREF
  __int64 *v4; // [sp+20h] [bp-58h]
  int v5; // [sp+24h] [bp-54h]
  int v6; // [sp+28h] [bp-50h]
  int v7; // [sp+2Ch] [bp-4Ch]
  _DWORD v8[18]; // [sp+30h] [bp-48h] BYREF

  KeQuerySystemTimePrecise(&v2);
  if ( (unsigned int)dword_617748 > 5 && TlgKeywordOn((int)&dword_617748, 0x200000000000i64) )
  {
    v1 = 2;
    v3 = v2;
    v8[8] = &v1;
    v8[9] = 0;
    v8[10] = 4;
    v8[11] = 0;
    v8[12] = &v3;
    v8[13] = 0;
    v8[14] = 8;
    v8[15] = 0;
    TlgWrite(&dword_617748, (unsigned __int8 *)dword_41486C + 1, 0, 0, 4, v8);
  }
  result = EtwKernelProvRegHandle;
  if ( EtwKernelProvRegHandle )
  {
    v4 = &v2;
    v5 = 0;
    v6 = 8;
    v7 = 0;
    result = EtwWrite(EtwKernelProvRegHandle, SHIDWORD(EtwKernelProvRegHandle), (int)KernelSystemStop, 0);
  }
  return result;
}

// PiCMSetProblem 
 
int __fastcall PiCMSetProblem(unsigned __int16 *a1, int a2, int a3)
{
  int result; // r0
  int v6; // r4
  int v7; // [sp+10h] [bp-40h] BYREF
  int v8; // [sp+14h] [bp-3Ch] BYREF
  int v9; // [sp+18h] [bp-38h] BYREF
  int v10[12]; // [sp+20h] [bp-30h] BYREF

  v7 = 0;
  v8 = 0;
  if ( (unsigned int)(a3 - 1) > 1 )
    return -1073741811;
  result = CmGetDeviceStatus(PiPnpRtlCtx, a1, 0, &v8, &v7, &v9);
  if ( result >= 0 )
  {
    v6 = v7;
    if ( a2 )
    {
      result = sub_7DEB58();
    }
    else
    {
      memset(v10, 0, 28);
      RtlInitUnicodeString((unsigned int)v10, a1);
      v10[3] = 1024;
      v10[4] = v6;
      v10[2] = 2;
      result = ZwPlugPlayControl();
    }
  }
  return result;
}

// EtwpCheckGuidAccessAndDoRundown 
 
int __fastcall EtwpCheckGuidAccessAndDoRundown(int a1, int a2, int *a3, int a4)
{
  int v7; // r4
  int v8; // r2
  unsigned int v9; // r6
  _BYTE v11[56]; // [sp-4h] [bp-38h] BYREF

  v7 = EtwpCheckGuidAccess((int)SystemTraceControlGuid, 128, 0, a4);
  if ( v7 >= 0 )
  {
    v8 = a3[3];
    if ( v8 == -2147483647 )
    {
      v9 = a3[2];
      if ( v9 <= 0x20 && (v9 & 3) == 0 )
      {
        memset(v11, 0, 32);
        memmove((int)v11, *a3, v9);
        EtwpLogKernelTraceRundown(a2, v11, a4);
        return v7;
      }
    }
    else if ( v8 == -2147483646 && a3[2] == 8 )
    {
      return EtwpCheckLoggerAccessAndDoRundown(*(unsigned __int16 *)*a3, a2, a4);
    }
    v7 = -1073741811;
  }
  return v7;
}

// EtwpGetSystemMaximumBufferCount 
 
int __fastcall EtwpGetSystemMaximumBufferCount(unsigned int *a1)
{
  __int64 v2; // r4
  __int64 v3; // kr08_8
  unsigned int v4; // r0
  unsigned int v5; // r3
  unsigned __int64 v6; // r0
  unsigned __int64 v7; // r2
  __int64 v8; // r0
  unsigned __int64 v10; // r0

  if ( a1[56] == 1 )
  {
    LODWORD(v2) = MmSizeOfPagedPoolInBytes;
LABEL_14:
    HIDWORD(v2) = 0;
    goto LABEL_4;
  }
  v3 = (unsigned int)MmGetNumberOfPhysicalPages(0);
  v2 = v3 << 12;
  v4 = MmGetMaximumNonPagedPoolInBytes();
  if ( !is_mul_ok(0x1000u, v3) || (unsigned int)v2 >= v4 )
  {
    LODWORD(v2) = v4;
    goto LABEL_14;
  }
LABEL_4:
  if ( (a1[152] & 2) != 0 && (v5 = a1[3], (v5 & 0x2000000) != 0) && (v5 & 0x400) != 0 )
  {
    LODWORD(v10) = _rt_udiv64(100i64, 50 * v2);
    v7 = v10;
    v8 = a1[1];
    if ( !(_DWORD)v8 )
      __brkdiv0();
  }
  else
  {
    LODWORD(v6) = _rt_udiv64(100i64, v2 * (unsigned int)EtwpMaxNonPagedPoolUsage);
    v7 = v6;
    v8 = a1[1];
    if ( !(_DWORD)v8 )
      __brkdiv0();
  }
  return _rt_udiv64(v8, v7);
}

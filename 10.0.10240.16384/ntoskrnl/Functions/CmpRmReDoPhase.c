// CmpRmReDoPhase 
 
int CmpRmReDoPhase(int result, int a2, ...)
{
  int v2; // r7
  int v3; // r4
  int v4; // r3
  _DWORD *v5; // r5
  int v6; // r0
  int v7; // r0
  int *v8; // [sp+10h] [bp-58h]
  char v9[4]; // [sp+18h] [bp-50h] BYREF
  _DWORD *v10; // [sp+1Ch] [bp-4Ch] BYREF
  int v11; // [sp+20h] [bp-48h] BYREF
  int v12; // [sp+24h] [bp-44h] BYREF
  int v13; // [sp+28h] [bp-40h] BYREF
  char v14[4]; // [sp+2Ch] [bp-3Ch] BYREF
  char v15[8]; // [sp+30h] [bp-38h] BYREF
  char v16[8]; // [sp+38h] [bp-30h] BYREF
  char v17[40]; // [sp+40h] [bp-28h] BYREF
  va_list varg_r2; // [sp+78h] [bp+10h] BYREF

  va_start(varg_r2, a2);
  v11 = 0;
  v9[0] = 0;
  v2 = result;
  if ( *(_DWORD *)(result + 8) != result + 8 )
  {
    v8 = &v11;
    if ( ClfsReadLogRecord(*(_DWORD *)(result + 56), (int *)varg_r2, 3, &v10, v14, v9, v16, v15) >= 0 )
    {
      do
      {
        if ( (v9[0] & 1) != 0 && CmpSearchAddTrans(0, v2, 0, 0, (int)(v10 + 4), 0, &v13) >= 0 )
        {
          v3 = (int)v10;
          v4 = v10[3];
          v5 = v10;
          v12 = (int)v10;
          if ( (v4 & 0x80000000) != 0 )
          {
            if ( CmpDoReadTxRBigLogRecord(v11, (int)v10, (unsigned int *)&v12) < 0 )
              break;
            v3 = (int)v10;
            v5 = (_DWORD *)v12;
          }
          if ( *v5 == HvBufferCheckSum(v5, v5[1]) )
          {
            CmpRealignLogBuffers((int)v5);
            v6 = CmpDoReDoRecord(v13, v5);
            v3 = (int)v10;
          }
          else
          {
            v6 = -1072103376;
            if ( KdDebuggerEnabled && !KdDebuggerNotPresent )
              __debugbreak();
          }
          if ( v6 < 0 )
          {
            *(_DWORD *)(v13 + 64) |= 2u;
            v3 = (int)v10;
          }
          if ( (*(_DWORD *)(v3 + 12) & 0x80000000) != 0 )
            ExFreePoolWithTag((unsigned int)v5);
        }
        v9[0] = 1;
        v7 = ClfsReadNextLogRecord(v11, &v10, v14, v9, 0, v16, v15, v17, v8);
      }
      while ( v7 != -1073741807 && v7 >= 0 );
    }
    result = v11;
    if ( v11 )
      result = ClfsTerminateReadLog();
  }
  return result;
}

// PopReleaseAdaptiveLock 
 
int PopReleaseAdaptiveLock()
{
  int result; // r0
  unsigned int v1; // r1
  __int16 v2; // r3
  int v3; // r8
  int v4; // r7
  int v5; // [sp+0h] [bp-68h] BYREF
  int v6; // [sp+8h] [bp-60h] BYREF
  int v7[5]; // [sp+Ch] [bp-5Ch] BYREF
  char v8[4]; // [sp+20h] [bp-48h] BYREF
  int v9[17]; // [sp+24h] [bp-44h] BYREF

  v8[0] = 0;
  memset(v9, 0, 20);
  LOBYTE(v6) = 0;
  memset(v7, 0, sizeof(v7));
  PopAdpmLockThread = 0;
  if ( PopLazyContext )
  {
    v6 = *(_DWORD *)&PopLazyContext;
    v7[0] = dword_61DE04;
    v7[1] = dword_61DE08;
    v7[2] = dword_61DE0C;
    v7[3] = *(_DWORD *)&byte_61DE10;
    v7[4] = dword_61DE14;
    PopLazyContext = 0;
  }
  result = ExReleaseResourceLite((int)&PopAdpmLock);
  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v2 = *(_WORD *)(v1 + 0x134) + 1;
  *(_WORD *)(v1 + 308) = v2;
  if ( !v2 && *(_DWORD *)(v1 + 100) != v1 + 100 )
    return sub_7EB028(result);
  if ( (_BYTE)v6 )
  {
    v3 = v7[0];
    if ( BYTE2(v7[3]) )
    {
      PopSensorActiveInput(&v6);
      v4 = v7[1];
    }
    else
    {
      v4 = v7[1];
      if ( LOBYTE(v7[3]) )
        PopSetWin32kInputTimeout(v7[0], v7[1]);
      if ( BYTE1(v7[3]) )
      {
        v9[5] = 1868437176;
        v9[6] = 1075086709;
        v9[7] = 1596000690;
        v9[8] = -841524783;
        v9[9] = v7[2];
        PopSendSessionInfo(v3);
      }
    }
    v9[3] = 7;
    v5 = v3;
    result = PopDispatchStateCallout((int)v8, (int)&v5);
    if ( HIBYTE(v7[3]) )
      result = PopSetWin32kInputTimeout(-1, v4);
  }
  return result;
}

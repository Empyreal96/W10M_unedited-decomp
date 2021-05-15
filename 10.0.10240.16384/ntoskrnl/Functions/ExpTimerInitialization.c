// ExpTimerInitialization 
 
BOOL ExpTimerInitialization()
{
  int v0; // r4
  BOOL result; // r0
  _BYTE v2[8]; // [sp+0h] [bp-68h] BYREF
  int v3[22]; // [sp+8h] [bp-60h] BYREF

  ExpWakeTimerLock = 0;
  ExpWakeTimerList = (int)&ExpWakeTimerList;
  dword_61A0D4 = (int)&ExpWakeTimerList;
  RtlInitUnicodeString((unsigned int)v2, L"Timer");
  memset(v3, 0, sizeof(v3));
  LOWORD(v3[0]) = 88;
  v3[2] = 256;
  v3[3] = 131073;
  v3[4] = 131074;
  v3[5] = 1179648;
  v3[6] = 2031619;
  v3[9] = 512;
  v3[11] = 192;
  v3[7] = 2031619;
  v3[15] = (int)ExpDeleteTimer;
  result = 0;
  if ( ObCreateObjectType() >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v2, L"IRTimer");
    v3[11] = 88;
    v3[15] = (int)ExpDeleteTimer2;
    v0 = ObCreateObjectType();
    ExpTimerFreedCookie = ExGenRandom(0);
    if ( v0 >= 0 )
      result = 1;
  }
  return result;
}

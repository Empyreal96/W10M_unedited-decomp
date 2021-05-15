// ExpSemaphoreInitialization 
 
BOOL ExpSemaphoreInitialization()
{
  int v1; // [sp+0h] [bp-68h] BYREF
  int v2[22]; // [sp+8h] [bp-60h] BYREF

  RtlInitUnicodeString((unsigned int)&v1, L"Semaphore");
  memset(v2, 0, sizeof(v2));
  LOWORD(v2[0]) = 88;
  v2[1] = 8;
  v2[2] = 256;
  v2[3] = 131073;
  v2[4] = 131074;
  v2[5] = 1179648;
  v2[6] = 2031619;
  v2[9] = 512;
  v2[11] = 20;
  v2[7] = 2031619;
  return ObCreateObjectType() >= 0;
}

// ExpProfileInitialization 
 
BOOL ExpProfileInitialization()
{
  int v1; // [sp+0h] [bp-68h] BYREF
  int v2[22]; // [sp+8h] [bp-60h] BYREF

  KiInitializeMutant((int)&ExpProfileStateMutex, 0, 1);
  RtlInitUnicodeString((unsigned int)&v1, L"Profile");
  memset(v2, 0, sizeof(v2));
  LOWORD(v2[0]) = 88;
  v2[2] = 256;
  v2[9] = 512;
  v2[11] = 56;
  v2[7] = 983041;
  v2[15] = (int)ExpProfileDelete;
  v2[3] = 131073;
  v2[4] = 131073;
  v2[5] = 131073;
  v2[6] = 983041;
  return ObCreateObjectType() >= 0;
}

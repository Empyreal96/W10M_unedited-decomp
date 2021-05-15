// SepTokenInitialization 
 
BOOL SepTokenInitialization()
{
  int v1; // [sp+0h] [bp-68h] BYREF
  int v2[22]; // [sp+8h] [bp-60h] BYREF

  RtlInitUnicodeString((unsigned int)&v1, L"Token");
  memset(v2, 0, sizeof(v2));
  LOWORD(v2[0]) = 88;
  v2[1] = 512;
  v2[2] = 256;
  v2[3] = 131098;
  v2[4] = 131552;
  v2[5] = 131077;
  v2[6] = 983551;
  BYTE2(v2[0]) |= 0xEu;
  v2[9] = 1;
  v2[7] = 983551;
  v2[15] = (int)SepTokenDeleteMethod;
  return ObCreateObjectType() >= 0 && SeRegisterObjectTypeMandatoryPolicy(SeTokenObjectType, 1) >= 0;
}

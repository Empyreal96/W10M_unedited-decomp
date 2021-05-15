// CmpCreateObjectTypes 
 
int CmpCreateObjectTypes()
{
  int v1[22]; // [sp+0h] [bp-68h] BYREF

  memset(v1, 0, sizeof(v1));
  LOWORD(v1[0]) = 88;
  v1[2] = 48;
  v1[3] = 131097;
  v1[10] = 44;
  BYTE2(v1[0]) = (BYTE2(v1[0]) | 8) & 0xEB | 4;
  v1[1] = 256;
  v1[12] = 0;
  v1[13] = 0;
  v1[9] = 1;
  v1[14] = (int)CmpCloseKeyObject;
  v1[4] = 131078;
  v1[5] = 131129;
  v1[15] = (int)CmpDeleteKeyObject;
  v1[6] = 983103;
  v1[7] = 983103;
  v1[16] = (int)CmpParseKey;
  v1[17] = (int)CmpSecurityMethod;
  v1[18] = (int)CmpQueryKeyName;
  return ObCreateObjectType();
}

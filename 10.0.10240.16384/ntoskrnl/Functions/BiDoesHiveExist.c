// BiDoesHiveExist 
 
BOOL __fastcall BiDoesHiveExist(int a1)
{
  char v2[8]; // [sp+18h] [bp-40h] BYREF

  RtlInitUnicodeString((unsigned int)v2, (unsigned __int16 *)(a1 + 12));
  return ZwQueryAttributesFile() >= 0;
}

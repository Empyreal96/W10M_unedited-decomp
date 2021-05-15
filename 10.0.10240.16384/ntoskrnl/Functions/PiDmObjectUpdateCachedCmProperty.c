// PiDmObjectUpdateCachedCmProperty 
 
int __fastcall PiDmObjectUpdateCachedCmProperty(int result, int a2, int a3, int a4, int a5, unsigned __int16 *a6, int a7)
{
  int v8; // r0
  char v9[8]; // [sp+10h] [bp-20h] BYREF
  char v10[24]; // [sp+18h] [bp-18h] BYREF

  if ( a4 == 9 && result == 1 )
  {
    if ( !a7 )
    {
      v8 = CmMapCmObjectTypeToPnpObjectType(1);
      return PiDmObjectUpdateCachedObjectProperty(v8, a2);
    }
    if ( a5 == 1 )
    {
      RtlInitUnicodeString((unsigned int)v9, a6);
      result = RtlGUIDFromString(v9, v10);
      if ( result >= 0 )
      {
        v8 = CmMapCmObjectTypeToPnpObjectType(1);
        return PiDmObjectUpdateCachedObjectProperty(v8, a2);
      }
    }
  }
  return result;
}

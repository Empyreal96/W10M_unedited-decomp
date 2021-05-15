// OpenGlobalizationUserSettingsKey 
 
int __fastcall OpenGlobalizationUserSettingsKey(int a1, int a2, int a3, int a4, int a5)
{
  int v6; // r0

  if ( !a5 )
    return -1073741811;
  v6 = sub_5C1588();
  switch ( v6 )
  {
    case 0:
      return RtlOpenCurrentUser(8, a5);
    case 1:
    case 2:
      return sub_5C1604();
    case 3:
      return -1073741822;
  }
  return -1073741595;
}

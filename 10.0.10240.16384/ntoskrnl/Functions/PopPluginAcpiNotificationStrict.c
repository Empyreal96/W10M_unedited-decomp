// PopPluginAcpiNotificationStrict 
 
int __fastcall PopPluginAcpiNotificationStrict(int a1, int a2, int a3)
{
  int result; // r0

  result = (*(int (__fastcall **)(int, int))(a1 + 72))(a2, a3);
  if ( !result )
    PopFxBugCheck(1640, a2, a1, a3);
  return result;
}

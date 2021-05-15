// CloseGlobalizationUserSettingsKey 
 
int __fastcall CloseGlobalizationUserSettingsKey(int a1)
{
  int v1; // r3

  v1 = 0;
  if ( a1 && a1 != -1 )
    v1 = ZwClose();
  return v1;
}

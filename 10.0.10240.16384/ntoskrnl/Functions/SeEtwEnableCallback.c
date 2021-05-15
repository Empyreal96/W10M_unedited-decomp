// SeEtwEnableCallback 
 
int __fastcall SeEtwEnableCallback(int a1, int a2, int a3, int a4, int a5)
{
  int result; // r0

  result = a5;
  if ( (a5 & 0x20) != 0 )
    return sub_555B20();
  byte_6417CC = 0;
  SepLearningModeSettings = 0;
  byte_6417CD = 0;
  SepTokenSidManagementLoggingEnabled = (a5 & 0x40) != 0;
  return result;
}

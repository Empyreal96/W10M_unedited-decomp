// PfProcessCreateNotification 
 
int __fastcall PfProcessCreateNotification(int a1, int a2)
{
  if ( !a2 )
    return -1073741637;
  if ( (dword_643904 & 1) != 0 || (dword_637340 & 1) != 0 )
    return sub_8086AC();
  PfSnBeginAppLaunch(a1);
  return 0;
}

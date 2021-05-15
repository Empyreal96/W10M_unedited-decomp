// _CmContainerListGenericObjectCallback 
 
int __fastcall CmContainerListGenericObjectCallback(int a1, unsigned __int16 *a2, int a3, _DWORD *a4)
{
  int result; // r0

  result = 0;
  if ( a4 )
  {
    if ( CmValidateDeviceContainerName(0, a2) < 0 )
    {
      result = 0;
    }
    else
    {
      result = 1;
      if ( *a4 )
        result = sub_811D54(1);
    }
  }
  return result;
}

// EtwpRealtimeRestoreState 
 
int EtwpRealtimeRestoreState()
{
  int result; // r0
  __int64 v1; // [sp+78h] [bp-28h]

  result = ZwQueryInformationFile();
  if ( result >= 0 )
  {
    if ( v1 )
      result = sub_81C7DC();
    else
      result = 0;
  }
  return result;
}

// LpcInitSystem 
 
int LpcInitSystem()
{
  int result; // r0

  LpcLegacyMaxMessageLength = 328;
  if ( AlpcpInitSystem() < 0 )
    return 0;
  result = 1;
  *(_DWORD *)LpcWaitablePortObjectType = AlpcPortObjectType;
  LpcPortObjectType = AlpcPortObjectType;
  return result;
}

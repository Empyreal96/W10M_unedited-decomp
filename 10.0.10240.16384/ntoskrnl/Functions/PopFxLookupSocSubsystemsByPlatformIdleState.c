// PopFxLookupSocSubsystemsByPlatformIdleState 
 
int PopFxLookupSocSubsystemsByPlatformIdleState()
{
  int result; // r0

  result = 0;
  if ( (int *)SocSubsystemsList != &SocSubsystemsList )
    result = sub_7BF37C(0, &SocSubsystemsList, SocSubsystemsList);
  return result;
}

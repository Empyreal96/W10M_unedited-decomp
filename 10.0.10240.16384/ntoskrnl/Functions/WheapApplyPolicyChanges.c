// WheapApplyPolicyChanges 
 
unsigned int WheapApplyPolicyChanges()
{
  int v0; // r1
  unsigned int result; // r0
  int *v2; // r3

  v0 = WheaRegistryKeysPresent;
  for ( result = 0; result < 7; ++result )
  {
    if ( WheaRegPolicyTableChanged[result] )
    {
      WheaRegPolicyTableChanged[result] = 0;
      v2 = (int *)*(&WheaRegPolicyTable + 4 * result + 1);
      if ( result )
      {
        switch ( result )
        {
          case 1u:
            WheapPolicyMemPersistOffline = *v2 != 0;
            v0 |= 2u;
            break;
          case 2u:
            WheapPolicyMemPfaDisable = *v2 != 0;
            v0 |= 4u;
            break;
          case 3u:
            v0 |= 8u;
            WheapPolicyMemPfaPageCount = *v2;
            break;
          case 4u:
            v0 |= 0x10u;
            WheapPolicyMemPfaThreshold = *v2;
            break;
          case 5u:
            v0 |= 0x20u;
            WheapPolicyMemPfaTimeout = (unsigned int)*v2 * (unsigned __int64)(unsigned int)dword_989680;
            break;
          default:
            WheaRegPolicyIgnoreDummyWrite = *v2 != 0;
            v0 |= 0x100u;
            break;
        }
      }
      else
      {
        WheapPolicyDisableOffline = *v2 != 0;
        v0 |= 1u;
      }
      WheaRegistryKeysPresent = v0;
    }
  }
  return result;
}

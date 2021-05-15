// VfFaultsInjectResourceFailure 
 
int __fastcall VfFaultsInjectResourceFailure(int a1, int a2, int a3, int a4)
{
  int v6; // r3
  int v7; // r0
  unsigned int v8; // r7
  unsigned int v9; // r6
  int v10; // r3
  int v11; // r0
  int v12[6]; // [sp+0h] [bp-18h] BYREF

  v12[0] = a3;
  v12[1] = a4;
  if ( ViFaultsInitialized )
  {
    if ( !ViFaultsDisabled )
    {
      if ( (MmVerifierData & 4) != 0 )
      {
        v8 = VfFaultInjectionProbability;
        v9 = VfFaultInjectionMaxProbability;
        if ( !VfFaultInjectionProbability )
          return 0;
        if ( VfFaultInjectionProbability > (unsigned int)VfFaultInjectionMaxProbability )
          return 0;
        if ( !VfFaultsIsSystemSufficientlyBooted() )
          return 0;
        if ( !a1 )
        {
          if ( ViHaveFaultTags )
          {
            v10 = ViFaultsForceAllAPIs;
            __dmb(0xBu);
            if ( !v10 )
              return 0;
          }
        }
        if ( !ViFaultsIsCurrentAppTarget() )
          return 0;
        if ( VfRandomGetNumber(0, v9) >= v8 )
        {
          ++dword_908664;
          if ( v8 != 600 )
            return 0;
          if ( v9 != 10000 )
            return 0;
          KeQueryTickCount(v12);
          if ( (v12[0] & 0x7FFFu) >= 0x400 )
            return 0;
          ++dword_908668;
        }
        else
        {
          ++dword_908660;
        }
        if ( a1 )
          v11 = 3;
        else
          v11 = 1;
        ViFaultsInjectionNotification(v11);
      }
      else
      {
        v6 = ViInjectInPagePathOnly;
        __dmb(0xBu);
        if ( v6 != 1 || !*(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3CE) )
          return 0;
        if ( a1 )
          v7 = 3;
        else
          v7 = 1;
        ViFaultsInjectionNotification(v7);
        ++dword_908650;
      }
      return 1;
    }
    ++dword_908674;
  }
  else
  {
    ++ViFaultsDecisions;
  }
  return 0;
}

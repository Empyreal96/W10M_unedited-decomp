// VfFaultsSetParameters 
 
int __fastcall VfFaultsSetParameters(int a1, int a2, int a3, int a4)
{
  int v5; // r5
  int v6; // r0
  int v7; // r0
  int v9[4]; // [sp+0h] [bp-10h] BYREF

  v9[1] = a4;
  v9[0] = MmVerifierData | 4;
  v5 = VfSetVerifierInformation(v9, 4, 1);
  if ( v5 >= 0 )
  {
    v6 = PsSetCreateProcessNotifyRoutine((int)ViCreateProcessCallback, 0);
    if ( *(_DWORD *)(a1 + 4) )
      VfFaultInjectionMaxProbability = *(_DWORD *)(a1 + 4);
    if ( *(_DWORD *)a1 )
    {
      VfFaultInjectionProbability = *(_DWORD *)a1;
    }
    else
    {
      VfFaultInjectionMaxProbability = 10000;
      VfFaultInjectionProbability = 600;
    }
    v7 = ViFaultsRemoveAllTags(v6, &VfFaultInjectionMaxProbability);
    ViFaultsRemoveAllApps(v7);
    if ( *(_WORD *)(a1 + 16) )
      v5 = ViFaultsAddAllApps(*(_DWORD *)(a1 + 20), *(unsigned __int16 *)(a1 + 16) >> 1);
    if ( v5 >= 0 && *(_WORD *)(a1 + 8) )
      v5 = ViFaultsAddAllTags(*(_DWORD *)(a1 + 12), *(unsigned __int16 *)(a1 + 8) >> 1);
  }
  return v5;
}

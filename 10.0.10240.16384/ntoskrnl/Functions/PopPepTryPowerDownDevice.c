// PopPepTryPowerDownDevice 
 
int __fastcall PopPepTryPowerDownDevice(int a1, int a2, int a3, unsigned __int8 a4)
{
  int v6; // r6
  int v7; // r8
  unsigned int v8; // r5

  v6 = 0;
  v7 = PopPepLockActivityLink(a1, 0, 6, 4);
  if ( (*(_DWORD *)(a1 + 16) & 1) == 0
    && !*(_DWORD *)(a1 + 92)
    && *(_BYTE *)(a1 + 88)
    && !**(_DWORD **)(a1 + 64)
    && !**(_DWORD **)(a1 + 68) )
  {
    v8 = *(_DWORD *)(a1 + 72);
    PopPepTriggerActivity(a1, 0, 4, 0);
    PopPepPromoteActivities(a1, 0, 1);
    if ( a2 && **(_DWORD **)(a1 + 64) == 2 )
      v6 = PopPepStartActivity(a1, 0, a1 + 48, 4);
    else
      PopPepRequestWork(v8, *(_DWORD *)(a1 + 72));
  }
  PopPepReleaseActivityLink(a1, 0, v7, a4);
  return v6;
}

// PopPepSurprisePowerOn 
 
int __fastcall PopPepSurprisePowerOn(int a1, int a2, int a3, int a4)
{
  int v5; // r6
  unsigned int v6; // r4
  int v8[4]; // [sp+8h] [bp-10h] BYREF

  v8[0] = a4;
  v5 = PopPepLockActivityLink(a1, 0, 6, 0, v8);
  if ( !*(_DWORD *)(a1 + 92) && !*(_BYTE *)(a1 + 88) && !**(_DWORD **)(a1 + 48) )
  {
    v6 = *(_DWORD *)(a1 + 72);
    PopPepTriggerActivity(a1, 0, 0, 0);
    PopPepPromoteActivities(a1, 0, 1);
    PopPepRequestWork(v6, *(_DWORD *)(a1 + 72));
  }
  return PopPepReleaseActivityLink(a1, 0, v5, LOBYTE(v8[0]));
}

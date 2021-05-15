// MmTriageActiveInLastCrash 
 
BOOL __fastcall MmTriageActiveInLastCrash(int a1)
{
  _DWORD *v1; // r1
  BOOL result; // r0
  int v3; // r4
  int v4; // r0
  char v5[4]; // [sp+8h] [bp-18h] BYREF
  char v6[4]; // [sp+Ch] [bp-14h] BYREF
  char v7[4]; // [sp+10h] [bp-10h] BYREF

  v1 = *(_DWORD **)(a1 + 132);
  result = 0;
  if ( v1 )
  {
    if ( *v1 >= 0x908u )
    {
      v3 = v1[7];
      if ( TriageGetBugcheckData(v3, v5, v6, v7) >= 0 )
      {
        v4 = TriageGetMmInformation(v3);
        if ( v4 )
        {
          if ( *(_DWORD *)(v4 + 12) )
            result = 1;
        }
      }
    }
  }
  return result;
}

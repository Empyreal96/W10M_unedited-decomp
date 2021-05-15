// WmipDeleteMethod 
 
int __fastcall WmipDeleteMethod(_DWORD *a1)
{
  int result; // r0
  unsigned int v3; // r0
  unsigned int v4; // r0
  int v5; // r1
  int v6; // r2
  int v7; // r3

  result = a1[10];
  if ( result )
    return sub_81BB34();
  if ( (a1[26] & 2) == 0 )
  {
    v3 = a1[15];
    if ( v3 )
      ExFreePoolWithTag(v3);
    v4 = a1[20];
    if ( v4 )
      ExFreePoolWithTag(v4);
    KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
    WmipCompleteGuidIrpWithError((int)a1, v5, v6, v7);
    result = KeReleaseMutex((int)&WmipSMMutex);
  }
  return result;
}

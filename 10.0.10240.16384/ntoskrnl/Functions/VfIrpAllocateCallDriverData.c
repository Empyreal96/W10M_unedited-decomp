// VfIrpAllocateCallDriverData 
 
int __fastcall VfIrpAllocateCallDriverData(int a1, _DWORD *a2)
{
  _BYTE *v4; // r0

  v4 = (_BYTE *)ExAllocateFromNPagedLookasideList((int)&ViIrpCallDriverDataList);
  *a2 = v4;
  if ( v4 )
  {
    memset(v4, 0, 120);
  }
  else if ( IovpCheckIrpForCriticalTracking(a1) )
  {
    return 0;
  }
  return 1;
}

// IoSetFsTrackOffsetState 
 
int __fastcall IoSetFsTrackOffsetState(int a1, int a2, int a3, int a4)
{
  _DWORD *v9; // r0

  if ( !IopIrpHasValidCombinationOfExtensionTypes(a1, 5) )
    return -1073741637;
  v9 = (_DWORD *)IopAllocateIrpExtension(a1, 5);
  if ( !v9 )
    return -1073741670;
  v9[7] = a2;
  v9[8] = a3;
  v9[9] = a4;
  return 0;
}

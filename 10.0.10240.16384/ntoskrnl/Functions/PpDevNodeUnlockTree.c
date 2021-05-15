// PpDevNodeUnlockTree 
 
int __fastcall PpDevNodeUnlockTree(int result)
{
  void *v1; // r0
  unsigned int v2; // r1
  __int16 v3; // r3

  switch ( result )
  {
    case 0:
      v1 = &IopDeviceTreeLock;
LABEL_3:
      result = ExReleaseResourceLite((int)v1);
      break;
    case 1:
    case 2:
    case 3:
      ExReleaseResourceLite((int)&IopDeviceTreeLock);
      v1 = &PiEngineLock;
      goto LABEL_3;
    case 4:
      result = ExConvertExclusiveToSharedLite((int)&IopDeviceTreeLock);
      break;
  }
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = *(_WORD *)(v2 + 0x134) + 1;
  *(_WORD *)(v2 + 308) = v3;
  if ( !v3 && *(_DWORD *)(v2 + 100) != v2 + 100 )
    result = sub_7BDAA0(result);
  return result;
}

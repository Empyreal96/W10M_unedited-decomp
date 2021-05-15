// PiSwProcessParentStartIrp 
 
int __fastcall PiSwProcessParentStartIrp(int a1)
{
  int v2; // r2
  int v3; // r3
  int v4; // r5
  int result; // r0
  unsigned int v6; // r1
  int v7; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = *(__int16 *)(v2 + 0x134) - 1;
  *(_WORD *)(v2 + 308) = v3;
  ExAcquireResourceExclusiveLite((int)&PiSwLockObj, 1, v2, v3);
  v4 = PiSwFindChildren();
  result = ExReleaseResourceLite((int)&PiSwLockObj);
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = (__int16)(*(_WORD *)(v6 + 0x134) + 1);
  *(_WORD *)(v6 + 308) = v7;
  if ( !v7 )
    return sub_7CBE70(result);
  if ( v4 )
    result = IoInvalidateDeviceRelations(a1, 5);
  return result;
}

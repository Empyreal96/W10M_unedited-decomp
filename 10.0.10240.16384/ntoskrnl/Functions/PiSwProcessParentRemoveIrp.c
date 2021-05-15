// PiSwProcessParentRemoveIrp 
 
int __fastcall PiSwProcessParentRemoveIrp(int result)
{
  int v1; // r4
  int v2; // r3
  int v3; // r2
  int v4; // r3
  int v5; // r0
  unsigned int v6; // r1
  int v7; // r3

  v1 = 0;
  if ( result )
    v2 = *(_DWORD *)(*(_DWORD *)(result + 176) + 20);
  else
    v2 = 0;
  if ( v2 )
    v1 = v2 + 20;
  if ( *(_DWORD *)(v1 + 4) )
  {
    v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v4 = *(__int16 *)(v3 + 0x134) - 1;
    *(_WORD *)(v3 + 308) = v4;
    ExAcquireResourceExclusiveLite((int)&PiSwLockObj, 1, v3, v4);
    if ( PiSwFindChildren() )
    {
      result = sub_7E06BC();
    }
    else
    {
      v5 = PiSwFindSwDevice(*(_DWORD *)(v1 + 4));
      if ( !v5 || (*(_DWORD *)(v5 + 4) & 1) == 0 && !*(_DWORD *)(v5 + 96) )
        PiSwCloseDecendents(v1);
      result = ExReleaseResourceLite((int)&PiSwLockObj);
      v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v7 = (__int16)(*(_WORD *)(v6 + 0x134) + 1);
      *(_WORD *)(v6 + 308) = v7;
      if ( !v7 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
        result = KiCheckForKernelApcDelivery(result);
    }
  }
  return result;
}

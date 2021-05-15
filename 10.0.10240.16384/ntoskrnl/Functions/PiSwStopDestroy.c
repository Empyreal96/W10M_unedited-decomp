// PiSwStopDestroy 
 
int __fastcall PiSwStopDestroy(int a1, unsigned __int16 *a2)
{
  int v3; // r2
  int v4; // r3
  int v6; // r0
  unsigned int v7; // r1
  int v8; // r3
  char v9[32]; // [sp+10h] [bp-20h] BYREF

  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = *(__int16 *)(v3 + 0x134) - 1;
  *(_WORD *)(v3 + 308) = v4;
  ExAcquireResourceExclusiveLite((int)&PiSwLockObj, 1, v3, v4);
  RtlInitUnicodeString((unsigned int)v9, a2);
  if ( PiSwFindChildren() )
    return sub_7E063C();
  v6 = ExReleaseResourceLite((int)&PiSwLockObj);
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = (__int16)(*(_WORD *)(v7 + 0x134) + 1);
  *(_WORD *)(v7 + 308) = v8;
  if ( !v8 && *(_DWORD *)(v7 + 100) != v7 + 100 && !*(_WORD *)(v7 + 310) )
    KiCheckForKernelApcDelivery(v6);
  return -1073741772;
}

// PpDeviceRegistration 
 
int __fastcall PpDeviceRegistration(int a1, int a2, int a3, int a4)
{
  unsigned int v8; // r5
  int v9; // r4
  int v10; // r0
  unsigned int v11; // r1
  int v12; // r3
  int result; // r0

  if ( !a4 )
  {
    v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v8 + 308);
    ExAcquireResourceExclusiveLite((int)&PnpRegistryDeviceResource, 1, a3, 0);
  }
  v9 = PiDeviceRegistration(a1, a2, a3);
  if ( a4
    || (v10 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource),
        v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0,
        v12 = (__int16)(*(_WORD *)(v11 + 0x134) + 1),
        *(_WORD *)(v11 + 308) = v12,
        v12) )
  {
    result = v9;
  }
  else
  {
    result = sub_7C9E94(v10);
  }
  return result;
}

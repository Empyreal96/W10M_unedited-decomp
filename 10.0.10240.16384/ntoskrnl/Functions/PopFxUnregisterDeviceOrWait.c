// PopFxUnregisterDeviceOrWait 
 
int __fastcall PopFxUnregisterDeviceOrWait(_DWORD *a1)
{
  unsigned int *v2; // r2
  unsigned int v3; // r4

  __dmb(0xBu);
  v2 = a1 + 42;
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 | 8, v2) );
  __dmb(0xBu);
  if ( (v3 & 8) != 0 )
    return sub_7E0E78();
  if ( PopFxLockDevice(a1, 0) )
    return PopFxUnregisterDevice();
  return KeSetEvent((int)(a1 + 12), 0, 0);
}

// PoFxUnregisterDevice 
 
int __fastcall PoFxUnregisterDevice(_DWORD *a1)
{
  int v2; // r5

  v2 = a1[7];
  if ( v2 )
    PopFxUnregisterDeviceOrWait((_DWORD *)a1[7]);
  else
    PopFxUnregisterDevice(a1);
  return PopFxDestroyDeviceDpm(v2, a1);
}

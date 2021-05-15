// IopDeviceEjectComplete 
 
int __fastcall IopDeviceEjectComplete(int a1, int a2, _DWORD *a3)
{
  unsigned int *v3; // r0
  unsigned int v4; // r4

  __dmb(0xBu);
  v3 = a3 + 10;
  do
    v4 = __ldrex(v3);
  while ( __strex(3u, v3) );
  __dmb(0xBu);
  a3[4] = PnpProcessCompletedEject;
  a3[5] = a3;
  a3[2] = 0;
  ExQueueWorkItem(a3 + 2, 1);
  if ( v4 != 1 )
    pIoFreeIrp(a2);
  return -1073741802;
}

// KdpSysWriteControlSpace 
 
int __fastcall KdpSysWriteControlSpace(unsigned int a1, int a2, int a3, int a4, int a5, unsigned int a6, _DWORD *a7)
{
  int v7; // r1
  unsigned int v8; // r3

  *a7 = 0;
  if ( a1 >= KeNumberProcessors_0 )
    return -1073741823;
  v7 = (int)*(&KiProcessorBlock + a1);
  if ( !v7 || a3 != 2 || a4 )
    return -1073741823;
  v8 = a6;
  if ( a6 > 0xA8 )
    v8 = 168;
  return KdpCopyMemoryChunks(v7 + 32, 0, a5, v8, 0, 5, a7);
}

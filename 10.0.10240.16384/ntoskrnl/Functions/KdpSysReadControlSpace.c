// KdpSysReadControlSpace 
 
int __fastcall KdpSysReadControlSpace(unsigned int a1, unsigned __int64 a2, int a3, unsigned int a4, _DWORD *a5)
{
  int v6; // r1
  int *v7; // r0
  unsigned int v8; // r3
  int v10; // [sp+10h] [bp-18h] BYREF

  *a5 = 0;
  if ( a1 >= KeNumberProcessors_0 )
    return -1073741823;
  v6 = (int)*(&KiProcessorBlock + a1);
  if ( !v6 )
    return -1073741823;
  v10 = (int)*(&KiProcessorBlock + a1);
  if ( a2 > 3 )
    return -1073741823;
  if ( (_DWORD)a2 == 2 )
  {
    v7 = (int *)(v6 + 32);
    v8 = 168;
  }
  else
  {
    if ( (_DWORD)a2 != 1 )
      return sub_903EE8();
    v7 = &v10;
    v8 = 4;
  }
  if ( v8 > a4 )
    v8 = a4;
  return KdpCopyMemoryChunks((unsigned int)v7, 0, a3, v8, 0, 4, a5);
}

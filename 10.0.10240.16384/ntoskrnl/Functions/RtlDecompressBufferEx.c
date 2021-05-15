// RtlDecompressBufferEx 
 
int __fastcall RtlDecompressBufferEx(unsigned __int8 a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  if ( !a1 || a1 == 1 )
    return -1073741811;
  if ( a1 > 4u )
    return -1073741217;
  return ((int (__fastcall *)(int, int, int, int, _DWORD, int, int, int))RtlDecompressBufferProcs[a1])(
           a2,
           a3,
           a4,
           a5,
           0,
           a6,
           a7,
           a4);
}

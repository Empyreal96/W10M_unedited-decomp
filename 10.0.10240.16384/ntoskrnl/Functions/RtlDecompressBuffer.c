// RtlDecompressBuffer 
 
int __fastcall RtlDecompressBuffer(unsigned __int8 a1, int a2, int a3, int a4, int a5, int a6)
{
  if ( !a1 || a1 == 1 )
    return -1073741811;
  if ( a1 <= 4u )
    return ((int (__fastcall *)(int, int, int, int, _DWORD, int, _DWORD, int))RtlDecompressBufferProcs[a1])(
             a2,
             a3,
             a4,
             a5,
             0,
             a6,
             0,
             a4);
  return -1073741217;
}

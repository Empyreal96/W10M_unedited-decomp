// RtlDecompressFragment 
 
int __fastcall RtlDecompressFragment(unsigned __int8 a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  if ( !a1 || a1 == 1 )
    return -1073741811;
  if ( a1 <= 4u )
    return ((int (__fastcall *)(int, int, int, int, int, _DWORD, int, int))RtlDecompressFragmentProcs[a1])(
             a2,
             a3,
             a4,
             a5,
             a6,
             0,
             a7,
             a8);
  return -1073741217;
}

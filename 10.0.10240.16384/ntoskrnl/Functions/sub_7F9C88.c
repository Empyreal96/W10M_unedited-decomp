// sub_7F9C88 
 
void __fastcall sub_7F9C88(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24)
{
  int v24; // r6
  int v25; // r7
  unsigned __int16 *v26; // r10
  int v27; // r3

  IopSymlinkRemoveECP(v25, (int)&a24);
  if ( IopSymlinkAllocateAndAddECP(v24, &a11, *v26, v27) < 0 )
  {
    FsRtlFreeExtraCreateParameter(a24);
    JUMPOUT(0x7287CA);
  }
  JUMPOUT(0x7287FE);
}

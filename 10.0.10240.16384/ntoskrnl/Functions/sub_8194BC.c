// sub_8194BC 
 
void __fastcall sub_8194BC(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28, int a29, int a30, int a31, int a32, int a33, int a34, int a35, int a36, int a37, int a38, int a39, int a40, int a41, int a42, int a43, int a44, int a45, int a46, int a47, int a48, int a49, int a50)
{
  unsigned int v50; // r0
  unsigned int v51; // r2

  v50 = KeQueryActiveGroupCount();
  v51 = *(unsigned __int16 *)(a50 + 4);
  if ( v51 < v50
    && *(_DWORD *)a50
    && (dword_681D78[v51] & *(_DWORD *)a50) == *(_DWORD *)a50
    && !(*(unsigned __int16 *)(a50 + 6) | *(unsigned __int16 *)(a50 + 10) | *(unsigned __int16 *)(a50 + 8)) )
  {
    JUMPOUT(0x7B50C8);
  }
  JUMPOUT(0x7B50C4);
}

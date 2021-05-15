// sub_7CB918 
 
void __fastcall sub_7CB918(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, char a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28, int a29, int a30, int a31, int a32, __int16 a33)
{
  int v33; // r5
  _DWORD *v34; // r7

  if ( CmGetDeviceContainerIdFromBase((_DWORD *)*v34, v33, (int)&a13, &a33) >= 0
    && CmRemoveDeviceFromContainer(*v34, &a33, &a13, v33) >= 0 )
  {
    PiDcResetChildDeviceContainers(v33, &a33);
    JUMPOUT(0x76DC04);
  }
  JUMPOUT(0x76DC66);
}

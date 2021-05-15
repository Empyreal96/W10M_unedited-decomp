// sub_7CB94C 
 
void __fastcall sub_7CB94C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, char a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16)
{
  int v16; // r5

  if ( a3 == 1 )
    PnpCtxRegDeleteKey(v16, a11, 0);
  if ( a14 == 1 )
    PnpCtxRegDeleteKey(v16, a12, 0);
  if ( a9 == 1 )
    CmDeleteDeviceContainer(v16, a16);
  JUMPOUT(0x76DE28);
}

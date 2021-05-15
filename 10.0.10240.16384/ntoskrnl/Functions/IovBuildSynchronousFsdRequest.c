// IovBuildSynchronousFsdRequest 
 
int __fastcall IovBuildSynchronousFsdRequest(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // r4
  int vars4; // [sp+34h] [bp+4h]

  v7 = XdvIoBuildSynchronousFsdRequest(
         a1,
         a2,
         a3,
         a4,
         a5,
         a6,
         a7,
         vars4,
         (int (__fastcall *)(int, int, int, int))IopBuildSynchronousFsdRequest);
  if ( v7 )
    VfSetIoBuildRequest();
  return v7;
}

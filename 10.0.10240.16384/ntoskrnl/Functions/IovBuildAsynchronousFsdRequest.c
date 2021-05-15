// IovBuildAsynchronousFsdRequest 
 
int __fastcall IovBuildAsynchronousFsdRequest(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // r4
  int vars4; // [sp+2Ch] [bp+4h]

  v6 = XdvIopBuildAsynchronousFsdRequest(
         a1,
         a2,
         a3,
         a4,
         a5,
         a6,
         vars4,
         (int (__fastcall *)(int, int, int))IopBuildAsynchronousFsdRequest);
  if ( v6 )
    VfSetIoBuildRequest();
  return v6;
}

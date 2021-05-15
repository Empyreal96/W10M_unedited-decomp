// PfTInitialize 
 
int __fastcall PfTInitialize(_BYTE *a1, int a2, int a3)
{
  if ( !a3 )
  {
    memset(a1, 0, 576);
    memset(&PfKernelGlobals, 0, 64);
    *(_DWORD *)a1 = 0;
    JUMPOUT(0x8176B0);
  }
  return sub_817610();
}

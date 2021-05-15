// IopFreeIrpAndMdls 
 
int __fastcall IopFreeIrpAndMdls(int a1)
{
  _DWORD *v2; // r0
  _DWORD *v3; // r4

  v2 = *(_DWORD **)(a1 + 4);
  if ( v2 )
  {
    do
    {
      v3 = (_DWORD *)*v2;
      IoFreeMdl();
      v2 = v3;
    }
    while ( v3 );
  }
  return pIoFreeIrp(a1);
}

// MiCreateRotateView 
 
int __fastcall MiCreateRotateView(int a1)
{
  _DWORD *v2; // r4
  int v3; // r0

  v2 = (_DWORD *)ExAllocatePoolWithTag(512, 24, 2004315469);
  if ( !v2 )
    JUMPOUT(0x7EA820);
  v3 = MiGetInPageSupportBlock(0);
  if ( !v3 )
    return sub_7EA818();
  v2[1] = 8;
  v2[2] = v3;
  MiInsertVadEvent(a1, v2, 0);
  return 1;
}

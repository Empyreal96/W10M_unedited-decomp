// sub_510CEC 
 
void __fastcall sub_510CEC(int a1, int a2, int a3, int a4, int a5, _DWORD *a6)
{
  int v6; // r7
  _DWORD *v7; // r0

  while ( 1 )
  {
    v7 = (_DWORD *)ExAllocatePoolWithTag(512, 4096);
    if ( !v7 )
      break;
    *v7 = *a6 + 1;
    *a6 = v7;
    a6 = v7;
    if ( *v7 >= *(_DWORD *)(v6 + 4) )
      JUMPOUT(0x428C28);
  }
  JUMPOUT(0x428C3E);
}

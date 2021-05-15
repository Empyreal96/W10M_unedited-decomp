// sub_554604 
 
void __fastcall sub_554604(unsigned int a1)
{
  int v1; // r4
  unsigned int v2; // r6

  if ( __PAIR64__(*(_DWORD *)(v1 + 28) & v2, *(_DWORD *)(v1 + 24) & a1) != *(_QWORD *)(v1 + 24) )
    JUMPOUT(0x4F5C8E);
  JUMPOUT(0x4F5CD4);
}

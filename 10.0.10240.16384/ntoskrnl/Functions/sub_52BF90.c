// sub_52BF90 
 
void __fastcall sub_52BF90(int a1, int a2)
{
  _QWORD *v2; // r4
  int v3; // r7

  if ( !v3 )
  {
    if ( *v2 <= *(_QWORD *)(a2 - 80) )
      JUMPOUT(0x470DDC);
    JUMPOUT(0x470DE4);
  }
  JUMPOUT(0x470DD8);
}

// sub_514C98 
 
void __fastcall sub_514C98(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v9; // r4
  int v10; // r0
  int v11; // r5

  if ( a9 < 2 )
  {
    v10 = PsReferencePrimaryToken(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
    a8 = 0;
    v11 = v10;
    SeQueryInformationToken(v10, 29, &a8);
    if ( a8 == 1 )
    {
      if ( v9 )
        ObfDereferenceObjectWithTag(v9);
    }
    else
    {
      ObfDereferenceObjectWithTag(v11);
    }
  }
  JUMPOUT(0x431F1A);
}

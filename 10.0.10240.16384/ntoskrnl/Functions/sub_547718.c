// sub_547718 
 
void __fastcall sub_547718(int a1, int a2, int a3)
{
  unsigned int v3; // r4
  int v4; // r5
  int v5; // r9
  int v6; // lr

  do
  {
    v3 = *(_DWORD *)v3;
    if ( (v3 & a3) != 0 )
      goto LABEL_5;
  }
  while ( v5 != (*(_DWORD *)(v3 + 4) & v6) );
  if ( v3 )
  {
    *(_DWORD *)(v4 + a1) = v3;
    JUMPOUT(0x4C4212);
  }
LABEL_5:
  JUMPOUT(0x4C420E);
}

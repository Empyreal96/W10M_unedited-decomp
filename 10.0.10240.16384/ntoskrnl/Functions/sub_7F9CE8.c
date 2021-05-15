// sub_7F9CE8 
 
void __fastcall sub_7F9CE8(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // r5
  int v6; // r6
  int v7; // r0
  unsigned __int16 *v8; // r4
  int v9; // r2
  int v10; // r3
  unsigned int v11; // r0

  v7 = IopSymlinkGetECP(*(_DWORD *)(v5 + 60), (int)&a5);
  if ( v7 < 0 )
    goto LABEL_6;
  v8 = (unsigned __int16 *)a5;
  v9 = *(_DWORD *)(a5 + 8);
  v10 = a5;
  while ( v9 )
  {
    v10 = v9;
    v9 = *(_DWORD *)(v9 + 8);
  }
  v11 = IopFindMatchingComponentsLengthR(v6 + 48, v10 + 12);
  v7 = IopSymlinkRememberJunction(v11, v6, v5, v8);
  if ( v7 < 0 )
LABEL_6:
    *(_DWORD *)(v5 + 24) = v7;
  JUMPOUT(0x728862);
}

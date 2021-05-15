// sub_54CB78 
 
void sub_54CB78()
{
  char v0; // zf
  int v1; // r5
  int v2; // r7

  if ( !v0 )
    JUMPOUT(0x4D6824);
  if ( ((*(unsigned __int8 *)((v1 >> 3) + *(_DWORD *)(v2 + 4)) >> (v1 & 7)) & 1) == 0 )
    JUMPOUT(0x4D6852);
  JUMPOUT(0x4D6874);
}

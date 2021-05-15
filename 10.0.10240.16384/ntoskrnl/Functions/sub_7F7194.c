// sub_7F7194 
 
void __fastcall sub_7F7194(int a1, int a2)
{
  int v2; // r6
  int v3; // r8
  _DWORD *v4; // r0

  v4 = (_DWORD *)ExpGetHandleExtraInfo(v2, a2);
  if ( v4 )
    *v4 = v3;
  JUMPOUT(0x71B618);
}

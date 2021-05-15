// sub_80E658 
 
void __fastcall sub_80E658(int a1)
{
  int v1; // r5
  _DWORD *v2; // r7

  if ( *(__int64 *)(v1 + 24) > 0xFFFFFF )
  {
    *v2 = 0xFFFFFF;
    v2[1] = a1;
  }
  JUMPOUT(0x797406);
}

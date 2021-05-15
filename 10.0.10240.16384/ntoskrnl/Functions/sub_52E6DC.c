// sub_52E6DC 
 
void __fastcall sub_52E6DC(int a1, int a2, _DWORD *a3)
{
  int v3; // r4
  _DWORD *v4; // r3

  if ( a3[1] == a2 )
  {
    v4 = *(_DWORD **)(v3 + 1040);
    if ( v4 )
      *(_DWORD *)(v3 + 1040) = *v4;
    if ( a3[4] )
    {
      if ( a3[6] )
        RtlFreeAnsiString(a3 + 5);
    }
  }
  JUMPOUT(0x47D0E8);
}

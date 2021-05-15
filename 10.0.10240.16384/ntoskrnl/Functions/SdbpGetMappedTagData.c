// SdbpGetMappedTagData 
 
int __fastcall SdbpGetMappedTagData(int a1, int a2)
{
  unsigned int v3; // r2
  int v5; // r3

  v3 = SdbpGetTagHeadSize() + a2;
  if ( v3 >= *(_DWORD *)(a1 + 12) )
    return sub_7CCB08();
  v5 = *(_DWORD *)(a1 + 4);
  if ( !(v5 + v3) )
    JUMPOUT(0x7CCB1C);
  return v5 + v3;
}

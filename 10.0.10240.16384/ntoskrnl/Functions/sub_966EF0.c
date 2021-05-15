// sub_966EF0 
 
void __fastcall sub_966EF0(int a1, int a2, _DWORD *a3)
{
  int v3; // r6
  int v4; // r3

  do
  {
    v4 = CmpPreloadedHivesCount + 1;
    __dmb(0xBu);
    CmpPreloadedHivesCount = v4;
    a3 = (_DWORD *)*a3;
  }
  while ( a3 != (_DWORD *)(*(_DWORD *)(v3 + 132) + 124) );
  JUMPOUT(0x94D5E4);
}

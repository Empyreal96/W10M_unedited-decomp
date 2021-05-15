// sub_80A488 
 
void __fastcall sub_80A488(int a1, int a2, int *a3)
{
  int v3; // r6
  int v4; // r8
  int v5; // r3

  if ( !v3 && *(_DWORD *)(v4 + 804) )
  {
    v5 = *a3;
    __dmb(0xBu);
    if ( (v5 & 8) != 0 )
      __debugbreak();
  }
  JUMPOUT(0x75FB56);
}

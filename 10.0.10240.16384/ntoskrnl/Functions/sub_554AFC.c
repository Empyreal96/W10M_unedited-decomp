// sub_554AFC 
 
void __fastcall sub_554AFC(int a1, int a2, void (__fastcall *a3)(_DWORD, _DWORD))
{
  int v3; // r5
  int v4; // r6
  _DWORD *v5; // r7

  if ( (*v5 & 0x80) != 0 )
    a3(*(_DWORD *)(v3 + 4), *(_DWORD *)(v4 + 76));
  JUMPOUT(0x4F6B26);
}

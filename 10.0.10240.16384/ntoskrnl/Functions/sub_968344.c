// sub_968344 
 
void __fastcall sub_968344(int a1, int a2, int a3, __int16 a4)
{
  int v4; // r4
  int v5; // r6
  int v6; // r0

  v6 = (*(int (__fastcall **)(_DWORD, _DWORD))(v4 + 12))((unsigned __int16)(a4 + 2), 0);
  if ( v6 )
  {
    memmove(v6, v5 + 76, *(unsigned __int16 *)(v5 + 72));
    JUMPOUT(0x94F210);
  }
  JUMPOUT(0x94F224);
}

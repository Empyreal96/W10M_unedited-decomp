// sub_51D30C 
 
void __fastcall sub_51D30C(int a1)
{
  __int64 v1; // r4
  unsigned int v2; // r6
  int v3; // r1

  v3 = *(_DWORD *)(a1 + 20);
  if ( !*(_DWORD *)(v3 + 56)
    || v2 > *(unsigned __int8 *)(v3 + 60) && *(_BYTE *)(v3 + 60)
    || ((*(_DWORD *)(v3 + 64) & 0x40) == 0 || v1)
    && (!(*(_DWORD *)(v3 + 76) & (unsigned int)v1 | *(_DWORD *)(v3 + 72) & HIDWORD(v1))
     || __PAIR64__(*(_DWORD *)(v3 + 84) & (unsigned int)v1, *(_DWORD *)(v3 + 80) & HIDWORD(v1)) != *(_QWORD *)(v3 + 80)) )
  {
    JUMPOUT(0x44A132);
  }
  JUMPOUT(0x44A11E);
}

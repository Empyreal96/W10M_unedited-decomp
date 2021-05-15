// MiGetPageFileSectionForReservation 
 
int __fastcall MiGetPageFileSectionForReservation(unsigned int a1, int a2, int a3)
{
  _DWORD *v6; // r0
  unsigned int v7; // r1
  unsigned int v8; // r2
  unsigned int v9; // r3
  int v11; // r0

  v6 = (_DWORD *)MiReferencePfBackedSection(a1);
  if ( v6 )
  {
    *(_DWORD *)a2 = *v6;
    v7 = (a1 & 0xFFFFF000) + 4092;
    *(_DWORD *)(a2 + 8) = a1 & 0xFFFFF000;
    *(_DWORD *)(a2 + 12) = v7;
    v8 = v6[1];
    if ( (a1 & 0xFFFFF000) < v8 )
      *(_DWORD *)(a2 + 8) = v8;
    v9 = v8 + 4 * v6[7] - 4;
    if ( v7 > v9 )
      *(_DWORD *)(a2 + 12) = v9;
    if ( !a3 )
    {
      *(_DWORD *)(a2 + 4) = 0;
      return 1;
    }
    v11 = MiLockProtoPoolPage(a1, (_BYTE *)(a2 + 16));
    *(_DWORD *)(a2 + 4) = v11;
    if ( v11 )
      return 1;
    MiReleasePageFileSectionInfo(a2);
  }
  return 0;
}

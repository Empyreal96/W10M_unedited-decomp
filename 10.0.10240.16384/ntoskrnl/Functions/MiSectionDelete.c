// MiSectionDelete 
 
int __fastcall MiSectionDelete(int a1)
{
  __int16 v1; // r10
  _DWORD *v3; // r4
  int v5; // r3
  unsigned int *v6; // r2
  unsigned int v7; // r1
  int v8; // r1

  v1 = *(_WORD *)(a1 + 34);
  v3 = (_DWORD *)MiSectionControlArea(a1);
  if ( *(_DWORD *)(a1 + 12) )
    return sub_802030();
  v5 = *(_DWORD *)(a1 + 20);
  if ( (v5 & 1) != 0 || (v5 & 2) != 0 )
    ObfDereferenceObject(v5 & 0xFFFFFFFC);
  if ( (*(_DWORD *)(a1 + 32) & 0x8000000) != 0 && (v3[7] & 0x20) == 0 && v3[8] )
  {
    __dmb(0xBu);
    v6 = v3 + 13;
    do
      v7 = __ldrex(v6);
    while ( __strex(v7 - 1, v6) );
  }
  if ( (v3[7] & 0x4000000) != 0 )
  {
    v8 = (*(_DWORD *)(a1 + 36) >> 12) & 0x7FFFF;
    if ( v8 == 0x7FFFF )
      v8 = -1;
    MiDereferencePerSessionProtos(v3, v8);
  }
  if ( (dword_682604 & 0x400001) != 0 && !v3[8] )
    MiLogSectionObjectEvent(a1, 0);
  return MiDereferenceControlAreaBySection(v3, v1 & 1);
}

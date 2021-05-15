// MiRotateHeadWsle 
 
int __fastcall MiRotateHeadWsle(_DWORD *a1, int a2)
{
  int v2; // r5
  int v3; // r4
  _DWORD *v4; // r0

  v2 = a1[2 * a2 + 31];
  if ( v2 != 0xFFFFF )
  {
    v3 = a1[63];
    v4 = MiRemoveEntryWsle(a1, v3 + 16 * v2);
    MiInsertWsle(v4, (_DWORD *)(v3 + 16 * v2), 0);
  }
  return v2;
}

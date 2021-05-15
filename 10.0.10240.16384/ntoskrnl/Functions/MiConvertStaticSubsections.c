// MiConvertStaticSubsections 
 
int __fastcall MiConvertStaticSubsections(int a1, int a2)
{
  int v2; // r5
  int v3; // r4
  __int16 v4; // r2
  __int16 v6; // r3
  int v7; // r2

  v2 = 0;
  v3 = a1 + 80;
  while ( 1 )
  {
    v4 = *(_WORD *)(v3 + 18);
    if ( (v4 & 8) != 0 || (v4 & 1) == 0 )
      goto LABEL_3;
    if ( *(_DWORD *)(v3 + 32) )
      return sub_520CAC();
    v6 = v4 & 0xFFFE;
    v7 = *(_DWORD *)(v3 + 28);
    *(_WORD *)(v3 + 18) = v6;
    *(_DWORD *)(v3 + 60) = 1;
    v2 += MiRemoveViewsFromSection(v3, a2, v7, 0);
LABEL_3:
    v3 = *(_DWORD *)(v3 + 8);
    if ( !v3 )
      return v2;
  }
}

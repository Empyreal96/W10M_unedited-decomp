// LdrpGetImageSize 
 
int __fastcall LdrpGetImageSize(int a1, _DWORD *a2)
{
  int v4; // r5
  int v5; // r4
  int v6; // r0
  int v7; // r0

  v4 = 0;
  v5 = 0;
  v6 = RtlImageNtHeader(a1 & 0xFFFFFFFC);
  if ( !v6 )
  {
    v4 = -1073741701;
    goto LABEL_5;
  }
  if ( (a1 & 1) != 0 )
  {
    v7 = LdrpKrnGetDataTableEntry(a1);
    if ( v7 )
      v5 = *(_DWORD *)(v7 + 32);
    goto LABEL_5;
  }
  if ( *(_WORD *)(v6 + 24) == 267 )
  {
    v5 = *(_DWORD *)(v6 + 80);
LABEL_5:
    *a2 = v5;
    return v4;
  }
  return sub_54DC50();
}

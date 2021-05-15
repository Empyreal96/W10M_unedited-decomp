// BiTranslateBootEntryId 
 
int __fastcall BiTranslateBootEntryId(int a1, int a2, _DWORD *a3, _DWORD *a4)
{
  int v5; // r5
  int v6; // r1
  int v7; // r2
  int v8; // r3
  int v10[4]; // [sp+0h] [bp-10h] BYREF

  v10[0] = (int)a4;
  v5 = BiLookupObjectByBootEntry(a1, a2, v10);
  if ( v5 >= 0 )
  {
    if ( (*(_DWORD *)(v10[0] + 32) & 4) != 0 )
    {
      v6 = *(_DWORD *)(v10[0] + 12);
      v7 = *(_DWORD *)(v10[0] + 16);
      v8 = *(_DWORD *)(v10[0] + 20);
      *a3 = *(_DWORD *)(v10[0] + 8);
      a3[1] = v6;
      a3[2] = v7;
      a3[3] = v8;
    }
    else
    {
      v5 = -1073741275;
    }
  }
  return v5;
}

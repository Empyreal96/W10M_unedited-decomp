// BiExportBcdObjects 
 
int __fastcall BiExportBcdObjects(int a1, _DWORD *a2)
{
  _DWORD *v2; // r4
  int v4; // r5
  int v5; // r9
  unsigned int v6; // r3
  int v8; // r6
  int v9; // r7

  v2 = (_DWORD *)*a2;
  v4 = 0;
  v5 = a1;
  if ( (_DWORD *)*a2 == a2 )
    return v4;
  while ( 1 )
  {
    v6 = v2[8];
    if ( (v6 & 5) != 0 )
      break;
LABEL_3:
    v2 = (_DWORD *)*v2;
    if ( v2 == a2 )
      return v4;
  }
  if ( ((v6 >> 2) & 1) != 0 )
  {
    if ( (v6 & 1) != 0 )
    {
      a1 = BiUpdateEfiEntry(v5, v2);
      if ( a1 < 0 )
      {
        if ( (v2[8] & 8) == 0 )
          JUMPOUT(0x812CF4);
        v4 = -2143748093;
      }
    }
    else
    {
      v8 = 0;
      a1 = BiIsPortableWorkspaceBoot(a1, 1);
      v9 = a1;
      if ( (v2[8] & 8) != 0 || !a1 )
      {
        a1 = BiCreateEfiEntry(v5, v2);
        v8 = a1;
      }
      if ( (v2[8] & 8) == 0 && !v9 )
      {
        if ( v8 < 0 )
          v8 = 0;
        else
          a1 = BiAddBootEntryToEfiBootManagerDisplayOrder(v5, v2);
      }
      if ( v8 < 0 )
        v4 = -2143748095;
    }
    goto LABEL_3;
  }
  return sub_812CE4(a1, 1);
}

// sub_7C49AC 
 
void __fastcall sub_7C49AC(char *a1, int a2, _DWORD *a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13)
{
  int v13; // r4
  unsigned __int8 *v14; // r6
  char *v15; // r7
  int v16; // r8
  int v17; // lr
  int v19; // r3
  int v20; // t1
  int v21; // r5

  v15 = a1;
  v16 = NlsMbAnsiCodePageTables;
  if ( v13 )
  {
    v17 = NlsAnsiToUnicodeData;
    do
    {
      if ( !a13 )
        break;
      v20 = *v14;
      v14 += 2;
      v19 = v20;
      --v13;
      --a13;
      v21 = (unsigned __int16)NlsLeadByteInfoTable[v20];
      if ( NlsLeadByteInfoTable[v20] )
      {
        if ( !a13 )
        {
          *(_WORD *)a1 = 0;
          a1 += 2;
          break;
        }
        *(_WORD *)a1 = *(_WORD *)(v16 + 2 * (*(v14 - 1) + v21));
        a1 += 2;
        --a13;
      }
      else
      {
        *(_WORD *)a1 = *(_WORD *)(v17 + 2 * v19);
        a1 += 2;
        --v14;
      }
    }
    while ( v13 );
  }
  if ( a3 )
  {
    *a3 = a1 - v15;
    JUMPOUT(0x6BE7C4);
  }
  JUMPOUT(0x6BE7C6);
}

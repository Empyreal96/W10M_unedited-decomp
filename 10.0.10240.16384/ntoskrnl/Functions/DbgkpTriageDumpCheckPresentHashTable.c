// DbgkpTriageDumpCheckPresentHashTable 
 
int __fastcall DbgkpTriageDumpCheckPresentHashTable(int a1, unsigned int a2, int a3, unsigned int *a4)
{
  unsigned int v5; // r5
  int v6; // r6
  int v7; // r2
  int result; // r0

  if ( a4 )
    *a4 = -1;
  v5 = (a2 >> 4)
     - 3571
     * ((unsigned int)(((631435965 * (unsigned __int64)(a2 >> 4)) >> 32)
                     + ((unsigned int)((a2 >> 4) - ((631435965 * (unsigned __int64)(a2 >> 4)) >> 32)) >> 1)) >> 11);
  v6 = *(_DWORD *)(a1 + 24);
  if ( *(_DWORD *)(v6 + 4 * v5) )
  {
    while ( 1 )
    {
      v7 = *(_DWORD *)(v6 + 4 * v5);
      if ( *(_QWORD *)v7 == a2 && (!a3 || *(_DWORD *)(v7 + 12) == a3) )
        break;
      if ( ++v5 >= 0xDF3 )
        v5 = 0;
      if ( !*(_DWORD *)(v6 + 4 * v5) )
        goto LABEL_10;
    }
    if ( a4 )
      *a4 = v5;
    result = 1;
  }
  else
  {
LABEL_10:
    if ( a4 )
      *a4 = v5;
    result = 0;
  }
  return result;
}

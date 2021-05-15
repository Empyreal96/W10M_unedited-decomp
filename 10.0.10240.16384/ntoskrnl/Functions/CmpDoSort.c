// CmpDoSort 
 
int __fastcall CmpDoSort(int a1, unsigned __int16 *a2)
{
  unsigned int v4; // r9
  __int16 v5; // r10
  unsigned __int16 *v6; // r4
  unsigned __int16 *v7; // r2
  int v9; // r7
  int v10; // r5
  int v11; // r3
  unsigned __int16 *v13; // [sp+0h] [bp-30h]
  unsigned __int16 v14[2]; // [sp+8h] [bp-28h] BYREF
  unsigned __int16 *v15; // [sp+Ch] [bp-24h]

  if ( !CmpSortByTag() )
    return 0;
  v4 = *((_DWORD *)a2 + 1);
  v5 = 0;
  v6 = (unsigned __int16 *)(v4 + 2 * (*a2 >> 1) - 2);
  if ( (unsigned int)v6 <= v4 )
    return 1;
  v7 = (unsigned __int16 *)*((_DWORD *)a2 + 1);
  v13 = v7;
  while ( 1 )
  {
    do
    {
      if ( !*v6-- )
        v5 = (_WORD)v6 + 2;
    }
    while ( v6 != v7 && *(v6 - 1) );
    v9 = *(_DWORD *)(a1 + 4);
    v14[0] = v5 - (_WORD)v6;
    v14[1] = v5 - (_WORD)v6;
    v15 = v6;
    if ( v9 != a1 )
      break;
LABEL_13:
    if ( (unsigned int)--v6 <= v4 )
      return 1;
  }
  while ( 1 )
  {
    if ( v9 == a1 )
    {
LABEL_12:
      v7 = v13;
      goto LABEL_13;
    }
    v10 = v9;
    v11 = *(_DWORD *)(v9 + 48);
    v9 = *(_DWORD *)(v9 + 4);
    if ( v11 )
    {
      if ( RtlEqualUnicodeString(v14, (unsigned __int16 *)(v10 + 44), 1) )
        return sub_9684A8();
    }
    if ( v9 == a1 )
      goto LABEL_12;
  }
}

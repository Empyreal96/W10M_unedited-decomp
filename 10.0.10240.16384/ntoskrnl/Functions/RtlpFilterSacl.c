// RtlpFilterSacl 
 
int __fastcall RtlpFilterSacl(int a1, int a2, unsigned int *a3, char a4)
{
  int v4; // lr
  int v5; // r4
  int v6; // r5
  unsigned int *v7; // r8
  int v8; // r10
  int result; // r0
  unsigned int v12; // r2
  unsigned int v13; // r5
  int v14; // r2
  int v15; // r7
  int i; // r4
  __int16 v17; // r1

  v4 = *(unsigned __int16 *)(a1 + 4);
  v5 = 8;
  v6 = a1 + 8;
  v7 = a3;
  v8 = a2;
  result = 8;
  if ( v4 )
  {
    do
    {
      if ( *(_BYTE *)v6 != 17 )
        return sub_8056DC(8, 64, 32);
      if ( (a4 & 0x10) != 0 )
        v5 += *(unsigned __int16 *)(v6 + 2);
      v6 += *(unsigned __int16 *)(v6 + 2);
      --v4;
    }
    while ( v4 );
    v7 = a3;
    v8 = a2;
  }
  v12 = (v5 + 3) & 0xFFFFFFFC;
  if ( *v7 >= v12 )
  {
    v13 = 0;
    *(_DWORD *)v8 = *(_DWORD *)a1;
    v14 = *(_DWORD *)(a1 + 4);
    *(_WORD *)(v8 + 2) = 8;
    v15 = v8 + 8;
    *(_DWORD *)(v8 + 4) = v14;
    *(_WORD *)(v8 + 4) = 0;
    for ( i = a1 + 8; v13 < *(unsigned __int16 *)(a1 + 4); i += *(unsigned __int16 *)(i + 2) )
    {
      if ( *(_BYTE *)i == 17 )
      {
        if ( (a4 & 0x10) != 0 )
        {
LABEL_14:
          memmove(v15, i, *(unsigned __int16 *)(i + 2));
          v17 = *(_WORD *)(v8 + 2);
          ++*(_WORD *)(v8 + 4);
          *(_WORD *)(v8 + 2) = *(_WORD *)(i + 2) + v17;
          v15 += *(unsigned __int16 *)(i + 2);
          result = 8;
        }
      }
      else
      {
        switch ( *(_BYTE *)i )
        {
          case 0x12:
            if ( (a4 & 0x20) != 0 )
              goto LABEL_14;
            break;
          case 0x13:
            if ( (a4 & 0x40) != 0 )
              goto LABEL_14;
            break;
          case 0x14:
            if ( (a4 & 0x80) != 0 )
              goto LABEL_14;
            break;
          default:
            if ( (a4 & 8) != 0 )
              goto LABEL_14;
            break;
        }
      }
      ++v13;
    }
  }
  else
  {
    *v7 = v12;
  }
  return result;
}

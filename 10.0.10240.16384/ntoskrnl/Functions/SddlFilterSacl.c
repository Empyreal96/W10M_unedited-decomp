// SddlFilterSacl 
 
int __fastcall SddlFilterSacl(int a1, int a2, unsigned int *a3, char a4)
{
  unsigned int *v4; // lr
  int v5; // r2
  int v6; // r5
  int v7; // r9
  int v9; // r7
  int result; // r0
  bool v12; // zf
  unsigned int v13; // r2
  unsigned int v14; // r5
  int v15; // r7
  int v16; // r3
  int v17; // r4
  bool v18; // zf

  v4 = a3;
  v5 = *(unsigned __int16 *)(a1 + 4);
  v6 = 8;
  v7 = a2;
  v9 = a1 + 8;
  result = 64;
  if ( v5 )
  {
    do
    {
      switch ( *(_BYTE *)v9 )
      {
        case 0x11:
          v12 = (a4 & 0x10) == 0;
          break;
        case 0x12:
          v12 = (a4 & 0x20) == 0;
          break;
        case 0x13:
          v12 = (a4 & 0x40) == 0;
          break;
        case 0x14:
          v12 = (a4 & 0x80) == 0;
          break;
        default:
          v12 = (a4 & 8) == 0;
          break;
      }
      if ( !v12 )
        v6 += *(unsigned __int16 *)(v9 + 2);
      v9 += *(unsigned __int16 *)(v9 + 2);
      --v5;
    }
    while ( v5 );
    v4 = a3;
    v7 = a2;
  }
  v13 = (v6 + 3) & 0xFFFFFFFC;
  if ( *v4 >= v13 )
  {
    v14 = 0;
    v15 = v7 + 8;
    *(_DWORD *)v7 = *(_DWORD *)a1;
    v16 = *(_DWORD *)(a1 + 4);
    *(_WORD *)(v7 + 2) = 8;
    v17 = a1 + 8;
    *(_DWORD *)(v7 + 4) = v16;
    for ( *(_WORD *)(v7 + 4) = 0; v14 < *(unsigned __int16 *)(a1 + 4); v17 += *(unsigned __int16 *)(v17 + 2) )
    {
      switch ( *(_BYTE *)v17 )
      {
        case 0x11:
          v18 = (a4 & 0x10) == 0;
          break;
        case 0x12:
          v18 = (a4 & 0x20) == 0;
          break;
        case 0x13:
          v18 = (a4 & 0x40) == 0;
          break;
        case 0x14:
          v18 = (a4 & 0x80) == 0;
          break;
        default:
          v18 = (a4 & 8) == 0;
          break;
      }
      if ( !v18 )
      {
        memmove(v15, v17, *(unsigned __int16 *)(v17 + 2));
        ++*(_WORD *)(v7 + 4);
        *(_WORD *)(v7 + 2) += *(_WORD *)(v17 + 2);
        v15 += *(unsigned __int16 *)(v17 + 2);
        result = 64;
      }
      ++v14;
    }
  }
  else
  {
    *v4 = v13;
  }
  return result;
}

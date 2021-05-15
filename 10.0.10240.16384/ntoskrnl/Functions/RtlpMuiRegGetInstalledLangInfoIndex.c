// RtlpMuiRegGetInstalledLangInfoIndex 
 
int __fastcall RtlpMuiRegGetInstalledLangInfoIndex(int a1, int a2, __int16 a3, _WORD *a4)
{
  int v4; // r5
  int v5; // r1
  int v6; // r2
  int v7; // lr
  int v8; // r0
  _WORD *v9; // r6
  int v11; // r1
  int v12; // lr
  int v13; // r0
  _WORD *v14; // r6

  v4 = a3;
  if ( a1 && a2 )
  {
    switch ( a2 )
    {
      case 1:
        if ( a3 )
        {
          v5 = *(unsigned __int16 *)(a1 + 6);
          LOWORD(v6) = 0;
          if ( *(_WORD *)(a1 + 6) )
          {
            v7 = *(_DWORD *)(a1 + 12);
            v8 = 0;
            while ( 1 )
            {
              v9 = (_WORD *)(v7 + 28 * v8);
              if ( (unsigned __int16)v9[2] == v4 && (*v9 & 0x1020) == 32 )
                break;
              v6 = (__int16)(v8 + 1);
              v8 = v6;
              if ( v6 >= v5 )
                return -1073741823;
            }
LABEL_11:
            if ( a4 )
              *a4 = v6;
            return 0;
          }
          return -1073741823;
        }
        break;
      case 3:
        if ( a3 >= 0 )
        {
          v11 = *(unsigned __int16 *)(a1 + 6);
          LOWORD(v6) = 0;
          if ( *(_WORD *)(a1 + 6) )
          {
            v12 = *(_DWORD *)(a1 + 12);
            v13 = 0;
            while ( 1 )
            {
              v14 = (_WORD *)(v12 + 28 * v13);
              if ( (__int16)v14[3] == v4 && (*v14 & 0x1020) == 32 )
                break;
              v6 = (__int16)(v13 + 1);
              v13 = v6;
              if ( v6 >= v11 )
                return -1073741823;
            }
            goto LABEL_11;
          }
          return -1073741823;
        }
        break;
      case 2:
        if ( a3 >= 0 && a3 < (int)*(unsigned __int16 *)(a1 + 6) )
        {
          if ( (*(_WORD *)(*(_DWORD *)(a1 + 12) + 28 * a3) & 0x1020) == 32 )
          {
            if ( a4 )
              *a4 = a3;
            return 0;
          }
          return -1073741823;
        }
        break;
      default:
        return -1073741823;
    }
  }
  return -1073741811;
}

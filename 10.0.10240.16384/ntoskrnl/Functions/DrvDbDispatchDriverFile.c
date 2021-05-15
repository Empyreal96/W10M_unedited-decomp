// DrvDbDispatchDriverFile 
 
int __fastcall DrvDbDispatchDriverFile(int a1, _WORD *a2, int a3, int a4, int a5)
{
  int result; // r0
  int v8; // r0
  bool v9; // zf
  int **v11; // [sp+10h] [bp-10h] BYREF

  v11 = 0;
  result = PnpCtxGetObjectContext(a1, a3, &v11);
  if ( result >= 0 )
  {
    v8 = (int)v11[2];
    if ( (v8 & 0x10000000) != 0 )
      goto LABEL_19;
    if ( !v8 )
      return -1073740697;
    if ( a4 == 2 )
    {
      if ( *(_BYTE *)(a5 + 4) )
        goto LABEL_11;
    }
    else
    {
      if ( a4 <= 2 )
        goto LABEL_19;
      if ( a4 <= 4 )
      {
LABEL_11:
        v9 = (v8 & 0x40000000) == 0;
        goto LABEL_14;
      }
      if ( a4 > 6 && a4 != 8 )
      {
        if ( a4 == 9 )
          goto LABEL_11;
LABEL_19:
        switch ( a4 )
        {
          case 1:
            result = DrvDbValidateDriverInfFileName(v8, a2);
            break;
          case 2:
            result = DrvDbOpenObjectRegKey(
                       v11,
                       0,
                       4,
                       (int)a2,
                       *(_DWORD *)a5,
                       *(_BYTE *)(a5 + 4),
                       *(_DWORD *)(a5 + 8),
                       (_DWORD *)(a5 + 12));
            break;
          case 3:
            result = DrvDbCreateDriverFile(v11, (int)a2, *(_DWORD *)a5, a5 + 4, (bool *)(a5 + 8));
            break;
          case 4:
            result = DrvDbDeleteObjectRegKey((int)v11, 4, a2, 0);
            break;
          case 5:
            result = DrvDbGetObjectList(
                       v11,
                       4,
                       *(_DWORD *)a5,
                       *(_DWORD *)(a5 + 4),
                       *(_DWORD *)(a5 + 8),
                       *(_DWORD *)(a5 + 12),
                       *(unsigned int **)(a5 + 16),
                       0);
            break;
          case 6:
            result = DrvDbGetDriverFileMappedPropertyKeys(
                       v11,
                       (int)a2,
                       *(_DWORD *)a5,
                       *(_DWORD *)(a5 + 12),
                       *(_DWORD *)(a5 + 16),
                       *(_DWORD **)(a5 + 20));
            break;
          case 8:
            result = DrvDbGetDriverFileMappedProperty(
                       v11,
                       (int)a2,
                       *(_DWORD *)a5,
                       *(_DWORD *)(a5 + 8),
                       *(_DWORD **)(a5 + 12),
                       *(int **)(a5 + 16),
                       *(_DWORD *)(a5 + 20),
                       *(_DWORD **)(a5 + 24));
            break;
          case 9:
            result = DrvDbSetDriverFileMappedProperty(
                       v11,
                       (int)a2,
                       *(_DWORD *)a5,
                       *(_DWORD *)(a5 + 8),
                       *(int (**)[5])(a5 + 12));
            break;
          default:
            result = -1073741811;
            break;
        }
        return result;
      }
    }
    v9 = v8 >= 0;
LABEL_14:
    if ( v9 )
      return -1073741790;
    goto LABEL_19;
  }
  return result;
}

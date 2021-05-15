// ObpLockHandleDataBaseEntry 
 
int __fastcall ObpLockHandleDataBaseEntry(int a1, int *a2, unsigned int *a3)
{
  int **v5; // r4
  int *v6; // r3
  int *v7; // r3
  int v9; // lr
  unsigned int v10; // r9
  int v11; // r7
  int **v12; // r2
  int *v13; // r3
  int *v14; // t1
  int v15; // r3
  unsigned int v16; // r3
  int v17; // r0
  int v18; // r3
  int v19; // r2

  v5 = (int **)(a1 - ObpInfoMaskToOffset[*(_BYTE *)(a1 + 14) & 7]);
  if ( (*(_BYTE *)(a1 + 15) & 0x40) != 0 )
  {
    v6 = *v5;
    if ( !*v5 )
    {
      *((_BYTE *)v5 + 7) = 1;
      v7 = v5[1];
      *v5 = a2;
      *a3 = 1;
      v5[1] = (int *)((unsigned int)v7 & 0xFF000000);
      return 0;
    }
    if ( v6 == a2 && *((unsigned __int8 *)v5 + 7) != 255 )
    {
      v19 = (unsigned __int8)(*((_BYTE *)v5 + 7) + 1);
      *((_BYTE *)v5 + 7) = v19;
      *a3 = ((unsigned int)v5[1] & 0xFFFFFF) + v19;
      return 0;
    }
    if ( v6 == a2 )
      return sub_7DDA08();
    v17 = ObpInsertHandleCount();
    if ( v17 )
    {
      v18 = *(_DWORD *)(v17 + 4);
      *(_DWORD *)v17 = a2;
      *(_DWORD *)(v17 + 4) = v18 & 0xFF000000;
      *(_BYTE *)(v17 + 7) = 1;
      *a3 = 1;
      return 0;
    }
  }
  else
  {
    v9 = 0;
    v10 = 0;
    v11 = **v5;
    v12 = (int **)(*v5 + 1);
    if ( !v11 )
      goto LABEL_28;
    do
    {
      v14 = *v12;
      v12 += 2;
      v13 = v14;
      if ( v14 == a2 )
      {
        if ( *((unsigned __int8 *)v5 + 7) != 255 )
        {
          ++*((_BYTE *)v12 - 1);
          v16 = *((unsigned __int8 *)v5 + 7) + ((unsigned int)v5[1] & 0xFFFFFF) + v10;
          goto LABEL_14;
        }
        v9 = 0;
        v10 += ((unsigned int)v5[1] & 0xFFFFFF) + 255;
      }
      else if ( !v13 )
      {
        v9 = (int)(v12 - 2);
      }
      --v11;
    }
    while ( v11 );
    if ( v9 )
      goto LABEL_11;
    if ( v10 < 0xFFFF01 )
    {
LABEL_28:
      v9 = ObpInsertHandleCount();
      if ( v9 )
      {
LABEL_11:
        v15 = *(_DWORD *)(v9 + 4);
        *(_DWORD *)v9 = a2;
        *(_DWORD *)(v9 + 4) = v15 & 0xFF000000;
        *(_BYTE *)(v9 + 7) = 1;
        v16 = v10 + 1;
LABEL_14:
        *a3 = v16;
        return 0;
      }
    }
  }
  return -1073741670;
}

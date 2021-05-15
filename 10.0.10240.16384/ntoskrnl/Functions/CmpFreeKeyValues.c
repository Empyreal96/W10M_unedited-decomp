// CmpFreeKeyValues 
 
int __fastcall CmpFreeKeyValues(int a1, int a2, int a3)
{
  int v6; // r2
  unsigned int *v7; // r7
  unsigned int v8; // r3
  int v9; // r6
  unsigned int v10; // t1
  int v11; // r3
  int v12[6]; // [sp+0h] [bp-18h] BYREF

  v12[0] = -1;
  if ( !CmpMarkKeyValuesDirty(a1) )
    return 0;
  if ( (*(_WORD *)(a3 + 2) & 2) == 0 )
  {
    if ( *(_DWORD *)(a3 + 36) )
    {
      v7 = (unsigned int *)(*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, *(_DWORD *)(a3 + 40), v12);
      if ( !v7 )
        return 0;
      v8 = *(_DWORD *)(a3 + 36);
      v9 = 0;
      if ( v8 )
      {
        while ( 1 )
        {
          v10 = *v7++;
          if ( !CmpFreeValue(a1, v10, v6, v8) )
            break;
          v8 = *(_DWORD *)(a3 + 36);
          if ( ++v9 >= v8 )
            goto LABEL_9;
        }
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, v12);
        return 0;
      }
LABEL_9:
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, v12);
      HvFreeCell(a1, *(_DWORD *)(a3 + 40));
    }
    v11 = *(unsigned __int16 *)(a3 + 74);
    *(_DWORD *)(a3 + 36) = 0;
    *(_DWORD *)(a3 + 40) = -1;
    if ( v11 )
    {
      HvFreeCell(a1, *(_DWORD *)(a3 + 48));
      *(_DWORD *)(a3 + 48) = -1;
      *(_WORD *)(a3 + 74) = 0;
    }
  }
  return 1;
}

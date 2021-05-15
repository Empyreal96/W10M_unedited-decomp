// MiStoreCheckCandidatePage 
 
int __fastcall MiStoreCheckCandidatePage(int a1, int a2, int a3, unsigned int *a4, _DWORD *a5)
{
  unsigned int *v6; // r8
  int *v7; // r9
  int v8; // r10
  int v9; // r5
  unsigned int v10; // r6
  unsigned int v11; // r1
  int v12; // r3
  unsigned int v13; // r5
  int v14; // r3
  unsigned int *v15; // r0
  int result; // r0
  unsigned int *v17; // r2
  unsigned int v18; // r0
  int v19; // r3
  int v20; // r1
  int *v22; // [sp+8h] [bp-30h]

  v6 = a4;
  v7 = (int *)a3;
  v8 = a2 & 0xFFFFFFF | (dword_63F99C << 28);
  v22 = (int *)a3;
  if ( (*(_DWORD *)(a1 + 20) & 0x8000000) != 0 )
  {
    v9 = 3;
    v10 = *(_DWORD *)(a1 + 4) | 0x80000000;
  }
  else
  {
    v11 = *(_DWORD *)(a1 + 4) | 0x80000000;
    if ( v11 >= dword_63389C
      && ((a3 = ((unsigned int)dword_63389C >> 20) & 0xFFC,
           v12 = *((unsigned __int8 *)&MiState[2423] + ((int)(((v11 >> 20) & 0xFFC) - a3) >> 2)),
           v12 == 5)
       || v12 == 13) )
    {
      v9 = -1070596096;
      v10 = v11 - 352;
    }
    else
    {
      v13 = v11 << 10;
      if ( v11 << 10 >= dword_63389C
        && ((a3 = ((unsigned int)dword_63389C >> 20) & 0xFFC,
             v14 = *((unsigned __int8 *)&MiState[2423] + ((int)(((v13 >> 20) & 0xFFC) - a3) >> 2)),
             v14 == 1)
         || v14 == 11)
        || (v14 = MmHighestUserAddress, v13 <= MmHighestUserAddress)
        || v13 >= 0xC0000000 && (v14 = dword_633894, v13 <= dword_633894) )
      {
        v15 = (unsigned int *)MiGetTopLevelPfn(a1, 0, a3, v14);
        if ( v15 == (unsigned int *)a1 )
          return -1073741253;
        v10 = *v15;
        __dmb(0xBu);
        v17 = v15 + 3;
        do
          v18 = __ldrex(v17);
        while ( __strex(v18 & 0x7FFFFFFF, v17) );
        if ( v13 >= dword_63389C
          && ((v19 = *((unsigned __int8 *)&MiState[2423]
                     + ((int)(((v13 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
               v19 == 1)
           || v19 == 11) )
        {
          v9 = v13 & 0xFFFFFFFC | 1;
        }
        else
        {
          if ( v10 == PsInitialSystemProcess )
            return -1073741401;
          v9 = v13 & 0xFFFFFFFC;
        }
      }
      else
      {
        v9 = (v11 << 10) | 2;
        v10 = 0;
      }
      v7 = v22;
    }
    v6 = a4;
  }
  v20 = *(_BYTE *)(a1 + 19) & 7;
  if ( (*(_BYTE *)(a1 + 19) & 8) != 0 )
    v20 = 5;
  *a5 = SmUpdateStoreContext(*a5, v20, (*(_BYTE *)(a1 + 18) & 0xC0) != 64);
  result = 0;
  *v7 = v8;
  *v6 = v10;
  v6[1] = v9;
  return result;
}

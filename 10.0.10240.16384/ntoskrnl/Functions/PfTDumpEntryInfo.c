// PfTDumpEntryInfo 
 
_DWORD *__fastcall PfTDumpEntryInfo(int a1, int a2, _WORD *a3)
{
  _DWORD *v3; // lr
  int v5; // r5
  int v7; // r2
  int v8; // r1
  int v9; // r6
  __int64 v10; // kr00_8
  _DWORD *v11; // r5
  int v12; // r1
  int v13; // r2
  int v14; // r3

  v3 = *(_DWORD **)(a1 + 8);
  v5 = *(_DWORD *)(a2 + 16);
  v7 = (unsigned __int16)(*(_WORD *)a1 - *(_WORD *)(a2 + 20));
  v8 = *(unsigned __int16 *)(v5 + 2 * v7);
  if ( v8 == 0xFFFF )
  {
    v9 = *(unsigned __int16 *)(a2 + 48);
    *(_WORD *)(a2 + 48) = v9 + 1;
    *(_WORD *)(v5 + 2 * v7) = v9;
    v10 = *(_QWORD *)(a2 + 36);
    v11 = (_DWORD *)(v10 + 16 * v9);
    if ( (unsigned int)(v11 + 4) <= HIDWORD(v10) )
    {
      v12 = v3[1];
      v13 = v3[2];
      v14 = v3[3];
      *v11 = *v3;
      v11[1] = v12;
      v11[2] = v13;
      v11[3] = v14;
      ++*(_WORD *)(*(_DWORD *)(a2 + 28) + 12);
    }
    else
    {
      v11 = (_DWORD *)(HIDWORD(v10) - 16);
      --*(_WORD *)(a2 + 48);
    }
  }
  else
  {
    LOWORD(v9) = *(_WORD *)(v5 + 2 * v7);
    v11 = (_DWORD *)(*(_DWORD *)(a2 + 36) + 16 * v8);
  }
  *a3 = v9;
  return v11;
}

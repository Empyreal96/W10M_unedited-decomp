// WdipSemUpdateInflightScenarioTable 
 
int __fastcall WdipSemUpdateInflightScenarioTable(_DWORD *a1, __int16 a2, unsigned int *a3, int a4)
{
  int v4; // r4
  unsigned int v9; // r0
  _BYTE *v10; // r5
  _BYTE *v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3

  v4 = 0;
  if ( !a1 || !a3 || !a4 )
    return -1073741811;
  v9 = WdipSemQueryInflightScenarioTable((unsigned int)a1, a2, a3);
  v10 = (_BYTE *)v9;
  if ( v9 )
  {
    ++*(_DWORD *)(v9 + 20);
  }
  else
  {
    if ( a3[125] >= 0x7D )
      return -1073741823;
    v11 = (_BYTE *)WdipSemFastAllocate(5, 24);
    v10 = v11;
    if ( !v11 )
      return -1073741670;
    memset(v11, 0, 24);
    v12 = a1[1];
    v13 = a1[2];
    v14 = a1[3];
    *(_DWORD *)v10 = *a1;
    *((_DWORD *)v10 + 1) = v12;
    *((_DWORD *)v10 + 2) = v13;
    *((_DWORD *)v10 + 3) = v14;
    *((_WORD *)v10 + 8) = a2;
    *((_DWORD *)v10 + 5) = 1;
    a3[a3[125]++] = (unsigned int)v10;
  }
  if ( !*(_DWORD *)a4 || *((_DWORD *)v10 + 5) > *(_DWORD *)(*(_DWORD *)a4 + 20) )
    *(_DWORD *)a4 = v10;
  return v4;
}

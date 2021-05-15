// RtlInitCodePageTable 
 
unsigned __int16 *__fastcall RtlInitCodePageTable(unsigned __int16 *result, int a2)
{
  int v2; // r2
  unsigned __int16 *v3; // r4
  int v4; // r5
  _WORD *v5; // r2

  v2 = *result;
  v3 = &result[v2];
  v4 = (unsigned __int16)(*v3 + v2);
  *(_WORD *)a2 = result[1];
  *(_WORD *)(a2 + 2) = result[2];
  *(_WORD *)(a2 + 4) = result[3];
  *(_WORD *)(a2 + 6) = result[4];
  *(_WORD *)(a2 + 8) = result[5];
  *(_WORD *)(a2 + 10) = result[6];
  *(_DWORD *)(a2 + 14) = *(_DWORD *)(result + 7);
  *(_DWORD *)(a2 + 18) = *(_DWORD *)(result + 9);
  *(_DWORD *)(a2 + 22) = *(_DWORD *)(result + 11);
  *(_DWORD *)(a2 + 28) = v3 + 1;
  if ( v3[257] )
    v5 = v3 + 514;
  else
    v5 = v3 + 258;
  *(_DWORD *)(a2 + 36) = v5;
  if ( *v5 )
    return (unsigned __int16 *)sub_81AB04();
  *(_WORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 40) = 0;
  *(_DWORD *)(a2 + 32) = &result[v4 + 1];
  return result;
}

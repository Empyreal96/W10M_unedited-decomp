// ObQueryTypeName 
 
int __fastcall ObQueryTypeName(int a1, int a2, unsigned int a3, _DWORD *a4)
{
  int v4; // r8
  int v5; // r1
  int v6; // r5
  int v8; // r3
  unsigned int v9; // r2
  int v10; // r4

  v4 = a2;
  v5 = ObTypeIndexTable[*(unsigned __int8 *)(a1 - 12) ^ (unsigned __int8)((unsigned __int16)(a1 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie];
  v6 = *(unsigned __int16 *)(v5 + 8);
  *a4 = v6 + 10;
  if ( a3 < v6 + 10 )
    return -1073741820;
  v8 = v6 + 10 + v4;
  *(_WORD *)(v8 - 2) = 0;
  v9 = *(unsigned __int16 *)(v5 + 8);
  v10 = v8 - 2 - v9;
  memmove(v10, *(_DWORD *)(v5 + 12), v9);
  *(_WORD *)v4 = v6;
  *(_WORD *)(v4 + 2) = v6 + 2;
  *(_DWORD *)(v4 + 4) = v10;
  return 0;
}

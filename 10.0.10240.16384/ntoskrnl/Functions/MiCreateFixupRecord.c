// MiCreateFixupRecord 
 
int __fastcall MiCreateFixupRecord(int a1, int a2, unsigned int a3, int a4, int a5, _WORD *a6, _DWORD *a7)
{
  int v7; // r10
  unsigned int v8; // r6
  int v9; // r8
  int v10; // r9
  unsigned int v11; // r2
  int v12; // r4
  __int16 v13; // r5
  int *v14; // r1
  int v16; // r0

  v7 = a4;
  v8 = a3;
  v9 = 0;
  v10 = 0;
  v11 = (unsigned __int16)*a6;
  if ( (v8 & 0xFFF) < 4096 - a4 )
  {
    v14 = (int *)(a2 + v8);
    if ( (v8 + 4096) >> 12 >= *(_DWORD *)(*(_DWORD *)a1 + 4) )
      return -1073741819;
    v12 = a5;
    v9 = *v14;
    if ( a5 != 4 )
      v10 = v14[1];
    v13 = *a6 >> 12;
  }
  else
  {
    *a6 = v11 & 0xFFF;
    v12 = a5;
    v13 = v11 >> 12;
  }
  v16 = ExAllocatePoolWithTag(1, 24, 1917218125);
  if ( !v16 )
    return -1073741670;
  *(_WORD *)(v16 + 12) = v13;
  *(_DWORD *)(v16 + 8) = v8 + v12;
  if ( (v8 & 0xFFF) < 4096 - v7 )
  {
    *(_DWORD *)(v16 + 4) = v8;
    *(_DWORD *)(v16 + 16) = v9;
    *(_DWORD *)(v16 + 20) = v10;
    *(_DWORD *)(*a7 + 4 * (v8 >> 12)) |= 1u;
  }
  else
  {
    *(_DWORD *)(v16 + 4) = (v8 & 0xFFFFF000) + 4096;
  }
  *(_DWORD *)(*a7 + 4 * (*(_DWORD *)(v16 + 8) >> 12)) |= 1u;
  *(_DWORD *)v16 = a7[2];
  a7[2] = v16;
  return 0;
}

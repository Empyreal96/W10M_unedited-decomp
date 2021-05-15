// WmipGenerateMofResourceNotification 
 
_DWORD *__fastcall WmipGenerateMofResourceNotification(unsigned __int16 *a1, unsigned __int16 *a2, _DWORD *a3, int a4)
{
  unsigned int v6; // r8
  unsigned int v7; // r9
  _DWORD *result; // r0
  unsigned int v9; // r7
  int v10; // r3
  int v11; // r4
  int v12; // r5
  int v13; // r3
  unsigned int v14; // r8
  int v15; // r4
  _WORD *v16; // r3

  v6 = 2 * (wcslen(a1) + 2);
  v7 = 2 * (wcslen(a2) + 2);
  result = (_DWORD *)ExAllocatePoolWithTag(1, v7 + v6 + 72, 1885957463);
  v9 = (unsigned int)result;
  if ( result )
  {
    result[1] = a4;
    result[2] = 1;
    result[3] = 0;
    result[11] = 266;
    *result = v7 + v6 + 72;
    v10 = a3[1];
    v11 = a3[2];
    v12 = a3[3];
    result[6] = *a3;
    result[7] = v10;
    result[8] = v11;
    result[9] = v12;
    KeQuerySystemTime(result + 4);
    *(_DWORD *)(v9 + 48) = 64;
    *(_DWORD *)(v9 + 56) = 72;
    *(_DWORD *)(v9 + 60) = v7 + v6;
    *(_WORD *)(v9 + 64) = 0;
    v13 = *(_DWORD *)(v9 + 56);
    v14 = v6 - 2;
    *(_WORD *)(v13 + v9) = v14;
    v15 = v13 + v9 + 2;
    memmove(v15, (int)a1, v14);
    v16 = (_WORD *)(v15 + 2 * (v14 >> 1));
    *v16 = v7 - 2;
    memmove((int)(v16 + 1), (int)a2, v7 - 2);
    WmipProcessEvent((unsigned int *)v9, 1, 0);
    result = (_DWORD *)ExFreePoolWithTag(v9);
  }
  return result;
}

// BapdpParseEventParts 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall BapdpParseEventParts(int a1, unsigned __int16 *a2, unsigned int a3, _DWORD *a4, int *a5)
{
  int result; // r0
  int v7; // r1
  int v8; // r2
  unsigned int v9; // r5
  unsigned int v10; // r6
  char *v11; // r3

  result = *(unsigned __int8 *)(a1 + 3);
  if ( result == 11
    && a3 >= 7
    && (v9 = *a2, v9 >= 3)
    && (result = a3 - 4, v9 <= a3 - 4)
    && (v10 = *(unsigned __int16 *)((char *)a2 + v9), v11 = (char *)a2 + v9, v10 >= 4)
    && (result = a3 - v9, v10 <= a3 - v9) )
  {
    *a4 = a2;
    a4[1] = 0;
    a4[2] = v9;
    a4[3] = 0;
    *((_BYTE *)a4 + 12) = 2;
    a4[4] = v11;
    a4[5] = 0;
    result = 1;
    a4[6] = v10;
    a4[7] = 0;
    *((_BYTE *)a4 + 28) = 1;
    a4[8] = &v11[v10];
    a4[9] = 0;
    a4[10] = a3 - v10 - v9;
    a4[11] = 0;
    v8 = 3;
  }
  else
  {
    *a4 = a2;
    v7 = 0;
    *(_QWORD *)(a4 + 1) = *(_QWORD *)(&a3 - 1);
    a4[3] = 0;
    v8 = 1;
  }
  *a5 = v8;
  return result;
}

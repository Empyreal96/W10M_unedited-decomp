// ExpCreateOutputARC 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall ExpCreateOutputARC(int a1, unsigned int *a2, unsigned __int16 *a3, unsigned __int16 *a4)
{
  int result; // r0
  unsigned int v8; // r8
  unsigned int v9; // r4
  int v10; // r7
  unsigned int v11; // r4 OVERLAPPED
  unsigned __int16 *v12; // r0
  int v13; // r3
  char *v14; // r2
  char *v15; // r9
  unsigned __int16 *v16[8]; // [sp+0h] [bp-20h] BYREF

  v16[0] = a3;
  v16[1] = a4;
  result = ExpFindArcName(a3, v16);
  if ( result >= 0 )
  {
    v8 = 2 * wcslen(v16[0]);
    v9 = v8 + 2;
    if ( a4 )
      v9 += 2 * wcslen(a4);
    v10 = v9 >> 1;
    v11 = v9 + 12;
    if ( *a2 >= v11 )
    {
      v13 = 1;
      v14 = (char *)v16[0];
      *(_QWORD *)a1 = *(_QWORD *)(&v11 - 1);
      *(_DWORD *)(a1 + 8) = 1;
      v15 = (char *)(a1 + 12);
      wcscpy_s(v15, v10, v14);
      ExFreePoolWithTag((unsigned int)v16[0]);
      if ( a4 )
        wcscpy_s(&v15[v8], v10, (char *)a4);
      *a2 = v11;
      result = 0;
    }
    else
    {
      v12 = v16[0];
      *a2 = v11;
      ExFreePoolWithTag((unsigned int)v12);
      result = -1073741789;
    }
  }
  return result;
}

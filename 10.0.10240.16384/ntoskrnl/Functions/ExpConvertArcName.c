// ExpConvertArcName 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall ExpConvertArcName(int a1, char *a2, unsigned int *a3, char *a4, unsigned __int16 *a5, int a6)
{
  int v7; // r4
  int v8; // r7
  char *v11; // r0
  char *v12; // r5
  int v13; // r4
  char *v14; // r0
  int v15; // r4
  int v16; // r4 OVERLAPPED
  int v17; // r0
  int v18; // r6
  int v19; // r3
  int v20; // r9
  char *v23[10]; // [sp+8h] [bp-28h] BYREF

  v7 = a6 + 10;
  v8 = 2 * (a6 + 10);
  v23[0] = a2;
  v11 = (char *)ExAllocatePoolWithTag(512, v8, 1920364101);
  v12 = v11;
  if ( !v11 )
    return -1073741670;
  wcscpy_s(v11, v7, (char *)L"\\ArcName\\");
  wcsncat_s(v12, v7, a4, a6);
  *(_WORD *)&v12[v8 - 2] = 0;
  if ( a1 == 3 )
  {
    v13 = ExpTranslateSymbolicLink((unsigned __int16 *)v12, v23);
    ExFreePoolWithTag((unsigned int)v12);
    if ( v13 < 0 )
      return v13;
    v13 = ExpCreateOutputNT((int)a2, a3, v23, (int)a5);
    v14 = v23[1];
LABEL_14:
    ExFreePoolWithTag((unsigned int)v14);
    return v13;
  }
  v15 = v8 + 12;
  if ( a5 )
    v15 += 2 * wcslen(a5);
  v16 = v15 + 2;
  v17 = ExAllocatePoolWithTag(512, v16, 1920364101);
  v18 = v17;
  if ( v17 )
  {
    v19 = 1;
    *(_QWORD *)v17 = *(_QWORD *)(&v16 - 1);
    *(_DWORD *)(v17 + 8) = 3;
    v20 = v17 + 12;
    wcscpy_s((char *)(v17 + 12), (unsigned int)(v16 - 12) >> 1, v12);
    ExFreePoolWithTag((unsigned int)v12);
    if ( a5 )
      wcscpy_s((char *)(v20 + v8), (unsigned int)(v16 - v8 - 12) >> 1, (char *)a5);
    else
      *(_WORD *)(v20 + v8) = 0;
    v13 = ExpTranslateNtPath(v18, a1, (int)v23[0], (int)a3);
    v14 = (char *)v18;
    goto LABEL_14;
  }
  ExFreePoolWithTag((unsigned int)v12);
  return -1073741670;
}

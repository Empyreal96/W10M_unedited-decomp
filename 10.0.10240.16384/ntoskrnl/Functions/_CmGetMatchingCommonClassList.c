// _CmGetMatchingCommonClassList 
 
int __fastcall CmGetMatchingCommonClassList(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v9; // r8
  int v13; // r7
  int (__fastcall *v14)(int, _DWORD, int, int, int, int *); // r5
  int v15; // r2
  int v17; // [sp+10h] [bp-50h] BYREF
  _DWORD v18[10]; // [sp+14h] [bp-4Ch] BYREF

  v9 = a7;
  v13 = a5;
  v17 = 0;
  memset(v18, 0, sizeof(v18));
  v14 = *(int (__fastcall **)(int, _DWORD, int, int, int, int *))(a1 + 160);
  v15 = a6;
  v18[3] = a5;
  v18[4] = a6;
  v18[5] = a7;
  v18[6] = a8;
  v18[1] = a3;
  v18[2] = a4;
  if ( v14 )
  {
    if ( v14(a1, 0, a2, 4, 1, &v17) != -1073741822 )
      return sub_811B84();
    a3 = v18[1];
    a4 = v18[2];
    v13 = v18[3];
    v15 = v18[4];
    v9 = v18[5];
  }
  return CmGetMatchingCommonClassListWorker(a1, a2, a3, a4, v13, v15, v9);
}

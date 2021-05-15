// CmpReportNotify 
 
int __fastcall CmpReportNotify(int a1, void (__fastcall **a2)(void *, int *), int a3, int a4, int a5, int a6)
{
  int v7; // r4
  void (__fastcall **v8)(void *, int *); // r5
  int result; // r0
  void (__fastcall *v11)(void *, int *); // r4
  int v12[8]; // [sp+10h] [bp-20h] BYREF

  v7 = a3;
  v8 = a2;
  if ( a5 != 1 )
  {
LABEL_2:
    result = CmpReportNotifyHelper(a1, v8, v8, v7, a4, a5, a6);
    if ( v8 != CmpMasterHive )
      result = CmpReportNotifyHelper(a1, CmpMasterHive, v8, v7, a4, a5, a6);
    return result;
  }
  v11 = a2[1];
  v12[0] = -1;
  result = ((int (__fastcall *)(void (__fastcall **)(void *, int *), int, int *))v11)(a2, a3, v12);
  if ( result )
  {
    v7 = *(_DWORD *)(result + 16);
    if ( (*(_WORD *)(result + 2) & 4) == 0
      || (v8[2](v8, v12),
          v8 = (void (__fastcall **)(void *, int *))CmpMasterHive,
          (result = (*((int (__fastcall **)(void *, int, int *))CmpMasterHive + 1))(CmpMasterHive, v7, v12)) != 0) )
    {
      a1 = *(_DWORD *)(a1 + 40);
      if ( (*(_WORD *)(result + 2) & 2) != 0 )
        v7 = *(_DWORD *)(result + 16);
      v8[2](v8, v12);
      goto LABEL_2;
    }
  }
  return result;
}

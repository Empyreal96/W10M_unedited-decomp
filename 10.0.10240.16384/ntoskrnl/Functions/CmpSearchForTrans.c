// CmpSearchForTrans 
 
int __fastcall CmpSearchForTrans(int a1, int a2, unsigned __int8 *a3, int a4)
{
  int v7; // r0
  int v8; // r4
  int v10[6]; // [sp+0h] [bp-18h] BYREF

  v10[1] = a4;
  v10[0] = 0;
  while ( 1 )
  {
    v7 = CmListGetNextElement(a1 + 8, v10, 0);
    v8 = v7;
    if ( !v7 )
      break;
    if ( a2 && *(_DWORD *)(v7 + 24) == a2 || a3 && RtlCompareMemory(a3, v7 + 40, 16) == 16 )
      return v8;
  }
  return 0;
}

// RtlEnumerateGenericTableLikeADirectory 
 
int __fastcall RtlEnumerateGenericTableLikeADirectory(int a1, int (*a2)(), int a3, int a4, int *a5, _DWORD *a6, int a7)
{
  int v7; // r6
  int v8; // r4
  int result; // r0
  int v12; // r0
  int v13; // r0
  int v14[8]; // [sp+0h] [bp-20h] BYREF

  v14[0] = a4;
  v7 = a4;
  v8 = *a5;
  v14[0] = *a5;
  if ( RtlIsGenericTableEmptyAvl(a1) )
    return sub_52796C();
  if ( !a2 )
    a2 = xHalTimerWatchdogStop;
  if ( *a6 != *(_DWORD *)(a1 + 36) )
  {
    v8 = 0;
    v14[0] = 0;
  }
  if ( v8 )
    goto LABEL_8;
  v13 = FindNodeOrParent(a1, a7, v14);
  if ( v13 == 1 )
  {
    v8 = v14[0];
    goto LABEL_8;
  }
  v7 = 0;
  if ( v13 == 3 )
  {
    v8 = RealSuccessor(v14[0]);
LABEL_8:
    if ( v7 )
      v8 = RealSuccessor(v8);
    goto LABEL_10;
  }
  v8 = v14[0];
LABEL_10:
  if ( !v8 )
    goto LABEL_17;
  while ( 1 )
  {
    v12 = a2();
    if ( v12 != -1073741198 )
      break;
    v8 = RealSuccessor(v8);
    if ( !v8 )
      goto LABEL_17;
  }
  *a5 = v8;
  *a6 = *(_DWORD *)(a1 + 36);
  if ( v12 )
LABEL_17:
    result = 0;
  else
    result = v8 + 16;
  return result;
}

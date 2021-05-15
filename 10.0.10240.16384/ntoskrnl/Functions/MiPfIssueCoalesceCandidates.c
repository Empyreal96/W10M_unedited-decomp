// MiPfIssueCoalesceCandidates 
 
int __fastcall MiPfIssueCoalesceCandidates(int **a1, int a2, int a3)
{
  int *v4; // r4
  int v6; // r2
  int v7; // r0
  int **v8; // r2
  _DWORD *v10; // r0
  _DWORD *v11; // r2
  int *v12; // r4
  __int64 v13; // r2
  int **v14; // r2

  v4 = *a1;
  if ( (int **)**a1 == a1 )
  {
    v6 = **a1;
    if ( (int **)v4[1] != a1 || *(int **)(v6 + 4) != v4 )
      __fastfail(3u);
    *a1 = (int *)v6;
    *(_DWORD *)(v6 + 4) = a1;
    v7 = MiIssueHardFaultIo((int)v4, 0, 0);
    v8 = *(int ***)(a3 + 4);
    *v4 = a3;
    v4[1] = (int)v8;
    if ( *v8 != (int *)a3 )
      sub_5278CC(v7);
    *v8 = v4;
    *(_DWORD *)(a3 + 4) = v4;
    return 0;
  }
  v10 = (_DWORD *)MiPfIssueCoalescedSupport(a1);
  if ( v10 )
  {
    v11 = *(_DWORD **)(a3 + 4);
    *v10 = a3;
    v10[1] = v11;
    if ( *v11 != a3 )
      __fastfail(3u);
    *v11 = v10;
    *(_DWORD *)(a3 + 4) = v10;
    return 0;
  }
  while ( 1 )
  {
    v12 = *a1;
    if ( *a1 == (int *)a1 )
      break;
    v13 = *(_QWORD *)v12;
    if ( (int **)v12[1] != a1 || *(int **)(v13 + 4) != v12 )
      __fastfail(3u);
    *a1 = (int *)v13;
    *(_DWORD *)(v13 + 4) = a1;
    MiIssueHardFaultIo((int)v12, 0, 0);
    v14 = *(int ***)(a3 + 4);
    *v12 = a3;
    v12[1] = (int)v14;
    if ( *v14 != (int *)a3 )
      __fastfail(3u);
    *v14 = v12;
    *(_DWORD *)(a3 + 4) = v12;
  }
  return -1073741670;
}

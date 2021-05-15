// -StDeviceIoIssue@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@PAU_PF_QUEUE@@@Z 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall ST_STORE<SM_TRAITS>::StDeviceIoIssue(int a1, int **a2)
{
  int v3; // r1
  int *v5; // r6
  unsigned int v6; // r5
  bool v7; // zf
  int v8; // r3
  __int64 v9; // kr00_8
  _DWORD *v10; // r8
  int v12; // [sp+8h] [bp-38h]
  int v13; // [sp+Ch] [bp-34h]
  int v14; // [sp+10h] [bp-30h]
  int v15[10]; // [sp+18h] [bp-28h] BYREF

  v3 = -2147483634;
  while ( 1 )
  {
    v5 = a2[1];
    if ( v5 == (int *)a2 )
      break;
    v6 = (unsigned int)*a2;
    v7 = *a2 == v5;
    *a2 = (int *)(**a2 & 0xFFFFFFF8);
    if ( v7 )
    {
      v8 = 0;
      *(_QWORD *)a2 = *(_QWORD *)(&a2 - 1);
    }
    else
    {
      *v5 = *v5 & 7 | (8 * ((unsigned int)*v5 >> 3) - 8);
    }
    v9 = *(_QWORD *)(v6 + 12);
    v10 = *(_DWORD **)(v6 + 8);
    v12 = *(_DWORD *)(a1 + 96) & v9;
    v14 = *(_DWORD *)(a1 + 100);
    v13 = ~(*(_DWORD *)(a1 + 88) - 1);
    if ( *(_DWORD *)(a1 + 680) && (v9 & 0x400000000i64) == 0 )
    {
      KeQueryPerformanceCounter(v15, 0);
      v10[1] = v15[0];
      v10[2] = v15[1];
    }
    StEtaIoStart(*(_DWORD *)(a1 + 276), HIDWORD(v9) >> 5, 0, (*(_DWORD *)(v6 + 16) >> 3) & 1 | (v6 + 4));
    *(_DWORD *)(v6 + 16) |= 8u;
    v3 = SmIssueIo(
           *(void **)(a1 + 92),
           (unsigned int)v9 >> v14,
           v13 & (16 * v12),
           HIDWORD(v9) >> 5,
           ((unsigned int)&v10[4 * *v10 + 2] + *(_DWORD *)(a1 + 88) + 3) & ~(*(_DWORD *)(a1 + 88) - 1),
           v6 | 1);
    if ( v3 < 0 )
    {
      ST_STORE<SM_TRAITS>::StDeviceIoMarkFailed(v6 + 4);
      *(_DWORD *)v6 = *(_DWORD *)v6 & 7 | (8 * (((unsigned int)*a2[1] >> 3) + 1));
      *a2[1] = *a2[1] & 7 | v6;
      a2[1] = (int *)v6;
      return v3;
    }
  }
  return v3;
}

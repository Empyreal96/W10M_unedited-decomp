// PopGetRemainingHibernateRangeDataSize 
 
int __fastcall PopGetRemainingHibernateRangeDataSize(_DWORD *a1, int a2, int a3, int a4)
{
  int *v5; // r1
  int v6; // r5
  int *v7; // r0
  __int64 v8; // kr10_8
  int v9; // r1
  int v10; // r0
  int v12[4]; // [sp+0h] [bp-10h] BYREF

  v12[0] = a4;
  v5 = (int *)a1[17];
  v6 = 0;
  v7 = a1 + 10;
  while ( v5 != v7 )
  {
    v8 = *(_QWORD *)(v5 + 3);
    v5 = (int *)*v5;
    v6 += (HIDWORD(v8) - (_DWORD)v8) << 12;
    a1[17] = v5;
  }
  v9 = a1[18];
  do
  {
    v10 = RtlFindNextForwardRunClear(a1[16], v9, (int)v12);
    v6 += v10 << 12;
    v9 = v12[0] + v10;
  }
  while ( v10 );
  if ( (_DWORD *)a1[16] == a1 + 6 )
    v6 += RtlNumberOfClearBits(a1 + 8) << 12;
  return v6;
}

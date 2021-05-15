// PopPowerTransitionTimesInMs 
 
int __fastcall PopPowerTransitionTimesInMs(int *a1, int *a2, int *a3, int *a4, int *a5)
{
  int result; // r0
  int v10; // r1
  int v11; // r10
  __int64 v12; // r0
  __int64 v13; // r0
  __int64 v14; // [sp+0h] [bp-30h]
  _DWORD v15[10]; // [sp+8h] [bp-28h] BYREF

  result = _rt_udiv64(1000000i64, *(_QWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x948));
  v11 = v10;
  v14 = 1000i64 * (unsigned int)result;
  if ( a1 )
  {
    result = PopQpcTimeInMs(&dword_61EF48, &dword_61EF50);
    *a1 = result;
  }
  if ( a2 )
  {
    result = PopQpcTimeInMs(&dword_61EF58, &dword_61EF60);
    *a2 = result;
  }
  if ( a5 )
  {
    v15[0] = 0;
    v15[1] = 0;
    result = PopQpcTimeInMs(v15, &dword_61EF78);
    *a5 = result;
    if ( PoResumeFromHibernate )
      *a5 = dword_61EFE8 + result;
  }
  if ( a3 )
  {
    HIDWORD(v12) = HIDWORD(v14) + 1000 * v11;
    LODWORD(v12) = v14;
    if ( !__PAIR64__(HIDWORD(v12), v14) )
      __brkdiv0();
    result = _rt_udiv64(v12, *(unsigned __int64 *)&dword_61EFB8);
    *a3 = result;
  }
  if ( a4 )
  {
    LODWORD(v13) = v14;
    HIDWORD(v13) = HIDWORD(v14) + 1000 * v11;
    if ( !__PAIR64__(HIDWORD(v13), v14) )
      __brkdiv0();
    result = _rt_udiv64(v13, *(_QWORD *)&dword_61F020 + qword_61F0D8);
    *a4 = result;
  }
  return result;
}

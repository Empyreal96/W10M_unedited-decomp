// -SmStReadThread@-$SMKM_STORE@USM_TRAITS@@@@SAXPAX@Z 
 
int __fastcall SMKM_STORE<SM_TRAITS>::SmStReadThread(int *a1)
{
  int v2; // r6
  int v3; // r9
  int v4; // r4
  int result; // r0
  int v6[10]; // [sp+18h] [bp-28h] BYREF

  v2 = *a1;
  SmGetFpContext(1);
  KeSetActualBasePriorityThread(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 12);
  v3 = ST_STORE<SM_TRAITS>::StAcquireReadContext(v2);
  if ( v3 )
    v4 = 0;
  else
    v4 = -1073741670;
  a1[5] = v4;
  result = KeSetEvent(a1 + 1, 0, 0);
  if ( v4 >= 0 )
  {
    v6[0] = v2 + 3832;
    v6[1] = v2 + 3816;
    result = KeWaitForMultipleObjects(2, v6, 1);
    if ( result != 1 )
      return sub_511310();
  }
  if ( v3 )
    result = ST_STORE<SM_TRAITS>::StReleaseReadContext(v2, v3);
  return result;
}

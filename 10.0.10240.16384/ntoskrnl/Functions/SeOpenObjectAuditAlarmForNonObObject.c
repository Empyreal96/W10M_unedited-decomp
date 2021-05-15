// SeOpenObjectAuditAlarmForNonObObject 
 
int __fastcall SeOpenObjectAuditAlarmForNonObObject(int a1, int a2, int a3, int a4, int a5, int *a6, int a7, int a8, int a9, unsigned __int8 a10)
{
  int v13; // r10
  int result; // r0
  int varg_r0; // [sp+78h] [bp+8h]
  int varg_r2; // [sp+80h] [bp+10h]
  int varg_r3; // [sp+84h] [bp+14h]

  varg_r0 = a1;
  varg_r2 = a3;
  varg_r3 = a4;
  v13 = a2;
  result = SepAdtAuditThisEventWithContext(0x76u, a10, a10 == 0, a6);
  if ( result )
    return sub_81B944();
  if ( a9 )
  {
    if ( a10 )
      result = SepAdtPrivilegeObjectAuditAlarm(
                 a1,
                 a3,
                 a4,
                 v13,
                 *a6,
                 a6[2],
                 *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 176),
                 a7,
                 a9,
                 a10);
  }
  return result;
}

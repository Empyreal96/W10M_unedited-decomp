// SepAdtLogAuditFailureEvent 
 
int __fastcall SepAdtLogAuditFailureEvent(int a1, int a2)
{
  int v5; // r0
  int v6; // r6
  int v7; // [sp+0h] [bp-2B0h] BYREF
  int v8[165]; // [sp+4h] [bp-2ACh] BYREF

  v7 = 0;
  memset(v8, 0, sizeof(v8));
  if ( SepAdtAuditFailureEventLogged && !a2 && (unsigned int)SepAdtAuditFailureCount < 0x32 )
    return 0;
  SepAdtAuditFailureEventLogged = 1;
  __dmb(0xBu);
  do
    v5 = __ldrex((unsigned int *)&SepAdtAuditFailureCount);
  while ( __strex(0, (unsigned int *)&SepAdtAuditFailureCount) );
  __dmb(0xBu);
  v6 = SeLocalSystemSid;
  v7 = 1;
  v8[3] = 524390;
  v8[0] = 521;
  v8[4] = 2;
  if ( !a2 )
  {
    if ( v5 )
    {
      *(&v7 + 5 * v8[1] + 6) = 4;
      *(&v7 + 5 * v8[1] + 7) = 4 * (*(unsigned __int8 *)(v6 + 1) + 2);
      *(&v7 + 5 * v8[1]++ + 10) = v6;
      *(&v7 + 5 * v8[1] + 6) = 1;
      *(&v7 + 5 * v8[1] + 7) = 24;
      *(&v7 + 5 * v8[1]++ + 10) = (int)&SeSubsystemName;
      *(&v7 + 5 * v8[1] + 6) = 10;
      *(&v7 + 5 * v8[1] + 7) = 4;
      *(&v7 + 5 * v8[1]++ + 8) = a1;
      *(&v7 + 5 * v8[1] + 6) = 3;
      *(&v7 + 5 * v8[1] + 7) = 1;
      *(&v7 + 5 * v8[1]++ + 8) = (unsigned __int8)SepCrashOnAuditFail;
      *(&v7 + 5 * v8[1] + 6) = 3;
      *(&v7 + 5 * v8[1] + 7) = 4;
      *(&v7 + 5 * v8[1]++ + 8) = v5;
      SepAdtLogAuditRecord((int)&v7);
    }
    return 0;
  }
  return sub_7DCE84(v5, 0, &SepAdtAuditFailureCount);
}

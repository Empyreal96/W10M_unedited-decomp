// ExpCheckFullProcessInformationAccess 
 
int __fastcall ExpCheckFullProcessInformationAccess(char a1, int a2, int a3, int a4)
{
  int v4; // r0
  int result; // r0
  int v6; // [sp+0h] [bp-8h] BYREF
  int v7; // [sp+4h] [bp-4h] BYREF

  v6 = a3;
  v7 = a4;
  if ( a1 != 1 )
    return -1073741790;
  v4 = RtlRunOnceExecuteOnce(&ExpFullProcessInfoInit, ExpInitFullProcessSecurityInfo, 0, &v7);
  if ( v4 >= 0 && (v4 = RtlCheckTokenMembership(0, v7, (int)&v6), v4 >= 0) && (_BYTE)v6 )
    result = 0;
  else
    result = sub_7C23F4(v4);
  return result;
}

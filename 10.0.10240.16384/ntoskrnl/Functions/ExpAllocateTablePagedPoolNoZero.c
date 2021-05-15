// ExpAllocateTablePagedPoolNoZero 
 
int __fastcall ExpAllocateTablePagedPoolNoZero(int a1, int a2)
{
  int v4; // r0
  int v5; // r4
  int result; // r0

  v4 = ExAllocatePoolWithTag(1, a2, 1651794511);
  v5 = v4;
  if ( a1 && v4 && PsChargeProcessPagedPoolQuota(a1, a2) < 0 )
    result = sub_7DE058();
  else
    result = v5;
  return result;
}

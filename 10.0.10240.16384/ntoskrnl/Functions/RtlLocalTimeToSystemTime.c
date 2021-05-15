// RtlLocalTimeToSystemTime 
 
int __fastcall RtlLocalTimeToSystemTime(_QWORD *a1, _QWORD *a2)
{
  int result; // r0
  __int64 v5; // [sp+Ch] [bp-30h]

  result = ZwQuerySystemInformation();
  if ( result >= 0 )
  {
    *a2 = v5 + *a1;
    result = 0;
  }
  return result;
}

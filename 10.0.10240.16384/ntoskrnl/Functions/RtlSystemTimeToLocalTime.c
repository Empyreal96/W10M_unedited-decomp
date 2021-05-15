// RtlSystemTimeToLocalTime 
 
int __fastcall RtlSystemTimeToLocalTime(_QWORD *a1, _QWORD *a2)
{
  int result; // r0
  __int64 v5; // [sp+Ch] [bp-30h]

  result = ZwQuerySystemInformation();
  if ( result >= 0 )
  {
    *a2 = *a1 - v5;
    result = 0;
  }
  return result;
}

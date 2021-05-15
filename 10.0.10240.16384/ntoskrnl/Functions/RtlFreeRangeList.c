// RtlFreeRangeList 
 
int __fastcall RtlFreeRangeList(_DWORD *a1)
{
  int result; // r0

  a1[2] = 0;
  a1[3] = 0;
  result = *a1 - 28;
  if ( a1 != (_DWORD *)(result + 28) )
    result = sub_80E79C();
  return result;
}

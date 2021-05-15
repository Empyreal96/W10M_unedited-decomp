// RtlpSystemTimeToTimeFields 
 
_WORD *__fastcall RtlpSystemTimeToTimeFields(_WORD *result, _WORD *a2)
{
  *result = *a2;
  result[1] = a2[1];
  result[7] = a2[2];
  result[2] = a2[3];
  result[3] = a2[4];
  result[4] = a2[5];
  result[5] = a2[6];
  result[6] = a2[7];
  return result;
}

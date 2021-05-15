// MiUpdatePagefilePeakUsage 
 
_DWORD *__fastcall MiUpdatePagefilePeakUsage(_DWORD *result)
{
  unsigned int v1; // r2

  v1 = *result - result[3] - 1;
  if ( result[4] < v1 )
    result[4] = v1;
  return result;
}

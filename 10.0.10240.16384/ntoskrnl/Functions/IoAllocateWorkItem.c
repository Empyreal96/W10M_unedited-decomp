// IoAllocateWorkItem 
 
_DWORD *__fastcall IoAllocateWorkItem(int a1)
{
  _DWORD *result; // r0

  if ( ViVerifierDriverAddedThunkListHead )
    return (_DWORD *)sub_5224DC();
  result = (_DWORD *)ExAllocatePoolWithTag(512, 52, 538996553);
  if ( result )
  {
    result[8] = 1;
    result[5] = a1;
    result[7] = 0;
    result[2] = IopProcessWorkItem;
    result[3] = result;
    *result = 0;
  }
  return result;
}

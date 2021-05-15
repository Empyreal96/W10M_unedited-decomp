// CmpEtwReleaseHivePath 
 
_DWORD *__fastcall CmpEtwReleaseHivePath(_DWORD *a1)
{
  if ( a1[1] )
    a1 = (_DWORD *)RtlFreeAnsiString(a1);
  return a1;
}

// MiReleaseControlAreaWaiters 
 
_DWORD *__fastcall MiReleaseControlAreaWaiters(_DWORD *result)
{
  _DWORD *v1; // r4

  if ( result )
  {
    do
    {
      v1 = (_DWORD *)*result;
      KeSignalGate((int)(result + 3), 1);
      result = v1;
    }
    while ( v1 );
  }
  return result;
}

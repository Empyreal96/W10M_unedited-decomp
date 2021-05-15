// IoAllocateErrorLogEntry 
 
int __fastcall IoAllocateErrorLogEntry(__int16 *a1, int a2)
{
  int v3; // r3
  __int16 *v4; // r1

  if ( !a1 )
    return 0;
  v3 = *a1;
  if ( v3 != 3 )
  {
    if ( v3 == 4 )
    {
      v4 = a1;
      a1 = 0;
      return IopAllocateErrorLogEntry(a1, v4, a2);
    }
    return 0;
  }
  v4 = (__int16 *)*((_DWORD *)a1 + 2);
  return IopAllocateErrorLogEntry(a1, v4, a2);
}

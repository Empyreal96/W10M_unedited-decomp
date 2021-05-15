// MiWakeModifiedPageWriter 
 
int __fastcall MiWakeModifiedPageWriter(_DWORD *a1, int a2)
{
  if ( a2 == -1 )
  {
    if ( a1[100] )
      KeSetEvent(a1 + 101, 0, 0);
    if ( a1[105] != 18 )
      KeSetActualBasePriorityThread(a1[140], 18);
  }
  else
  {
    a1[106] = a2;
  }
  return KeSetEvent(a1 + 107, 0, 0);
}

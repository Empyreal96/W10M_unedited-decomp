// ExQueueWorkItemEx 
 
int __fastcall ExQueueWorkItemEx(_DWORD *a1, int a2, int a3)
{
  int v3; // r1

  if ( *a1 )
    sub_5155E0();
  if ( a2 >= 7 && a2 < 32 || a2 >= 64 )
    KeBugCheckEx(228, 6, a1);
  if ( a1[2] <= (unsigned int)MmUserProbeAddress )
    KeBugCheckEx(228, 7, a1);
  if ( (unsigned int)a2 >= 7 )
    v3 = a2 - 32;
  else
    v3 = ExpBuiltinPriorities[a2];
  return ExpQueueWorkItem(a1, v3, a3, 0);
}

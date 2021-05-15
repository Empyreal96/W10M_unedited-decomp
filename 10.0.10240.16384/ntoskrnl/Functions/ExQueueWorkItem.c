// ExQueueWorkItem 
 
int __fastcall __spoils<R0,R2,R3,R12> ExQueueWorkItem(_DWORD *a1, int a2)
{
  int v3; // r1
  int result; // r0

  if ( *a1 )
    sub_52D2E8();
  if ( a2 >= 7 && a2 < 32 || a2 >= 64 )
    KeBugCheckEx(228, 6, a1);
  if ( a1[2] <= (unsigned int)MmUserProbeAddress )
    KeBugCheckEx(228, 7, a1);
  if ( (unsigned int)a2 >= 7 )
    v3 = a2 - 32;
  else
    v3 = ExpBuiltinPriorities[a2];
  result = ExpQueueWorkItem(a1, v3, -1, 0);
  if ( !result )
    KeBugCheckEx(228, 5, a1);
  return result;
}

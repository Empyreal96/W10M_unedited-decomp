// ExCopyWakeTimerInfo 
 
int __fastcall ExCopyWakeTimerInfo(unsigned int *a1, int *a2)
{
  int v4; // r0
  int v5; // r5

  v4 = ExAllocatePoolWithTag(1, *a1);
  v5 = v4;
  if ( !v4 )
    return -1073741670;
  memmove(v4, (int)a1, *a1);
  *a2 = v5;
  return 0;
}

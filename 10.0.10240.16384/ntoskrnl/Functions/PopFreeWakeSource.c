// PopFreeWakeSource 
 
unsigned int __fastcall PopFreeWakeSource(_DWORD *a1)
{
  int v2; // r3
  int v3; // r0
  unsigned int v4; // r0
  unsigned int v5; // r0
  unsigned int v6; // r0

  v2 = a1[2];
  if ( v2 )
  {
    if ( (unsigned int)(v2 - 2) <= 1 )
    {
      v3 = a1[3];
      if ( v3 )
        ExDeleteWakeTimerInfo(v3);
    }
  }
  else
  {
    v4 = a1[4];
    if ( v4 )
      ExFreePoolWithTag(v4);
    v5 = a1[6];
    if ( v5 )
      ExFreePoolWithTag(v5);
    v6 = a1[8];
    if ( v6 )
      ExFreePoolWithTag(v6);
  }
  return ExFreePoolWithTag((unsigned int)a1);
}

// MUIInitializeResourceLock 
 
int __fastcall MUIInitializeResourceLock(unsigned int *a1)
{
  int v2; // r4
  int v4; // r0
  unsigned int v5; // r5
  unsigned int v6; // r2

  if ( !a1 )
    return -1073741811;
  if ( *a1 )
    return 0;
  v4 = ExAllocatePoolWithTag(512, 56, 1836411216);
  v5 = v4;
  if ( !v4 )
    return -1073741801;
  v2 = ExInitializeResourceLite(v4);
  if ( (v2 & 0xC0000000) == -1073741824 )
  {
LABEL_13:
    if ( v5 )
      ExFreePoolWithTag(v5);
    return v2;
  }
  __dmb(0xBu);
  do
    v6 = __ldrex(a1);
  while ( !v6 && __strex(v5, a1) );
  __dmb(0xBu);
  if ( !v6 )
  {
    v5 = 0;
    v2 = 0;
    goto LABEL_13;
  }
  return sub_7E899C();
}

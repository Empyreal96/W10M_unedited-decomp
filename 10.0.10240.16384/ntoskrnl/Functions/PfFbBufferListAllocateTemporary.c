// PfFbBufferListAllocateTemporary 
 
int __fastcall PfFbBufferListAllocateTemporary(_DWORD *a1, int a2)
{
  unsigned int *v4; // r7
  unsigned int v5; // r4
  int v6; // r4
  int v7; // r0
  unsigned int v8; // r0

  __dmb(0xBu);
  v4 = a1 + 16;
  do
    v5 = __ldrex(v4);
  while ( __strex(v5 + a2, v4) );
  __dmb(0xBu);
  if ( (signed int)(v5 + a2) <= a1[13] )
  {
    v7 = ExAllocatePoolWithTag(a1[10], a2);
    if ( v7 )
    {
      PfFbBufferListInsertInFree(a1, v7, a2, 1);
      return 0;
    }
    v6 = -1073741670;
  }
  else
  {
    v6 = -1073741523;
  }
  __dmb(0xBu);
  do
    v8 = __ldrex(v4);
  while ( __strex(v8 - a2, v4) );
  __dmb(0xBu);
  return v6;
}

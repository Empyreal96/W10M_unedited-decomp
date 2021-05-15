// PopQueueWorkItem 
 
int __fastcall PopQueueWorkItem(_DWORD *a1)
{
  int result; // r0
  unsigned int *v3; // r2
  unsigned int v4; // r1
  unsigned int v5; // r1

  result = 0;
  __dmb(0xBu);
  v3 = a1 + 4;
  do
  {
    v4 = __ldrex(v3);
    v5 = v4 + 1;
  }
  while ( __strex(v5, v3) );
  __dmb(0xBu);
  if ( v5 == 1 )
  {
    ExQueueWorkItem(a1, 1);
    result = 1;
  }
  return result;
}

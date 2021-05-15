// KiActivateWaiterKQueue 
 
// local variable allocation has failed, the output may be wrong!
unsigned int *__fastcall KiActivateWaiterKQueue(unsigned int *result)
{
  unsigned int *v1; // r4
  unsigned int *v2; // r5
  unsigned int *v3; // r6
  unsigned int v4; // r1
  unsigned int *v5; // r1 OVERLAPPED
  unsigned int **v6; // r2 OVERLAPPED
  unsigned int v7; // r2

  v1 = result;
  if ( result[6] < result[7] )
  {
    v2 = (unsigned int *)result[4];
    v3 = result + 4;
    if ( v2 != result + 4 && (unsigned int *)result[3] != result + 2 )
    {
      *(_QWORD *)&v5 = *(_QWORD *)v2;
      if ( *(unsigned int **)(*v2 + 4) != v2 || *v6 != v2 )
        __fastfail(3u);
      *v6 = v5;
      v5[1] = (unsigned int)v6;
      *v2 = 0;
      result = (unsigned int *)KiWakeQueueWaiter(((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408, result, v2);
      if ( result )
      {
        --v1[1];
      }
      else
      {
        v7 = *v3;
        *v2 = *v3;
        v2[1] = (unsigned int)v3;
        if ( *(unsigned int **)(v7 + 4) != v3 )
          sub_51565C();
        *(_DWORD *)(v7 + 4) = v2;
        *v3 = (unsigned int)v2;
      }
    }
  }
  __dmb(0xBu);
  do
    v4 = __ldrex(v1);
  while ( __strex(v4 & 0xFFFFFF7F, v1) );
  return result;
}

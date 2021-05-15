// PopFxRequestWorker 
 
int __fastcall PopFxRequestWorker(_DWORD *a1)
{
  int *v1; // r1
  void *v2; // r6
  unsigned int v3; // r2
  unsigned int v4; // r5
  int *v5; // r0
  int v6; // r7

  if ( a1 )
  {
    if ( (a1[4] & 1) == 0 )
      return sub_53EB20();
    v3 = a1[19];
    v1 = a1 + 20;
    v2 = a1 + 6;
  }
  else
  {
    v1 = &PopFxSystemWorkOrders;
    v2 = &PopFxSystemWorkQueue;
    v3 = 4;
  }
  v4 = 0;
  v5 = v1;
  if ( v3 )
  {
    while ( 1 )
    {
      v6 = v5[4];
      if ( !v6 )
        break;
      if ( v6 < v1[4] )
        v1 = v5;
      ++v4;
      v5 += 7;
      if ( v4 >= v3 )
        return PopFxQueueWorkOrder(v2, v1, 0, 0);
    }
    v1 = v5;
  }
  return PopFxQueueWorkOrder(v2, v1, 0, 0);
}

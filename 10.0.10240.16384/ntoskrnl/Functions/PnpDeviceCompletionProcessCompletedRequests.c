// PnpDeviceCompletionProcessCompletedRequests 
 
int __fastcall PnpDeviceCompletionProcessCompletedRequests(int a1, int a2, _DWORD *a3)
{
  int i; // r4
  _DWORD *v8; // r0

  *a3 = 0;
  for ( i = 0; !PnpDeviceCompletionQueueIsEmpty(); *a3 = 1 )
  {
    if ( !dword_6306F8 && (!a2 || !a1 && *a3) )
      break;
    v8 = (_DWORD *)PnpDeviceCompletionQueueGetCompletedRequest();
    if ( PnpDeviceCompletionProcessCompletedRequest(v8) == -1073741106 )
      i = -1073741106;
  }
  return i;
}

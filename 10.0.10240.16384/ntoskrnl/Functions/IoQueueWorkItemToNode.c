// IoQueueWorkItemToNode 
 
int __fastcall IoQueueWorkItemToNode(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  _DWORD *v7; // r0
  int v8; // r4

  v7 = (_DWORD *)IopQueueWorkItemProlog(a1, a2, a4);
  v8 = ExQueueWorkItemEx(v7, a3, a5);
  if ( !v8 )
    ObfDereferenceObjectWithTag(a1[5]);
  return v8;
}

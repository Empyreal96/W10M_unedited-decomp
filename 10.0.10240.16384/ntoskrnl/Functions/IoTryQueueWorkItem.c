// IoTryQueueWorkItem 
 
int __fastcall IoTryQueueWorkItem(_DWORD *a1, int a2, int a3, int a4)
{
  _DWORD *v6; // r0
  int v7; // r4
  int result; // r0
  int v9; // r0

  v6 = (_DWORD *)IopQueueWorkItemProlog(a1, a2, a4);
  v7 = ExTryQueueWorkItem(v6, a3);
  if ( v7 || (v9 = ObfDereferenceObjectWithTag(a1[5]), !a1[7]) )
    result = v7;
  else
    result = sub_55483C(v9);
  return result;
}

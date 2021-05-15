// SepInformFileSystemsOfDeletedLogon 
 
// local variable allocation has failed, the output may be wrong!
_DWORD *__fastcall SepInformFileSystemsOfDeletedLogon(_DWORD *a1, int a2)
{
  _DWORD *result; // r0
  _DWORD *v5; // r4 OVERLAPPED
  int (*v6)(); // r3

  result = (_DWORD *)ExAllocatePoolWithTag(512, 28, 1397122387);
  v5 = result;
  if ( result )
  {
    result[4] = *a1;
    result[5] = a1[1];
    result[6] = a2;
    if ( a2 )
      PspReferenceSiloObject(a2);
    v6 = SepNotifyFileSystems;
    *((_QWORD *)v5 + 1) = *(_QWORD *)(&v5 - 1);
    *v5 = 0;
    result = (_DWORD *)ExQueueWorkItem(v5, 1);
  }
  return result;
}

// FsRtlpOplockDequeueRH 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall FsRtlpOplockDequeueRH(_DWORD *a1)
{
  int result; // r0
  int v3; // r1 OVERLAPPED
  _DWORD *v4; // r2 OVERLAPPED

  result = IoGetOplockFullFoExt(a1[3]);
  if ( result )
    *(_DWORD *)(result + 40) = 0;
  *(_QWORD *)&v3 = *(_QWORD *)a1;
  if ( *(_DWORD **)(*a1 + 4) != a1 || (_DWORD *)*v4 != a1 )
    sub_523F6C();
  *v4 = v3;
  *(_DWORD *)(v3 + 4) = v4;
  return result;
}

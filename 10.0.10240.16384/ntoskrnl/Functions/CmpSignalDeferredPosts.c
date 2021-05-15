// CmpSignalDeferredPosts 
 
unsigned int __fastcall CmpSignalDeferredPosts(unsigned int result)
{
  _DWORD *v1; // r5
  _DWORD *v2; // r4
  __int64 v3; // r2
  int *v4; // r3
  int v5; // r0
  _DWORD *v6; // r0

  v1 = (_DWORD *)result;
  while ( 1 )
  {
    v2 = (_DWORD *)*v1;
    if ( (_DWORD *)*v1 == v1 )
      return result;
    v3 = *(_QWORD *)v2;
    if ( (_DWORD *)v2[1] != v1 || *(_DWORD **)(v3 + 4) != v2 )
      sub_7C9CA8(result);
    *v1 = v3;
    *(_DWORD *)(v3 + 4) = v1;
    v4 = (int *)v2[6];
    if ( *((_WORD *)v2 + 10) != 3 )
    {
      v5 = *v4;
LABEL_8:
      KeSetEvent(v5, 0, 0);
      ObfDereferenceObject(*(_DWORD *)v2[6]);
      goto LABEL_9;
    }
    v6 = (_DWORD *)v4[1];
    if ( v6 )
      ExQueueWorkItem(v6, v4[2]);
    v5 = *(_DWORD *)v2[6];
    if ( v5 )
      goto LABEL_8;
LABEL_9:
    result = CmpFreePostBlock(v2 - 2);
  }
}

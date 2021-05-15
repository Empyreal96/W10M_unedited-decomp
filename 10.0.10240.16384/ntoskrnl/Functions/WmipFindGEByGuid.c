// WmipFindGEByGuid 
 
// local variable allocation has failed, the output may be wrong!
int *__fastcall WmipFindGEByGuid(unsigned int a1, int a2)
{
  int v4; // r5
  int *v5; // r4
  int v6; // r0
  int *v8; // r1 OVERLAPPED
  int **v9; // r2 OVERLAPPED
  int **v10; // r2 OVERLAPPED
  int v11; // r1 OVERLAPPED

  KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
  v4 = WmipGEHeadPtr;
  v5 = *(int **)WmipGEHeadPtr;
  if ( *(_DWORD *)WmipGEHeadPtr == WmipGEHeadPtr )
  {
LABEL_4:
    KeReleaseMutex((int)&WmipSMMutex);
    v5 = 0;
  }
  else
  {
    while ( memcmp(a1, (unsigned int)(v5 + 10), 16) )
    {
      v5 = (int *)*v5;
      if ( v5 == (int *)v4 )
        goto LABEL_4;
    }
    v6 = WmipReferenceEntry(v5);
    if ( a2 )
    {
      *(_QWORD *)&v8 = *(_QWORD *)v5;
      if ( *(int **)(*v5 + 4) != v5 || *v9 != v5 )
        __fastfail(3u);
      *v9 = v8;
      v8[1] = (int)v9;
      v10 = (int **)WmipGEHeadPtr;
      v11 = *(_DWORD *)WmipGEHeadPtr;
      *(_QWORD *)v5 = *(_QWORD *)&v11;
      if ( *(int ***)(v11 + 4) != v10 )
        sub_7D6450(v6);
      *(_DWORD *)(v11 + 4) = v5;
      *v10 = v5;
    }
    KeReleaseMutex((int)&WmipSMMutex);
  }
  return v5;
}

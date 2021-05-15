// PfpFlushEventBuffers 
 
int PfpFlushEventBuffers()
{
  _DWORD *v0; // r4
  int v1; // r5
  _DWORD *v2; // r0
  _DWORD *v3; // r3
  _DWORD *v4; // r6
  int v5; // r3
  _DWORD *v6; // r7
  int v7; // r3
  _DWORD *v8; // r0

  v0 = 0;
  v1 = 0;
  PfFbBufferListFlushStandby(qword_643A00);
  v2 = (_DWORD *)RtlpInterlockedFlushSList((unsigned __int64 *)&unk_643A50);
  if ( v2 )
  {
    do
    {
      v3 = v2;
      v2 = (_DWORD *)*v2;
      *v3 = v0;
      v0 = v3;
    }
    while ( v2 );
    while ( 1 )
    {
      v4 = v0;
      v5 = v0[4];
      v0 = (_DWORD *)*v0;
      v6 = v4 + 6;
      if ( v5 )
        break;
LABEL_6:
      PfFbBufferListInsertInFree(qword_643A00, v4, v4[3] - (_DWORD)v4, v4[5], 1);
      if ( !v0 )
        return v1;
    }
    while ( 1 )
    {
      v1 = PfpCopyEvent((int)v6);
      if ( v1 < 0 )
        break;
      v6 += 2 * ((*v6 >> 2) & 0x3FF);
      v7 = v4[4] - 1;
      v4[4] = v7;
      if ( !v7 )
        goto LABEL_6;
    }
    memmove((int)(v4 + 6), (int)v6, v4[3] - (_DWORD)v6);
    v8 = v4;
    while ( 1 )
    {
      PfTFullEventListAdd(v8);
      if ( !v0 )
        break;
      v8 = v0;
      v0 = (_DWORD *)*v0;
    }
  }
  return v1;
}

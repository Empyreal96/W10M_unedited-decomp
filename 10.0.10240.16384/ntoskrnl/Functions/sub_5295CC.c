// sub_5295CC 
 
void sub_5295CC()
{
  int *v0; // r4
  int v1; // r6
  int *v2; // r8
  int v3; // r10
  _DWORD *v4; // r7
  int *v5; // r9
  _DWORD *i; // r5

  v4 = (_DWORD *)(v1 + 36);
  while ( 1 )
  {
    v5 = v0;
    if ( (_DWORD *)*v4 == v4 )
      goto LABEL_11;
    if ( !*((_BYTE *)v0 + 28) )
    {
      for ( i = *(_DWORD **)(v1 + 36); ; i = (_DWORD *)*i )
      {
        if ( i == v4 )
          goto LABEL_10;
        if ( !FsRtlpOplockKeysEqual(*(_DWORD *)(*(_DWORD *)(v0[2] + 96) + 28), i[3], 0) )
          break;
      }
      v3 = 0;
LABEL_10:
      if ( v3 )
      {
LABEL_11:
        v0 = (int *)v0[1];
        FsRtlpRemoveAndCompleteWaitingIrp(v5);
      }
    }
    v0 = (int *)*v0;
    if ( v0 == v2 )
      JUMPOUT(0x46683E);
  }
}

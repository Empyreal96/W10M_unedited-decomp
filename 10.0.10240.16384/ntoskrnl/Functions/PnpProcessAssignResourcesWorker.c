// PnpProcessAssignResourcesWorker 
 
int __fastcall PnpProcessAssignResourcesWorker(_DWORD *a1, _DWORD *a2)
{
  _DWORD *v3; // r5
  _DWORD *i; // r4
  int v5; // r2
  int v6; // r3

  v3 = a1;
  for ( i = a1; ; i = (_DWORD *)i[1] )
  {
LABEL_2:
    if ( *a2 )
    {
      if ( (v5 = i[67] & 0x2000) != 0 && i[69] == 12 || v5 && ((v6 = i[69], v6 == 33) || v6 == 36) )
        PipClearDevNodeProblem(i);
    }
    if ( (i[67] & 0x6000) == 0 && i[43] == 771 )
      a2[a2[1]++ + 2] = i[4];
    if ( !i[1] )
      break;
  }
  while ( i != v3 )
  {
    if ( *i )
    {
      i = (_DWORD *)*i;
      goto LABEL_2;
    }
    if ( i[2] )
      i = (_DWORD *)i[2];
  }
  return 0;
}

// RtlTraceDatabaseEnumerate 
 
int __fastcall RtlTraceDatabaseEnumerate(int a1, _DWORD *a2, _DWORD *a3)
{
  int v6; // r4
  int i; // r3
  unsigned int v8; // r2

  RtlpTraceDatabaseAcquireLock();
  if ( *a2 )
  {
    if ( *a2 != a1 || a2[1] >= *(_DWORD *)(a1 + 64) )
      goto LABEL_4;
  }
  else
  {
    *a2 = a1;
    a2[1] = 0;
    a2[2] = **(_DWORD **)(a1 + 68);
  }
  for ( i = a2[2]; !i; a2[2] = i )
  {
    v8 = a2[1] + 1;
    a2[1] = v8;
    if ( v8 >= *(_DWORD *)(a1 + 64) )
      break;
    i = *(_DWORD *)(*(_DWORD *)(a1 + 68) + 4 * v8);
  }
  if ( a2[1] < *(_DWORD *)(a1 + 64) || a2[2] )
  {
    *a3 = a2[2];
    a2[2] = *(_DWORD *)(a2[2] + 24);
    v6 = 1;
    goto LABEL_14;
  }
  *a3 = 0;
LABEL_4:
  v6 = 0;
LABEL_14:
  RtlpTraceDatabaseReleaseLock(a1);
  return v6;
}

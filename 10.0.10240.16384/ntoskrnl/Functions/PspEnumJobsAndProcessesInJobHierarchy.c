// PspEnumJobsAndProcessesInJobHierarchy 
 
int __fastcall PspEnumJobsAndProcessesInJobHierarchy(int a1, int a2, int a3, int a4, int a5, unsigned int a6)
{
  int v6; // r7
  unsigned int v7; // r5
  int v9; // r6
  int v10; // r4
  int v11; // r8
  int v12; // r0
  int i; // r7
  int v16; // [sp+Ch] [bp-24h]

  v16 = a2;
  v6 = a3;
  v7 = a6;
  v9 = a1;
  v10 = a1;
  v11 = 0;
  while ( 1 )
  {
    if ( (v7 & 2) == 0 )
    {
      v11 = PspCallJobHierarchyCallbacks(v10, a2, v6, a4, a5, v7);
      if ( v11 < 0 )
        goto LABEL_11;
      v7 = a6 & 0xFFFFFFFE;
    }
    v12 = PspGetNextChildJob(v10, 0);
    if ( !v12 )
    {
      for ( i = *(_DWORD *)(v10 + 572); v10 != v9; i = *(_DWORD *)(i + 572) )
      {
        if ( (v7 & 2) != 0 )
        {
          v11 = PspCallJobHierarchyCallbacks(v10, v16, a3, a4, a5, a6 & 0xFFFFFFFE);
          if ( v11 < 0 )
            goto LABEL_11;
        }
        v12 = PspGetNextChildJob(i, v10);
        if ( v12 )
          break;
        v10 = i;
      }
      v6 = a3;
    }
    v10 = v12;
    if ( !v12 )
      break;
    a2 = v16;
  }
  if ( (v7 & 2) == 0 )
    return v11;
  v11 = PspCallJobHierarchyCallbacks(v9, v16, v6, a4, a5, v7);
LABEL_11:
  if ( !v10 || v10 == v9 )
    return v11;
  return sub_7BDA78();
}

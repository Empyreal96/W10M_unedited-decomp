// CmpBlockTwoHiveWrites 
 
int __fastcall CmpBlockTwoHiveWrites(_DWORD *a1, _DWORD *a2, int a3)
{
  int v4; // r7
  int v5; // r0
  int v8; // r8
  int v9; // r2
  int v10; // r3
  int v11; // r0
  int v12; // r4
  unsigned int *v13; // r0
  unsigned int v14; // r4
  unsigned int v15; // r1
  _DWORD *v16; // r0

  v4 = 0;
  v5 = 0;
  v8 = 0;
  while ( 1 )
  {
    v11 = CmpGetNextActiveHive(v5);
    v12 = v11;
    if ( !v11 )
      break;
    if ( a1 == (_DWORD *)v11 || a2 == (_DWORD *)v11 )
    {
      if ( a3 )
        CmpReferenceHive(v11);
      ExAcquireResourceExclusiveLite(*(_DWORD *)(v12 + 1872), 1, v9, v10);
      if ( a1 == (_DWORD *)v12 )
        v8 = 1;
      else
        v4 = 1;
      if ( (!a1 || v8 == 1) && (!a2 || v4 == 1) )
      {
        v13 = (unsigned int *)(v12 + 1832);
        __pld((void *)(v12 + 1832));
        v14 = *(_DWORD *)(v12 + 1832) & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v15 = __ldrex(v13);
        while ( v15 == v14 && __strex(v14 - 2, v13) );
        if ( v15 != v14 )
          ExfReleaseRundownProtection((unsigned __int8 *)v13);
        break;
      }
    }
    v5 = v12;
  }
  if ( a1 && !v8 || a2 && !v4 )
  {
    if ( v8 == 1 )
    {
      ExReleaseResourceLite(a1[468]);
      if ( !a3 )
        return -1073741772;
      v16 = a1;
    }
    else
    {
      if ( v4 != 1 )
        return -1073741772;
      ExReleaseResourceLite(a2[468]);
      if ( !a3 )
        return -1073741772;
      v16 = a2;
    }
    CmpDereferenceHive(v16);
    return -1073741772;
  }
  return 0;
}

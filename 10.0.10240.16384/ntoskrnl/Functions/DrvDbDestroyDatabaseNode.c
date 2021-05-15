// DrvDbDestroyDatabaseNode 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall DrvDbDestroyDatabaseNode(int a1, _DWORD *a2)
{
  int v3; // r6
  int v4; // r1 OVERLAPPED
  _DWORD *v5; // r2 OVERLAPPED
  unsigned int v6; // r5

  v3 = DrvDbUnloadDatabaseNode(a1, a2);
  if ( v3 >= 0 )
  {
    *(_QWORD *)&v4 = *(_QWORD *)a2;
    if ( *(_DWORD **)(*a2 + 4) != a2 || (_DWORD *)*v5 != a2 )
      __fastfail(3u);
    *v5 = v4;
    *(_DWORD *)(v4 + 4) = v5;
    v6 = a2[18];
    if ( v6 )
    {
      ExDeleteResourceLite((_DWORD *)a2[18]);
      ExFreePoolWithTag(v6);
    }
    RtlFreeAnsiString(a2 + 2);
    RtlFreeAnsiString(a2 + 5);
    ExFreePoolWithTag((unsigned int)a2);
  }
  return v3;
}

// PipDeleteBindingId 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PipDeleteBindingId(int a1, unsigned __int16 *a2)
{
  unsigned __int16 *v2; // r6
  unsigned __int16 *v3; // r4
  int v4; // r5
  int v7; // r1 OVERLAPPED
  unsigned __int16 **v8; // r2 OVERLAPPED

  v2 = (unsigned __int16 *)(a1 + 28);
  v3 = *(unsigned __int16 **)(a1 + 28);
  v4 = -1073741275;
  while ( v3 != v2 )
  {
    if ( RtlEqualUnicodeString(v3 + 4, a2, 0) )
    {
      *(_QWORD *)&v7 = *(_QWORD *)v3;
      if ( *(unsigned __int16 **)(*(_DWORD *)v3 + 4) != v3 || *v8 != v3 )
        __fastfail(3u);
      *v8 = (unsigned __int16 *)v7;
      *(_DWORD *)(v7 + 4) = v8;
      PipFreeBindingId(v3);
      return 0;
    }
    v3 = *(unsigned __int16 **)v3;
  }
  return v4;
}

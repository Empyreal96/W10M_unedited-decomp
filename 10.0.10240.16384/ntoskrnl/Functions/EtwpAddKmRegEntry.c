// EtwpAddKmRegEntry 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall EtwpAddKmRegEntry(int a1, int a2, unsigned int a3, int a4, _DWORD *a5)
{
  int v9; // r6
  _BYTE *v10; // r0
  _BYTE *v11; // r4
  _DWORD *v12; // r2 OVERLAPPED
  int v13; // r1 OVERLAPPED

  v9 = 0;
  v10 = (_BYTE *)ExAllocatePoolWithTag(512, 60, 1383560261);
  v11 = v10;
  if ( !v10 )
    return -1073741801;
  memset(v10, 0, 60);
  v11[50] = 1;
  EtwpReferenceGuidEntry(a1);
  *((_DWORD *)v11 + 4) = a1;
  if ( a2 == 2 )
    v11[50] |= 8u;
  if ( a3 )
  {
    *((_DWORD *)v11 + 10) = a4;
    *((_DWORD *)v11 + 11) = a3;
    if ( MmIsSessionAddress(a3) )
    {
      v11[50] |= 0x10u;
      *((_DWORD *)v11 + 7) = MmGetSessionIdEx(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
    }
  }
  v12 = (_DWORD *)(a1 + 28);
  v13 = *(_DWORD *)(a1 + 28);
  *(_QWORD *)v11 = *(_QWORD *)&v13;
  if ( *(_DWORD *)(v13 + 4) != a1 + 28 )
    sub_8061A0();
  *(_DWORD *)(v13 + 4) = v11;
  *v12 = v11;
  *((_DWORD *)v11 + 2) = v11 + 8;
  *((_DWORD *)v11 + 3) = v11 + 8;
  v11[50] |= 0x80u;
  *a5 = v11;
  return v9;
}

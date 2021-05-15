// MmResetDriverPaging 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MmResetDriverPaging(int a1)
{
  int result; // r0
  int v2; // r6
  int v3; // r8
  int v4; // r4
  int v5; // r3
  int v6; // r4
  int i; // r5
  int v8; // r1 OVERLAPPED
  unsigned int v9; // r2 OVERLAPPED

  result = MiImagePagable(0, a1);
  v2 = result;
  if ( result )
  {
    v3 = *(_DWORD *)(result + 24);
    v4 = RtlImageNtHeader(v3);
    result = MiCancelPhase0Locking(v2);
    v5 = *(unsigned __int16 *)(v4 + 20) + v4;
    v6 = *(unsigned __int16 *)(v4 + 6);
    for ( i = v5 + 24; v6; i += 40 )
    {
      if ( (*(_DWORD *)(i + 36) & 0x2000000) == 0 )
      {
        result = MmImageSectionPagable((int *)i);
        if ( !result )
        {
          *(_QWORD *)&v8 = *(_QWORD *)(i + 12);
          if ( v9 < *(_DWORD *)(i + 8) )
            v9 = *(_DWORD *)(i + 8);
          result = MiLockCode(
                     v2,
                     (((unsigned int)(v8 + v3) >> 10) & 0x3FFFFC) - 0x40000000,
                     (((v8 + v9 + v3 - 1) >> 10) & 0x3FFFFC) - 0x40000000,
                     2);
        }
      }
      --v6;
    }
  }
  return result;
}

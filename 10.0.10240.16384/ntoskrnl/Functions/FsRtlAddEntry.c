// FsRtlAddEntry 
 
int __fastcall FsRtlAddEntry(__int64 *a1, unsigned int a2, int a3, int a4)
{
  __int64 v5; // kr00_8
  unsigned int v8; // r3
  int result; // r0
  unsigned int v10; // r5
  int v11; // r0
  int v12; // r6
  int v13[6]; // [sp+0h] [bp-18h] BYREF

  v13[0] = a4;
  v5 = *a1;
  if ( HIDWORD(v5) + a3 > (unsigned int)v5 )
  {
    if ( (unsigned int)v5 >= 0x800 )
      v10 = v5 + 2048;
    else
      v10 = 2 * v5;
    if ( RtlULongLongToULong(8 * v10, (unsigned __int64)v10 >> 29, v13) < 0 )
      return sub_520418();
    v11 = ExAllocatePoolWithTag(*((unsigned __int16 *)a1 + 4), v13[0], 1953649478);
    v12 = v11;
    if ( !v11 )
      return sub_520418();
    memmove(v11, *((_DWORD *)a1 + 3), 8 * *((_DWORD *)a1 + 1));
    if ( *((_WORD *)a1 + 4) == 1 && *(_DWORD *)a1 == 15 )
      ExFreeToPagedLookasideList(&FsRtlFirstMappingLookasideList, *((_DWORD *)a1 + 3));
    else
      ExFreePoolWithTag(*((_DWORD *)a1 + 3), 0);
    *((_DWORD *)a1 + 3) = v12;
    *(_DWORD *)a1 = v10;
  }
  v8 = *((_DWORD *)a1 + 1);
  if ( a2 < v8 )
    memmove(*((_DWORD *)a1 + 3) + 8 * (a2 + a3), *((_DWORD *)a1 + 3) + 8 * a2, 8 * (v8 - a2));
  result = 1;
  *((_DWORD *)a1 + 1) += a3;
  return result;
}

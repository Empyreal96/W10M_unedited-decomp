// SmKmIssueIo 
 
int __fastcall SmKmIssueIo(int a1, int a2, void (__cdecl *a3)(void *, struct _IO_STATUS_BLOCK *, unsigned int), void *a4, int a5)
{
  unsigned int v5; // r5
  int i; // r7
  int result; // r0
  union _LARGE_INTEGER v8; // [sp+8h] [bp-20h] BYREF

  v5 = *(_DWORD *)(a2 + 16);
  for ( i = *(_DWORD *)(a1 + 24); v5 >= *(_DWORD *)i; i += 16 )
    v5 -= *(_DWORD *)i;
  v8.QuadPart = *(_QWORD *)(i + 8) + *(unsigned int *)(a2 + 20) * (unsigned __int64)v5 + *(unsigned int *)(a2 + 12);
  if ( a5 )
    result = SmKmIssueFileIo((struct _SMKM_FILE_INFO *)a1, (struct _SMKM_ISSUE_IO_PARAMS *)a2, &v8, a3, a4);
  else
    result = SmKmIssueVolumeIo(a1, a2, &v8, a3);
  return result;
}

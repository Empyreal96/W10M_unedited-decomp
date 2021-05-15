// -SmKmIssueFileIo@@YAJPAU_SMKM_FILE_INFO@@PAU_SMKM_ISSUE_IO_PARAMS@@PAT_LARGE_INTEGER@@P6AXPAXPAU_IO_STATUS_BLOCK@@K@Z3@Z 
 
int __fastcall SmKmIssueFileIo(struct _SMKM_FILE_INFO *a1, struct _SMKM_ISSUE_IO_PARAMS *a2, union _LARGE_INTEGER *a3, void (__cdecl *a4)(void *, struct _IO_STATUS_BLOCK *, unsigned int), void *a5)
{
  int *v5; // r5
  int v6; // r0
  int v8; // r0
  int *v10; // [sp+0h] [bp-28h]

  v5 = *(int **)a2;
  v6 = *(_DWORD *)a1;
  v10 = *(int **)a2;
  if ( (*((_DWORD *)a2 + 6) & 1) != 0 )
    v8 = NtReadFile(v6, 0, a4, a5, v10, *((_DWORD *)a2 + 1), *((_DWORD *)a2 + 2), a3, 0);
  else
    v8 = NtWriteFile(v6, 0, a4, a5, v10, *((_DWORD *)a2 + 1), *((_DWORD *)a2 + 2), a3, 0);
  if ( (v8 & 0xC0000000) == -1073741824 )
  {
    *v5 = v8;
    ((void (__fastcall *)(void *, int *, _DWORD))a4)(a5, v5, 0);
  }
  return 259;
}
